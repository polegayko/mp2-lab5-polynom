// PolynomList3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "TMonom.h"
#include "TList.h"
#include "TPolimon.h"

using namespace std;

int main()
{
	/*
	TMonom M1(2,105);
	TMonom M2(M1);
	TMonom M3;
	M3 = M1;
	TMonom M4(7, 155);
	M3 = M1 + M4;
	cout << "M3: \n " << "Coeff =" << M3.GetCoeff() << "Index =" << M3.GetIndex() << "Link =" << M3.GetLink() << endl;
	M3 = TMonom(4, 206);
	cout << "M3: \n " << "Coeff =" << M3.GetCoeff() << "Index =" << M3.GetIndex() << "Link =" << M3.GetLink() << endl;
	M3.SetCoeff(-7);
	M3.SetIndex(303);
	cout << "M3: \n " << "Coeff =" << M3.GetCoeff() << "Index =" << M3.GetIndex() << "Link =" << M3.GetLink() << endl;
	cout << M3.GetMon(10)<<endl;
	cout << M1.GetMon(10) << endl;
	cout << M4.GetMon(10) << endl;
	TList P;
	P.AddMonom(M1.GetCoeff(),M1.GetIndex());
	P.AddMonom( M3.GetCoeff(), M3.GetIndex());
	string s1 = P.GetPolinom(10);
	cout <<"P= \n"<< s1<< endl;
	TList R(P);
	s1 = R.GetPolinom(10);
	cout <<"copy R\n"<< s1 << endl;
	TList Q=P;
	s1 = Q.GetPolinom(10);
	cout << "Q=P=\n"<<s1 << endl;
	TMonom *M5 = new TMonom(6, 543);
	Q.AddMonom(M5->GetCoeff(),M5->GetIndex()); 
	s1 = Q.GetPolinom(10);
	cout << "Q=P+=\n" << s1 << endl;
	Q.AddMonom(12, 303);
	s1 = Q.GetPolinom(10);
	cout <<"Q=\n"<< s1 << endl;
	
	R = P + Q;
    s1 = R.GetPolinom(10);
    cout << "R=P+Q= " << s1 << endl;
	R = Q + P;
	s1 = R.GetPolinom(10);
	cout << "R=Q+P=\n "<<s1 << endl;
	Q.AddMonom(-12, 303);
	s1 = Q.GetPolinom(10);
	cout << s1 << endl; */
	TPolimon Pol("2xy-15z^2xy^3+4");
	cout << Pol.GetPolinom() << endl;
	/*
	string P1[5] = {"3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z",
				 "3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z" };
	string Q1[5] = { "4x^3y^2z^6-6x^2yz^8",
				   "4x^7y^2z^6-6x^6yz^8",
				   "4x^5y^2z^5+5x^4y^3z^3",
				   "4x^6y^2z^6-6x^2yz^8",
				   "-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z" };
	for (int i = 0; i < 5; i++)
	{
		TPolimon Sum;
		TPolimon Left(P1[i]);
		TPolimon Right(Q1[i]);
		Sum = Left+Right;
		cout << endl;
		cout << endl;
		cout << Sum.GetPolinom() << endl;
	}
	*/
	

	system("pause");

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
