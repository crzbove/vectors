#include "QuickSort.h"

template <typename T> void QuickSort(T* array, int length) {
    // начало и конец сортируемой области
    int i = 0;
    int j = length - 1;

    // центральный элемент массива
    T mid = array[length / 2];

    //Деление массива на две половины
    do {
        while (array[i] < mid) {
            i++;
        }
        //В правой части будут те элементы, которые больше центрального
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
        // Отправка левой половины на сортировку
        QuickSort(array, j + 1);
    }
    if (i < length) {
        // Отправка правой половины
        QuickSort(&array[i], length - i);
    }
}
