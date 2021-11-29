#include <iostream> 
using namespace std;
//#include "stdafx.h" 
#include <stdio.h> 
//#include "hdlist.h" 
#include <Windows.h>

// Визначення структури списку та прототипи функцій 
typedef int ELEMT;
typedef struct dlist
// Визначення структури для формування списку 
{
	ELEMT element;  /* елемент списку */
	struct dlist* next; /* вказівник на наступний елемент */
} DLIST;
typedef DLIST* POSD;
// прототипи функцій 
int len_d(DLIST* pl);
void insert_d(DLIST** ppH, POSD k, ELEMT p, int* error);
ELEMT del_d(DLIST* pH, POSD k, int* error);
POSD locate_d(DLIST* pH, ELEMT p);
ELEMT retrieve_d(DLIST* pH, POSD k, int* error);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukr");

	//  визначення змінних 
	int nerror;  // змінна для повідомлення про помилку 
	DLIST* pH = 0;   // вказівник на 1-й елемент списку 
	POSD pC;  // змінна для визначен. позиції в списку 
	int i;   // внутріш.змінна для лічильника цик-лів 

   // вставка елементів (починаємо з останнього) 
	insert_d(&pH, 0, 400, &nerror);
	insert_d(&pH, 0, 300, &nerror);
	insert_d(&pH, 0, 200, &nerror);
	insert_d(&pH, 0, 100, &nerror);

	// Виводимо результат тобто список  
	pC = pH;
	printf("After insert: \n");
	for (i = 1; i <= len_d(pH); i++)
	{
		printf(" L[%d] = %d\n", i, retrieve_d(pH, pC, &nerror));
		pC = pC->next;
	}
	// Видалення 2 елементу 
	pC = pH;  // вказівник на початок списку  
	pC = pC->next; //отримали вказівник на другий еле-мент  
	del_d(pH, pC, &nerror);
	// Виводимо результат після видалення 
	pC = pH;
	printf("After deletation: \n");
	for (i = 1; i <= len_d(pH); i++)
	{
		printf(" L[%d] = %d\n", i, retrieve_d(pH, pC, &nerror));
		pC = pC->next;
	}
	return 0;
}


int len_d(DLIST* pl)
{
	DLIST* p = pl;
	int i = 0;
	while (p != 0)
	{
		i++;
		p = p->next;
	}
	return i;
}

// Функція вставки елементу p в позицію списку k+1 
void insert_d(DLIST** ppH, POSD k, ELEMT p, int* error)
{
	DLIST* pNew;
	*error = 0;
	// виділення пам’яті для нового елементу 
	pNew = (DLIST*)malloc(sizeof(DLIST));
	if (pNew == 0)
	{
		*error = 1;
		return;
	}
	pNew->element = p;
	// при k==0 вставка першим елементом списку 
	if (k == 0)
	{
		pNew->next = *ppH;
		*ppH = pNew;
	}
	else
	{
		pNew->next = k->next;
		k->next = pNew;
	}
}
// Функція видалення k-го елементу списку 
// повертає видалений елемент 
ELEMT del_d(DLIST* pH, POSD k, int* error)
{
	ELEMT elem = 0;
	POSD temp;
	*error = 0;

	if ((temp = k->next) == 0) *error = 1;
	// вказівник на останній елемент (нема чого видаляти) 
	else
	{
		elem = temp->element;
		k->next = temp->next;
		free(temp);
	}
	return elem;
}
// Отримання вказаного елементу списку 
// позиція задається як вказівник на потрібний елемент 
ELEMT retrieve_d(DLIST* pH, POSD k, int* error)
{
	ELEMT elem = 0;
	*error = 1;
	if (k != 0)
	{
		*error = 0;
		elem = k->element;
	}
	return elem;
}
// Пошук елементу в списку за заданим значенням p 
// повертає позицію в списку або 0 якщо такого елементу не знайдено 
POSD locate_d(DLIST* pH, ELEMT p)
{
	POSD pCur = pH;
	while (pCur != 0)
		if (pCur->element == p) return pCur;
		else
			pCur = pCur->next;
	return pCur;
}