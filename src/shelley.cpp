#include <iostream>

#include <shelley/shelley.h>
#include <shelley/utility.h>

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

    std::cout << "Input was \"" << input << "\"\n";
}
