

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Merge(int* A, int first, int last)
{
    int middle, start, final, j;
    int* mas = new int[10];
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
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
    //возвращение результата в список
    for (j = first; j <= last; j++) A[j] = mas[j];
    delete[]mas;
};
//рекурсивная процедура сортировки
void MergeSort(int* A, int first, int last)
{
    {
        if (first < last)
        {
            MergeSort(A, first, (first + last) / 2); //сортировка левой части
            MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
            Merge(A, first, last); //слияние двух частей
        }
    }
};

int* generateArray(int count) // заполняем массив десятью случайными числами (от 1 до 50)
{
    int* mas = new int[count];
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        mas[i] = 1 + rand() % 50;
    };
    return mas;
}

int main() // выводим массив
{
    setlocale(0, "");
    int count = 10;
    int* mas = generateArray(count);
    int* A = generateArray(count);
    cout << "массив: " << endl; // вывод массива
    for (int z = 0; z < count; z++)
    {
        cout << mas[z] << endl;
    }
    cout << "Упорядоченный массив: " << endl; // вывод упорядоченного массива
    MergeSort(A, 0, 10);
    for (int z = 1; z <= count; z++)
    {
        cout << A[z] << endl ;
    }
    delete[]A;
    return 0;
}
