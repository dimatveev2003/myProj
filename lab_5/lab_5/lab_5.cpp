// lab_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FigureFactory.h"
#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

int compare_s(double s1, double s2) {
	if (s1 > s2)
		return 1;
	else if (s2 > s1)
		return 2;
	else
		return 0;
}




int main()
{
	setlocale(LC_ALL, "Russian");
	triangle tmass[5];
	rectangle rmass[5];

	int d1[2], d2[2], d3[2], d4[2], xy_move[2];
	int choice, tcount = 0, rcount = 0;
	char id[10];
	FigureFactory creator;
	while (true) {
		cout << "1 - Создать треугольник" << endl;
		cout << "2 - Создать прямоугольник" << endl;
		cout << "3 - Переместить треугольник" << endl;
		cout << "4 - Переместить прямоугольник" << endl;
		cout << "5 - Удалить треугольник" << endl;
		cout << "6 - Удалить прямоугольник" << endl;
		cout << "7 - Сравнить площади двух фигур" << endl;
		cout << "8 - Выйти из программы" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите последовательно координаты точек треугольника" << endl;
			for (int i = 0; i < 2; i++) {
				cin >> d1[i];
				cin >> d2[i];
				cin >> d3[i];
			}
			cout << "Введите уникальный идентификатор фигуры длинной до 10 символов" << endl;
			cin >> id;
			tcount++;
			tmass[tcount - 1] = *creator.create_triangle(d1, d2, d3, id);
			break;
		case 2:
			cout << "Введите последовательно координаты точек прямоугольника" << endl;
			for (int i = 0; i < 2; i++) {
				cin >> d1[i];
				cin >> d2[i];
				cin >> d3[i];
				cin >> d4[i];
			}
			cout << "Введите уникальный идентификатор фигуры длинной до 10 символов" << endl;
			cin >> id;
			rcount++;
			rmass[rcount - 1] = *creator.create_rectangle(d1, d2, d3, d4, id);
			break;
		case 3:
			cout << "Введите смещение по оси х и у" << endl;
			cin >> xy_move[0];
			cin >> xy_move[1];
			cout << "Введите id треугольника, который хотите переместить "; cin >> id;
			for (int i = 0; i < 5; i++) {
				if (strcmp(tmass[i].get_id(), id) == 0) {
					tmass[i].move(xy_move);
					tmass[i].print_coord();
					break;
				}
			}
			break;
		case 4:
			cout << "Введите смещение по оси х и у" << endl;
			cin >> xy_move[0];
			cin >> xy_move[1];
			cout << "Введите id прямоугольника, который хотите переместить "; cin >> id;
			for (int i = 0; i < 5; i++) {
				if (strcmp(rmass[i].get_id(), id) == 0) {
					rmass[i].move(xy_move);
					rmass[i].print_coord();
					break;
				}
			}
			break;
		case 5:
			cout << "Введите id треугольника, который хотите удалить "; cin >> id;
			for (int i = 0; i < 5; i++) {
				if (strcmp(tmass[i].get_id(), id) == 0) {
					tcount -= 1;
					if (i < 4) {
						for (int j = i; j < 4; j++) {
							swap(tmass[j], tmass[j + 1]);
						}
					}
				}
			}
			break;
		case 6:
			cout << "Введите id прямоугольника, который хотите удалить "; cin >> id;
			for (int i = 0; i < 5; i++) {
				if (strcmp(rmass[i].get_id(), id) == 0) {
					rcount -= 1;
					if (i < 4) {
						for (int j = i; j < 4; j++) {
							swap(rmass[j], rmass[j + 1]);
						}
					}
				}
			}
			break;
		case 7:
			cout << compare_s(tmass[0].square(), rmass[0].square()) << endl;
			break;
		case 8:
			exit(0);
		default:
			cout << "Вы ввели неправильное значение!" << endl;
			break;
		}
	}
    return 0;
}

