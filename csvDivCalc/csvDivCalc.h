#pragma once


#include <iostream>
#include <fstream>
#include <string>
//#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;



/*
Дата фиксации реестра	01.01.2020
Дата выплаты			10.01.2020
тип выплаты				1
наименование цб			первая
исин					us123
страна эмитента			сша
количество бумаг		1
выплата на 1 бумагу		0,35
комиссия				0
налог					0.04
поулчено				0.31
валюта					usd
*/

//переменные сбора для данных
string dataReestra, pustota;
string dataViplai;
string tipViplati;
string naimenovanieBumagi;
string isin;
string stranaEmitenta;
string kolichestvoBumag;
string viplataNa1bumagu;
string komissia;
string nalog;
string polucheno;
string valuta;

string komADR;

int isklucheniaRaschotov[1000]{};


//переменные для конвертации
double kolvoCB, na1CB, komissiaADR, nalogUderjan, poluchenoItogo;
int typeDiv;


//переменные для работы
int iteral = 0, stroki = 0, kolvoStrokIskluchenia = 0;





















