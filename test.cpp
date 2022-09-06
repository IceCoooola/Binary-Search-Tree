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
	t.Add(1);
	t.InOrder();
	cout << endl;
	t.Add(3);
	t.InOrder();
	cout << endl;
	t.Add(2);
	t.InOrder();
	cout << endl;
	t.Add(6);
	t.InOrder();
	cout << endl;
	return 0;
}

