#pragma once
#include <iostream>

struct Point {
	int PointCoordsCount;
	double* PointCoords;
};

class Vector
{
protected:
	double* Coords = nullptr;
	unsigned int CoordsCount = 0;
public:
	Vector();
	Vector(double*, unsigned int);
	Vector(Point, Point);
	std::string ToString();

	// TODO: смешанное произведение

	double GetLength();

	bool IsCollinearTo(Vector another);
	bool IsCodirectedTo(Vector another);
	bool IsOrtogonalTo(Vector another);
	bool IsComplanarTo(Vector another);

	double FindCOSBetweenThisAnd(Vector another);
	
	friend Vector operator+ (Vector leftOperand, Vector rightOperand);
	friend Vector operator- (Vector leftOperand, Vector rightOperand);
	friend Vector operator* (double leftOperand, Vector rightOperand);
	friend Vector operator* (Vector leftOperand, double rightOperand);

	// скалярное произведение
	friend double operator* (Vector leftOperand, Vector rightOperand);

	// векторное произведение
	friend Vector operator& (Vector leftOperand, Vector rightOperand);

	// проверка равенства строго по определению (см Vector.cpp)
	friend bool operator== (Vector leftOperand, Vector rightOperand);

	// проверка по длине
	friend bool operator> (Vector leftOperand, Vector rightOperand);

	// проверка по длине
	friend bool operator>= (Vector leftOperand, Vector rightOperand);

	// проверка по длине
	friend bool operator< (Vector leftOperand, Vector rightOperand);

	// проверка по длине
	friend bool operator<= (Vector leftOperand, Vector rightOperand);


	// нахождение определителя матрицы
	double FindMatrixDeterminant(double** mainMatrix, int size);
};
