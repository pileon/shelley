#include <gtest/gtest.h>
#include <shelley/utility.h>

TEST(dummy, dummy)
{
    EXPECT_EQ(1, 1);
}

TEST(utility, get_prompt)
{
    EXPECT_EQ(shelley::utility::get_prompt(), "# ");
}
