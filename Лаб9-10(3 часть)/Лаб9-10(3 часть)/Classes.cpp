#include "Classes.h"

void cake::set()
{
	cout << "Введите название: "; cin >> name;
	cout << "Введите вес: "; cin >> weight;
	cout << "Введите цену: "; cin >> price;
}
void cake::set(string Name)
{
	name = Name;
}
void cake::set(int Price)
{
	price = Price;
}
void cake::set(int Weight, int Price)
{
	weight = Weight;
	price = Price;
}
void cake::set(string Name, int Weight, int Price)
{
	name = Name;
	weight = Weight;
	price = Price;
}
void cake::get()
{
	cout << "1)" << name << endl;
	cout << "2)Вес " << weight << endl;
	cout << "3)Цена " << price << endl;
}
int cake::getPrice()
{
	return this->price;
}
//Функторы


//Friend-функции
bool Comparison(cake obj1, cake obj2)
{
	if (obj1.name < obj2.name)
		return true;
	else
	{
		if (obj1.weight < obj2.weight)
			return true;
		else
		{
			if (obj1.price < obj2.price)
				return true;
			else
				return false;
		}
	}
}
bool PriceIf(cake obj)
{
	if (obj.price < 20)
		return false;
	else return true;
}
bool MultiComparison(pair<cake, int> obj)
{
	if (obj.first.price <= 20)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, cake obj)
{
	os << "\n\t1." << obj.name << "\n\t2." << obj.weight << "\n\t3." << obj.price << endl;
	return os;
}
bool operator==(cake obj1, cake obj2)
{
	return (obj1.name == obj2.name && obj1.weight == obj2.weight && obj1.price == obj2.price);
}
bool operator<(cake obj1, cake obj2)
{
	if (obj1.name < obj2.name)
		return true;
	else
	{
		if (obj1.weight < obj2.weight)
			return true;
		else
		{
			if (obj1.price < obj2.price)
				return true;
			else
				return false;
		}
	}
}