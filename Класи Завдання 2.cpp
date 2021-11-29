#include <stdlib.h>
#include <cstring>

#include <cstdlib>
#define KOL_ELEM 20
#include <Windows.h>
#define MAX_LN 30

#include <string>




#include <iostream>

using namespace std;

//	Варіант 5
//	Створити клас Fruit з властивостями : вид, колір, маса, стан.

class Fruit
{
	string _kind;
	string _color;
	double _mass;
	string _status;
public:
	Fruit() {
		cout << " empty constructor called " << endl;
		_kind = "None";
		_color = "None";
		_mass = 0.0;
		_status = "None";
		cout << " empty constructor finished" << endl;
	}
	Fruit(string kind, string color, double mass, string status)
	{
		cout << " konstructor with parameters called " << endl;
		_kind = kind;
		_color = color;
		_mass = mass;
		_status = status;
		cout << " konstructor with parameters stopped " << endl;

	}
	~Fruit()
	{
		cout << " destructor called " << endl;

	}
	string GetKind()
	{
		return (_kind);
	}

	string GetColor()
	{
		return (_color);
	}

	double GetMass()
	{
		return (_mass);
	}

	string GetStatus()
	{
		return (_status);
	}

	void SetKind(string kind)
	{
		_kind = kind;
	}

	void SetColor(string color)
	{
		_color = color;
	}

	void SetMass(double mass)
	{
		_mass = mass;
	}

	void SetStatus(string status)
	{
		_status = status;
	}
};

Fruit* table[KOL_ELEM];

void AddClass()
{
	string kind;
	string color;
	double mass;
	string status;

	cout << " Введіть параметри для нового об'єкта " << endl;
	cout << " Тип > "; cin >> kind; cout << endl;
	cout << " Колір > "; cin >> color; cout << endl;
	cout << " Маса в грамах > "; cin >> mass; cout << endl;
	cout << " Стан > "; cin >> status; cout << endl;

	Fruit* newClass = new Fruit(kind, color, mass, status);

	for (int i = 0; i < KOL_ELEM; i++)
	{
		if ((table[i] != NULL) && (i == KOL_ELEM - 1))
		{
			int whatElem;
			int vibor;
			cout << " Масив уже повністю заповнено " << endl;
			cout << " Бажаєте записати новий елемент замість старого? " << endl;
			cout << " Так -- 1, Ні -- 0 " << endl;
			cin >> vibor;
			if (vibor == 0) { break; }
			else 
			{
				cout << " Існують ячейки від 0 до " << KOL_ELEM - 1 << endl;
				cout << " В яку ячейку записати новий елемент? > "; cin >> whatElem; cout << endl;
				cout << " Новий елемент було записано в ячейку " << whatElem << endl;
				table[whatElem] = newClass;
			}
		}
		else {
		if (table[i] == NULL)
		{
			cout << " Новий об'єкт буде записано в ячейку номер " << i << endl;
			table[i] = newClass;
			break;
		}
		else
		{
			if (table[i] != NULL)
			{
				continue;
			}

		}


	}
		}
	
	
	//table[NumberElem](kind, color, mass, status);
};

void FindClass(string nameClass) {
	for (int i = 0; i < KOL_ELEM; i++)
	{
		if ((i == KOL_ELEM - 1) && (table[i] == NULL)) { cout << " Потрібний елемент не знайдено! " << endl; }

		else {
			if (table[i] != NULL) {
				string KindOfClasses = table[i]->GetKind();
				/*	if ((i == KOL_ELEM - 1) && (KindOfClasses != nameClass)) {
						cout << " Потрібний елемент не знайдено! ";
						break;
					}
					*/

					//else if(i < KOL_ELEM) {
				if (KindOfClasses != nameClass)
				{
					if ((i == KOL_ELEM - 1) && (KindOfClasses != nameClass)) {
						cout << " Потрібний елемент не знайдено! " << endl;
						break;
					}
					else { continue; }
				}
				else {
					cout << " Елемент знайдено " << endl;
					cout << " Тип: " << table[i]->GetKind() << endl;
					cout << " Колір: " << table[i]->GetColor() << endl;
					cout << " Маса в грамах: " << table[i]->GetMass() << endl;
					cout << " Стан: " << table[i]->GetStatus() << endl;
					break;
				}
			}
			//}
			else { continue; }

		}
	}
}

