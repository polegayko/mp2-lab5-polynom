#pragma once
#include "TMonom.h"
#include <sstream>
#include <iostream>
#include "string.h"
using namespace std;
class TList
{
private:
	TMonom* PFirst;


public:
	TList()
	{
		PFirst = new TMonom();
	};
	TList(const TList &tmp)
	{
		PFirst = new TMonom();
		TMonom* PCur = PFirst;
		TMonom* tmpCur = tmp.PFirst->GetLink();
		while (tmpCur != tmp.PFirst)
		{
			TMonom* Copy = new TMonom(*tmpCur);
			PCur->SetLink(Copy);
			Copy->SetLink(PFirst);
			PCur = Copy;
			tmpCur = tmpCur->GetLink();
		};
	}
	TList &operator= (const TList &tmp)
	{
		TMonom* PCur= PFirst->GetLink();
		while (PCur != PFirst)
		{
			PFirst->SetLink(PCur->GetLink());
			PCur->SetLink(0);
			delete PCur;
			PCur = PFirst->GetLink();
		}
		
		//PFirst = new TMonom();
		TMonom* tmpCur = tmp.PFirst->GetLink();
		PCur = PFirst;
		while (tmpCur != tmp.PFirst)
		{
			TMonom* Copy = new TMonom(*tmpCur);
			PCur->SetLink(Copy);
			Copy->SetLink(PFirst);
			PCur = Copy;
			tmpCur = tmpCur->GetLink();
		};
		return *this;
	}
	~TList()
	{
		TMonom* p = PFirst->GetLink();
		while (p != PFirst) 
		{
		  PFirst->SetLink(p->GetLink());
		  p->SetLink(0);
		  delete p;
		  p = PFirst->GetLink();
		}
		delete PFirst;
	};
	void AddMonom(int coeff,int index )
	{
		TMonom* tmp= new TMonom(coeff, index);
		
		TMonom* PPrev = PFirst;
		TMonom* PCur = PFirst->GetLink();
		while (PCur->GetIndex() > tmp->GetIndex())
		{
			PPrev = PCur;
			PCur= PCur->GetLink();
		}
		if (PCur->GetIndex() == tmp->GetIndex())
		{
			int sumcoeff = PCur->GetCoeff() + tmp->GetCoeff();
		
			if (sumcoeff ==0)
			{
				PPrev->SetLink(PCur->GetLink());
				PCur->SetLink(0);
				delete PCur;
			}
			else 
			{
				PCur->SetCoeff(sumcoeff);
			}
		}
		else
		{
			tmp->SetLink(PCur);
			PPrev->SetLink(tmp);
		}
		
	};
	string GetPolinom(int MaxInd)
	{
		string st = "";
		TMonom* PCur = PFirst->GetLink();
		while (PCur != PFirst)
		{
			string stM = PCur->GetMon(MaxInd);
			if (stM[0] != '-')
			{
				st += "+" + stM;
			}
			else st += stM;
			PCur = PCur->GetLink();
		}
		return st;

	}
	TList operator+ ( TList tmp)
	{
		string s1;
		
		TList res(tmp);
		
		TMonom* PCur = PFirst->GetLink();
		while (PCur != PFirst)
		{
			
			res.AddMonom(PCur->GetCoeff(),PCur->GetIndex());
			
			PCur = PCur->GetLink();
		}
		
		return res;
	}

};

