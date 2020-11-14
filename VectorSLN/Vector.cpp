#include "Vector.h"
#include <string>

Vector::Vector()
{
	Coords = nullptr;
	CoordsCount = 0;
}

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

bool Vector::IsOrtogonalTo(Vector another)
{
	return *this * another == 0;
}

// TODO: Проверка компланарности
bool Vector::IsComplanarTo(Vector another)
{
	return false;
}

double Vector::FindCOSBetweenThisAnd(Vector another)
{
	return (*this * another) / (this->GetLength() * another.GetLength());
}

Vector operator+(Vector leftOperand, Vector rightOperand)
{
	double* newCoords = new double[leftOperand.CoordsCount];

	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		newCoords[i] = leftOperand.Coords[i] + rightOperand.Coords[i];
	}
	return Vector(newCoords, leftOperand.CoordsCount);
}

Vector operator-(Vector leftOperand, Vector rightOperand)
{
	double* newCoords = new double[leftOperand.CoordsCount];

	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		newCoords[i] = leftOperand.Coords[i] - rightOperand.Coords[i];
	}
	return Vector(newCoords, leftOperand.CoordsCount);
}

Vector operator*(double leftOperand, Vector rightOperand)
{
	double* newCoords = new double[rightOperand.CoordsCount];

	for (int i = 0; i < rightOperand.CoordsCount; i++)
	{
		newCoords[i] = rightOperand.Coords[i] * leftOperand;
	}

	return Vector(newCoords, rightOperand.CoordsCount);
}

Vector operator*(Vector leftOperand, double rightOperand)
{
	return rightOperand * leftOperand;
}

// скалярное произведение
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
	double* newCoords = new double[leftOperand.CoordsCount];



	return Vector(newCoords, leftOperand.CoordsCount);
}

// По определению:
// Два вектора называются равными тогда и только тогда, когда:
// 1) Они имеют одинаковое число координат
// 2) Соответствующие координаты равны между собой.
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

double Vector::FindMatrixDeterminant(double** mainMatrix, int size)
{
	int i, j;

	double determinant = 0;
	double** newMatrix;

	if (size == 1)
	{
		determinant = mainMatrix[0][0];
	}
	else if (size == 2)
	{
		determinant = mainMatrix[0][0] * mainMatrix[1][1] - mainMatrix[0][1] * mainMatrix[1][0];
	}
	else
	{
		newMatrix = new double* [size - 1];
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size - 1; ++j)
			{
				if (j < i) {
					newMatrix[j] = mainMatrix[j];
				}
				else {
					newMatrix[j] = mainMatrix[j + 1];
				}
			}
			determinant += pow((double)-1, (i + j)) * FindMatrixDeterminant(newMatrix, size - 1) * mainMatrix[i][size - 1];
		}
		delete[] newMatrix;
	}
	return determinant;
}