#include "stdafx.h"
#include "FigureFactory.h"


triangle* FigureFactory::create_triangle(int* d1, int* d2, int* d3, char* id1) {
	return new triangle(d1, d2, d3, id1);
}


rectangle* FigureFactory::create_rectangle(int* d1, int* d2, int* d3, int* d4, char* id1) {
	return new rectangle(d1, d2, d3, d4, id1);
}

/*void FigureFactory::delete_triangle(triangle& t1) {
	delete& t1;
}

void FigureFactory::delete_rectangle(rectangle& r1) {
	delete& r1;
}*/