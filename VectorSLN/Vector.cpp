#include "Vector.h"

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
	if (pointA.PointCoordsCount != pointB.PointCoordsCount) {
		throw std::exception("Размерность должна быть одинаковой.");
	}

	double* VectorCoords = new double[pointA.PointCoordsCount];

	for (int i = 0; i < pointA.PointCoordsCount; i++)
	{
		VectorCoords[i] = pointB.PointCoords[i] - pointA.PointCoords[i];
	}

	this->Coords = VectorCoords;
	this->CoordsCount = pointA.PointCoordsCount;
}

//std::string Vector::ToString()
//{
//	std::string result = "(";
//
//	for (int i = 0; i < this->CoordsCount; i++)
//	{
//		result += std::to_string(this->Coords[i]) + "; ";
//	}
//	result += ")";
//
//	return result;
//}

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

double Vector::FindCOSBetweenThisAnd(Vector another)
{
	return (*this * another) / (this->GetLength() * another.GetLength());
}

double Vector::FindCosBetweenVectors(Vector a, Vector b)
{
	return a.FindCOSBetweenThisAnd(b);
}

// Проверка компланарности векторов
bool Vector::CheckVectorsCoplanarity(Vector a, Vector b, Vector c)
{
	return VectorsMixedProduct(a, b, c) == 0;
}

// Смешанное произведение
double Vector::VectorsMixedProduct(Vector a, Vector b, Vector c)
{
	return a * (b & c);
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	out << "(";

	for (int i = 0; i < vector.CoordsCount; i++)
	{
		out << vector.Coords[i];
		if (i != vector.CoordsCount - 1) {
			out << "; ";
		}
	}
	out << ")";

	return out;
}

Vector operator+(Vector leftOperand, Vector rightOperand)
{
	if (leftOperand.CoordsCount != rightOperand.CoordsCount) {
		throw std::exception("Разные размерности векторов.");
	}

	double* newCoords = new double[leftOperand.CoordsCount];

	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		newCoords[i] = leftOperand.Coords[i] + rightOperand.Coords[i];
	}
	return Vector(newCoords, leftOperand.CoordsCount);
}

Vector operator-(Vector leftOperand, Vector rightOperand)
{
	if (leftOperand.CoordsCount != rightOperand.CoordsCount) {
		throw std::exception("Разные размерности векторов.");
	}

	double* newCoords = new double[leftOperand.CoordsCount];

	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		newCoords[i] = leftOperand.Coords[i] - rightOperand.Coords[i];
	}
	return Vector(newCoords, leftOperand.CoordsCount);
}

Vector operator-(Vector operand)
{
	double* newCoords = new double[operand.CoordsCount];

	for (int i = 0; i < operand.CoordsCount; i++)
	{
		newCoords[i] = -operand.Coords[i];
	}

	return Vector(newCoords, operand.CoordsCount);
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

// Скалярное произведение
double operator*(Vector leftOperand, Vector rightOperand)
{
	if (leftOperand.CoordsCount != rightOperand.CoordsCount) {
		throw std::exception("Разные размерности векторов.");
	}

	double result = 0.0;
	for (int i = 0; i < leftOperand.CoordsCount; i++)
	{
		result += leftOperand.Coords[i] * rightOperand.Coords[i];
	}
	return result;
}

// Векторное произведение (по определению, только для 3х мерного пространства)
Vector operator&(Vector leftOperand, Vector rightOperand)
{
	if ((leftOperand.CoordsCount == rightOperand.CoordsCount) && leftOperand.CoordsCount != 3) {
		throw std::exception("Только для трёхмерных вектров.");
	}

	double* newCoords = new double[leftOperand.CoordsCount];
	double** intermediateCalcs = new double* [leftOperand.CoordsCount - 1];

	for (int i = 0; i < leftOperand.CoordsCount - 1; i++)
	{
		intermediateCalcs[i] = new double[leftOperand.CoordsCount - 1];
	}

	int minor = 0;
	for (size_t j = 0; j < leftOperand.CoordsCount; j++) // количество миноров
	{
		int idx = 0;
		for (size_t i = 0; i < leftOperand.CoordsCount; i++)
		{
			if (i != minor) {
				intermediateCalcs[0][idx] = leftOperand.Coords[i];
				intermediateCalcs[1][idx] = rightOperand.Coords[i];
				idx++;
			}
		}
		minor++;
		newCoords[j] = pow(-1.0, (2 + j)) * Vector::FindMatrixDeterminant(intermediateCalcs, leftOperand.CoordsCount - 1);
	}

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