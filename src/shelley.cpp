#include <shelley/shelley.h>
#include <shelley/utility.h>

#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <iterator>
#include <sstream>

#include <unistd.h>
#include <sys/wait.h>
#include <iomanip>

using namespace shelley;

int main()
{
    using command = std::vector<std::string>;

    std::vector<command> commands;

    std::cout << utility::get_prompt() << std::flush;

    std::string input;
    if (!std::getline(std::cin, input))
    {
        if (!std::cin.eof())
            std::cerr << "\nError reading input\n";

        return 0;
    }


    commands.emplace_back(utility::tokenize(input));

    for (auto const& cmd : commands)
    {
        // Create a process
        pid_t pid = fork();

        if (pid == -1)
            std::cerr << "Error forking process: " << errno << ' ' << strerror(errno) << '\n';
        else if (pid == 0)
        {
            // In child, for now just exit
             exit(0);
        }
        else
        {
            // In parent, wait for child to exit
            int status;
            if (wait(&status) == -1)
                std::cerr << "Error waiting for child process: " << errno << ' ' << strerror(errno) << '\n';
            else
            {
                if (WIFEXITED(status))
                    std::cout << "Child exited with status " << WEXITSTATUS(status) << '\n';
                else if (WIFSIGNALED(status))
                    std::cout << "Child exited with a signal: " << WTERMSIG(status) << '\n';
                else
                {
                    auto flags = std::cout.flags();
                    std::cout << "Chid exited with unknown exit status: " << std::hex << std::setw(8) << std::setfill('0') << status << '\n';
                    std::cout.flags(flags);
                }
            }
        }
    }
}
