#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max);
void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min);
void OddRows(int** a, const int rowCount, const int colCount, int rowNo, int& max);


int main()
{
	srand((unsigned)time(NULL));

	int Low = -12;
	int High = 37;

	int rowCount; // ����� �������
	int colCount; // ������� �������
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	int min;
	OddRows(a, rowCount, colCount, 0, min);
	if (rowCount <= 2 || colCount <= 2) {
		cout << "Zminit znachennia!" << endl;
	}
	else {
		cout << "Min z max: " << min << endl;
	}

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& max)
{
	if (a[rowNo][colNo] < max)
		max = a[rowNo][colNo];
	if (colNo < colCount - 1)
		MinRow(a, rowNo, colCount, colNo + 1, max);
}


void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max)
{
	int min = a[rowNo][0];
	MinRow(a, rowNo, colCount, 0, min); // ������� ������� MinRow, ��� ������� ��������� �������� � ������� �����
	if (rowNo == 1)
		max = min;
	if (min > max)
		max = min;

}

void OddRows(int** a, const int rowCount, const int colCount, int rowNo, int& max) {
	if (rowNo % 2 == 0) { // ������� �� ����� ������ 
		if (rowNo < rowCount) { // �������� �� �� ������� �������� ���, �� ����� ����������
			MaxMinRows(a, rowCount, colCount, rowNo, max);
			OddRows(a, rowCount, colCount, rowNo + 1, max);
		}
	}
	else {
		if (rowNo < rowCount) // �������� �� �� ������� �������� ���, �� ����� ����������
		{
			OddRows(a, rowCount, colCount, rowNo + 1, max);
		}
	}
}