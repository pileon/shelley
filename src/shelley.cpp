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
    std::cout << utility::get_prompt() << std::flush;

    std::string input;
    if (!std::getline(std::cin, input))
    {
        if (!std::cin.eof())
            std::cerr << "\nError reading input\n";

        return 0;
    }

    auto command = utility::tokenize(input);

    std::cout << "command is \"" << command[0] << "\"\n";
    std::cout << "    it has " << command.size() - 1 << " arguments\n";
    for (auto const& s : std::vector<std::string>{std::begin(command) + 1, std::end(command)})
        std::cout << "    \"" << s << "\"\n";
}
