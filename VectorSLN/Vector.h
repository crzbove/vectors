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
	// нахождение определителя матрицы
	static double FindMatrixDeterminant(double** mainMatrix, int size);
public:
	Vector();
	Vector(double*, unsigned int);
	Vector(Point, Point);
	//std::string ToString();

	double GetLength();

	bool IsCollinearTo(Vector another);
	bool IsCodirectedTo(Vector another);
	bool IsOrtogonalTo(Vector another);

	double FindCOSBetweenThisAnd(Vector another);
	static bool CheckVectorsCoplanarity(Vector a, Vector b, Vector c);
	static double VectorsMixedProduct(Vector a, Vector b, Vector c);

	friend std::ostream& operator<< (std::ostream& out, const Vector& vector);

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
};
