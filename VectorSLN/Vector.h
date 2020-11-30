#pragma once
#include <iostream>

struct Point {
	unsigned int PointCoordsCount;
	double* PointCoords;
};

class Vector
{
protected:
	/// <summary>
	/// Массив с координатами вектора
	/// </summary>
	double* Coords = nullptr;

	/// <summary>
	/// Количество координат
	/// </summary>
	unsigned int CoordsCount = 0;

	/// <summary>
	/// Нахождение значения определителя матрицы
	/// </summary>
	/// <param name="mainMatrix">Квадратная матрица</param>
	/// <param name="size">Размерность квадратной матрицы</param>
	/// <returns>Значение определителя матрицы mainMatrix</returns>
	static double FindMatrixDeterminant(double** mainMatrix, int size);
public:
	/// <summary>
	/// Конструктор класса по умолчанию.
	/// </summary>
	Vector();

	/// <summary>
	/// Конструктор класса по координатам вектора.
	/// </summary>
	/// <param name="Coords">Массив с координатами вектора.</param>
	/// <param name="CoordsCount">Количество координат вектора.</param>
	Vector(double* Coords, unsigned int CoordsCount);

	/// <summary>
	/// Конструктор класса по точкам начала и конца вектора.
	/// </summary>
	/// <param name="pointA">Точка начала.</param>
	/// <param name="pointB">Точка конца.</param>
	Vector(Point pointA, Point pointB);
	//std::string ToString();

	/// <summary>
	/// Нахождение длины данного вектора
	/// </summary>
	/// <returns>Длина вектора</returns>
	double GetLength();

	/// <summary>
	/// Проверка коллинеарности вектора по отношению к заданному в аргументе.
	/// </summary>
	/// <param name="another">Вектор, по отношению к которому нужно проверить коллинеарность.</param>
	bool IsCollinearTo(Vector another);

	/// <summary>
	/// Проверка сонаправленности вектора по отношению к заданному в аргументе.
	/// </summary>
	/// <param name="another">Вектор, по отношению к которому нужно проверить сонаправленность.</param>
	bool IsCodirectedTo(Vector another);

	/// <summary>
	/// Проверка ортогональности вектора по отношению к заданному в аргументе.
	/// </summary>
	/// <param name="another">Вектор, по отношению к которому нужно проверить ортогональность.</param>
	bool IsOrtogonalTo(Vector another);

	/// <summary>
	/// Вычисление значения косинуса угла между данным и заданным векторами.
	/// </summary>
	/// <param name="another">Заданный вектор, по отношению к которому нужно вычислить угол.</param>
	/// <returns>Значение косинуса угла между данным и заданным векторами.</returns>
	double FindCOSBetweenThisAnd(Vector another);

	/// <summary>
	/// Вычисление косинуса угла между векторами a и b.
	/// </summary>
	/// <param name="a">Вектор a.</param>
	/// <param name="b">Вектор b.</param>
	/// <returns>Значение косинуса угла между векторами a и b.</returns>
	static double FindCosBetweenVectors(Vector a, Vector b);

	/// <summary>
	/// Проверка компланарности векторов a, b и c.
	/// </summary>
	/// <param name="a">Вектор a.</param>
	/// <param name="b">Вектор b.</param>
	/// <param name="c">Вектор c.</param>
	static bool CheckVectorsCoplanarity(Vector a, Vector b, Vector c);

	/// <summary>
	/// Вычисление смешанного произведения векторов a, b и c.
	/// </summary>
	/// <param name="a">Вектор a.</param>
	/// <param name="b">Вектор b.</param>
	/// <param name="c">Вектор c.</param>
	static double VectorsMixedProduct(Vector a, Vector b, Vector c);

	/// <summary>
	/// Вывод координат вектора в удобном для восприятия виде.
	/// </summary>
	/// <param name="out">Поток для вывода.</param>
	/// <param name="vector">Вектор для вывода.</param>
	friend std::ostream& operator<< (std::ostream& out, const Vector& vector);

	/// <summary>
	/// Сложение двух векторов.
	/// </summary>
	/// <param name="leftOperand">Первый вектор.</param>
	/// <param name="rightOperand">Второй вектор.</param>
	/// <returns>Вектор, равный сумме двух векторов.</returns>
	friend Vector operator+ (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Вычитание двух векторов.
	/// </summary>
	/// <param name="leftOperand">Первый вектор.</param>
	/// <param name="rightOperand">Второй вектор.</param>
	/// <returns>Вектор, равный разности двух векторов.</returns>
	friend Vector operator- (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Составление вектора противоположного данному.
	/// </summary>
	friend Vector operator- (Vector operand);

	/// <summary>
	/// Умножение вектора на заданное число.
	/// </summary>
	/// <param name="leftOperand">Число.</param>
	/// <param name="rightOperand">Заданный вектор.</param>
	/// <returns>Новый вектор, умноженный на заданное число.</returns>
	friend Vector operator* (double leftOperand, Vector rightOperand);

	/// <summary>
	/// Умножение вектора на заданное число.
	/// </summary>
	/// <param name="leftOperand">Заданный вектор.</param>
	/// <param name="rightOperand">Число.</param>
	/// <returns>Новый вектор, умноженный на заданное число.</returns>
	friend Vector operator* (Vector leftOperand, double rightOperand);

	/// <summary>
	/// Скалярное произведение двух векторов a и b.
	/// </summary>
	/// <param name="leftOperand">Вектор a.</param>
	/// <param name="rightOperand">Вектор b.</param>
	/// <returns>Скалярное произведение векторов a * b.</returns>
	friend double operator* (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Векторное произведение двух векторов a и b.
	/// </summary>
	/// <param name="leftOperand">Вектор a.</param>
	/// <param name="rightOperand">Вектор b.</param>
	/// <returns>Векторное произведение векторов a & b.</returns>
	friend Vector operator& (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Проверка равенства двух векторов.
	/// (По определению:
	/// Два вектора называются равными тогда и только тогда, когда:
	/// 1) Они имеют одинаковое число координат
	/// 2) Соответствующие координаты равны между собой).
	/// </summary>
	///	<param name = "leftOperand"> Вектор a.</param>
	///	<param name = "rightOperand">Вектор b.</param>
	/// <returns>Результат сравнения по равенству двух векторов a и b.</returns>
	friend bool operator== (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Проверка на неравенство двух векторов (больше). Проверка по длине векторов.
	/// </summary>
	friend bool operator> (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Проверка на неравенство двух векторов (больше или равно). Проверка по длине векторов.
	/// </summary>
	friend bool operator>= (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Проверка на неравенство двух векторов (меньше). Проверка по длине векторов.
	/// </summary>
	friend bool operator< (Vector leftOperand, Vector rightOperand);

	/// <summary>
	/// Проверка на неравенство двух векторов (меньше или равно). Проверка по длине векторов.
	/// </summary>
	friend bool operator<= (Vector leftOperand, Vector rightOperand);
};
