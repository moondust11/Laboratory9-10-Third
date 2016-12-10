#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <deque>
#include <iterator>
#include <memory>
#include <map>
#include <functional>

using namespace std;

class cake
{
private:
	string name;
	int weight;
	int price;
public:
	~cake()
	{
		name = "Не определён";
		weight = NULL;
		price = NULL;
	}
	cake() : name("Не определён"), weight(NULL), price(NULL)
	{}
	cake(string Name, int Weight, int Price) : weight(Weight), price(Price), name(Name)
	{}
	void set();
	void set(string Name);
	void set(int Price);
	void set(int Weight, int Price);
	void set(string Name, int Weight, int Price);
	void get();
	int getPrice();
	friend ostream& operator<<(ostream& os, cake obj);
	friend bool Comparison(cake obj1, cake obj2);
	friend bool operator==(cake obj1, cake obj2);
	friend bool operator<(cake obj1, cake obj2);
	friend bool PriceIf(cake obj);
	friend bool MultiComparison(pair<cake, int> obj);
};

struct Func1
{
	int operator()(list<double> &obj)
	{
		int k = 0;
		for (auto it : obj)
		{
			if (it > 5)
				k++;
		}
		return k;
	}
};

struct Func2
{
	int operator()(list<double> &obj, int l)
	{
		int k = 0;
		for (auto it : obj)
		{
			if (it < l)
				k++;
		}
		return k;
	}
};