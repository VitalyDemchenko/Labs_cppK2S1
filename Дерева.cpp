#include <cstdlib>
#include <iostream>
using namespace std;
#include <Windows.h>

int tabs = 0;


int amount_1 = 0; // непарне


int amount = 0; // парне

struct Branch
{
    int Data;
    Branch* RightBranch;
    Branch* LeftBranch;

};

void Add(int aData, Branch*& aBranch)
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else
        if (aBranch->Data > aData)
        {
            Add(aData, aBranch->LeftBranch);
        }
        else
        {
            Add(aData, aBranch->RightBranch);
        };
}


void priam_obh(Branch*& aBranch)
{
    if (NULL == aBranch)    return;

    cout << aBranch->Data << endl; //вузол дерева
    priam_obh(aBranch->LeftBranch); //обхід лівого піддерева 
    priam_obh(aBranch->RightBranch); //обхід правого піддерева 
}

void print(Branch* aBranch) // функція виведення дерева
{
    if (!aBranch) return;
    tabs += 5;

    print(aBranch->LeftBranch);
    for (int i = 0; i < tabs; i++) cout << " ";
    cout << aBranch->Data << endl;

    print(aBranch->RightBranch);
    tabs -= 5;
    return;
}

void simmetr_obh(Branch*& aBranch)
{
    if (NULL == aBranch)    return;

    simmetr_obh(aBranch->LeftBranch);
    cout << aBranch->Data << endl;
    simmetr_obh(aBranch->RightBranch);
}

int par(Branch*& aBranch)
{
    if (NULL == aBranch)    return 0;

    if (aBranch->Data % 2 == 0)
    {
        amount++;
    }
    par(aBranch->LeftBranch);
    par(aBranch->RightBranch);
    return amount;
}

int ne_par(Branch*& aBranch)
{
    if (NULL == aBranch)    return 0;

    if (aBranch->Data % 2 == 1)
    {

        amount_1++;
    }

    ne_par(aBranch->LeftBranch);
    ne_par(aBranch->RightBranch);
    return amount_1;
}

int summa(Branch*& aBranch) // сума всіх елементів
{
    int sum = 0;
    if (aBranch != NULL) {
        sum += summa(aBranch->LeftBranch);
        sum += aBranch->Data;
        sum += summa(aBranch->RightBranch);
    }
    return sum;
}
void add_elem(int aData, Branch*& aBranch) // додавання нового елементу
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else
    {
        if (aData < aBranch->Data) {
            add_elem(aData, aBranch->LeftBranch);
        }
        else if (aData > aBranch->Data) {
            add_elem(aData, aBranch->RightBranch);
        }
    }
}
 /* int* read_from_file(int* massiv, int n)
{
    int i = 0;
    int x = 0;
    int* p;
    p = massiv;
    if (!(p = (int*)malloc(n * sizeof(int)))) {
        printf(" No memory ");
        return (p);

    }
    else { FILE* fp;
    fp = fopen("fileTree.txt", "r");
    if (fp == NULL) {
        printf("file not found");

    }
    else {
        for (i = 0; i < n;i++) {
            fscanf(fp, "%f", &x);
            *((int*)p + i) = x;
        }
    }
    fclose(fp);
    return (p);
    }

}*/
void FreeTree(Branch* aBranch) // звільнення пам'яті
{
    if (!aBranch) return;
    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);
    delete aBranch;
    return;
}

Branch* del_elem(Branch*& aBranch, int aData) // видалення нового елементу
{
    if (aBranch == NULL)
        return aBranch;

    if (aData == aBranch->Data) {

        Branch* tmp;
        if (aBranch->RightBranch == NULL)
            tmp = aBranch->LeftBranch;
        else {

            Branch* ptr = aBranch->RightBranch;
            if (ptr->LeftBranch == NULL) {
                ptr->LeftBranch = aBranch->LeftBranch;
                tmp = ptr;
            }
            else {

                Branch* pmin = ptr->LeftBranch;
                while (pmin->LeftBranch != NULL) {
                    ptr = pmin;
                    pmin = ptr->LeftBranch;
                }
                ptr->LeftBranch = pmin->RightBranch;
                pmin->LeftBranch = aBranch->LeftBranch;
                pmin->RightBranch = aBranch->RightBranch;
                tmp = pmin;
            }
        }

        delete aBranch;
        return tmp;
    }
    else if (aData < aBranch->Data)
        aBranch->LeftBranch = del_elem(aBranch->LeftBranch, aData);
    else
        aBranch->RightBranch = del_elem(aBranch->RightBranch, aData);
    return aBranch;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukr");


    Branch* Root = 0;
    int num;
    int element;
    int numbers;

    do {
        cout << endl;
        cout << " 1. Додати елемент " << endl;
        cout << " 2. Додати декілька елементів " << endl;
        cout << " 3. Вивести суму всіх елементів  " << endl;
        cout << " 4. Прямий обхiд бiнарного дерева " << endl;
        cout << " 5. Симетричний обхiд бiнарного дерева " << endl;
        cout << " 6. Вивести бінарне дерево " << endl;
        cout << " 7. Звільнити пам'ять " << endl;
        cout << " 8. Видалити елемент " << endl;
        //cout << " 9. Читання з файла " << endl;
        cout << " 0. Вийти\n\n";
        cout << " Номер команди > "; cin >> numbers;
        cout << endl;
        switch (numbers)
        {
        case 1:
        {
            cout << "Введiть елемент: ";   cin >> element;
            add_elem(element, Root);


            break;}
        //-----------------------------------------------
        case 2:
        {cout << "Кiлькiсть елементiв бiнарного дерева: ";   cin >> num;

        cout << endl;

        for (int i = 0; i < num; i++)
        {
            Add(rand() % 20, Root); // заповнення цілими числами від 0 до 20

        }

        break;}
        //-----------------------------------------------
        case 3:
        {
            cout << summa(Root) << endl;
            cout << endl;
            break;
        }

        //-----------------------------------------------
        case 4: { priam_obh(Root);
            cout << endl;
            break;
        }
              //-----------------------------------------------
        case 5: {
            simmetr_obh(Root);
            cout << endl;
            break;
        }
              //-----------------------------------------------
        case 6: {

            print(Root);
            cout << endl;
            break;}

        //-----------------------------------------------

        case 7:
        {
            FreeTree(Root);
            cout << "Звiльнення динамiчної пам'ятi..." << endl;
            break;
        }

        //-----------------------------------------------
        case 8:
        {
            cout << "Введiть елемент для видалення : "; cin >> element;
            del_elem(Root, element);
            break;
        }
       
         //-----------------------------------------------
        /*case 9: {
            string line;
            ifstream in("C:\\Text_lb_der\\derevo.txt");
            if (in.is_open())
            {
                while (getline(in, line))
                {
                    cout << line << std::endl;
                }
            }

            break;} */
        //-----------------------------------------------
        case 0: {break;}

        default: { cout << endl << " Команда не визначена\n\n";
            break;}
        }
    } while (numbers != 0);
    //system("pause");
    return 0;

}