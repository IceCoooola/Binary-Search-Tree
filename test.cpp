#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include"BinarySearchTree.h"
int main()
{
	BinarySearchTree<int> t;
	t.Add(4);
	t.InOrder();
	cout << endl;
	Node<int>* tt = t.find(2);
	if (tt)
	{
		cout << tt->_data<< " found\n";
	}
	t.Add(1);
	t.InOrder();
	cout << endl;
	t.Add(3);
	t.InOrder();
	cout << endl;
	Node<int>* tt2 = t.find(3);
	if (tt2)
	{
		cout << tt2->_data << " found\n";
	}
	t.Add(2);
	t.InOrder();
	cout << endl;
	t.Add(6);
	t.InOrder();
	cout << endl;
	t.erase(2);
	t.InOrder();
	cout << endl;
	t.erase(3);
	t.InOrder();
	cout << endl;
	t.erase(1);
	t.InOrder();
	cout << endl;
	t.erase(4);
	t.InOrder();
	cout << endl;
	t.erase(6);
	t.InOrder();
	cout << endl;

	return 0;
}
