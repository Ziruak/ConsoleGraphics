
#include "pch.h"
#include "../Matrix.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestMatrixOne, TestMatrixOne_1) {
	mat3 res(mat3::one());
	EXPECT_EQ(1, res[0][0]);
	EXPECT_EQ(0, res[0][1]);
	EXPECT_EQ(0, res[0][2]);

	EXPECT_EQ(0, res[1][0]);
	EXPECT_EQ(1, res[1][1]);
	EXPECT_EQ(0, res[1][2]);

	EXPECT_EQ(0, res[2][0]);
	EXPECT_EQ(0, res[2][1]);
	EXPECT_EQ(1, res[2][2]);
}