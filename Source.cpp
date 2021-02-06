#include <iostream>
#include <queue>
#include <iterator>
#include <vector>
#include <string>
using namespace std;
queue <string> que_list;
int GetSize() 
{
	int size;
	cout << "Введите длину очереди:\t";
	//cin.ignore();
	while (!(cin >> size) || (cin.peek() != '\n') || size < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число:\t";
	}
	return size;
}
void Create_que(int size) 
{
	for (int i = 0; i < size; i++) 
	{
		string tmp;
		cout << "Введите " << i << "-й элемент очереди:\t";
		cin >> tmp;
		que_list.push(tmp);
	}
}
void Print_que() 
{
	vector <string> tmp;
	int i = 0;
	while (!que_list.empty()) 
	{
		cout << i << "-й элемент очереди:\t" << que_list.front() << endl;
		tmp.push_back(que_list.front());
		que_list.pop();
		i++;
	}
	for (int j = 0; j < tmp.size(); j++) 
	{
		que_list.push(tmp[j]);
	}
}
bool Add_element() 
{
	string value;
	vector <string> tmp;
	bool check = false;
	cout << "Введите значение, после которого нужно добавить элемент:\t";
	cin >> value;
	while (!que_list.empty())
	{
		
		tmp.push_back(que_list.front());
		que_list.pop();
		
	}
	
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == value)
		{
			check = true;
			que_list.push(tmp[i]);
			string temp;
			cout << "Введите значение нового элемента в очереди:\t";
			cin >> temp;
			que_list.push(temp);
		}
		else
		{
			que_list.push(tmp[i]);
		}
	}
	return check;
}
int main() 
{
	setlocale(LC_ALL, "ru");
	int size = GetSize();
	Create_que(size);
	cout << "================================================" << endl;
	cout << "Изначальная очередь:" << endl;
	Print_que();
	cout << "================================================" << endl;

	if (Add_element()) 
	{
		cout << "================================================" << endl;
		cout << "Очередь после добавления:" << endl;
		Print_que();
		cout << "================================================" << endl;
	}
	else 
	{
		cout << "Такого элемента в очереди нет" << endl;
	}

}