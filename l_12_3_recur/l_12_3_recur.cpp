#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info; // створення псевдоніму типу

struct Elem
{
	Elem* next;
	Elem* prev;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info k, Info numb);
void print(Elem* L);
void process(Elem* L, Info value);

int main()
{
	srand((unsigned)time(NULL)); // настройка рандому 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);  // настройка відображення кирилиці

	Elem* first = NULL,
		* last = NULL; // створення списку 

	enqueue(first, last, 1, 10); // ввід в чергу елементів 
	cout << "Оригінальний список: " << endl << endl;
	print(first); // Вивід черги
	cout << endl << endl;

	Info info;
	cout << "Введіть значення інформаційного поля, яке буде продубльовано в списку: "; cin >> info;
	cout << endl;
	process(first, info); // Опрацювання черги
	cout << endl;
	print(first);
	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info k, Info numb)
{
	Info value = 1 + rand() % 100; // рандомне число
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
	if (k < numb) {
		k++;
		enqueue(first, last, k, numb);
	}
}


void print(Elem* L)
{
	// рекурсивно виводить значення інформаційних полей елементів списку
	if (L != NULL) {
		cout << L->info << " ";
		L = L->next;
		print(L);
	}
}

void process(Elem* L, Info value)
{
	if (L != NULL)
		if (L->info == value)
		{
			Elem* tmp = new Elem;  // створюється тимчасовий елемент
			tmp->info = value;  // тимчасовий елемент отримує значення, введене користувачем 
			tmp->next = L->next; // посилання тимчасового елементу настроюється на посиланя елемента 
			L->next = tmp; // вставляється тимчасовий елемент
			process(L->next->next, value); // рекурсивний виклик і перехід далі на 2 елементи, оскільки один вставлено
		}
		else
			process(L->next, value); // рекурсивний виклик і перехід
}