#pragma once
#include<iostream>
template<class K>
struct Node
{
	K _data;
	Node<K>* _left;
	Node<K>* _right;
	Node(K data = 0) : _data(data), _left(nullptr), _right(nullptr){}
};

template<class K>
class BinarySearchTree
{
	typedef Node<K>* BTNode;
public:
	BinarySearchTree() :_root(nullptr) {}
	bool Add(const K& data)
	{
		if (_root == nullptr)
		{
			_root = new Node<K>(data);
			return true;
		}
		else
		{
			BTNode cur = _root;
			BTNode parent = nullptr;
			while (cur)
			{
				if (cur->_data > data)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_data < data)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					std::cout << "Data already exist.\n";
					return false;
				}
			}
			if (data > parent->_data)
			{
				BTNode newNode = new Node<K>(data);
				parent->_right = newNode;
			}
			else
			{
				BTNode newNode = new Node<K>(data);
				parent->_left = newNode;
			}
			return true;
		}
	}

	//Insert a data using recursion.
	bool AddR(const K& data)
	{
		return _AddR(_root, data);
	}

	BTNode find(const K& data)
	{
		BTNode cur = _root;
		while (cur)
		{
			if (cur->_data < data)
			{
				cur = cur->_right;
			}
			else if (cur->_data > data)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	void erase(const K& data)
	{
		BTNode cur = _root;
		BTNode parent = _root;
		while (cur)
		{
			if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				break;
			}
		}
		if (!cur)
		{
			std::cout << "Delete failed. Data no found!\n";
			return;
		}
		if (cur->_left == nullptr)
		{
			if (cur == _root)
			{
				_root = _root->_right;
				delete cur;
			}
			else
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_right;
					delete cur;
				}
				else
				{
					parent->_right = cur->_right;
					delete cur;
				}
			}
		}
		else if (cur->_right == nullptr)
		{
			if (cur == _root)
			{
				_root = _root->_left;
				delete cur;
			}
			else
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_left;
					delete cur;
				}
				else
				{
					parent->_right = cur->_left;
					delete cur;
				}
			}
		}
		else
		{
			//find the max value of left tree   or    find the min value of right tree
			//save the value and delete it
			//replace cur position's data by the value
			BTNode maxNode = cur->_left;
			while (maxNode->_right)
			{
				maxNode = maxNode->_right;
			}
			K tmp = maxNode->_data;
			erase(maxNode->_data);
			cur->_data = tmp;
		}
	}

	void InOrder()
	{
		if (_root == nullptr)
		{
			std::cout << "list empty.\n";
			return;
		}
		_InOrder(_root);
	}

private:

	BTNode _root;
	void _InOrder(BTNode node)
	{
		if (node == nullptr)
		{
			return;
		}
		_InOrder(node->_left);
		std::cout << node->_data << " ";
		_InOrder(node->_right);
	}

	bool _AddR(BTNode& root,const K& data)
	{
		if (root == nullptr)
		{
			root = new Node<K>(data);
			return true; 
		}
		if (data > root->_data)
		{
			return _AddR(root->_right, data);
		}
		else if (data < root->_data)
		{
			return _AddR(root->_left , data);
		}
		else
		{
			return false;
		}
	}
};
