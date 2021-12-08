#include <iostream>
#include <ctime>
using namespace std;

void func(double** arr, int N, int M)
{
	double max_value = arr[0][0];
	double min_value = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i >= j)
			{
				if (arr[i][j] < min_value)
				{
					min_value = arr[i][j];
				}
			}
			if (i + j > M - 1)
			{
				if (arr[i][j] > max_value)
				{
					max_value = arr[i][j];
				}
			}

		}
	}
	cout << "Максимум в верхней области - " << max_value << endl;
	cout << "Минимум в нижней области - " << min_value;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	int N, M;
	cout << "Введите количество строк - ";

	cin >> N;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка, повторите ввод -  ";
		cin >> N;
	}
	cout << endl << "Введите количество столбцов - ";
	cin >> M;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка, повторите ввод -  ";
		cin >> M;
	}
	double** array = new double* [N];
	for (int i = 0; i < N; i++)
	{
		array[i] = new double[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array[i][j] = rand() % 100 / 3.1;
			cout << array[i][j] << "       ";
		}
		cout << endl;
	}

	func(array, N, M);

}