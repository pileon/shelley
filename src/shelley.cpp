#include <shelley/shelley.h>
#include <shelley/utility.h>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <unistd.h>
#include <sys/wait.h>


using namespace shelley;

namespace
{
    using command = std::vector<std::string>;

    [[noreturn]] void execute_command(command const& cmd)
    {
        // First translate the vector of std::string objects to an argv array
        auto argv = utility::arguments_to_argv(cmd);

        // Execute the command
        execvp(argv[0], argv.data());

        // The execvp function returned? That's not good
        if (errno == ENOENT)
            std::cerr << "shelley: " << cmd[0] << ": command not found\n";
        else
            std::cerr << "shelley: " << cmd[0] << ": " << strerror(errno) << '\n';
        exit(127);
    }

    void wait()
    {
        int status;
        if (::wait(&status) == -1)
            std::cerr << "Error waiting for child process: " << errno << ' ' << strerror(errno) << '\n';
        else
        {
            // TODO: Do I need to print these? Maybe if the child exited with a signal?
            if (WIFEXITED(status))
            {
                //std::cout << "Child exited with status " << WEXITSTATUS(status)
                //          << '\n';
            }
            else if (WIFSIGNALED(status))
            {
                //std::cout << "Child exited with a signal: " << WTERMSIG(status)
                //          << '\n';
            }
            else
            {
                auto flags = std::cout.flags();
                std::cout << "Chid exited with unknown exit status: " << std::hex << std::setw(8) << std::setfill('0') << status << '\n';
                std::cout.flags(flags);
            }
        }
    }

    void process_commands(std::vector<command> const& commands)
    {
        for (auto const& cmd : commands)
        {
            // Create a process
            pid_t pid = fork();

            if (pid == -1)
                std::cerr << "Error forking process: " << errno << ' ' << strerror(errno) << '\n';
            else if (pid == 0)
            {
                // In child
                execute_command(cmd);
            }
            else
            {
                // In parent, wait for child to exit
                wait();
            }
        }
    }
}

int main()
{
    for (;;)
    {
        std::cout << utility::get_prompt() << std::flush;

        std::string input = utility::get_input(std::cin);
        if (input.empty())
        {
            if (std::cin.eof())
                break;
        }

        std::vector<command> commands;
        commands.emplace_back(utility::tokenize(input));

        process_commands(commands);
    }
}
