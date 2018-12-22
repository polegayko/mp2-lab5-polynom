#pragma once
#include "TList.h"
#include "TMonom.h"
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
class TPolimon
{
private:
	int MaxDeg;
	TList CList;
	void StrToArr(string st, string *w, int &k)
	{
		if ((st[0] != '-') && (st[0] != '+'))
		{
			st = "+" + st;
		}
		k = -1;
		for (int i = 0; i < st.length(); i++)
		{
			if ((st[i] == '-') || (st[i] == '+'))
			{
				w[++k] = st[i];
			}
			else
			{
				w[k] += st[i];
			}
		}
		k++;
	}
	int GetCoeff(string monom)
	{
		string coef = "";
		for (int i = 0; (i < monom.length()) && ((monom[i] != 'x') && (monom[i] != 'y') && (monom[i] != 'z')); i++)
		{
			coef += monom[i];
		}
		int gc = atoi(coef.c_str());
		return  gc;
	}
	int GetIndex(string monom)
	{
		int l;
		char Var[3] = { 'x','y','z' };
		int Deg[3] = { 0,0,0 };
		for (int i = 0; i < 3; i++)
		{
			l = monom.find(Var[i]);
			if ((l >= 0) && (l <= monom.length()))
			{
				if (monom[l + 1] == '^')
				{
					Deg[i] = monom[l + 2] - 48;
				}
				else
				{
					Deg[i] = 1;
				}
			}
		}
		if ((Deg[0] < MaxDeg) && (Deg[1] < MaxDeg) && (Deg[2] < MaxDeg))
		{
			return Deg[0] * MaxDeg*MaxDeg + Deg[1] * MaxDeg + Deg[2];
		}
		else return -1;
	}
public:
	TPolimon(string st = "", int _MaxDeg=10)
	{
		MaxDeg = _MaxDeg;
		string *Monom;
		Monom = new string[st.length() + 1];
		int k;
		StrToArr(st, Monom, k);
		for (int i = 0; i < k; i++)
		{
			CList.AddMonom(GetCoeff(Monom[i]), GetIndex(Monom[i]));
		}

	};
	~TPolimon(){};
	string GetPolinom()
	{
		string s1 = CList.GetPolinom(MaxDeg);
		if(s1=="")
		{
			s1 = "0";
		}
		else
		{
			if (s1[0] == '+')
			{
				//s1[0] = ' ';
				s1.erase(0, 1);
			}
		}
		return s1;
	}
	TPolimon(const TPolimon &tmp)
	{
		MaxDeg = tmp.MaxDeg;
		CList = tmp.CList;
	}
	TPolimon &operator=(const TPolimon &tmp)
	{
		MaxDeg = tmp.MaxDeg;
		CList = tmp.CList;
		return *this;
	}
	TPolimon operator+(const TPolimon &tmp)
	{
		TPolimon Sum(tmp);
		Sum.CList = CList + tmp.CList;
		return Sum;
	}

};

