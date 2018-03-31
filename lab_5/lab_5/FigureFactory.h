#pragma once
#include "triangle.h"
#include "rectangle.h"
class FigureFactory {
public:
	triangle* create_triangle(int* d1, int* d2, int* d3, char* id1);
	rectangle* create_rectangle(int* d1, int* d2, int* d3, int* d4, char* id1);
	/*void delete_triangle(triangle& t1);
	void delete_rectangle(rectangle& r1);*/
};