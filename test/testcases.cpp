#include "gtest.h"
#include "TMonom.h"

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom  M1(4, 123));
}
TEST(TMonom, can_get_coeff_of_monom)
{
	TMonom  M1(4, 123);
	EXPECT_EQ(4, M1.GetCoeff());
}
TEST(TMonom, can_get_index_of_monom)
{
	TMonom  M1(4, 123);
	EXPECT_EQ(123, M1.GetIndex());
}
TEST(TMonom, can_set_index_of_monom)
{
	TMonom  M2;
	ASSERT_NO_THROW(M2.SetIndex(234));
}
TEST(TMonom, can_set_coeff_of_monom)
{
	TMonom  M2;
	ASSERT_NO_THROW(M2.SetCoeff(6));
}
TEST(TMonom, can_get_monom)
{
	TMonom  M2(3,657);
	EXPECT_EQ("3x^6y^5z^7", M2.GetMon(10));
}


