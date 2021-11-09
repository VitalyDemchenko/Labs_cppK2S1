// черга на масивах.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
using namespace std;
#include <Windows.h>
class info
{
public:
    int id;
    string surname;
    string name;
    string patr;
};

class queue
{
private:
    int maxSize;
    info* queArray;
    int front;
    int rear;
    int nItems;
public:
    queue(int s)
    {
        maxSize = s;
        queArray = new info[maxSize];
        front = 0;
        rear = -1;
        nItems = 0;

    }
    void insert(int j, string surname2, string name2, string patr2)
    {
        if (rear == maxSize - 1)
        {
            rear = -1;
            nItems = 0;
        }
        queArray[++rear].id = j;
        queArray[rear].surname = surname2;
        queArray[rear].name = name2;
        queArray[rear].patr = patr2;

        nItems++;
    }

    void remove2()
    {
        int temp = queArray[front++].id;
        string tmsurname = queArray[front].surname;
        string tmname = queArray[front].name;
        string tmpatr = queArray[front].patr;
        if (front == maxSize)
        {
            front = 0;
        }
        nItems--;
        cout << " Видалений елемент: " << endl;
        cout << " id : " << temp << endl;
        cout << " FIO " << tmsurname << " " << tmname << " " << tmpatr << endl;
    }

    void removeSeveral(int koldel)
    {
        if (koldel > nItems) {
            cout << " Неможливо видалити більше елементів ніж є! ";
            cout << endl;
            cout << endl;
        }
        else {
            for (int i = 0; i < koldel; i++) {
                int temp = queArray[front].id;
                string tmsurname = queArray[front].surname;
                string tmname = queArray[front].name;
                string tmpatr = queArray[front].patr;
                front++;
                if (front == maxSize)
                {
                    front = 0;
                }
                nItems--;
                cout << " Видалений елемент: " << endl;
                cout << " id : " << temp << endl;
                cout << " FIO " << tmsurname << " " << tmname << " " << tmpatr << endl;
            }
        }

    }

    void removeAll()
    {

        for (int i = 0; i < nItems + 1; i++) {
            int temp = queArray[front++].id;
            string tmsurname = queArray[front].surname;
            string tmname = queArray[front].name;
            string tmpatr = queArray[front].patr;
            if (front == maxSize)
            {
                front = 0;
            }
            nItems--;
            cout << " Видалений елемент: " << endl;
            cout << " id : " << temp << endl;
            cout << " FIO " << tmsurname << " " << tmname << " " << tmpatr << endl;
        }
    }
    void peekFront()
    {
        cout << endl;
        cout << " Перший елемент: " << endl;
        cout << " id: " << queArray[front].id << endl;
        cout << " FIO: " << queArray[front].surname << " " << queArray[front].name << " " << queArray[front].patr << endl;
        cout << endl;

    }

    bool isEmpty()
    {
        return(nItems == 0);
    }

    bool isFull()
    {
        return (nItems == maxSize);
    }

    int size()
    {
        return nItems;
    }

    void display()
    {
        if (nItems == 0)
        {
            cout << "Черга порожня\n";
            return;
        }


        /*
        if (front>rear)
        {
            int j = front;
            while (j!= maxSize)
            {
                cout << queArray[j] << endl;
                j++;
            }
            j = 0;
            while(j<=rear)
            {
                cout << queArray[j]<< endl;
                j++;
            }
        }
        else if(front<rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << i+1 << ": " << queArray[i] << endl;
            }
        }
        else if(nItems == 1)
            cout << "1: " << queArray[front];
        */
        cout << endl;
        return;
    }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukr");

    int choise = 1;
    int number;
    string surname2;
    string name2;
    string patr2;
    cout << " Введіть розмір черги > ";
    cin >> number;
    queue TheQueue(number);
    cout << endl;
    if (number <= 0) { cout << " Введіть кількість елементів більше 0"; }
    else {
        while (choise != 0)
        {
            cout << "1 - Додати елемент\n2 - Видалити  елемент\n3 - Вивести верхній елемент\n4 - Вивести розмір черги\n5 - Видалити декілька верхніх елементів\n6 - Перевірити чергу на порожність\n7 - Видалити чергу\n0 - Вихід\n";
            cout << endl;
            cout << "Введіть номер команди: "; cin >> choise;
            switch (choise)
            {
            case 1: // вставка
                cout << "Елемент: " << endl;
                cout << "Введіть id > "; cin >> number; cout << endl;
                cout << "Введіть Прізвище > "; cin >> surname2; cout << endl;
                cout << "Введіть Ім'я > "; cin >> name2; cout << endl;
                cout << "id По-батькові > "; cin >> patr2; cout << endl;
                TheQueue.insert(number, surname2, name2, patr2);
                break;
            case 2:  // видалення
                if (TheQueue.isEmpty())
                {
                    cout << endl;
                    cout << "Черга порожня\n";
                    cout << endl;
                }
                else { TheQueue.remove2(); }
                break;
            case 3: // виведення першого
                if (TheQueue.isEmpty())
                {
                    cout << endl;
                    cout << "Черга порожня\n";
                    cout << endl;
                }
                else
                {
                    TheQueue.peekFront();

                }
                break;
            case 4:
                if (TheQueue.isEmpty())
                {
                    cout << endl;
                    cout << "Черга порожня\n";
                    cout << endl;
                }
                else {
                    cout << endl;
                    cout << " Розмір черги: " << TheQueue.size();
                    cout << endl;
                    cout << endl;
                }
                break;
            case 5:
                if (TheQueue.isEmpty())
                {
                    cout << endl;
                    cout << "Черга порожня\n";
                    cout << endl;
                }
                else
                {
                    int koldel;
                    cout << " Скільки елементів видалити? "; cin >> koldel;
                    cout << endl;

                    TheQueue.removeSeveral(koldel);
                }

                break;
            case 6:
                if (TheQueue.isEmpty())
                {
                    cout << endl;
                    cout << "Черга порожня\n";
                    cout << endl;
                }
                else {
                    cout << " Черга не порожня, к-ть елементів: " << TheQueue.size();
                    cout << endl;

                }
                break;
            case 7:
                if (TheQueue.isEmpty())
                {
                    cout << endl;
                    cout << "Черга порожня\n";
                    cout << endl;
                }
                else
                {

                    TheQueue.removeAll();
                }
                break;
            }
        }
    }
    return 0;
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
