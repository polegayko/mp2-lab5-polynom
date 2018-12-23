#include "gtest.h"
#include "TPolimon.h"


TEST(TPolimon, can_create_polynom)
{
	ASSERT_NO_THROW(TPolimon  P);
}
TEST(TPolimon, can_get_right_polynom)
{
	TPolimon Pol("2xy-15z^2xy^3+4");
	EXPECT_TRUE("-15x^1y^3z^2+2x^1y^1+4" ==  Pol.GetPolinom());
}
TEST(TPolimon, can_get_right_sum_polynom)
{
	
	string P[5] = { "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z" };
	string Q[5] = { "4x^3y^2z^6-6x^2yz^8",
				   "4x^7y^2z^6-6x^6yz^8",
				   "4x^5y^2z^5+5x^4y^3z^3",
				   "4x^6y^2z^6-6x^2yz^8",
				   "-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z" };
	string R[5] = { "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1+4x^3y^2z^6-6x^2y^1z^8",
				   "4x^7y^2z^6-6x^6y^1z^8+3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1",
				   "7x^5y^2z^5+7x^3y^5z^1",
				   "7x^7y^5z^1+4x^6y^2z^6+3x^5y^2z^5-5x^4y^3z^3-6x^2y^1z^8",
				   "0" };
	

	for (int i = 0; i < 5; i++)
	{
		TPolimon P1(P[i]);
		TPolimon Q1(Q[i]);
		TPolimon Sum;
		Sum = P1 + Q1;
		EXPECT_TRUE(R[i] == Sum.GetPolinom());
	}
}