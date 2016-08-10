#include <shelley/shelley.h>
#include <shelley/utility.h>

#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <iterator>
#include <sstream>

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
        std::cout << "cmd is \"" << cmd[0] << "\"\n";
        std::cout << "    it has " << cmd.size() - 1 << " arguments\n";
        for (auto const &s : std::vector<std::string>{std::begin(cmd) + 1, std::end(cmd)})
            std::cout << "    \"" << s << "\"\n";
    }
}
