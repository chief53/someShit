#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const unsigned int COUNT_OF_NUMBERS = 10; // добавляем положительную константу. Она обозначит размер массива.

void merge(int* A, int first, int last) 
{
	int middle, start, final;

	int* mas = new int[COUNT_OF_NUMBERS];
	middle = (first + last) / 2; //вычисление среднего элемента
	start = first; //начало левой части
	final = middle + 1; //начало правой части

	for (int j = first; j <= last; j++) //выполнять от начала до конца
	{ 
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	};

	//возвращение результата в список
	for (int j = first; j <= last; j++) {
		A[j] = mas[j];
	};

	delete[] mas;
};

//рекурсивная процедура сортировки
void mergeSort(int* A, int first, int last) 
{
	if (first < last)
	{
		mergeSort(A, first, (first + last) / 2); //сортировка левой части
		mergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
		merge(A, first, last); //слияние двух частей
	}
};

int* generateArray() // заполняем массив десятью случайными числами (от 1 до 50)
{
	int* mas = new int[COUNT_OF_NUMBERS];
	srand(time(0));
	for (int i = 0; i < COUNT_OF_NUMBERS; i++)
	{
		mas[i] = 1 + rand() % 50;
	};
	return mas;
}

void printArray(int* arr) 
{
	for (int z = 0; z < COUNT_OF_NUMBERS; z++)
	{
		cout << arr[z] << endl;
	};
}

int main() // выводим массив
{
	setlocale(0, "");

	int* arrayOfNumbers = generateArray();
	cout << "Исходный массив: " << endl; // вывод массива
	printArray(arrayOfNumbers);

	mergeSort(arrayOfNumbers, 0, COUNT_OF_NUMBERS - 1);

	cout << "Упорядоченный массив: " << endl; // вывод упорядоченного массива
	printArray(arrayOfNumbers);

	delete[] arrayOfNumbers;
	return 0;
}