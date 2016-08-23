#include <gtest/gtest.h>
#include <shelley/utility.h>

TEST(utility, get_prompt)
{
    EXPECT_EQ(shelley::utility::get_prompt(), "# ");
}

TEST(utility, tokenize)
{
    auto tokens = shelley::utility::tokenize("foo bar baz");

    ASSERT_EQ(tokens.size(), 3ul);

    EXPECT_EQ(tokens[0], "foo");
    EXPECT_EQ(tokens[1], "bar");
    EXPECT_EQ(tokens[2], "baz");
}

TEST(utility, arguments_to_argv)
{
    auto argv = shelley::utility::arguments_to_argv({"foo", "bar", "baz" });

    ASSERT_EQ(argv.size(), 4ul);  // 4 because of the terminating null pointer

    EXPECT_NE(argv[0], nullptr);
    EXPECT_NE(argv[1], nullptr);
    EXPECT_NE(argv[2], nullptr);
    EXPECT_EQ(argv[3], nullptr);

    EXPECT_STREQ(argv[0], "foo");
    EXPECT_STREQ(argv[1], "bar");
    EXPECT_STREQ(argv[2], "baz");

    // Cleanup
    for (auto a : argv)
        delete [] a;
    argv.clear();
}

TEST(utility, get_input)
{
    std::istringstream iss{"foo\nbar\nbaz\n"};
    std::vector<std::string> input{
        shelley::utility::get_input(iss),
        shelley::utility::get_input(iss),
        shelley::utility::get_input(iss)
    };

    ASSERT_EQ(input.size(), 3ul);

    EXPECT_EQ(input[0], "foo");
    EXPECT_EQ(input[1], "bar");
    EXPECT_EQ(input[2], "baz");

    EXPECT_FALSE(iss.eof());

    EXPECT_TRUE(shelley::utility::get_input(iss).empty());

    EXPECT_TRUE(iss.eof());
}
