#include <stdlib.h>
#include <cstring>

#include <cstdlib>

#include <Windows.h>
#define MAX_LN 30
#include <string>

//	Варіант 5
//	Створити клас Fruit з властивостями : вид, колір, маса, стан.
#include <iostream>
using namespace std;


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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukr");

	
	string kind = " Яблуко ";
	string color = " Червоне ";
	double mass;
	string status = " Спіле ";
	string newkind;
	string newcolor;
	double newmass;
	string newstatus;

	int numbers;
	//Fruit Apple(kind, color, 0.1 , Status);
	//string theStatus = Apple.GetStatus();
	//cout << theStatus;
	cout << " Введіть параметри для об'єкта " << endl;
	cout << " Тип > "; cin >> kind; cout << endl;
	cout << " Колір > "; cin >> color; cout << endl;
	cout << " Маса в грамах > "; cin >> mass; cout << endl;
	cout << " Стан > "; cin >> status; cout << endl;
	Fruit NewFruit(kind, color, mass, status);

	do
	{
		cout << endl;
		cout << " 1. Вивести інформацію пр об'єкт " << endl;
		cout << " 2. Змінити тип об'єкта " << endl;
		cout << " 3. Змінити колір " << endl;
		cout << " 4. Змінити масу " << endl;
		cout << " 5. Змінити стан " << endl;
		cout << " 0. Завершити роботу " << endl;
		cout << " Номер команди > "; cin >> numbers;
		cout << endl;
		switch (numbers)
		{
		case 1:   // вивід інформації
		{
			cout << " Тип: " << NewFruit.GetKind() << endl;
			cout << " Колір: " << NewFruit.GetColor() << endl;
			cout << " Маса в грамах: " << NewFruit.GetMass() << endl;
			cout << " Стан: " << NewFruit.GetStatus() << endl;
		break;
		}
		case 2: //  Змінити тип
		{	
			cout << " Змінити тип > "; cin >> newkind; cout << endl;
			NewFruit.SetKind(newkind);
			break;
		}

		case 3:   // Змінити колір
		{
			cout << " Змінити колір > "; cin >> newcolor; cout << endl;
			NewFruit.SetColor(newcolor);
			break;
		}

		case 4:   // Змінити масу
		{	cout << " Маса вказується в грамах " << endl;
			cout << " Змінити масу > "; cin >> newmass; cout << endl;
			NewFruit.SetMass(newmass);
			break;
		}

		case 5:  //  Змінити стан
		{
			cout << " Змінити стан > "; cin >> newstatus; cout << endl;
			NewFruit.SetStatus(newstatus);
			break;
		}

		}
	} while (numbers != 0);
    
    return 0;

}
