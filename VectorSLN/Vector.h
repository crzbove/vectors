#pragma once
#include <iostream>

class Vector
{
private:
	double* Coords;
	unsigned int CoordsCount;
public:
	Vector(double*, unsigned int);
	std::string ToString();
	friend Vector operator+ (const Vector leftOperand, const Vector rightOperand);
	friend Vector operator* (const Vector leftOperand, const Vector rightOperand);
	friend Vector operator- (const Vector leftOperand, const Vector rightOperand);
	friend Vector operator* (const int leftOperand, const Vector rightOperand);
	friend Vector operator* (const Vector leftOperand, const int rightOperand);
};

