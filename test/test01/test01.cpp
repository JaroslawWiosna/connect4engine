
#include <gtest/gtest.h>
#include "Grid.hpp"

TEST(Test, test01)
{
	std::string board01 = "2111122";

	Grid grid01(board01);
	grid01.print();

	ASSERT_TRUE(grid01.hasFirstWon());
	ASSERT_FALSE(grid01.hasSecondWon());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
