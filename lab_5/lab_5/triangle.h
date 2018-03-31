#pragma once
class triangle{
protected:
	char id[10];
	int dot_1[2];
	int dot_2[2];
	int dot_3[2];
	double a, b, c, s, p;
public:
	triangle();
	triangle(const triangle& t1);
	triangle(int* d1, int* d2, int* d3, char* id1);//конструктор - задает координаты, вычисляет стороны, ищет периметр
	virtual void move(int* xy);//перемещает фигуру на координатной плоскости в форме x1+xy[0]...
	virtual double square();
	virtual double perimetr();
	virtual void culc_sides();
	char* get_id();
	virtual void print_coord();
};