void editClass(string EditedClass)
{	


	string newkind;
	string newcolor;
	double newmass;
	string newstatus;
	for (int i = 0; i < KOL_ELEM; i++)
	{
		if ((i == KOL_ELEM - 1) && (table[i] == NULL)) { cout << " Потрібний елемент не знайдено! " << endl; }

		else {
			if (table[i] != NULL) {
				string KindOfClasses = table[i]->GetKind();
				/*	if ((i == KOL_ELEM - 1) && (KindOfClasses != nameClass)) {
						cout << " Потрібний елемент не знайдено! ";
						break;
					}
					*/

					//else if(i < KOL_ELEM) {
				if (KindOfClasses != EditedClass)
				{
					if ((i == KOL_ELEM - 1) && (KindOfClasses != EditedClass)) {
						cout << " Потрібний елемент не знайдено! " << endl;
						break;
					}
					else { continue; }
				}
				else {
					cout << " Елемент знайдено " << endl;
					cout << " Тип: " << table[i]->GetKind() << endl;
					cout << " Колір: " << table[i]->GetColor() << endl;
					cout << " Маса в грамах: " << table[i]->GetMass() << endl;
					cout << " Стан: " << table[i]->GetStatus() << endl;

					cout << " Змінити тип > "; cin >> newkind; cout << endl;
					cout << " Змінити колір > "; cin >> newcolor; cout << endl;
					cout << " Змінити масу > "; cin >> newmass; cout << endl;
					cout << " Змінити стан > "; cin >> newstatus; cout << endl;

					cout << " Вибраний об'єкт змінено " << endl;
					table[i]->SetKind(newkind);
					table[i]->SetColor(newcolor);
					table[i]->SetMass(newmass);
					table[i]->SetStatus(newstatus);
					break;
				}
			}
			//}
			else { continue; }

		}
	}
			
				
		}

void deleteClass(string EditedClass)
{


	string newkind;
	string newcolor;
	double newmass;
	string newstatus;
	for (int i = 0; i < KOL_ELEM; i++)
	{
		if ((i == KOL_ELEM - 1) && (table[i] == NULL)) { cout << " Потрібний елемент не знайдено! " << endl; }

		else {
			if (table[i] != NULL) {
				string KindOfClasses = table[i]->GetKind();
				/*	if ((i == KOL_ELEM - 1) && (KindOfClasses != nameClass)) {
						cout << " Потрібний елемент не знайдено! ";
						break;
					}
					*/

					//else if(i < KOL_ELEM) {
				if (KindOfClasses != EditedClass)
				{
					if ((i == KOL_ELEM - 1) && (KindOfClasses != EditedClass)) {
						cout << " Потрібний елемент не знайдено! " << endl;
						break;
					}
					else { continue; }
				}
				else {
					cout << " Елемент знайдено " << endl;
					cout << " Тип: " << table[i]->GetKind() << endl;
					cout << " Колір: " << table[i]->GetColor() << endl;
					cout << " Маса в грамах: " << table[i]->GetMass() << endl;
					cout << " Стан: " << table[i]->GetStatus() << endl;


					cout << " Елемент видалено " << endl;
					table[i] = NULL;
					break;
				}
			}
			//}
			else { continue; }

		}
	}


}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukr");
	
	for (int i = 0; i < KOL_ELEM; i++)
	{
		table[i] = NULL;
	}

	string kind ;
	string color ;
	double mass;
	string status ;
	string newkind;
	string newcolor;
	double newmass;
	string newstatus;
	string NameofClass;


	int numbers;

	int Numberelem1 = 0;
	string newFr ;
	string EditedClass;
	string DeletedClass;

	do
	{
		cout << endl;
		
			cout << " 1. Додати об'єкт " << endl;
			cout << " 2. Знайти об'єкт " << endl;
			cout << " 3. Змінити об'єкт " << endl;
			cout << " 4. Видалити об'єкт " << endl;
			cout << " 0. Завершити роботу " << endl;
			cout << endl;
			cout << " Номер команди > "; cin >> numbers;
			cout << endl;
			switch (numbers)
			{

		
				case 1:   // 
				{	
					//cout << " В яку ячейку додати новий об'єкт? > "; cin >> Numberelem1; cout << endl;

					AddClass();
					break;
				}
				case 2: //  
				{
					cout << " Який фрукт знайти? "; cin >> newFr; cout << endl;
					FindClass(newFr);
					break;
				}
				case 3:
				{
					cout << " Який елемент змінити? > "; cin >> EditedClass; cout << endl;

					editClass(EditedClass);
					break;


				}
				case 4:
				{	cout << " Який елемент видалити? > "; cin >> DeletedClass; cout << endl;

						deleteClass(DeletedClass);
				break;

				}

				
			}
			} while (numbers != 0); 

	

	return 0;

}