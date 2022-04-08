#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
// ������� ������� ����������
void quickSort(int *numbers, int left, int right)
{
	for (int i = 0; i < 12; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	int pivot; // ����������� �������
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = numbers[left];
	cout << "  pivot =" << pivot << "   " << "  left =" << left << "  right =" << right << endl;
	while (left < right) // ���� ������� �� ���������
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			cout << "  numer [" << left << "]=" << numbers[left] << "   numer [" << right << "]=" << numbers[right] << endl;
			numbers[left] = numbers[right]; // ���������� ������� [right] �� ����� ������������

			left++; // �������� ����� ������� ������
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			cout << "  numer [" << left << "]=" << numbers[left] << "  numer [" << right << "]=" << numbers[right] << endl;
			numbers[right] = numbers[left]; // ���������� ������� [left] �� ����� [right]

			right--; // �������� ������ ������� ������
		}
	}
	numbers[left] = pivot; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int a[12] = { 99,96,27,86,40,39,17,56,66,68,98,22 };
	// ����� ��������� ������� �� ����������
	for (int i = 0; i<12; i++)
		printf("%d ", a[i]);
	printf("\n");
	quickSort(a, 0, 11); // ����� ������� ����������
						// ����� ��������� ������� ����� ����������
	for (int i = 0; i<12; i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}