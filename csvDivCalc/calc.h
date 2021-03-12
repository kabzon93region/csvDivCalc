#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class calc
{
public:

	//переменные для расчётов
	/*
	double Dkb, Dv1b, Dn0, Dn1, Dn2, Dp0, Dp1, Dp2;
	double Dnal0, Dnal10, Dnal15, Dnal20, Dnal25, Dnal2637, Dnal28, Dnal30, Dnal37;
	double Dsr0, Dsr10, Dsr15, Dsr20, sr25, Dsr2637, Dsr28, Dsr30, Dsr37;
	double Dcurrrent;
	*/

	
	static void okruglSDS(string &strDouble);
	static double okruglD(double doubleOkrugl);

	static bool kompensAnalise(string &d11, string &d21, string &t1, string &isin1, string &k1, string &v1b1, string &p1, string &d12, string &d22, string &t2, string &isin2, string &k2, string &v1b2, string &p2);
	static void kompensCalc(string &t1, string &k1, string &v1b1, string &n1, string &p1, string &t2, string &n2, string &p2);

	static bool adrAnalyse(string dr, string isin, string v1b, string adrDr[], string adrIsin[], string adrV1b[], int &adrKol);
	static void adrKomCalc(string &dr, string &isin, string &k, string &v1b, string &kom, string &nal, string &pol, string adrDr[], string adrIsin[], string adrV1b[], string adrKom[], int &adrKol, int stroka);

	static int nalogAnalise(double kol, double v1b, double nal, double pol, int stroka);
	static void nalogCalc();

};