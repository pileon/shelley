#include <gtest/gtest.h>
#include <shelley/utility.h>

TEST(utility, get_prompt)
{
    EXPECT_EQ(shelley::utility::get_prompt(), "# ");
}

TEST(utility, tokenize)
{
    auto tokens = shelley::utility::tokenize("foo bar baz");

    EXPECT_EQ(tokens.size(), 3ul);

    if (tokens.size() >= 3)
    {
        EXPECT_EQ(tokens[0], "foo");
        EXPECT_EQ(tokens[1], "bar");
        EXPECT_EQ(tokens[2], "baz");
    }
}
