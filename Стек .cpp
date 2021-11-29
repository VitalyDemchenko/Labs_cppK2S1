#include <iostream>
using namespace std;
//#include "stdafx.h"
//#include "hfstac.h"


#include <Windows.h>

#define MAXLENGTH 100
typedef int ELEMT;
typedef struct
{
    ELEMT elements[MAXLENGTH + 1];
    int top;
} FSTAC;

// прототипи функцій

void makenull(FSTAC* pS);
int isEmpty(FSTAC* pS);
int isFull(FSTAC* pS);
ELEMT top(FSTAC* pS, int* error);
ELEMT pop(FSTAC* pS, int* error);
void push(FSTAC* pS, ELEMT p, int* error);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukr");

    // Розподіляємо два стеки та змінну для повідомлень про помилку 
    int error;
    FSTAC S1, S2;
    // Очищаємо обидва стеки
    makenull(&S1);
    makenull(&S2);
    // Записуємо  4 елементи в стек S1
    for (int i = 1; i <= 4; i++)
    {
        push(&S1, i * 10, &error);
        // Друкуємо результат для перевірки
        printf("s1 =%d\n", top(&S1, &error));
    }
    // Копіюємо елементи зі стеку S1 в стек S2
    for (int i = 1; i <= 4; i++)
        push(&S2, pop(&S1, &error), &error);
    // Видаляємо елементи зі стеку S2 з друком 
    for (int i = 1; i <= 4; i++)
        printf("s2 = %d\n", pop(&S2, &error));
    getchar();
    return 0;
}

//#include "stdafx.h"
//#include "hfstac.h"

// Функція очистки стеку
void makenull(FSTAC* pS)
{
    pS->top = 0;
}

// Функція перевірки чи пустий стек
// повертає 1 – стек пустий, 0 – стек не пустий 
int isEmpty(FSTAC* pS)
{
    if (pS->top == 0) return 1;
    return 0;
}

// Перевірка чи не вичерпане місце в стеку 
// повертає 1 – стек заповнений, 0 – стек ще має місце для елементів
int isFull(FSTAC* pS)
{
    if (pS->top == MAXLENGTH) return 1;
    return 0;
}

// Повертає елемент з вершини стеку
ELEMT top(FSTAC* pS, int* error)
{
    ELEMT p = 0;
    *error = 0;
    if (isEmpty(pS)) *error = 1;
    else p = pS->elements[pS->top];
    return p;
}

// Видаляє елемент з вершини, повертає видалений елемент
ELEMT pop(FSTAC* pS, int* error)
{
    ELEMT p = 0;
    *error = 0;
    if (isEmpty(pS)) *error = 1;
    else
    {
        p = pS->elements[pS->top];
        pS->top--;
    }
    return p;
}

// Вставляє елемент на вершину стеку
void push(FSTAC* pS, ELEMT p, int* error)
{
    *error = 0;
    if (isFull(pS)) *error = 1;
    else
    {
        pS->top++;
        pS->elements[pS->top] = p;
    }
}