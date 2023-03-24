#include <iostream>
#include <cstdlib>
#include <ctime>
void arr_add(int*& arr,int length,int num){
	if (num <= 0)
		return;
	int* tmp = new int[length + num]{};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//Динамическая память
	/*
	int* pointer=new int;//Направлние указателя на произвольный участок динамической памяти, размером в 4 байта(т.к.INT)
	*pointer = 15;//Запись в динамическую память числа 15
	std::cout << "pointer = " << pointer << "\n";
	std::cout << "*pointer = " << *pointer << "\n";

	delete pointer;//Освобождение(очистка) области динамической памяти на которую направлен указатель
	//Необходимо во избежание утечки памяти

	pointer = new int;// выделение нового участка динамической памяти
	std::cout << "pointer = " << pointer << "\n";
	*pointer = 7;
	std::cout << "*pointer = " << *pointer << "\n";

	delete pointer;
	*/
	//Динамичские массивы
	/*
	std::cout << "Введите размер массива ->";
	int size;
	std::cin >> size;

	int* d_arr = new int[size];//Выделение динамической памяти для хранения массива
	std::cout << "Ввод массива:\n";
	for (int i = 0; i < size; i++) {
		std::cout << "Введите " << i + 1 << "-й элемент ->";
		std::cin >> d_arr[i];
	}
	std::cout << "Итоговый массив:\n";
	for (int i=0; i < size; i++)
		std::cout << d_arr[i] << " ";
	std::cout << "\n";

	delete[] d_arr;//Очистка динамической памяти выдленной под массив
	*/
	//Двумерный динамический массив
	/*
	int rows, cols;
	std::cout << "Введите размеры двумерного массива ->";
	std::cin >> rows >> cols;
	//int* mx = new int[rows][cols];//Не работает
	int** mx = new int* [rows];
	for (int i = 0; i < cols; i++) {
		mx[i] = new int[cols];
	}
	//Использование массива точно такое же как и у статического

	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[]mx;
	*/
	//Задача 1. Увеличение массива
	std::cout << "Задача 1.\nВведите размер массива ->";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	srand(time(NULL));
	std::cout << "Изначальный массив:\n";
	std::cout << "[ ";
	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % (21 - 10) + 10;//[10...20]
		std::cout << arr1[i] << ", ";
	}
	std::cout << "\b\b]\nВведите количество новых элементов ->";
	std::cin >> n;

	arr_add(arr1, size1, n);
	size1 += n;
	std::cout << "Итоговый массив:\n[";
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << ", ";
	std::cout << "\b\b]\n";



	system("pause");


	return 0;
}