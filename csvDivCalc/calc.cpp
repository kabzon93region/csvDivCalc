#include "calc.h"


//------------------------------------------
void calc::okruglSDS(string &strDoubleRef)
{
	cout << setprecision(16);

	double Dcurrent = stod(strDoubleRef, nullptr);

	Dcurrent = round(Dcurrent * 10000000000000000) / 10000000000000000;
	Dcurrent = round(Dcurrent * 1000000000000000) / 1000000000000000;
	Dcurrent = round(Dcurrent * 100000000000000) / 100000000000000;
	Dcurrent = round(Dcurrent * 10000000000000) / 10000000000000;
	Dcurrent = round(Dcurrent * 1000000000000) / 1000000000000;
	Dcurrent = round(Dcurrent * 100000000000) / 100000000000;
	Dcurrent = round(Dcurrent * 10000000000) / 10000000000;
	Dcurrent = round(Dcurrent * 1000000000) / 1000000000;
	Dcurrent = round(Dcurrent * 100000000) / 100000000;
	Dcurrent = round(Dcurrent * 10000000) / 10000000;
	Dcurrent = round(Dcurrent * 1000000) / 1000000;
	Dcurrent = round(Dcurrent * 100000) / 100000;
	Dcurrent = round(Dcurrent * 10000) / 10000;
	Dcurrent = round(Dcurrent * 1000) / 1000;
	Dcurrent = round(Dcurrent * 100) / 100;

	strDoubleRef = to_string(Dcurrent);

	return;
}
//------------------------------------------


//------------------------------------------
double calc::okruglD(double doubleOkrugl)
{
	cout << setprecision(16);

	double Dcurrent = doubleOkrugl;

	Dcurrent = round(Dcurrent * 10000000000000000) / 10000000000000000;
	Dcurrent = round(Dcurrent * 1000000000000000) / 1000000000000000;
	Dcurrent = round(Dcurrent * 100000000000000) / 100000000000000;
	Dcurrent = round(Dcurrent * 10000000000000) / 10000000000000;
	Dcurrent = round(Dcurrent * 1000000000000) / 1000000000000;
	Dcurrent = round(Dcurrent * 100000000000) / 100000000000;
	Dcurrent = round(Dcurrent * 10000000000) / 10000000000;
	Dcurrent = round(Dcurrent * 1000000000) / 1000000000;
	Dcurrent = round(Dcurrent * 100000000) / 100000000;
	Dcurrent = round(Dcurrent * 10000000) / 10000000;
	Dcurrent = round(Dcurrent * 1000000) / 1000000;
	Dcurrent = round(Dcurrent * 100000) / 100000;
	Dcurrent = round(Dcurrent * 10000) / 10000;
	Dcurrent = round(Dcurrent * 1000) / 1000;
	Dcurrent = round(Dcurrent * 100) / 100;

	doubleOkrugl = Dcurrent;

	return doubleOkrugl;
}
//------------------------------------------


//------------------------------------------
bool calc::kompensAnalise(string &d11, string &d21, string &t1, string &isin1, string &k1, string &v1b1, string &p1, string &d12, string &d22, string &t2, string &isin2, string &k2, string &v1b2, string &p2)
{
	if ( (d11 == d12) && (d21 != d22) && (t1 == t2) && (isin1 == isin2) && (k1 == k2) && (v1b1 == v1b2) && (p1 != p2) )
	{
		return true;
	}
	else
	{
		return false;
	}
}
//------------------------------------------


//------------------------------------------
void calc::kompensCalc(string &t1, string &k1, string &v1b1, string &n1, string &p1, string &t2, string &n2, string &p2)
{
	cout << setprecision(16);

	t1 = "3";
	t2 = "3";

	double Dkb, Dv1b, Dp0, Dp1, Dp2, Dn0, Dn1, Dn2;

	Dkb = stod(k1, nullptr);

	Dv1b = stod(v1b1, nullptr);

	Dp1 = stod(p1, nullptr);

	Dp2 = stod(p2, nullptr);

	Dn1 = stod(n1, nullptr);

	Dn2 = (Dp2 / 0.9) - Dp2;

	Dn2 = okruglD(Dn2);

	Dp0 = (Dkb*Dv1b);
	Dp0 = okruglD(Dp0);

	Dn0 = Dp0 / 10;
	Dn0 = okruglD(Dn0);

	Dn1 = Dn0 - Dn2;

	n1 = to_string(Dn1);

	n2 = to_string(Dn2);


	return;
}
//------------------------------------------


//------------------------------------------
bool calc::adrAnalyse(string dr, string isin, string v1b, string adrDr[], string adrIsin[], string adrV1b[], int &adrKol)
{
	for (size_t i = 0; i < adrKol; i++)
	{
		if ( (dr == adrDr[i]) && (isin == adrIsin[i]) && (v1b == adrV1b[i]) )
		{
			return true;
		}
	}

	return false;
}
//------------------------------------------


