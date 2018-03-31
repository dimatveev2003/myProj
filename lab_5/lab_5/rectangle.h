#pragma once
#include "triangle.h"

class rectangle : public triangle {
protected:
	int dot_4[2];
	double d;
public:
	rectangle();
	rectangle(const rectangle& r1);
	rectangle(int* d1, int* d2, int* d3, int* d4, char* id1);
	void move(int* xy);
	double square();
	double perimetr();
	void culc_sides();
	void print_coord();
};