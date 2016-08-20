#include "shelley/utility.h"

#include <algorithm>
#include <cctype>
#include <vector>
#include <iterator>
#include <sstream>
#include <iostream>

namespace
{
    // Clean up spaces
    void clean_spaces(std::string& input)
    {
        // First strip leading space
        auto first_non_space = std::find_if_not(std::begin(input), std::end(input),
                                                [](auto const& ch) { return std::isspace(ch); });
        if (first_non_space != std::begin(input) && first_non_space != std::end(input))
        {
            input = input.substr(first_non_space - std::begin(input));
        }

        // Then strip trailing spaces
        auto last_non_space = std::find_if_not(std::rbegin(input), std::rend(input),
                                                [](auto const& ch) { return std::isspace(ch); });
        if (last_non_space != std::rbegin(input) && last_non_space != std::rend(input))
        {
            input = input.substr(0, -(last_non_space - std::rend(input)));
        }

        // Then turn multiple white-space into a single white-space
        input.erase(std::unique(std::begin(input), std::end(input),
                                [](auto const &first, auto const &second)
        {
            return std::isspace(first) && std::isspace(second);
        }), std::end(input));

        // Lastly turn all white-space into an actual space
        std::replace_if(std::begin(input), std::end(input), [](auto const& ch)
        {
            return std::isspace(ch);
        }, ' ');
    }
}

std::string shelley::utility::get_input(std::istream& is)
{
    std::string input;
    if (!std::getline(is, input))
    {
        if (!is.eof())
            throw std::runtime_error("error reading input");

        return "";
    }

    return input;
}

std::vector<std::string> shelley::utility::tokenize(std::string input)
{
    clean_spaces(input);

    // Split each "word" into a vector
    std::istringstream input_stream{input};
    std::vector<std::string> command{std::istream_iterator<std::string>{input_stream},
                                     std::istream_iterator<std::string>{}};

    return command;
}

std::vector<char*> shelley::utility::arguments_to_argv(std::vector<std::string> const& arguments)
{
    std::vector<char*> argv(arguments.size() + 1, nullptr);
    std::transform(std::begin(arguments), std::end(arguments), std::begin(argv),
                   [](std::string const& s)
                   {
                       char* a = new char[s.size() + 1]{'\0'};
                       std::copy(std::begin(s), std::end(s), a);
                       return a;
                   });
    return argv;
}
