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

    std::cout << "1: Input is \"" << input << "\"\n";

    // Turn multiple white-space into single white-space
    input.erase(std::unique(std::begin(input), std::end(input), [](auto const& first, auto const& second)
    {
        return std::isspace(first) && std::isspace(second);
    }), std::end(input));

    std::cout << "2: Input is \"" << input << "\"\n";

    // Turn all white-space into a space
    std::replace_if(std::begin(input), std::end(input), [](auto const& ch)
    {
        return std::isspace(ch);
    }, ' ');

    std::cout << "3: Input is \"" << input << "\"\n";

    // Split each "word" into a vector
    std::istringstream input_stream{input};
    std::vector<std::string> command{std::istream_iterator<std::string>{input_stream},
                                     std::istream_iterator<std::string>{}};

    std::cout << "4: command is\n";
    for (auto const& s : command)
        std::cout << "    \"" << s << "\"\n";
}
