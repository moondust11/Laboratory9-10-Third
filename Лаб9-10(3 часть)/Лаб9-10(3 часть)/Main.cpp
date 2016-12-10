#include <Windows.h>
#include "Classes.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//�������� � ������������� �������� ����������������� ����
	cake obj1("A", 1, 10), obj2("B", 2, 20), obj3("C", 3, 30), obj4("D", 4, 40);
	//�������� ������
	list<cake> First;
	//������������� ������
	First.push_front(obj3);
	First.push_back(obj1);
	First.push_front(obj4);
	First.push_back(obj2);
	//�������� ����
	deque<cake> Second(count_if(First.begin(), First.end(), PriceIf));
	//�������� ����������� First
	int i = 1;
	cout << "�������� ����������� First" << endl;
	for (auto it = First.begin(); it != First.end(); ++it, i++)
		cout << i << ")" << *it << endl;
	i = 1;
	//���������� First
	First.sort();
	//�������� ����������� First ����� ���������� �� ��������
	cout << "�������� ����������� First ����� ���������� �� ��������" << endl;
	for (auto it = First.begin(); it != First.end(); ++it, i++)
		cout << i << ")" << *it << endl;
	i = 1;
	//����� �������� �� ��������� �������
	cake temp("A", 1, 10);
	auto f = find(First.begin(), First.end(), temp);
	//����� ��������� ��������
	cout << "����� ��������� �������� �� �������: (A,1,10)" << endl;
	cout << *f << endl;
	//����������� ��������� �� First � Second �������� �������: Price >= 20
	copy_if(First.begin(), First.end(), Second.begin(), PriceIf);
	//����������� �������� Second
	cout << "����������� �������� Second" << endl;
	i = 1;
	for (deque<cake>::reverse_iterator itp = Second.rbegin(); itp != Second.rend(); ++itp, i++)
		cout << i << ")" << *itp << endl;
	i = 1;
	//���������� �� �����������
	First.sort(Comparison);
	sort(Second.begin(), Second.end(), Comparison);
	//�������� First � Second
	cout << "�������� First ����� ���������� �� �����������" << endl;
	for (auto it = First.begin(); it != First.end(); ++it, i++)
		cout << i << ")" << *it << endl;
	i = 1;
	cout << "�������� Second ����� ���������� �� �����������" << endl;
	for (auto itp = Second.begin(); itp != Second.end(); ++itp, i++)
		cout << i << ")" << *itp << endl;
	i = 1;
	//������� � ������������� multimap
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
	//����� ���������
	cout << "�������� Third ����� ������������ ��� ���������, ���������� ��������" << endl;
	for (auto it = Third.begin(); it != Third.end(); ++it, i++)
		cout << i << ")" << it->first << " : " << it->second << endl;
	i = 1;
	//����� ���� �� ��������
	int k = count_if(Third.begin(), Third.end(), MultiComparison);
	cout << "���-�� ���������, ������������ � Third, ���������������\n���������� �������: pair<cake, int> obj.first.price <=20 �����: ";
	cout << k << endl << endl;
	cout << "�������� �� ��, ���� �� ����������� �������,\n��������������� ������� ����, � Third: ";
	if (any_of(Third.begin(), Third.end(), MultiComparison))
		cout << "true." << endl;
	else
		cout << "false." << endl;
	cout << endl;
	Func1 f1;
	Func2 f2;
	list<double> obj = { 2.0,3.5,4.5,5.3,6.7,7.0,2.1,2.4,10.5,11.0 };
	auto it99 = bind(f1, obj);
	cout << "���-�� ��������� > 5: " << it99() << endl;
	auto it199 = bind(f2, obj, 10);
	cout << "���-�� ��������� < 5: " << it199() << endl;
}