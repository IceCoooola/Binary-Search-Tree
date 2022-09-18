#define CRT_SECURE_NO_WARNINGS
#include"BinarySearchTree.h"
#include<string>


int main()
{
	K::BinarySearchTree<int> bt;
	bt.AddR(1);
	bt.AddR(22);
	bt.AddR(3);
	bt.AddR(44);
	bt.AddR(-1);
	bt.AddR(61);
	bt.InOrder();
	K::BinarySearchTree<int> btcpy(bt);
	std::cout << std::endl << "test constructor copy node:\n";
	btcpy.InOrder();
	std::cout << std::endl << "test constructor copy node:\n";
	K::BinarySearchTree<int>btcpy2 = bt;
	btcpy2.InOrder();
	std::cout << std::endl<< "deleting 1 :" << std::endl;
	bt.eraseR(1);
	bt.InOrder();
	std::cout << std::endl << "deleting 3 :" << std::endl;
	bt.eraseR(3);
	bt.InOrder();
	std::cout << std::endl << "deleting 61:" << std::endl;
	bt.eraseR(61);
	bt.InOrder();
	std::cout << std::endl << "deleting -1:" << std::endl;
	bt.eraseR(-1);
	bt.InOrder();
	std::cout << std::endl << "deleting 22:" << std::endl;
	bt.eraseR(22);
	bt.InOrder();
	std::cout << std::endl << "deleting 44:" << std::endl;
	bt.eraseR(44);
	bt.InOrder();

	KV::BinarySearchTree<std::string, std::string> bts;
	bts.Add("apple", "苹果");
	bts.Add("orange", "橘子");
	bts.Add("cucumber", "黄瓜");
	bts.Add("banana", "香蕉");
	bts.Add("pen", "笔");
	bts.InOrder();
	KV::Node<std::string, std::string>* ret = bts.find("pen");
	std::cout << ret->_key << " -> "<< ret->_value<<" translation is found\n";
	bts.erase("banana");
	bts.AddR("anime", "动漫");
	bts.eraseR("pen");
	bts.InOrder();
	return 0;
}
