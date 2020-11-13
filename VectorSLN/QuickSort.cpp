#include "QuickSort.h"

template <typename T> void QuickSort(T* array, int length) {
    // ������ � ����� ����������� �������
    int i = 0;
    int j = length - 1;

    // ����������� ������� �������
    T mid = array[length / 2];

    //������� ������� �� ��� ��������
    do {
        while (array[i] < mid) {
            i++;
        }
        //� ������ ����� ����� �� ��������, ������� ������ ������������
        while (array[j] > mid) {
            j--;
        }

        if (i <= j) {
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        // �������� ����� �������� �� ����������
        QuickSort(array, j + 1);
    }
    if (i < length) {
        // �������� ������ ��������
        QuickSort(&array[i], length - i);
    }
}
