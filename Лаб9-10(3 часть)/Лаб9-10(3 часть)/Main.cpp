#include <Windows.h>
#include "Classes.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Создание и инициализация объектов пользовательского типа
	cake obj1("A", 1, 10), obj2("B", 2, 20), obj3("C", 3, 30), obj4("D", 4, 40);
	//Создания списка
	list<cake> First;
	//Инициализация списка
	First.push_front(obj3);
	First.push_back(obj1);
	First.push_front(obj4);
	First.push_back(obj2);
	//Создание деки
	deque<cake> Second(count_if(First.begin(), First.end(), PriceIf));
	//Просмотр содержимого First
	int i = 1;
	cout << "Просмотр содержимого First" << endl;
	for (auto it = First.begin(); it != First.end(); ++it, i++)
		cout << i << ")" << *it << endl;
	i = 1;
	//Сортировка First
	First.sort();
	//Просмотр содержимого First после сортировки по убыванию
	cout << "Просмотр содержимого First после сортировки по убыванию" << endl;
	for (auto it = First.begin(); it != First.end(); ++it, i++)
		cout << i << ")" << *it << endl;
	i = 1;
	//Поиск элемента по заданному условию
	cake temp("A", 1, 10);
	auto f = find(First.begin(), First.end(), temp);
	//Вывод найденого элемента
	cout << "Вывод найденого элемента по условию: (A,1,10)" << endl;
	cout << *f << endl;
	//Копирование элементов из First в Second согласно условию: Price >= 20
	copy_if(First.begin(), First.end(), Second.begin(), PriceIf);
	//Реверсивный просмотр Second
	cout << "Реверсивный просмотр Second" << endl;
	i = 1;
	for (deque<cake>::reverse_iterator itp = Second.rbegin(); itp != Second.rend(); ++itp, i++)
		cout << i << ")" << *itp << endl;
	i = 1;
	//Сортировки по возрастанию
	First.sort(Comparison);
	sort(Second.begin(), Second.end(), Comparison);
	//Просмотр First и Second
	cout << "Просмотр First после сортировки по возрастанию" << endl;
	for (auto it = First.begin(); it != First.end(); ++it, i++)
		cout << i << ")" << *it << endl;
	i = 1;
	cout << "Просмотр Second после сортировки по возрастанию" << endl;
	for (auto itp = Second.begin(); itp != Second.end(); ++itp, i++)
		cout << i << ")" << *itp << endl;
	i = 1;
	//Слияние и инициализация multimap
	multimap<cake, int> Third;
	auto it1 = First.begin();
	auto it2 = Second.begin();
	for (i = 0; i < First.size() + Second.size(); i++)
	{
		if (it1 != First.end())
		{
			Third.insert(pair<cake, int>(*it1, i + 10));
			++it1;
		}
		if (it2 != Second.end())
		{
			Third.insert(pair<cake, int>(*it2, i + 1));
			++it2;
		}
	}
	i = 1;
	//Вывод мультимэп
	cout << "Просмотр Third после присваивания ему элементов, полученных слиянием" << endl;
	for (auto it = Third.begin(); it != Third.end(); ++it, i++)
		cout << i << ")" << it->first << " : " << it->second << endl;
	i = 1;
	//Поиск элем по условиям
	int k = count_if(Third.begin(), Third.end(), MultiComparison);
	cout << "Кол-во элементов, содержащихся в Third, удовлетворяющих\nследующему условию: pair<cake, int> obj.first.price <=20 равно: ";
	cout << k << endl << endl;
	cout << "Проверка на то, есть ли определённый элемент,\nудовлетворяющий условию выше, в Third: ";
	if (any_of(Third.begin(), Third.end(), MultiComparison))
		cout << "true." << endl;
	else
		cout << "false." << endl;
	cout << endl;
	Func1 f1;
	Func2 f2;
	list<double> obj = { 2.0,3.5,4.5,5.3,6.7,7.0,2.1,2.4,10.5,11.0 };
	auto it99 = bind(f1, obj);
	cout << "Кол-во элементов > 5: " << it99() << endl;
	auto it199 = bind(f2, obj, 10);
	cout << "Кол-во элементов < 5: " << it199() << endl;
}