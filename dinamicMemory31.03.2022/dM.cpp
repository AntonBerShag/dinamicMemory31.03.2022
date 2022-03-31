#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> void showArr(T arr[], int length);
template <typename T> void fillArr(T arr[], int length, int min = 0, int max = 100);

template <typename T> T* addEl(T arr[], unsigned int &length, int n);
template <typename T> T* delEl(T arr[], unsigned int& length, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	

	//Задача 1
	/*cout << "Задача 1\nВведите длину массива: ";
	unsigned int size1;
	cin >> size1;
	int* z1 = new int[size1];
	fillArr(z1, size1, 10, 30);
	cout << "Изначальный массив:\n";
	showArr(z1, size1);
	z1 = addEl(z1, size1, 5);
	cout << "Итоговый массив:\n";
	showArr(z1, size1);
	delete[] z1;*/

	//Задача 2
	cout << "Задача 2\nВведите длину массива: ";
	unsigned int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, 10, 51);
	cout << "Изначальный массив:\n";
	showArr(z2, size2);
	z2 = delEl(z2, size2, 3);
	cout << "Итоговый массив:\n";
	showArr(z2, size2);

	/*const int L = 5;
	int arr[L];

	unsigned int n;
	cout << "Введите длину массива: ";
	cin >> n;
	int* dArr = new int[n];
	//dArr[0] = 10;
	for (int i = 0; i < n; i++)
		dArr[i] = i + 1;
	cout << "Изначальный массив:\n";
	showArr(dArr, n);

	delete[] dArr;
	dArr = nullptr;

	dArr = new int[n + 1];*/

	return 0;
}

//Задача 2. Уменьшение размера массива
template <typename T> T* delEl(T arr[], unsigned int& length, int n) {
	if (n <= 0 || n >= length)
		return arr;
	length -= n;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete arr;
	arr = new T[length];
	for (int i = 0; i < length; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}


//Задача 1. Увеличение размера массива
template <typename T> T* addEl(T arr[], unsigned int& length, int n) {
	if (n <= 0)
		return arr;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[length + n];
	length += n;
	for (int i = 0; i < length - n; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}


//Заполнение массива случайными числами от min до max
template <typename T> void fillArr(T arr[], int length, int min, int max) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}
//Вывод массива
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}