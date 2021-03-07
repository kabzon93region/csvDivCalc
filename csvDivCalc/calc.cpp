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
bool calc::adrAnalyse()
{

	return false;
}
//------------------------------------------


//------------------------------------------
void calc::getADRk()
{

}
//------------------------------------------


//------------------------------------------
bool calc::nalogAnalise()
{

	return false;
}
//------------------------------------------


//------------------------------------------
void calc::nalogCalc()
{

}
//------------------------------------------
