#pragma once
#include<iostream>

namespace K 
{
	template<class K>
	struct Node
	{
		K _data;
		Node<K>* _left;
		Node<K>* _right;
		Node(K data = 0) : _data(data), _left(nullptr), _right(nullptr) {}
	};

	template<class K>
	class BinarySearchTree
	{
		typedef Node<K>* BTNode;
	public:

		BinarySearchTree() :_root(nullptr) {}

		BinarySearchTree(const BinarySearchTree<K>& root)
		{
			_root = _copy(root._root);
		}

		BinarySearchTree<K>& operator=(BinarySearchTree<K> copy)
		{
			swap(_root, copy._root);
			return *this;
		}

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

		bool eraseR(const K& data)
		{
			return _eraseR(_root, data);
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

		BTNode _copy(const BTNode& root)
		{
			if (root == nullptr)
				return nullptr;
			BTNode copy = new Node<K>(root->_data);
			copy->_left = _copy(root->_left);
			copy->_right = _copy(root->_right);
			return copy;
		}

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

		bool _AddR(BTNode& root, const K& data)
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
				return _AddR(root->_left, data);
			}
			else
			{
				return false;
			}
		}

		bool _eraseR(BTNode& root, const K& data)
		{
			if (root == nullptr)
				return false;
			if (data > root->_data)
			{
				return _eraseR(root->_right, data);
			}
			else if (data < root->_data)
			{
				return _eraseR(root->_left, data);
			}
			else
			{
				if (root->_left == nullptr)
				{
					BTNode del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					BTNode del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					BTNode minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					int min = minRight->_data;
					_eraseR(root->_right, min);
					root->_data = min;
				}
				return true;
			}
		}
	};
}

namespace KV
{
	template<class K, class V>
	struct Node
	{
		K _key;
		V _value;
		Node<K, V>* _left;
		Node<K, V>* _right;
		Node(K key = 0, V value = 0) : _key(key), _value(value), _left(nullptr), _right(nullptr) {}
	};

	template<class K, class V>
	class BinarySearchTree
	{
		typedef Node<K, V>* BTNode;
	public:

		BinarySearchTree() :_root(nullptr) {}

		BinarySearchTree(const BinarySearchTree<K, V>& root)
		{
			_root = _copy(root._root);
		}

		BinarySearchTree<K, V>& operator=(BinarySearchTree<K, V> copy)
		{
			swap(_root, copy._root);
			return *this;
		}

		bool Add(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node<K, V>(key, value);
				return true;
			}
			else
			{
				BTNode cur = _root;
				BTNode parent = nullptr;
				while (cur)
				{
					if (cur->_key > key)
					{
						parent = cur;
						cur = cur->_left;
					}
					else if (cur->_key < key)
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
				if (key > parent->_key)
				{
					BTNode newNode = new Node<K, V>(key, value);
					parent->_right = newNode;
				}
				else
				{
					BTNode newNode = new Node<K, V>(key, value);
					parent->_left = newNode;
				}
				return true;
			}
		}

		//Insert a data using recursion.
		bool AddR(const K& key, const V& value)
		{
			return _AddR(_root, key, value);
		}

		BTNode find(const K& key)
		{
			BTNode cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
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

		void erase(const K& key)
		{
			BTNode cur = _root;
			BTNode parent = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
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
				K tmpKey = maxNode->_key;
				V tmpValue = maxNode->_value;
				erase(maxNode->_key);
				cur->_key = tmpKey;
				cur->_value = tmpValue;
			}
		}

		bool eraseR(const K& key)
		{
			return _eraseR(_root, key);
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

		BTNode _copy(const BTNode& root)
		{
			if (root == nullptr)
				return nullptr;
			BTNode copy = new Node<K, V>(root->_key, root->_value);
			copy->_left = _copy(root->_left);
			copy->_right = _copy(root->_right);
			return copy;
		}

		void _InOrder(BTNode node)
		{
			if (node == nullptr)
			{
				return;
			}
			_InOrder(node->_left);
			std::cout << node->_key << " -> "<<node->_value<<std::endl;
			_InOrder(node->_right);
		}

		bool _AddR(BTNode& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				root = new Node<K, V>(key, value);
				return true;
			}
			if (key > root->_key)
			{
				return _AddR(root->_right, key, value);
			}
			else if (key < root->_key)
			{
				return _AddR(root->_left, key, value);
			}
			else
			{
				return false;
			}
		}

		bool _eraseR(BTNode& root, const K& key)
		{
			if (root == nullptr)
				return false;
			if (key > root->_key)
			{
				return _eraseR(root->_right, key);
			}
			else if (key < root->_key)
			{
				return _eraseR(root->_left, key);
			}
			else
			{
				if (root->_left == nullptr)
				{
					BTNode del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					BTNode del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					BTNode minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K minK = minRight->_key;
					V minV = minRight->_value;
					_eraseR(root->_right, minK);
					root->_key = minK;
					root->_value = minV;
				}
				return true;
			}
		}
	};
}
