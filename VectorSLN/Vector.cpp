#include "Vector.h"
#include <string>

Vector::Vector(double* Coords, unsigned int CoordsCount)
{
	this->Coords = Coords;
	this->CoordsCount = CoordsCount;
}

Vector::Vector(Point pointA, Point pointB)
{
	if (pointA.PointCoordsCount == pointB.PointCoordsCount) {
		double* VectorCoords = new double[pointA.PointCoordsCount];

		for (int i = 0; i < pointA.PointCoordsCount; i++)
		{
			VectorCoords[i] = pointB.PointCoords[i] - pointA.PointCoords[i];
		}

		this->Coords = VectorCoords;
		this->CoordsCount = pointA.PointCoordsCount;
	}
}

std::string Vector::ToString()
{
	std::string result = "(";

	for (int i = 0; i < this->CoordsCount; i++)
	{
		result += std::to_string(this->Coords[i]) + "; ";
	}
	result += ")";

	return result;
}

double Vector::GetLength() {
	double result = 0.0;

	for (int i = 0; i < this->CoordsCount; i++)
	{
		result += this->Coords[i] * this->Coords[i];
	}

	return sqrt(result);
}

bool Vector::IsCollinearTo(Vector another)
{
	if (this->CoordsCount == another.CoordsCount) {
		double coef = this->Coords[0] / another.Coords[0];

		for (int i = 1; i < this->CoordsCount; i++)
		{
			if (this->Coords[i] / another.Coords[i] != coef) {
				return false;
			}
		}
		return true;
	}

	return false;
}

bool Vector::IsCodirectedTo(Vector another)
{
	return this->IsCollinearTo(another)
		&& (this->Coords[0] / another.Coords[0] > 0);
}

double Vector::FindCOSBetweenThisAnd(Vector another)
{
	return (*this * another) / (this->GetLength() * another.GetLength());
}

Vector operator+(Vector leftOperand, Vector rightOperand)
{
	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		leftOperand.Coords[i] += rightOperand.Coords[i];
	}
	return leftOperand;
}

Vector operator-(Vector leftOperand, Vector rightOperand)
{
	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		leftOperand.Coords[i] -= rightOperand.Coords[i];
	}
	return leftOperand;
}

Vector operator*(double leftOperand, Vector rightOperand)
{
	for (int i = 0; i < rightOperand.CoordsCount; i++)
	{
		rightOperand.Coords[i] *= leftOperand;
	}
	return rightOperand;
}

Vector operator*(Vector leftOperand, double rightOperand)
{
	return rightOperand * leftOperand;
}

// скал€рное произведение
double operator*(Vector leftOperand, Vector rightOperand)
{
	double result = 0.0;
	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		result += leftOperand.Coords[i] * rightOperand.Coords[i];
	}
	return result;
}

// TODO: векторное произведение
Vector operator&(Vector leftOperand, Vector rightOperand)
{
	return Vector();
}

// ѕо определению:
// ƒва вектора называютс€ равными тогда и только тогда, когда:
// 1) ќни имеют одинаковое число координат
// 2) —оответствующие координаты равны между собой.
bool operator==(Vector leftOperand, Vector rightOperand)
{
	if (leftOperand.CoordsCount != rightOperand.CoordsCount) {
		return false;
	}
	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		if (leftOperand.Coords[i] != rightOperand.Coords[i]) {
			return false;
		}
	}

	return true;
}

bool operator>(Vector leftOperand, Vector rightOperand)
{
	return leftOperand.GetLength() > rightOperand.GetLength();
}

bool operator>=(Vector leftOperand, Vector rightOperand)
{
	return leftOperand.GetLength() >= rightOperand.GetLength();
}

bool operator<(Vector leftOperand, Vector rightOperand)
{
	return leftOperand.GetLength() < rightOperand.GetLength();
}

bool operator<=(Vector leftOperand, Vector rightOperand)
{
	return leftOperand.GetLength() <= rightOperand.GetLength();
}
