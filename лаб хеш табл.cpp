#include <iostream>
#include <string>
#include <Windows.h>
#define PRIME_SIZE 100 

using namespace std;

class Person
{
public:
    Person* next;

    int age;

    Person()
    {
        this->next = NULL;
    }

    Person(int age)
    {

        this->age = age;
        this->next = NULL;
    }

    ~Person()
    {

        if (this->next != NULL)
        {
            delete this->next;
        }
    }
};

class HashTable
{
    Person* table[PRIME_SIZE];


    static int hash(int  Value)
    {

        return Value % PRIME_SIZE;
    }

public:

    HashTable()
    {
        for (int i = 0; i < PRIME_SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    ~HashTable()
    {

        for (int i = 0; i < PRIME_SIZE; i++)
        {
            delete table[i];
        }
    }


    void push(int age)
    {
        int hashNumber = hash(age);
        Person* pers = new Person(age);
        Person* place = table[hashNumber];
        if (place == NULL)
        {
            table[hashNumber] = pers;
            return;
        }

        while (place->next != NULL)
        {
            place = place->next;
        }
        place->next = pers;
    }


    Person* find(int age)
    {
        int hashNumber = hash(age);
        Person* result = table[hashNumber];
        if (!result)
        {
            cout << " Елемент не знайдено" << endl;
            cout << endl;
            return NULL;
        }
        while (result->age != age)
        {
            if (!result->next)
            {
                cout << " Елемент не знайдено" << endl;
                cout << endl;
                break;
            }
            result = result->next;
        }
        return result;
    }

    void deleteElem(int age2)
    {
        int hashNumber = hash(age2);
        Person* result = table[hashNumber];

        if (!result)
        {
            cout << " Елемент не знайдено" << endl;
            cout << endl;

        }
        else {

            if (result->next == NULL)
            {
                cout << " Видалено елемент " << result->age << endl;

                cout << endl;
                result->age = 0;
                result = result->next;
                table[hashNumber] = NULL;
                delete  result;
            }
            else {
                if (result->age == age2)
                {
                    Person* result4 = result;
                    result4->next = result->next;
                    result4 = result4->next;
                    table[hashNumber] = result4;

                }
                Person* result3 = result;
                Person* result2 = result;
                int mar33 = 1;
                while (result3->age != age2)
                {
                    if (result3->next == 0)
                    {
                        cout << " Елемент не знайдено" << endl;
                        cout << endl;
                        mar33 = 0;
                        break;
                    }
                    //else if (result3->age == age2) {
                    //    mar33 = 1;

                   //}
                    else {

                        result2 = result3;
                        result3 = result3->next;

                    }

                }
                if (mar33 == 1) {
                    cout << " Видалено елемент " << result3->age << endl;

                    cout << endl;

                    result2->next = result3->next;

                }
            }

        }
    }

    int numElem(int it)
    {
        Person* result = table[it];

        if (!result)
        {
            int result2 = 0;
            return result2;
        }
        else {

            int result2 = result->age;
            return result2;
        }


    }
    // перевірка на порожність
    int perevNulls(int it2) // 0 - елемента немає
    {
        Person* result5 = table[it2];
        int markperev;
        if (!result5)
        {
            markperev = 0;
        }
        else { markperev = 1; }
        return markperev;
    }

    void numElem2(int it)
    {
        Person* result4 = table[it];
        if (!result4) { cout << " "; }
        else {
            if (!result4->next)
            {
                cout << " ";
            }
            else {
                while (result4->next != NULL)
                {
                    result4 = result4->next;
                    int newNum2 = result4->age;
                    cout << " --> " << newNum2;
                }
            }
        }
    }

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukr");

    HashTable newTable;
    int numbers;
    string name1;
    string surname1;
    int age1;
    int age2;
    string name2;
    int zmdelElem;
    int randElem;
    do
    {
        cout << endl;
        cout << " 1. Додати елемент " << endl;
        cout << " 2. Пошук елемента за ім'ям " << endl;
        cout << " 3. Вивести всі елементи " << endl;
        cout << " 4. Видалити елемент " << endl;
        cout << " 5. Додати декілька випадкових чисел " << endl;
        cout << " 0. Вийти\n\n";
        cout << " Номер команди > "; cin >> numbers;
        cout << endl;
        switch (numbers)
        {
        case 1:
        {

            cout << " Введіть число > "; cin >> age1; cout << endl;
            newTable.push(age1);
            cout << " Додано елемент" << endl;
            cout << " " << age1 << endl;

            break;}
        //-----------------------------------------------
        case 2:
        {
            cout << " Введіть шукане число > "; cin >> age2;
            cout << endl;
            Person* search = newTable.find(age2);
            if (search)
            {
                cout << " Елемент " << search->age << " в таблиці існує " << endl;
                cout << endl;
            }
        }
        //-----------------------------------------------
        break;
        case 3:

        {   for (int i = 0; i <= PRIME_SIZE - 1; i++)
        {
            int newmarPer = newTable.perevNulls(i);

            if (newmarPer == 0)
            {
                if (i == PRIME_SIZE - 1) {
                    for (int i = 0; i <= PRIME_SIZE; i++) {
                        if (i < PRIME_SIZE) {
                            int newmarPer = newTable.perevNulls(i);
                            if (newmarPer == 0)
                            {
                                continue;
                            }
                            else { break; }
                        }
                        else { cout << " Таблиця поки що пуста " << endl; }
                    }
                }

                else { continue; }
            }

            else {

                int result3 = newTable.numElem(i);

                cout << " KEY = " << i << " elem = " << result3;
                newTable.numElem2(i);
                cout << endl;
            }


        }
        //cout << " Коли elem = 0, це означає що поточна комірка пуста " ;
        cout << endl;

        }
        break;
        case 4:
        {
            cout << " Який елемент видалити? > "; cin >> zmdelElem;
            cout << endl;
            newTable.deleteElem(zmdelElem);

        }
        break;
        //-----------------------------------------------
        case 5:
        {
            int Firstrand, Lastrand;
            cout << " Скільки випадкових елементів вставити? > "; cin >> randElem; cout << endl;
            cout << " З якого елемента? > "; cin >> Firstrand; cout << endl;
            cout << " По який ? > "; cin >> Lastrand; cout << endl;
            for (int i = 0; i < PRIME_SIZE; i++)
            {
                int RandomEl = rand() % (Lastrand - Firstrand + 1) + Firstrand;
                newTable.push(RandomEl);

                cout << " Додано елемент" << endl;
                cout << " " << RandomEl << endl;
            }


            break;}
        //-----------------------------------------------
        case 0: {break;}
        default: { cout << endl << " Команда не визначена\n\n";
            break;}
        }
    } while (numbers != 0);
    //system("pause");
    return 0;
}