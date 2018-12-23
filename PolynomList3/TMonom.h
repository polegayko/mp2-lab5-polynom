#pragma once
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "string.h"
using namespace std;
class TMonom
{
	int Coeff; // вещественные числа слишком длинные
	int Index;
	TMonom *Link;

public:
	TMonom(int _Coeff=0, int _Index=-1)
	{
		Coeff = _Coeff;
		Index = _Index;
		Link = this;
	};
	~TMonom()
	{
		Link = NULL;		
	};
	TMonom(const TMonom &tmp)
	{
		Coeff = tmp.Coeff;
		Index = tmp.Index;
		Link = this;
	};
	TMonom &operator= (TMonom tmp)
	{
		Coeff = tmp.Coeff;
		Index = tmp.Index;
		return *this;
	};
	TMonom operator+ (TMonom tmp)
	{
		TMonom res;
		if (Index == tmp.Index)
		{
			if (Coeff + tmp.Coeff != 0)
			{
				res.Coeff = Coeff + tmp.Coeff;
				res.Index = tmp.Index;
			}
		}
		return res;
	};
	int GetCoeff()
	{
		return Coeff;
	};
	int GetIndex()
	{
		return Index;
	};
	TMonom* GetLink()
	{
		return Link;
	};
	void SetCoeff(int C)
	{
		Coeff = C;
	};
	void SetIndex(int In)
	{
		Index = In;
	};
	void SetLink(TMonom* TM)
	{
		Link = TM;
	};
	string GetMon (int MaxInd)
	{
		
		
		
		stringstream ss;
		ss << Coeff;
		int n;
		int m;
		int k;
		k = Index % MaxInd;
		m = (Index / MaxInd) % MaxInd;
		n = Index / (MaxInd*MaxInd);
		if (n != 0)
		{
			ss << "x^";
			ss << n;
			
			
		}
		if (m != 0)
		{
			ss << "y^";
			ss << m;
			
			;
		}
		if (k != 0)
		{
			ss << "z^";
			ss << k;
			
			
		}
		return ss.str();
	};
};

