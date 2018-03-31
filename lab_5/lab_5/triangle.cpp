#include "stdafx.h"
#include "triangle.h"
#include <cmath>
#include <iostream>
using namespace std;
void triangle::move(int* xy) {
	for (int i = 0; i < 2; i++) {
		dot_1[i] += xy[i];
		dot_2[i] += xy[i];
		dot_3[i] += xy[i];
	}
}

double triangle::perimetr() {
	p = a + b + c;
	return a + b + c;
}

double triangle::square() {
	culc_sides();
	perimetr();
	s = sqrt(p / 2 * (p / 2 - a)*(p / 2 - b)*(p / 2 - c));
	return sqrt(p / 2 * (p / 2 - a)*(p / 2 - b)*(p / 2 - c));
}

void triangle::culc_sides() {
	a = sqrt((dot_1[0] - dot_2[0])*(dot_1[0] - dot_2[0]) + (dot_1[1] - dot_2[1])*(dot_1[1] - dot_2[1]));
	b = sqrt((dot_2[0] - dot_3[0])*(dot_2[0] - dot_3[0]) + (dot_2[1] - dot_3[1])*(dot_2[1] - dot_3[1]));
	c = sqrt((dot_1[0] - dot_3[0])*(dot_1[0] - dot_3[0]) + (dot_1[1] - dot_3[1])*(dot_1[1] - dot_3[1]));
}

triangle::triangle(int* d1, int* d2, int* d3, char* id1) {
	for (int i = 0; i < 2; i++) {
		dot_1[i] = d1[i];
		dot_2[i] = d2[i];
		dot_3[i] = d3[i];
	}
	for (int i = 0; i < 10; i++) {
		id[i] = id1[i];
	}
	culc_sides();
}

triangle::triangle(){}

triangle::triangle(const triangle& t1) {
	for (int i = 0; i < 2; i++) {
		this->dot_1[i] = t1.dot_1[i];
		this->dot_2[i] = t1.dot_2[i];
		this->dot_3[i] = t1.dot_3[i];
	}
	for (int i = 0; i < 10; i++) {
		this->id[i] = t1.id[i];
	}
	this->a = t1.a;
	this->b = t1.b;
	this->c = t1.c;

}

char* triangle::get_id() {
	return this->id;
}

void triangle::print_coord() {
	cout << this->dot_1[0] << " ";
	cout << this->dot_1[1] << endl;
	cout << this->dot_2[0] << " ";
	cout << this->dot_2[1] << endl;
	cout << this->dot_3[0] << " ";
	cout << this->dot_3[1] << endl;
}