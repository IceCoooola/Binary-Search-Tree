#pragma once
#define CRT_SECURE_NO_WARNINGS
#include<iostream>

//tree node
template<class K>
struct Node 
{
	K _data;
	Node* _left;
	Node* _right;
	Node(K data = 0) : _data(data),_left(nullptr),_right(nullptr)
	{}
};

template<class K>
class BinarySearchTree 
{
	typedef Node<K>* BTNode;
public:
//default constructor
	BinarySearchTree() :_root(nullptr){}
//add one element, if no root, then create a root
//if larger than root, then go right and find the correct space. 
//if smaller than root, then go left and find the correct space.
	bool Add(const K& data)
	{
  //check if tree is empty
		if (_root == nullptr)
		{
			_root = new Node<K>(data);
			return true;
		}
		else
		{
      //current pointer place
			BTNode cur = _root;
      //current pointer's parent
			BTNode parent = nullptr;
			//while current pointer is not nullpointer 
      while (cur)
			{
      //if current pointer's data is larger than new data
      //then go left
				if (cur->_data > data)
				{
					parent = cur;
					cur = cur->_left;
				}
      //if current pointer's data is smaller than new data
      //then go right
				else if(cur->_data < data)
				{
					parent = cur;
					cur = cur->_right;
				}
        //if the data already exist, then return false
				else
				{
					std::cout << "Data already exist.\n";
					return false;
				}
			}
      //if new data is larger than parent's data, then add the element to parent's right
			if (data > parent->_data)
			{
				BTNode newNode = new Node<K>(data);
				parent->_right = newNode;
			}
      //else add it to left
			else
			{
				BTNode newNode = new Node<K>(data);
				parent->_left = newNode;
			}
			return true;
		}
	}

	void InOrder()
	{
  //recursively traverse. in order
		_InOrder(_root);
	}

private:
	BTNode _root;
  
  //Inorder's sub function.
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
};
