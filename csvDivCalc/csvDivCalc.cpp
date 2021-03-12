#include "csvDivCalc.h"
#include "calc.h"





//---------------------
//главная функция)
int main()
{

	setlocale(LC_ALL, "RU");
	cout << setprecision(16);

	//файловые переменные
	string ifn, ofn;

	cout << "Введите имя исходного файла (ту таблицу, которую из выгрузки сделали и сохранили как csv файл, вводит ьтолько имя файла без расширения .csv):" << endl;
	cin >> ifn;
	cout << endl << endl;

	cout << "Введите имя выходного файла (ту таблицу, которую программа сохранит как csv файл  после расчётов, вводить только имя файла без расширения .csv):" << endl;
	cin >> ofn;
	cout << endl << endl;
	   
	ifstream iFile(ifn + ".csv");
	ofstream oFile(ofn + ".csv");
	ifstream adrFile("adr.csv");


	   	 
		//проверяем успешность открытия файла выплат
		if (!iFile.is_open())
		{
			cout << "Обшибка: Файл выплат не открылся (T_T)" << endl;
			system("pause");
			return 1;
		}

		//проверяем успешность открытия файла расписок
		if (!adrFile.is_open())
		{
			cout << "Обшибка: Файл расписок не открылся (T_T)" << endl;
			system("pause");
			return 1;
		}

		
	//запрашиваем ввод количества строк для прокатки сбора данных из файла выплат
	cout << "Количество строк всего документа: ";
	cin >> stroki; 
	cout << endl;
	
	cout << "Количество строк для исключения при расчётах: ";
	cin >> kolvoStrokIskluchenia;
	cout << endl;

	int *strokiIskluchenia = new int[kolvoStrokIskluchenia];

		for (size_t i = 0; i < kolvoStrokIskluchenia; i++)
		{
			cout << "Номер " << i+1 << " строки в документе для исключения при расчётах: ";
			cin >> strokiIskluchenia[i];
			cout << endl;
		}




	//массивы данных в которые мы вносим данные из файла выплат
	string *dataReestraArray = new string [stroki];
	string *pustotaArray = new string[stroki];
	string *dataViplaiArray = new string[stroki];
	string *tipViplatiArray = new string[stroki];
	string *naimenovanieBumagiArray = new string[stroki];
	string *isinArray = new string[stroki];
	string *stranaEmitentaArray = new string[stroki];
	string *kolichestvoBumagArray = new string[stroki];
	string *viplataNa1bumaguArray = new string[stroki];
	string *komissiaArray = new string[stroki];
	string *nalogArray = new string[stroki];
	string *poluchenoArray = new string[stroki];
	string *valutaArray = new string[stroki];




	//запрашиваем количество строк в справочнике расписок
	cout << "Количество строк в справочнике расписок: ";
	cin >> adrStroki;
	cout << endl;

	   	  

	//массивы данных в которые вносится инфа из справочника комиссий расписок
	string *adrReestrArray = new string[adrStroki];
	string *adrNameArray = new string[adrStroki];
	string *adrIsinArray = new string[adrStroki];
	string *adrKommissiaArray = new string[adrStroki];
	string *adrViplataArray = new string[adrStroki];


		//запускаем цикл сбора данных из файла расписок
		iteral = 0;
		while (iteral < adrStroki)
		{
			getline(adrFile, adrReestrArray[iteral], ';');
			getline(adrFile, adrNameArray[iteral], ';');
			getline(adrFile, adrIsinArray[iteral], ';');
			getline(adrFile, adrKommissiaArray[iteral], ';');
			getline(adrFile, adrViplataArray[iteral], '\n');
			iteral++;
		}



		//запускаем цикл сбора данных из файла выплат
		iteral = 0;
		while(iteral < stroki)
		{
			getline(iFile, dataReestraArray[iteral], ';');

			getline(iFile, pustotaArray[iteral], ';');

			getline(iFile, dataViplaiArray[iteral], ';');

			getline(iFile, tipViplatiArray[iteral], ';');

			getline(iFile, naimenovanieBumagiArray[iteral], ';');

			getline(iFile, isinArray[iteral], ';');

			getline(iFile, stranaEmitentaArray[iteral], ';');

			getline(iFile, kolichestvoBumagArray[iteral], ';');

			getline(iFile, viplataNa1bumaguArray[iteral], ';');

			getline(iFile, komissiaArray[iteral], ';');

			getline(iFile, nalogArray[iteral], ';');

			getline(iFile, poluchenoArray[iteral], ';');

			getline(iFile, valutaArray[iteral], '\n');

			iteral++;
		}




		//отправляем на пересчёт значения из массивов
		iteral = 0;
		while (iteral < stroki)
		{
			
			//првоеряем на исключение текущую строку
			for (size_t i = 0; i < kolvoStrokIskluchenia; i++)
			{
				//cout << iteral << " првоеряем на исключение текущую строку" << endl;
				if (iteral == (strokiIskluchenia[i] - 1))
				{
					//cout << iteral << " найдена строка исключения: " << iteral << endl;
					goto endRaschet; // если номер текущей строки - 1 (то ест ьиндекс в массиве) списка исключений, то мы идем в конец цикла расчётов
				}

			}


			//првоеряем расписка ли это
			if (calc::adrAnalyse( dataReestraArray[iteral], isinArray[iteral], viplataNa1bumaguArray[iteral], adrReestrArray, adrIsinArray, adrViplataArray, adrStroki) == true)
			{
				//проводим рассчёт расписки по ссылкам/указателям
				calc::adrKomCalc( ref(dataReestraArray[iteral]), ref(isinArray[iteral]), ref(kolichestvoBumagArray[iteral]), ref(viplataNa1bumaguArray[iteral]), ref(komissiaArray[iteral]), ref(nalogArray[iteral]), ref(poluchenoArray[iteral]), adrReestrArray, adrIsinArray, adrViplataArray, adrKommissiaArray, adrStroki, iteral+1);
				goto endRaschet;
			}


			//првоеряем предыдущую строку на исключения
			for (size_t i = 0; i < kolvoStrokIskluchenia; i++)
			{
				//cout << iteral << " првоеряем предыдущую строку на исключения \t iteral -1: " << endl;
				if ( ((iteral -1) == (strokiIskluchenia[i] - 1)) && (iteral >> 0) )
				{
					//cout << iteral << " предыдущая строка есть в исключениях " << iteral - 1 << "\t strokiIskluchenia[i] - 1: " << strokiIskluchenia[i] - 1 << endl;
					goto startRaschet; // если номер текущей строки - 1 (то ест ьиндекс в массиве) то мы идем в конец цикла расчётов
				}
			}

			//проверка на компенс и его расчёт если да			
			if ( (calc::kompensAnalise(ref(dataReestraArray[iteral - 1]), ref(dataViplaiArray[iteral - 1]), ref(tipViplatiArray[iteral - 1]), ref(isinArray[iteral - 1]), ref(kolichestvoBumagArray[iteral - 1]), ref(viplataNa1bumaguArray[iteral - 1]), ref(poluchenoArray[iteral-1]), ref(dataReestraArray[iteral]), ref(dataViplaiArray[iteral]), ref(tipViplatiArray[iteral]), ref(isinArray[iteral]), ref(kolichestvoBumagArray[iteral]), ref(viplataNa1bumaguArray[iteral]), ref(poluchenoArray[iteral]))) == true)
			{
				//проводим расчёт обоих выплат связанных компенсом
				//cout << iteral << " найдена выплата с компенсом в стрках " << iteral-1 << " и " << iteral << endl;
				//cout << iteral << " проводим в них расчёт " << endl;
				calc::kompensCalc( ref(tipViplatiArray[iteral - 1]), ref(kolichestvoBumagArray[iteral - 1]), ref(viplataNa1bumaguArray[iteral - 1]), ref(nalogArray[iteral - 1]), ref(poluchenoArray[iteral - 1]), ref(tipViplatiArray[iteral]), ref(nalogArray[iteral]), ref(poluchenoArray[iteral]));
				//cout << iteral << " расчёт операций связанных компенсом завершон " << endl;
				goto endRaschet;
			}




		startRaschet:
			//расчет
			//calc::okruglSDS(ref(viplataNa1bumaguArray[iteral]));





		endRaschet:
			iteral++;
		}



		//проверяем успешность открытия итогового файла выплат
		if (!oFile.is_open())
		{
			cout << "Обшибка: Файл выплат не открылся (T_T)" << endl;
			system("pause");
			return 1;
		}


		//записываем в итоговый файл все массивы посмтрочно
		iteral = 0;
		while (iteral < stroki)
		{
			oFile << (dataReestraArray[iteral] + ";" + pustotaArray[iteral] + ";" + dataViplaiArray[iteral] +";" + tipViplatiArray[iteral] +";" + naimenovanieBumagiArray[iteral] +";" + isinArray[iteral] +";" + stranaEmitentaArray[iteral] +";" + kolichestvoBumagArray[iteral] +";" + viplataNa1bumaguArray[iteral] +";" + komissiaArray[iteral] +";" + nalogArray[iteral] +";" + poluchenoArray[iteral] +";" + valutaArray[iteral] + ";") << endl;
			iteral++;
		}





	//закрываем файлы
	iFile.close();
	oFile.close();
	adrFile.close();



	//system("pause");



	//очищаем динамические массивы
	delete[] adrReestrArray;
	delete[] adrNameArray;
	delete[] adrIsinArray;
	delete[] adrKommissiaArray;
	delete[] adrViplataArray;
	delete[] strokiIskluchenia;
	delete[] dataReestraArray;
	delete[] pustotaArray;
	delete[] dataViplaiArray;
	delete[] tipViplatiArray;
	delete[] naimenovanieBumagiArray;
	delete[] isinArray;
	delete[] stranaEmitentaArray;
	delete[] kolichestvoBumagArray;
	delete[] viplataNa1bumaguArray;
	delete[] komissiaArray;
	delete[] nalogArray;
	delete[] poluchenoArray;
	delete[] valutaArray;



	system("pause");
	return 0;
}
//---------------------