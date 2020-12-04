#include "Vector.h"
#include "QuickSort.h"

int main() {
	using namespace std;

	setlocale(LC_ALL, "Russian");

	unsigned int size = 0, count = 0;
	int userChoice = -1;
	Point* points = new Point[2];

	cout << "Введите размерность вектора: ";
	cin >> size;
	double* coords = new double[size];

	cout << "Введите количество векторов: ";
	cin >> count;
	Vector* vectors = new Vector[count];
	cout << "Выберите способ задания векторов:\n1 - по координатам двух точек (начала и конца)\n2 - по координатам вектора\n\n: > ";
	cin >> userChoice;
	cout << "-----------------------------\n\n";

	for (int k = 0; k < count; k++)
	{
		cout << "Вектор-" << k + 1 << ":\n";

		switch (userChoice) {
		case 1:
			for (int p = 0; p < 2; p++)
			{
				coords = new double[size];
				for (int s = 0; s < size; s++)
				{
					cout << "Введите " << s + 1 << "-ю координату " << p + 1 << " точки: ";
					cin >> coords[s];
				}
				points[p].PointCoordsCount = size;
				points[p] = { size, coords };
				cout << "\n";
			}
			vectors[k] = Vector(points[0], points[1]);
			break;
		case 2:
			coords = new double[size];

			for (int i = 0; i < size; i++)
			{
				cout << "Введите " << i + 1 << "-ю компоненту вектора: ";
				cin >> coords[i];
			}
			vectors[k] = Vector(coords, size);
			cout << "\n";
			break;
		default:
			return 255;
		}
	}

	cout << "\n\nВекторы:\n";
	for (int i = 0; i < count; i++)
	{
		cout << vectors[i];
		cout << "\n   Длина: " << vectors[i].GetLength() << "\n\n";
	}

	QuickSort<Vector>(vectors, count);
	cout << "\n\nВекторы (отсортированные):\n";
	for (int i = 0; i < count; i++)
	{
		cout << vectors[i];
		cout << "\n   Длина: " << vectors[i].GetLength() << "\n\n";
	}

	cout.setf(ios::boolalpha);
	cout << "\n\nРезультаты тестирования:\n";
	cout << "Сложение первого и последнего вектора: " << (vectors[0] + vectors[count - 1]) << "\n";
	cout << "Вычитание первого и второго вектора: " << (vectors[0] - vectors[1]) << "\n";
	cout << "Скалярное произведение последнего и предпоследнего вектора: " << vectors[count - 1] * vectors[count - 2] << "\n";
	cout << "Значение косинуса угла между вторым и предпоследним вектором: " << vectors[1].FindCOSBetweenThisAnd(vectors[count - 2]) << "\n";
	cout << "Первый вектор, умноженный на 3.55: " << (3.55 * vectors[0]) << " ?== " << (vectors[0] * 3.55) << "\n";
	cout << "^^ значения должны совпадать\n\n";
	cout << "Равен ли первый вектор предпоследнему?: " << (vectors[0] == vectors[count - 2]) << "\n";
	cout << "Векторное произведение первого и последнего векторов" << (vectors[0] & vectors[count - 1]) << "\n";
	cout << "Смешанное произведение первого, второго и предпоследнего векторов: " << (Vector::VectorsMixedProduct(vectors[0], vectors[1], vectors[count - 2])) << "\n";
	cout << "Векторное произведение вектора самого на себя (должно быть = 0-вектору): " << (vectors[0] & vectors[0]) << "\n";

	delete[] coords, vectors, points;

	return 0;
}