#pragma once

#include "Heap.h"

template<class T>
struct HuffmanTreeNode
{
	T _w;
	HuffmanTreeNode<T>* _right;
	HuffmanTreeNode<T>* _left;
	HuffmanTreeNode<T>* _parent;

	HuffmanTreeNode(const T& w)
		: _w(w)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};

template <class T>
class HumanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	HumanTree()
		: _root(NULL)
	{}

	HumanTree(T* a, size_t n, const T& invalid = T())
	{
		struct Compare
		{
			bool operator()(Node* l, Node* r) const
			{
				return l->_w < r->_w;
			}
		};
		Heap<Node*, Compare> minHeap;	//为了节省空间传指针
		for (size_t i = 0; i < n; ++i)
		{
			if (a[i] != invalid)
				minHeap.Push(new Node(a[i]));
		}

		while (minHeap > 1)
		{
			Node* left = minHeap.Top();
			minHeap.Pop();
			Node* right = minHeap.Top();
			minHeap.Pop();

			Node* parent = new Node(left->_w + right->_w);
			parent->_left = left;
			left->_parent = parent;
			parent->_right = right;
			right->_parent = parent;
			minHeap.Push(parent);
		}
		_root = minHeap.Top();
	}

	~HumanTree()
	{
		_Destroy(_root);
	}

	void _Destroy(Node* root)
	{
		if (root == NULL)
			return;
		_Destroy(root->_left);
		_Destroy(root->_rihgt);
		delete root;
		root = NULL;
	}

	Node* GetRoot();

private:
	//将拷贝构造和赋值运算符声明为防拷贝的
	HumanTree(const HumanTree<T>&);
	HumanTree& operator=(const HumanTree<T>&);

protected:
	Node* _root;
};

void TestHufumanTree()
{
	int a[] = { 0, 3, 1, 2, 6, 5, 7, 8, 9, 4 };
	HumanTree<int> ht(a, sizeof(a) / sizeof(a[0]));
}
