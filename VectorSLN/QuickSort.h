#pragma once

/// <summary>
/// Быстрая сортировка
/// </summary>
/// <typeparam name="T">Тип элементов сортируемого массива</typeparam>
/// <param name="array">Указатель на массив сортируемых элементов</param>
/// <param name="length">Длина сортируемого массива</param>
template <typename T> void QuickSort(T* array, int length);