//------------------------------------------
void calc::adrKomCalc(string &dr, string &isin, string &k, string &v1b, string &kom, string &nal, string &pol, string adrDr[], string adrIsin[], string adrV1b[], string adrKom[], int &adrKol, int stroka)
{
	cout << setprecision(16);

	double Dkol = stod(k, 0);
	double Dv1b = stod(v1b, 0);
	double Dkom = stod(kom, 0);
	double Dnal = stod(nal, 0);
	double Dpol = stod(pol, 0);

	bool Bkom = false;
	if (Dkom > 0.00)
	{
		Bkom = true;
	}
	
	double *DadrKom = new double[adrKol];
	for (size_t i = 0; i < adrKol; i++)
	{
		if (i == 0)
		{
			DadrKom[i] = 0.00;
		}
		else
		{
			DadrKom[i] = stod(adrKom[i], 0);
		}
	}

	for (size_t i = 0; i < adrKol; i++)
	{
		if ((dr == adrDr[i]) && (isin == adrIsin[i]) && (v1b == adrV1b[i]))
		{
			Dkom = Dkol * DadrKom[i];
			Dkom = okruglD(Dkom);
		}
	}

	kom = to_string(Dkom);

	if (Bkom)
	{
		//если была уже указана комиссия изначально, отпрвляем на проверку ставки налога
		cout << "---" << nalogAnalise(Dkol, Dv1b, Dnal, Dpol, stroka) << endl;
	}
	else
	{
		cout << "---" << nalogAnalise(Dkol, Dv1b, (Dnal - Dkom), Dpol, stroka) << endl;
	}
}
//------------------------------------------


//------------------------------------------
int calc::nalogAnalise(double kol, double v1b, double nal, double pol, int stroka)
{
	cout << setprecision(16);

	int stavka[9];
	for (size_t i = 0; i < 9; i++)
	{
		stavka[i] = -1;
	}

	int srst = 0;

	double Dv0;
	double Dn10, Dn15, Dn20, Dn21, Dn25, Dn28, Dn30, Dn37;

	Dv0 = kol * v1b;
	Dv0 = okruglD(Dv0);


	//10p
	Dn10 = okruglD((Dv0 / 100) * 10);
	if ( (Dn10 == nal) || (Dn10 == nal - 0.01) || (Dn10 == nal + 0.01) )
	{
		stavka[0] = 10;
	}

	//15p
	Dn15 = okruglD((Dv0 / 100) * 15);
	if ( (Dn15 == nal) || (Dn15 == nal - 0.01) || (Dn15 == nal + 0.01))
	{
		stavka[1] = 15;
	}

	//20p
	Dn20 = okruglD((Dv0 / 100) * 20);
	if ( (Dn20 == nal) || (Dn20 == nal - 0.01) || (Dn20 == nal + 0.01))
	{
		stavka[2] = 20;
	}

	//21p
	Dn21 = okruglD((Dv0 / 100) * 21);
	if ( (Dn21 == nal) || (Dn21 == nal - 0.01) || (Dn21 == nal + 0.01))
	{
		stavka[3] = 21;
	}

	//25p
	Dn25 = okruglD((Dv0 / 100) * 25);
	if ( (Dn25 == nal) || (Dn25 == nal - 0.01) || (Dn25 == nal + 0.01))
	{
		stavka[4] = 25;
	}

	//28p
	Dn28 = okruglD((Dv0 / 100) * 28);
	if ( (Dn28 == nal) || (Dn28 == nal - 0.01) || (Dn28 == nal + 0.01))
	{
		stavka[5] = 28;
	}

	//30p
	Dn30 = okruglD((Dv0 / 100) * 30);
	if ( (Dn30 == nal) || (Dn30 == nal - 0.01) || (Dn30 == nal + 0.01))
	{
		stavka[6] = 30;
	}

	//37p
	Dn37 = okruglD((Dv0 / 100) * 37);
	if ( (Dn37 == nal) || (Dn37 == nal - 0.01) || (Dn37 == nal + 0.01))
	{
		stavka[7] = 37;
	}

	//0p
	if ( (0 == nal) || (0 == nal - 0.01) || (0 == nal + 0.01))
	{
		stavka[8] = 0;
	}

	//расчет корректности


	for (size_t i = 0; i < 9; i++)
	{
		if (stavka[i] != -1)
		{
			srst++;
		}
	}

	if (srst >> 1)
	{
		cout << "???: " << stroka << endl;
		return -1;
	}
	else
	{
		for (size_t i = 0; i < 9; i++)
		{
			if (stavka[i] != -1)
			{
				cout << "ставка в строке " << stroka << " равна " << stavka[i] << endl;
				return stavka[i];
			}
		}
	}
}
//------------------------------------------


//------------------------------------------
void calc::nalogCalc()
{
	cout << setprecision(16);

}
//------------------------------------------
