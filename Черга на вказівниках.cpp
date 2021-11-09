// Черга на вказівниках.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <Windows.h>

//  Варіант 5
//  Черга хворих до лікаря, кожен елемент складається з ID і ПІБ пацієнта


struct Node //вузол списка
{
    int id;
    string name;
    string surname;
    string patr;

    //інформаційне поле
    Node* next; //вказівник на наступний елемент
};

struct Queue
{
    int size; // лічильник
    Node* first; //вказівник на початок черги
    Node* last; //вказівник на кінець черги
    int marker = 0;
};

void Creation(Queue* Q) //створення черги
{
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
    Q->size = 0;
    Q->marker = 1;
}

bool Full(Queue* Q) //перевірка черги на пустоту
{
    if (Q->first == Q->last) return true;
    else return false;
}

void TopCout(Queue* Q)
{
    cout << " id: " << Q->first->next->id << endl;
    cout << " FIO: " << Q->first->next->surname << " " << Q->first->next->name << " " << Q->first->next->patr << endl;
}

void Add(Queue* Q) //додавання елемента
{
    int id2;
    string name2;
    string surname2;
    string patr2;
    cout << "\nВведіть id > "; cin >> id2;
    cout << "\nВведіть Прізвище > ";  cin >> surname2;
    cout << "\nВведіть Ім'я > ";  cin >> name2;
    cout << "\nВведіть По-батькові > ";  cin >> patr2;

    Q->last->next = new Node;
    Q->last = Q->last->next;
    Q->last->id = id2; //додавання елемента в кінець
    Q->last->name = name2;
    Q->last->surname = surname2;
    Q->last->patr = patr2;

    Q->last->next = NULL; //обнулення вказівника
    Q->size++;
    cout << "\nЕлемент додано\n\n";
}

void TESTAdd(Queue* Q) //додавання 5 елементів для тестування
{
    int id2 = 1;
    string name2 = "TEST";
    string surname2 = "TEST";
    string patr2 = "TEST";
    for (int i = 0; i < 5; i++) {

        Q->last->next = new Node;
        Q->last = Q->last->next;
        Q->last->id = id2; //додавання елемента в кінець
        Q->last->name = name2;
        Q->last->surname = surname2;
        Q->last->patr = patr2;

        Q->last->next = NULL; //обнулення вказівника
        Q->size++;
        id2++;
    }
    cout << "\nЕлементи додано\n\n";
}

void Delete(Queue* Q) //видалення елемента
{
    Node* VremPtr;
    VremPtr = Q->first;

    Q->first = Q->first->next; //зміщення вказівника
    Q->size--;

    free(VremPtr);
    cout << "\nЕлемент видалено\n\n";
}

void DeleteSeveral(Queue* Q) //видалення елементів
{
    int koldel;
    cout << " Скільки елементів  видалити? "; cin >> koldel;
    cout << endl;
    if (koldel <= Q->size) {
        for (int i = 0; i < koldel; i++) {
            if (Q->first == Q->last) {
                break;
            }


            Node* VremPtr;
            VremPtr = Q->first;

            Q->first = Q->first->next; //зміщення вказівника
            Q->size--;

            free(VremPtr);
        }

        cout << "\nЕлементи видалені\n\n";
    }
    else {
        cout << " Неможливо видалити більше елементів ніж є! " << endl;
        cout << " Перед видаленням варто перевірити к-ть елементів! " << endl;
        cout << endl;
    }

}

void DeleteAll(Queue* Q, int size) // видалення черги
{
    cout << endl;
    if (size > 0) {
        for (int i = 0; i < size; i++)
        {
            if (Q->first == Q->last)
            {
                break;
            }
            Node* VremPtr;
            VremPtr = Q->first;

            Q->first = Q->first->next; //зміщення вказівника
            Q->size--;

            free(VremPtr);
        }
        //free (Q);        
        cout << "\nЕлементи видалені\n\n";
    }
    else {
        cout << " Список пустий, немає чого видаляти! " << endl;
        cout << " Перед видаленням варто перевірити к-ть елементів! " << endl;
        cout << endl;
    }

}

int Size(Queue* Q) //розмір черги
{
    return Q->size;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukr");
    Queue Q;
    Creation(&Q);
    char number;
    do
    {
        cout << "1. Додати елемент " << endl;
        cout << "2. Видалити елемент " << endl;
        cout << "3. Вивести верхній елемент " << endl;
        cout << "4. Взнати розмір черги " << endl;
        cout << "5. Видалити декілька елементів " << endl;
        cout << "6. Перевірити на порожність " << endl;
        cout << "7. Видалити чергу " << endl;
        cout << "8. Додати одразу 5 елементів(для тестування) " << endl;
        cout << "0. Вийти\n\n";
        cout << "Номер команди > "; cin >> number;
        switch (number)
        {
        case '1': Add(&Q);
            break;
            //-----------------------------------------------
        case '2':
            if (Full(&Q)) { cout << endl << "Черга порожня\n\n"; }
            else { Delete(&Q); }
            break;
            //-----------------------------------------------
        case '3':
            if (Full(&Q)) { cout << endl << "Черга порожня\n\n"; }
            else
            {
                //cout<<"\n id: "<<Top(&Q)<<"\n"<< " FIO: " << Top2(&Q) <<"\n\n"; 
                cout << endl;
                TopCout(&Q);
                cout << endl;
            }
            break;
            //-----------------------------------------------
        case '4':
            if (Full(&Q)) { cout << endl << "Черга порожня\n\n"; }
            else { cout << "\nРозмір черги: " << Size(&Q) << "\n\n"; }
            break;
            //-----------------------------------------------

        case '5':
            if (Full(&Q)) { cout << endl << "Черга порожня\n\n"; }

            else { DeleteSeveral(&Q); }
            break;

            //-----------------------------------------------
        case '6':
            if (Full(&Q)) { cout << endl << "Черга порожня\n\n"; }

            else {
                cout << endl;
                cout << " Черга не порожня " << endl;
                cout << " Кількість елементів: " << Size(&Q) << endl;
                cout << endl;
            }

            break;
            //-----------------------------------------------
        case '7':
            if (Full(&Q)) { cout << endl << "Черга порожня\n\n"; }

            else {
                int size2 = Size(&Q);
                DeleteAll(&Q, size2);
            }
            break;
            //-----------------------------------------------
        case '8': TESTAdd(&Q);
            break;

            //-----------------------------------------------
        case '0': break;
        default: cout << endl << "Команда не визначена\n\n";
            break;
        }
    } while (number != '0');
    //system("pause");
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
