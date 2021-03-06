// Lab_1_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;



struct NOTE {
	string name;
	string surname;
	int numPhone;
	int birthDay[3];
	NOTE* next;
	NOTE* prev;
};



class list {
private:
	NOTE* endList;
	NOTE* begList;
public:
	void add(string name, string surname, int numPhone, int* birthDay);
	void findMonth(int m);
	void remove(int num);
	list() :begList(NULL), endList(NULL) {};
	~list();
	void show();
};

void coutStruct(NOTE* a) {
	cout << "-------------------------" << endl;
	cout << a->name << " " << a->surname << endl;
	cout << a->numPhone << endl;
	cout << a->birthDay[0] << "." << a->birthDay[1] << "." << a->birthDay[2] << endl;
	cout << "-------------------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string tempName, tempSur;
	int sw1, tempPh, tempBd[3], tempMonth;
	list list1;
	while (true) {
		cout << "Меню:" << endl;
		cout << "1 - Добавить в список" << endl;
		cout << "2 - Вывести список" << endl;
		cout << "3 - Найти по месяцу" << endl;
		cout << "4 - Удалить из списка" << endl;
		cout << "5 - Выйти из программы" << endl;
		cin >> sw1;
		switch (sw1) {
		case 1:
			cout << "Введите имя: "; cin >> tempName;
			cout << "Введите фамилию: "; cin >> tempSur;
			cout << "Введите номер телефона: "; cin >> tempPh;
			cout << "Введите дату рождения: "; cin >> tempBd[0] >> tempBd[1] >> tempBd[2];
			list1.add(tempName, tempSur, tempPh, tempBd);
			break;
		case 2:
			list1.show();
			break;
		case 3:
			cout << "Введите месяц: "; cin >> tempMonth;
			list1.findMonth(tempMonth);
			break;
		case 4:
			cout << "Введите номер удаляемого: "; cin >> tempPh;
			list1.remove(tempPh);
			break;
		case 5:
			exit(0);
		default:
			cout << "Вы ввели неправильное значение!" << endl;
			break;
		}
	}
	return 0;
}

void list::add(string _name, string _surname, int _numPhone, int* _birthDay) {
	NOTE* pv = new NOTE;
	NOTE* pt = begList;
	pv->next = NULL;
	pv->name = _name;
	pv->surname = _surname;
	pv->numPhone = _numPhone;
	pv->birthDay[0] = _birthDay[0];
	pv->birthDay[1] = _birthDay[1];
	pv->birthDay[2] = _birthDay[2];
	if (begList == NULL) {
		pv->prev = NULL;
		begList = endList = pv;
	}
	else {
		while (pt) {
			if (pv->surname < pt->surname) {
				pv->next = pt;
				if (pt == begList) {
					pv->prev = NULL;
					begList = pv;
				}
				else {
					(pt->prev)->next = pv;
					pv->prev = pt->prev;
				}
				pt->prev = pv;
				return;
			}
			pt = pt->next;
		}
		pv->next = 0;
		pv->prev = endList;
		endList->next = pv;
		endList = pv;
	}
}

list::~list() {};

void list::show() {
	NOTE* temp = begList;
	while (temp != NULL) {
		coutStruct(temp);
		temp = temp->next;
	}
}

void list::findMonth(int m) {
	bool temp1 = false;
	NOTE* temp = begList;
	while (temp != NULL) {
		if (m == temp->birthDay[1]) {
			coutStruct(temp);
			temp1 = true;
		}
		temp = temp->next;
	}
	if (temp1 == false) {
		cout << "Людей, родившихся в этом месяце, не найдено!" << endl;
	}
}


void list::remove(int num) {
	bool temp1 = false;
	NOTE* temp = begList;
	while (temp != NULL) {
		if (num == temp->numPhone) {
			if ((temp == begList) && (temp != endList)) {
				(temp->next)->prev = NULL;
				begList = temp->next;
				delete(temp);
				temp1 = true;
				cout << "Удалено!" << endl;
				break;
			}
			else if ((temp == endList) && (temp != begList)) {
				(temp->prev)->next = NULL;
				endList = temp->prev;
				delete(temp);
				temp1 = true;
				cout << "Удалено!" << endl;
				break;
			}
			else if ((temp == endList) && (temp == begList)) {
				endList = NULL;
				begList = NULL;
				delete(temp);
				temp1 = true;
				cout << "Удалено!" << endl;
				break;
			}
			else {
				(temp->prev)->next = temp->next;
				(temp->next)->prev = temp->prev;
				delete(temp);
				temp1 = true;
				cout << "Удалено!" << endl;
				break;
			}
		}
		temp = temp->next;
	}
	if (temp1 == false) {
		cout << "Нет людей с таким номером телефона!" << endl;
	}
}