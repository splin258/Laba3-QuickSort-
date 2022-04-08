#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
// Функция быстрой сортировки
void quickSort(int *numbers, int left, int right)
{
	for (int i = 0; i < 12; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = numbers[left];
	cout << "  pivot =" << pivot << "   " << "  left =" << left << "  right =" << right << endl;
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			cout << "  numer [" << left << "]=" << numbers[left] << "   numer [" << right << "]=" << numbers[right] << endl;
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего

			left++; // сдвигаем левую границу вправо
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			cout << "  numer [" << left << "]=" << numbers[left] << "  numer [" << right << "]=" << numbers[right] << endl;
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]

			right--; // сдвигаем правую границу вправо
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int a[12] = { 99,96,27,86,40,39,17,56,66,68,98,22 };
	// Вывод элементов массива до сортировки
	for (int i = 0; i<12; i++)
		printf("%d ", a[i]);
	printf("\n");
	quickSort(a, 0, 11); // вызов функции сортировки
						// Вывод элементов массива после сортировки
	for (int i = 0; i<12; i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}