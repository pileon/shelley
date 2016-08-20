#pragma once
#ifndef SHELLEY_UTILITY_H
#define SHELLEY_UTILITY_H

#include <string>
#include <vector>

// Clion doesn't yet support C++17 nested namepace names
// namespace shelley::utility
namespace shelley
{
    namespace utility
    {
        /**
         * \brief Get one line of input
         *
         * \param is input stream to read input from
         * \return A string containing the line just read
         */
        std::string get_input(std::istream& is);

        /**
         * \brief Return the current prompt
         *
         * \returns A string contaning the curret prompt
         */
        inline std::string get_prompt()
        {
            return "# ";
        }

        /**
         * \brief Clean up and tokenize a single command input
         *
         * Returns a vector of strings, where the first element is the command
         * and the remaining elements are the arguments to the command
         *
         * \param input
         * \return A vector of strings
         */
        std::vector<std::string> tokenize(std::string input);

        /**
         * \brief Convert a vector of string objects to a vector of pointers to characters
         *
         * To execute a command we need an argv-style array. This function creates such
         * an array in the form of a vector. This function also adds an extra null-pointer
         * element at the end.
         *
         * \param arguments the vector to convert
         * \return a vector of pointers to characters, terminated by a null pointer
         */
        std::vector<char*> arguments_to_argv(std::vector<std::string> const& arguments);
    }
}

#endif //SHELLEY_UTILITY_H
