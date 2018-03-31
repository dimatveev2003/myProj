#include "stdafx.h"
#include "rectangle.h"
#include <cmath>
#include <iostream>
using namespace std;
void rectangle::move(int* xy) {
	for (int i = 0; i < 2; i++) {
		dot_1[i] += xy[i];
		dot_2[i] += xy[i];
		dot_3[i] += xy[i];
		dot_4[i] += xy[i];
	}
}

double rectangle::square() {
	return  a * b;
}

void rectangle::culc_sides() {
	a = sqrt((dot_1[0] - dot_2[0])*(dot_1[0] - dot_2[0]) + (dot_1[1] - dot_2[1])*(dot_1[1] - dot_2[1]));
	b = sqrt((dot_2[0] - dot_3[0])*(dot_2[0] - dot_3[0]) + (dot_2[1] - dot_3[1])*(dot_2[1] - dot_3[1]));
	c = a;
	d = b;
}

double rectangle::perimetr() {
	return  2 * (a + b);
}

rectangle::rectangle(int* d1, int* d2, int* d3, int* d4, char* id1) : triangle(d1, d2, d3, id1) {
	for (int i = 0; i < 2; i++)
		dot_4[i] = d4[i];
}
rectangle::rectangle(){}


rectangle::rectangle(const rectangle& r1) {
	for (int i = 0; i < 2; i++) {
		this->dot_1[i] = r1.dot_1[i];
		this->dot_2[i] = r1.dot_2[i];
		this->dot_3[i] = r1.dot_3[i];
		this->dot_3[i] = r1.dot_4[i];
	}
	for (int i = 0; i < 10; i++) {
		this->id[i] = r1.id[i];
	}
	this->a = r1.a;
	this->b = r1.b;
	this->c = r1.c;
	this->d = r1.d;
}

void rectangle::print_coord() {
	cout << this->dot_1[0] << " ";
	cout << this->dot_1[1] << endl;
	cout << this->dot_2[0] << " ";
	cout << this->dot_2[1] << endl;
	cout << this->dot_3[0] << " ";
	cout << this->dot_3[1] << endl;
	cout << this->dot_4[0] << " ";
	cout << this->dot_4[1] << endl;
}