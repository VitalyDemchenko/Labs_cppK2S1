

#include <iostream>
using namespace std;
#include <Windows.h>
int i;
int j;
int n;

#include <string>


int k;
int count;
#include <fstream>
//сортування Шелла

void MetShellSort(int A[], int B[], int n ) 
{
	k = n;
	k = k / 2;
	while (k > 0)
	{
		for (i = 0; i < n - k; i++)
		{
			j = i;

			while (j >= 0 && A[j] > A[j + k])
			{
				::count = A[j];
				A[j] = A[j + k];
				A[j + k] = ::count;
				j--;

			}
		}
		k = k / 2;
	}
	//вивід масива
	cout << " Сортований масив " << endl;
	for (i = 0; i < n; i++) { cout << A[i] << " "; }
	//for (i = 0; i < n; i++) { B[i] = A[i]; }

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukr");


	
	
	cout << " Розмір масиву > "; cin >> n;
	int* A = new int[n]; 
	int* B = new int[n];
	for (i = 0; i < n; i++) 
	{
		cout << i + 1 << " елемент > "; cin >> A[i];
	}
	
	cout << "\n Несортований Масив: ";
	cout << endl;

	for (i = 0; i < n; i++) { cout << A[i] << " "; }
	cout << endl;

	MetShellSort(A, B, n );
	
	//for (i = 0; i < n; i++) { cout << A[i] << " "; }

	string path = "sortedMassive.txt";
	ofstream fout;
	
	fout.open(path);

	if (!fout.is_open())
	{
		cout << " Помилка відкриття файла ";
	}
	else
	{
		fout << " Відсортований масив ";
		fout <<" \n";
		for (i = 0; i < n; i++) 
		{
			fout << " ";
			fout << A[i]; 
		fout << "\n";
		}

	}

	delete[] A; 




	system("pause>>void");

	return 0;

}
