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
	Vector(double*, unsigned int);
	Vector(Point, Point);
	std::string ToString();

	double GetLength();

	bool IsCollinearTo(Vector another);
	bool IsCodirectedTo(Vector another);

	double FindCOSBetweenThisAnd(Vector another);

	friend Vector operator+ (Vector leftOperand, Vector rightOperand);
	friend Vector operator- (Vector leftOperand, Vector rightOperand);
	friend Vector operator* (double leftOperand, Vector rightOperand);
	friend Vector operator* (Vector leftOperand, double rightOperand);

	// ��������� ������������
	friend double operator* (Vector leftOperand, Vector rightOperand);

	// ��������� ������������
	friend Vector operator& (Vector leftOperand, Vector rightOperand);

	// �������� ��������� ������ �� ����������� (�� Vector.cpp)
	friend bool operator== (Vector leftOperand, Vector rightOperand);

	// �������� �� �����
	friend bool operator> (Vector leftOperand, Vector rightOperand);

	// �������� �� �����
	friend bool operator>= (Vector leftOperand, Vector rightOperand);

	// �������� �� �����
	friend bool operator< (Vector leftOperand, Vector rightOperand);

	// �������� �� �����
	friend bool operator<= (Vector leftOperand, Vector rightOperand);
};