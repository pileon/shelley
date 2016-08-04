#pragma once
#ifndef SHELLEY_UTILITY_H
#define SHELLEY_UTILITY_H

#include <string>

// Clion doesn't yet support C++17 nested namepace names
// namespace shelley::utility
namespace shelley
{
    namespace utility
    {
        /**
         * \brief Return the current prompt
         *
         * \returns A string contaning the curret prompt
         */
        inline std::string get_prompt()
        {
            return "# ";
        }
    }
}

#endif //SHELLEY_UTILITY_H
