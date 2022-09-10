#define CRT_SECURE_NO_WARNINGS
#include"BinarySearchTree.h"



int main()
{
	BinarySearchTree<int> bt;
	bt.AddR(1);
	bt.AddR(22);
	bt.AddR(3);
	bt.AddR(44);
	bt.AddR(-1);
	bt.AddR(61);
	bt.InOrder();
	BinarySearchTree<int> btcpy(bt);
	std::cout << std::endl << "test constructor copy node:\n";
	btcpy.InOrder();
	std::cout << std::endl << "test constructor copy node:\n";
	BinarySearchTree<int>btcpy2 = bt;
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

	return 0;
}
