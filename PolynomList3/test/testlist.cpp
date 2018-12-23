#include "gtest.h"
#include "TList.h"
#include "TMonom.h"

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList P);
}
TEST(TList, can_add_monom_to_list)
{
	TList P;
	ASSERT_NO_THROW(P.AddMonom(3,196));
}
TEST(TList, can_get_polynom_from_list)
{
	TList P;
	P.AddMonom(8, 303);
	P.AddMonom(5, 303);
	P.AddMonom(-2, 357);
	EXPECT_EQ("-2x^3y^5z^7+13x^3z^3", P.GetPolinom(10));
}
