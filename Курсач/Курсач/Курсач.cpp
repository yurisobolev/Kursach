#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;
int NN = 0;
string FileName;
struct Human {
	string name1{}, name2{}, name3{};
	int rozhd1 = 0, rozhd2 = 0, rozhd3 = 0;
	int postup = 0;
	string kafedra{};
	string groupe{};
	string zachetka{};
	char pol{};
	string Predmet[90]{};
	int ozenka[90]{};
	int Ses_count = 0;
};
class File {
private:
	string dat = ".dat";
	string put;
	void FIRST() {
		cout << "Введите название файла (пробел запрещён): ";
		cin >> FileName;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		FileName = FileName + dat;
		ofstream fout;
		fout.open(FileName);
		if (fout.is_open()) {
			cout << "(" << FileName << ") создан успешно!" << endl;
		}
		else {
			cout << "!!Ошибка! Файл (" << FileName << ") не может быть создан!!" << endl;
			cout << "!!Перезапустите программу!!" << endl;
			exit(0);
		}
		fout.close();
	}
	int FIRST_R() {
		cout << "Введите название файла (не указывая тип .dat): ";
		cin >> FileName;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		FileName = FileName + dat;
		ifstream fin;
		fin.open(FileName);
		if (fin.is_open()) {
			system("cls");
			string str;
			while (!fin.eof()) {
				str = "";
				getline(fin, str);
				cout << str << endl;
			}
		}
		else {
			cout << "!!Ошибка! Файл (" << FileName << ") не может быть открыт!!" << endl;
			cout << "!!Пропишите путь в ручную!!" << endl;
			return true;
		}
		fin.close();
		return false;
	}
	int FIRST_E() {
		cout << "Введите название файла (не указывая тип .dat): ";
		cin >> FileName;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		FileName = FileName + dat;
		ifstream fin;
		fin.open(FileName);
		if (fin.is_open()) {
			fin.close();
			start();
		}
		else {
			cout << "!!Ошибка! Файл (" << FileName << ") не может быть открыт!!" << endl;
			cout << "!!Пропишите путь в ручную!!" << endl;
			return true;
		}
		fin.close();
		return false;
	}
public:
	void start() {
		ifstream fin;
		fin.open(FileName);
		if (fin.is_open()) {
			char ch;
			while (fin.get(ch)) {
				if (ch == '№') {
					NN = NN + 1;
				}
			}
			fin.close();
		}
		else {
			cout << "!!Ошибка! Файл (" << FileName << ") не может быть открыт!!" << endl;
			cout << "!!Перезапустите программу!!" << endl;
			exit(0);
		}
	}
	void E(Human& arr, int i) {
		ifstream fin;
		fin.open(FileName);
		if (fin.is_open()) {
			string str;
			string str1;
			int PROV = 0;
			int l = 0;
			int ii = 0;
			int k = 0;
			int k1 = 0;
			char ch;
			int d1 = 0;
			while (!fin.eof()) {
				if ((i != 0) && (l == 0)) {
					while (!fin.eof()) {
						if (l < i) {
							fin >> str;
							if (str == "====================================================================") {
								l++;
							}
						}
						else { break; }
					}
				}
				str = "";
				fin >> str;
				if (str == "Имя:") {
					if (PROV != 0) {
						goto EXIT;
					}
					PROV++;
					fin >> str1;
					arr.name1 = str1;
				}
				if (str == "Фамилия:") {
					fin >> str1;
					arr.name2 = str1;
				}
				if (str == "Отчество:") {
					fin >> str1;
					arr.name3 = str1;
				}
				if (str == "Дата") {
					fin >> str1;
					int c1 = 0;
					while (fin.get(ch)) {
						for (int ii = 48; ii < 58; ii++) {
							if (ch == ' ') {
								break;
							}
							if (ch == (char)ii) {
								if (c1 != 0) {
									d1 = d1 * 10;
								}
								d1 = d1 + ((int)ii - (int)'0');
								c1++;
								break;
							}
							else if (ch == (char)46) {
								arr.rozhd1 = d1;
								c1 = 0;
								d1 = 0;
								while (fin.get(ch)) {
									for (int iii = 48; iii < 58; iii++) {
										if (ch == (char)iii)
										{
											if (c1 != 0) {
												d1 = d1 * 10;
											}
											d1 = d1 + ((int)iii - (int)'0');
											c1++;
											break;
										}
										else if (ch == (char)46) {
											arr.rozhd2 = d1;
											c1 = 0;
											d1 = 0;
											while (fin.get(ch)) {
												if (ch == '\n') {
													arr.rozhd3 = d1;
													goto YEAR;
												}
												for (int i4 = 48; i4 < 58; i4++) {
													if (ch == (char)i4) {
														if (c1 != 0) {
															d1 = d1 * 10;
														}
														d1 = d1 + ((int)i4 - (int)'0');
														c1++;
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			YEAR:
				if (str == "Год") {
					d1 = 0;
					int c1 = 0;
					fin >> str;
					while (fin.get(ch)) {
						for (int i5 = 48; i5 < 58; i5++) {
							if (ch == ' ') {
								break;
							}
							if (ch == (char)i5) {
								if (c1 != 0) {
									d1 = d1 * 10;
								}
								d1 = d1 + ((int)i5 - (int)'0');
								c1++;
								break;
							}
							if (ch == '\n') {
								arr.postup = d1;
								goto YEAR;
							}
						}
					}
				}
				if (str == "Факультет-кафедра:") {
					fin >> str1;
					arr.kafedra = str1;
				}
				if (str == "Группа:") {
					fin >> str1;
					arr.groupe = str1;
				}
				if (str == "Номер") {
					fin >> str1;
					fin >> str1;
					fin >> str1;
					arr.zachetka = str1;
				}
				if (str == "Пол:") {
					while (fin.get(ch)) {
						if ((ch == (char)77) || (ch == (char)109 || ch == (char)204) || (ch == (char)236))
						{
							ch = 'м';
							arr.pol = ch;
							break;
						}
						if ((ch == (char)87) || (ch == (char)119) || (ch == (char)198) || (ch == (char)230))
						{
							ch = 'ж';
							arr.pol = ch;
							break;
						}
					}
				}
				if ((str == "Это") || (str == "сессия")) {
					d1 = 0;
					int c1 = 0;
					k = 0;
					k1 = 0;
					int A = 0;
					while (fin.get(ch)) {
						for (int i = 48; i < 58; i++) {
							if (ch == ' ') {
								break;
							}
							if (ch == '(') {
								break;
							}
							if (ch == (char)i) {
								d1 = (d1 + ((int)i - (int)'0')) - 1;
								arr.Ses_count = d1 + 1;
								goto Predmet;
							}
						}
					}
				Predmet:
					fin >> str;
					if (str == ")") {
						fin >> str;
					}
					if (str == "Оценка") {
						while (fin.get(ch)) {
							str1 = "";
							if (ch == '(') {
								while (fin.get(ch)) {
									if (ch == ')') {
										A = (d1 * 10) + k;
										arr.Predmet[A] = str1;
										k++;
										goto Mark;
									}
									str1 = str1 + ch;
								}
							}
						}
					Mark:int M = 0;
						while (fin.get(ch)) {
							for (int i = 48; i < 58; i++) {
								if (ch == '\n') {
									goto Predmet;
								}
								if ((ch == ' ') || (ch == ':')) {
									break;
								}
								if (ch == (char)i) {
									M = (int)i - (int)'0';
									A = (d1 * 10) + k1;
									arr.ozenka[A] = M;
									k1++;
									break;
								}
							}
						}
					}
				}
				if (str == "====================================================================") {
					if (i == ii) {
					EXIT:
						break;
					}
					ii++;
				}
			}
		}
		else {
			cout << "!!Файл не найден!!" << endl;

		}
		fin.close();
	}
	void EditerFile() {
		cout << "1- воспользоваться автоматическим поиском файла\n2- в ручную прописать местонахождение файла" << endl;
		int vubor; Repeat: cout << "::"; cin >> vubor;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		switch (vubor)
		{
		case(1): {
			if (FIRST_E());
			break;
		}
			   break;
		}
	}
	void AddFile(Human& arr, int i);
	void ReadFile() {
		cout << "1- воспользоваться автоматическим поиском файла\n2- в ручную прописать местонахождение файла" << endl;
		int vubor; Repeat: cout << "::"; cin >> vubor;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		switch (vubor)
		{
		case(1): {
			if (FIRST_R());
			break;
		}
			   break;
		}
	}
	void CreaterFile() {
		cout << "::Программа работает по принципу паралельного сохранения в файл::" << endl;
		cout << "Выберите место сохранения:" << endl;
		cout << "1- путь по умолчанию" << endl;
		int vubor; Repeat:cout << "::"; cin >> vubor;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		switch (vubor)
		{
		case(1): {
			FIRST();
			break;
		}

		}
	}
	void DeleteFile1() {
		ofstream fout;
		fout.open(FileName);
		fout.close();
	}
};

class Helper2 {
private:
	string* zachetki = new string[NN];
public:
	~Helper2() { delete[] zachetki; cout << "Память очищена! Утечка памяти предотвращена!" << endl; }
	string zachetka(string vvod, int i) {
		for (int j = 0; j < i; j++) {
			if (vvod == zachetki[j]) {
				cout << "!!Зачётка совпадает с (" << j + 1 << ") студентом!!" << endl;
				cout << "!!Похоже, вы написали информацию о 2 одинаковых студентах!!" << endl;
				cout << "!!Вам прийдётся переписать данные этого студента!!" << endl;
				vvod = "false"; return vvod;
			}
		}
		zachetki[i] = vvod;
		return vvod;
	}
	int zachetka1(string vvod, int i) {
		for (int j = 0; j < i; j++) {
			if (vvod == zachetki[j]) {
				cout << "!!Зачётка (" << i << ") студента совпадает с зачёткой (" << j + 1 << ") студентом!!" << endl;
				cout << "!!Такого не может быть, вам придётся переписать (" << i + 1 << ") студента!!" << endl;
				return i;
			}
		}
		return 0;
	}
	void SaveZ(Human& arr, int i) {
		zachetki[i] = arr.zachetka;
	}
};
class Message {
private:
	int DAY(int vvod) {
		if ((vvod <= 31) && (vvod >= 1)) {
			return true;
		}
		cout << "!!Вы ввели недопустимое значение!!" << endl;
		cout << "!!Введите (1-31)!!" << endl;
		return false;
	}
	int MONTH(int vvod) {
		if ((vvod <= 12) && (vvod >= 1)) {
			return true;
		}
		cout << "!!Вы ввели недопустимое значение!!" << endl;
		cout << "!!Введите (1-12)!!" << endl;
		return false;
	}
	int YEAR(int vvod) {
		if ((vvod > 999)) {
			return true;
		}
		cout << "!!Вы ввели недопустимое значение!!" << endl;
		return false;
	}
	int Student() {
		cout << "!!Вы ввели недопустимое количество студентов!!" << endl;
		cout << "!!Введите его занаво!!" << endl;
		return 0;
	}
	friend class Helper;
};
class Helper : public Message {
public:
	int CheckS() {
		int vvod;
		if (cin >> vvod) {
			if ((vvod > 0) && (vvod < 10)) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				_flushall();
				return vvod;
			}
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			_flushall();
			vvod = 0;
			return vvod;
		}
		else if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			_flushall();
			vvod = 0;
			return vvod;
		}
		vvod = 0;
		return vvod;
	}
	int CheckS(int vvod) {
		if (vvod < 1) {
			cout << "!!Вы ввели недопустимое значение (1-9)!!" << endl;
			cout << "!!Введите количество заново!!" << endl;
			return false;
		}
		return vvod;
	}
	int CheckM() {
		int vvod;
		if (cin >> vvod) {
			if ((vvod > 0) && (vvod < 6)) {
				return vvod;
			}
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			vvod = 0;
			return vvod;
		}
		else if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			_flushall();
			vvod = 0;
			return vvod;
		}
		vvod = 0;
		return vvod;
	}
	int CheckM(int vvod) {
		if (vvod < 1) {
			cout << "!!Вы ввели недопустимое значение (1-5)!!" << endl;
			cout << "!!Введите оценку заново!!" << endl;
			return false;
		}
		return vvod;
	}
	int Check1() {
		int vvod;
		if (cin >> vvod) {
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			return vvod;
		}
		else if (cin.fail()) {
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			vvod = 0;
			return vvod;
		}
		return vvod;
	}
	int Check1(int vvod, char v) {
		if (((v == 'D') && (vvod < 1)) || (v == 'D')) {
			if (!DAY(vvod)) {
				return false;
			}
			return vvod;
		}
		else if (((v == 'M') && (vvod < 1)) || (v == 'M')) {
			if (!MONTH(vvod)) {
				return false;
			}
			return vvod;
		}
		else if (((v == 'Y') && (vvod < 1)) || (v == 'Y')) {
			if (!YEAR(vvod)) {
				return false;
			}
			return vvod;
		}
		else if ((v == 'S') && (vvod < 1)) {
			Student();
			return false;
		}
		else if (vvod < 1) {
			cout << "!!Вы ввели недопустимое значение!!" << endl;
			cout << "!!Вам придётся переписать данные этого студента!!" << endl;
			return false;
		}
		return vvod;
	}
	int CheckCh() {
		char ch{ 2 };
		cin >> ch;
		if ((ch == (char)77) || (ch == (char)109 || ch == (char)204) || (ch == (char)236))
		{
			ch = 'м';
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			return ch;
		}
		if ((ch == (char)87) || (ch == (char)119) || (ch == (char)198) || (ch == (char)230))
		{
			ch = 'ж';
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			return ch;
		}
		ch = (char)48;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		cout << "!!Просилось ввести (м/ж) или (m/w)!!" << endl;
		cout << "!!Повторите ввод пола!!" << endl;
		return ch;
	}
};
class Enter {
public:
	void set(Human& arr, int i) {
		Helper H1;
		if (i == 0) {
			cout << "::Пожалуйста, не вводите лишних символов, для корректной работы программы (например пробелы)::" << endl;
			cout << "::Пробелы не будут сохранены::" << endl;
		}
		cout << "\nВведите имя (" << i + 1 << ") студента: ";
		cin >> arr.name1;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		cout << "Введите фамилию (" << i + 1 << ") студента: ";
		cin >> arr.name2;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		cout << "Введите отчество (" << i + 1 << ") студента: ";
		cin >> arr.name3;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		if (i == 0) {
			cout << "::Пожалуйста, вводите данные цифрами (целое число)::" << endl;
		}
	TRY_CHISL:
		cout << "Введите число когда родился (" << i + 1 << ") студент: ";
		arr.rozhd1 = H1.Check1();
		if ((arr.rozhd1 = H1.Check1(arr.rozhd1, 'D')) == false) {
			goto TRY_CHISL;
		}
	TRY_CHISL2:
		cout << "Введите месяц когда родился студент (" << i + 1 << ") студент: ";
		arr.rozhd2 = H1.Check1();
		if ((arr.rozhd2 = H1.Check1(arr.rozhd2, 'M')) == false) {
			goto TRY_CHISL2;
		}
	TRY_CHISL3:
		cout << "Введите год, когда был рождён (" << i + 1 << ") студент: ";
		arr.rozhd3 = H1.Check1();
		if (!H1.Check1(arr.rozhd3, 'Y')) {
			goto TRY_CHISL3;
		}
	TRY_CHISL4:
		cout << "Введите год поступления (" << i + 1 << ") студента в институт: ";
		arr.postup = H1.Check1();
		if (!H1.Check1(arr.postup, 'Y')) {
			goto TRY_CHISL4;
		}
		if (arr.postup <= arr.rozhd3 + 15) {
			cout << "!!Студент не может поступить в такое ранее время!!" << endl;
			goto TRY_CHISL4;
		}
		if (i == 0) {
			cout << "::Пробелы не будут сохранены (используйте \"-\" и \"_\")::" << endl;
		}
		cout << "Введите факультет-кафедру (" << i + 1 << ") студента: ";
		cin >> arr.kafedra;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		cout << "Введите группу (" << i + 1 << ") студента: ";
		cin >> arr.groupe;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		if (i == 0) {
			cout << "::Номер зачётной книжки не может повторяться::" << endl;
		}
		cout << "Введите номер зачётной книжки (" << i + 1 << ") студента: ";
		cin >> arr.zachetka;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
	AGAIN_POL:
		cout << "Введите пол (" << i + 1 << ") студента (м/ж) или (m/w): ";
		arr.pol = H1.CheckCh();
		if (arr.pol == (char)48) {
			goto AGAIN_POL;
		}
	TRY_SES:
		cout << "Введите количество сессий (" << i + 1 << ") студента (1-9): ";
		arr.Ses_count = H1.CheckS();
		if (!H1.CheckS(arr.Ses_count)) {
			goto TRY_SES;
		}
		if (i == 0) {
			cout << "::Если вы хотите завершить ввод оценок в данной сессии,::" << endl;
			cout << "::то введите \"0\" когда требуется ввести предмет::" << endl;
		}
		for (int k = 0; k < arr.Ses_count; k++) {
			k = k - 1;
		EXIT:
			k = k + 1;
			if (k >= arr.Ses_count) {
				goto FinishSes;
			}
			cout << "Это сессия (" << k + 1 << ")" << endl;
			for (int k1 = 0; k1 < 10; k1++) {
				int k2 = (k * 10) + k1;
				cout << "Введите предмет (" << k1 + 1 << "): ";

				cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
				getline(cin, arr.Predmet[k2]);
				if (arr.Predmet[k2] == "0") {
					goto EXIT;
				}
			TRY_MARK:
				cout << "Введите оценку по предмету (" << arr.Predmet[k2] << "): ";
				arr.ozenka[k2] = H1.CheckM();
				if (!H1.CheckM(arr.ozenka[k2])) {
					goto TRY_MARK;
				};
			}
		}
	FinishSes:
		cout << "\n______________________________________________" << endl;
	}
	void get(Human& arr, int i) {
		if (i != 0) { cout << "\n"; }
		cout << "================================№" << i + 1 << "==================================" << endl;
		if (i == 0) {
			cout << "::Номер студента (каким по счёту был введён) №" << i + 1 << "::" << endl;
		}
		cout << "Имя: " << arr.name1 << "\nФамилия: " << arr.name2 << "\nОтчество: " << arr.name3 << endl;
		cout << "Дата рождения: " << arr.rozhd1 << "." << arr.rozhd2 << "." << arr.rozhd3 << endl;
		cout << "Год посутпления: " << arr.postup << endl;
		cout << "Факультет-кафедра: " << arr.kafedra << endl;
		cout << "Группа: " << arr.groupe << endl;
		cout << "Номер зачётной книжки: " << arr.zachetka << endl;
		cout << "Пол: " << arr.pol << endl;
		cout << "Оценки: " << endl;
		for (int k = 0; k < arr.Ses_count; k++) {
			k = k - 1;
		EXIT:
			k = k + 1;
			if (k >= arr.Ses_count) {
				goto FinishSes;
			}
			cout << "Это сессия (" << k + 1 << ")" << endl;
			for (int k1 = 0; k1 < 10; k1++) {
				int k2 = (k * 10) + k1;
				if (arr.ozenka[k2] == 0) {
					goto EXIT;
				}
				cout << "Оценка по предмету (" << arr.Predmet[k2] << "): " << arr.ozenka[k2] << endl;
			}
		}
	FinishSes:
		cout << "====================================================================" << endl;
	}
};
void File::AddFile(Human& arr, int i) {
	ofstream fout;
	fout.open(FileName, ofstream::app);
	if (fout.is_open()) {
		if (i != 0) { fout << "\n"; }
		fout << "================================№" << i + 1 << "==================================" << endl;
		fout << "Имя: " << arr.name1 << "\nФамилия: " << arr.name2 << "\nОтчество: " << arr.name3 << endl;
		fout << "Дата рождения: " << arr.rozhd1 << "." << arr.rozhd2 << "." << arr.rozhd3 << endl;
		fout << "Год посутпления: " << arr.postup << endl;
		fout << "Факультет-кафедра: " << arr.kafedra << endl;
		fout << "Группа: " << arr.groupe << endl;
		fout << "Номер зачётной книжки: " << arr.zachetka << endl;
		fout << "Пол: " << arr.pol << endl;
		fout << "Оценки: " << endl;
		for (int k = 0; k < arr.Ses_count; k++) {
			k = k - 1;
		EXIT:
			k = k + 1;
			if (k >= arr.Ses_count) {
				goto FinishSes;
			}
			fout << "Это сессия (" << k + 1 << ")" << endl;
			for (int k1 = 0; k1 < 10; k1++) {
				int k2 = (k * 10) + k1;
				if (arr.ozenka[k2] == 0) {
					goto EXIT;
				}
				fout << "Оценка по предмету (" << arr.Predmet[k2] << "): " << arr.ozenka[k2] << endl;
			}
		}
	FinishSes:
		fout << "====================================================================" << endl;
	}
	else {
		cout << "!!Ошибка! Файл (" << FileName << ") не может быть открыт!!" << endl;
		cout << "!!Перезапустите программу!!" << endl;
		exit(0);
	}
	fout.close();
};
class Work {
public:
	Work() {};
	~Work() {};
	void Create() {
		system("cls");
		File F1;
		F1.CreaterFile();
	CREATE_AGAIN:
		cout << "Введите количество студентов: ";
		Helper H1;
		Enter Ent1;
		int N;
		N = H1.Check1();
		string v{};
		if (H1.Check1(N, 'S')) {
			Human* arr = new Human[N];
			NN = N;
			Helper2 H2;
			for (int i = 0; i < N; i++) {
			TryVvod:
				Ent1.set(arr[i], i);
				v = H2.zachetka(arr[i].zachetka, i);
				if (v == "false") {
					goto TryVvod;
				}
				F1.AddFile(arr[i], i);
			}
			system("cls");
			for (int i = 0; i < N; i++) {
				Ent1.get(arr[i], i);
			}
			delete[] arr;
		}
		else { goto CREATE_AGAIN; }
	}
	void Editore() {
		File F1;
		Enter Ent1;
		Helper H1;
		F1.EditerFile();
		Human* arr = new Human[NN];
		for (int i = 0; i < NN; i++) {
			F1.E(arr[i], i);
		}
	TRY_AGAIN1:
		cout << "Выберите действие:" << endl;
		cout << "1- Добавить студента/студентов." << endl;
		cout << "2- Изменить студента." << endl;
		cout << "3- Показать, что находится в файле." << endl;
		cout << "4- Показать информацию определённого студента." << endl;
		cout << "5- Выполнение варианта номер 81\n";
		cout << "6- Выйти из режима редактирования.\n::";
	TRY_VVOD:
		int n; cin >> n; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
		switch (n)
		{
		case(1): {
			system("cls");
		CREATE_AGAIN:
			cout << "Введите количество дополнительных студентов студентов: ";
			Helper H1;
			int N;
			N = H1.Check1();
			string v{};
			if (H1.Check1(N, 'S')) {
				N = NN + N;
				Human* arr1 = new Human[N];
				for (int i = 0; i < NN; i++) {
					arr1[i] = arr[i];
				}
				delete[] arr;
				int l = NN;
				NN = N;
				N = l;
				Human* arr = new Human[NN];
				for (int i = 0; i < NN; i++) {
					arr[i] = arr1[i];
				}
				delete[] arr1;
				Helper2 H2;
				for (int i = 0; i < N; i++) {
					H2.SaveZ(arr[i], i);
				}
				for (int i = N; i < NN; i++) {
				TryVvod2:
					Ent1.set(arr[i], i);
					v = H2.zachetka(arr[i].zachetka, i);
					if (v == "false") {
						goto TryVvod2;
					}
					F1.AddFile(arr[i], i);
				}
				system("cls");
				for (int i = 0; i < NN; i++) {
					Ent1.get(arr[i], i);
				}
			}
			else { goto CREATE_AGAIN; };
			break;
		}
		case(2): {
			system("cls");
			string v{};
			for (int i = 0; i < NN; i++) {
				Ent1.get(arr[i], i);
			}
		TRY_STUDENT:
			cout << "\nКакого студента вы хотите изменить? Введите его номер: ";
			cin >> n; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			if ((n > NN) || (n < 1)) {
				cout << "!!Введите (1-" << NN << ")!!" << endl;
				goto TRY_STUDENT;
			}
		TryVvod3:
			Helper2 H2;
			n = n - 1;
			Ent1.set(arr[n], n);
			v = H2.zachetka(arr[n].zachetka, n);
			if (v == "false") {
				goto TryVvod3;
			}
			cout << "Куда сохранить изменения?" << endl;
			cout << "1- В тот же файл\n2- В новый файл\n::";

			cin >> n; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			switch (n)
			{
			case(1): {
				F1.DeleteFile1();
				for (int i = 0; i < NN; i++) {
					F1.AddFile(arr[i], i);
				}
				break;
			}
			case(2): {
				system("cls");
				F1.CreaterFile();
				for (int i = 0; i < NN; i++) {
					F1.AddFile(arr[i], i);
				}
				break;
			}
			default: {
				cout << "!!Введите (1-2)!!" << endl;
				goto TRY_STUDENT;
				break; }
			}
			system("cls");
			for (int i = 0; i < NN; i++) {
				Ent1.get(arr[i], i);
			}
			break;
		}
		case(3): {
			system("cls");
			for (int i = 0; i < NN; i++) {
				Ent1.get(arr[i], i);
			}
			goto TRY_AGAIN1;
			break;
		}
		case(4): {
			system("cls");
		TRY_VVOD2:
			cout << "О каком студенте вы хотите получить информацию?\nВведите его номер:";
			cin >> n; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			n = n - 1;
			if ((n > NN) || (n < 0)) {
				cout << "!!Введите 1-" << NN << "!!" << endl;
				goto TRY_VVOD2;
			}
			Ent1.get(arr[n], n);
			break;
		}
		case(5): {
			system("cls");
			float kol_12345 = 0.0f;
			float summa = 0.0f;
			float* Prozent = new float[NN];
			int* id = new int[NN];
			int* Ses_count = new int[9];
			int kostil = -1;
			for (int i = 0; i < 9; i++) {
				Ses_count[i] = 0;
			}
			for (int i = 0; i < NN; i++) {
				id[i] = i;
			}
			cout << "Введите необходимые семестры по одному через Enter(для завершения введите 0) :" << endl;
			while (kostil != 0) {
				cin >> kostil;
				switch (kostil) {
				case 1: case 2: case 3: case 4: case 5: case 6:
				case 7: case 8: case 9: {
					if (Ses_count[kostil - 1] > 0) {
						cout << "Значение уже используется.Попробуйте другое." << endl;
						break;
					}
					Ses_count[kostil - 1]++;
					break;
				}
				case (0): {
					kostil = 0;
					break;
				}
				default: {
					cout << "!!Введите подходящее значение!!" << endl;
					break;
				}
				}
			}
			for (int i = 0; i < NN; i++)
			{
				for (int kost = 0; kost < 9; kost++) {
					if (Ses_count[i] == 1)
					{
						kol_12345 = 0;
						summa = 0;
						for (int k = (10 * i); k < (10 * (i +
							1)); k++) {
							if (arr[i].ozenka[k] !=
								0) {
								kol_12345++;
								summa +=
									arr[i].ozenka[k];
							}
						}
					}
				}
				Prozent[i] = summa / kol_12345;
			}
			int temp1;
			float temp;
			for (int i = 0; i < NN - 1; i++) {
				for (int j = 0; j < NN - i - 1; j++) {
					if (Prozent[j] > Prozent[j + 1]) {
						temp = Prozent[j];
						Prozent[j] = Prozent[j + 1];
						Prozent[j + 1] = temp;
						temp1 = id[j];
						id[j] = id[j + 1];
						id[j + 1] = temp1;
					}
				}
			}
			for (int i = NN - 1; i >= 0; i--) {
				Ent1.get(arr[id[i]], i);
			}
			cout <<
				"\n____________________________________________________________________" << endl;
		AGAIN_POL7:
			cout <<
				"____________________________________________________________________" << endl;
			cout << "Введите пол, по которому хотите сортировать список студетов(м / ж) или(m / w)\n::";
			char Pol = H1.CheckCh();
			if (Pol == (char)48) {
				goto AGAIN_POL7;
			}
			system("cls");
			bool TF = false;
			int k = 0;
			for (int i = 0; i < NN; i++) {
				TF = pol(arr[id[i]], Pol);
				if ((TF == true) && (Prozent[i] < 25)) {
					Ent1.get(arr[id[i]], k);
					k++;
				}
			}
			if (k == 0) {
				cout << "Таких студентов нет!" << endl;
			}
			cout <<
				"____________________________________________________________________" << endl;
		TRY_CHOOSE7:
			cout << "Куда сохранить изменения?" << endl;
			cout << "1- В тот же файл\n2- В новый файл\n::";
			cin >> n; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			TF = false;
			k = 0;
			switch (n)
			{
			case(1): {
				F1.DeleteFile1();
				for (int i = 0; i < NN; i++) {
					TF = pol(arr[id[i]], Pol);
					if (TF == true) {
						F1.AddFile(arr[i], k);
						k++;
					}
				}
				break;
			}
			case(2): {
				system("cls");
				F1.CreaterFile();
				for (int i = 0; i < NN; i++) {
					TF = pol(arr[id[i]], Pol);
					if (TF == true) {
						F1.AddFile(arr[i], k);
						k++;
					}
				}
				break;
			}
			default: {
				cout << "=================" << endl;
				cout << "!!Введите (1-2)!!" << endl;
				cout << "=================" << endl;
				goto TRY_CHOOSE7;
				break; }
			}
			delete[] Prozent;
			delete[] id;
			break;
		}
		case(6): {
			break;
		}
		default: {
			cout << "!!Ввелите 1-5!!" << endl;
			goto TRY_VVOD;
		}
		}
	}
	int pol(Human& arr, char ch) {
		if (arr.pol == ch) {
			return true;
		}
		else { return false; }
	}
};
class Programm {
public:
	void Start_Program() {
		File F1;
		Work W1;
		NN = 0;
	TRY_AGAIN1:
		cout << "\nДобро пожаловать в меню программы!\nВыберите нужный вам вариант работы:" << endl;
		cout << "1- Начало работы \"с чистого листа\" и последующем созданием файла." << endl;
		cout << "2- Редактирование файла." << endl;
		cout << "3- Выход из программы.\n::";
		int n;
		if (cin >> n) {
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			switch (n)
			{
			case(1): {
				cout << "Вы выбрали:" << endl;
				cout << "1- Начало работы \"с чистого листа\" и последующем созданием файла." << endl;
				cout << "Уверенны, что хотите выбрать этот режим работы? (1/0)\n:: ";
				cin >> n;
				if (n != 1) {
					goto TRY_AGAIN1;
				}
				else if (cin.fail()) {
					cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
					cout << "Введите (1/0)" << endl;
					goto TRY_AGAIN1;
				}

				W1.Create();
				break;
			}
			case(2): {
				cout << "Вы выбрали: " << endl;
				cout << "2- Редактирование файла." << endl;
				cout << "Уверенны, что хотите выбрать этот режим работы? (1/0)\n:: ";
				cin >> n;
				if (n != 1) {
					goto TRY_AGAIN1;
				}
				else if (cin.fail()) {
					cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
					cout << "Введите (1/0)" << endl;
					goto TRY_AGAIN1;
				}
				system("cls");
				W1.Editore();
				break; }
			case(3): {
				cout << "Вы выбрали: " << endl;
				cout << "3- Выход из программы." << endl;
				cout << "Уверенны, что хотите выйти? (1/0)\n:: ";
				cin >> n;
				if (n != 1) {
					goto TRY_AGAIN1;
				}
				else if (cin.fail()) {
					cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
					cout << "Введите (1/0)" << endl;
					goto TRY_AGAIN1;
				}
				exit(0);
			}
			default: {
				cout << "Введите (1-5)" << endl;
				goto TRY_AGAIN1;
				break;
			}
			}
		}
		else if (cin.fail()) {
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			cout << "Введите (1-5)" << endl;
			goto TRY_AGAIN1;
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
RESTART:
	Programm M1;
	M1.Start_Program();
	cout << "\n\nПерезапустить программу? (1/0)\n::";
	bool vubor; cin >> vubor; cin.clear(); cin.ignore(cin.rdbuf()->in_avail());	_flushall();
	if (vubor == true) {
		system("cls");
		goto RESTART;
	}
	system("pause");
	return 0;
}