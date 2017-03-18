#pragma once
#include<assert.h>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;
//非递归版本
template<typename T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& data)
		: _data(data)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<typename T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()//构造
		:_root(NULL)
	{}

	BinaryTree(const T* arr,size_t size,const T& invalid)//构造
	{
		size_t index = 0;
		_root = _CreateTree(arr, size, index, invalid);
	}

	BinaryTree(BinaryTree<T>& t)//拷贝构造
	{
		_root = _Copy(t._root);
	}

	BinaryTree operator=(BinaryTree<T>& t)//赋值运算符重载
	{
		if (_root != t._root)
		{
			BinaryTree<T> temp(t);
			swap(_root, t._root);
		}
		return *this;
	}

	~BinaryTree()//析构
	{
		_Destory(_root);
	}

	void PrevOrder()//前序遍历
	{
		size_t index = 0;
		_PrintPrev(_root);
	}

	void InOrder()//中序遍历
	{
		_PrintIn(_root);
	}

	void BackOrder()//后序遍历
	{
		_PrintBack(_root);
	}

	void PrevOrderNon()//非递归前序遍历
	{
		size_t index = 0;
		_PrintPrevNon(_root);
	}

	void InOrderNon()//非递归中序遍历
	{
		_PrintInNon(_root);
	}

	void BackOrderNon()//非递归后序遍历
	{
		_PrintBackNon(_root);
	}


	//BinaryTree(const T* arr, size_t size, const T& invalid)//建树非递归
	//{
	//	Node* cur = NULL;
	//	stack<Node*> s;
	//	size_t index = 0;
	//	while (index < size)
	//	{
	//		while (index < size && arr[index] != invalid)
	//		{
	//			if (index == 0)//根节点特殊处理
	//			{
	//				_root = new Node[index++];
	//				cur = _root;
	//			}
	//			else
	//			{
	//				cur->_left = new Node[index++];
	//				cur = cur->_left;
	//			}
	//			s.push(cur);
	//		}
	//		index++;
	//		Node* top = s.top();
	//		s.pop();
	//		if (index < size && arr[index] != invalid)//如果右子树的根节点不为空，在创建
	//		{
	//			cur = top;
	//			cur->_right = new Node[index++];
	//			cur = cur->_right;
	//			s.push(cur);
	//		}
	//	}
	//}



protected:
	Node* _CreateTree(const T* arr, size_t size, size_t& index, const T& invalid)//建树
	{
		assert(arr);
		Node* root = NULL;
		if (index < size && arr[index] != invalid)
		{
			root = new Node(arr[index]);
			root->_left = _CreateTree(arr, size, ++index, invalid);//注意要将index先进行++
			root->_right = _CreateTree(arr, size, ++index, invalid);
		}
		return root;
	}

	Node* _Copy(Node* node)//拷贝
	{
		Node* cur = node;
		Node* root = NULL;
		if (cur)
		{
			root = new Node(cur->_data);
			root->_left = _Copy(cur->_left);
			root->_right = _Copy(cur->_right);
		}
		return root;
	}

	void _Destory(Node* root)//析构销毁
	{
		Node* cur = root;
		if (cur)
		{
			_Destroy(cur->_left);
			_Destroy(cur->_right);
			delete cur;
			cur = NULL;
		}
	}

	void _PrintPrev(Node* root)//递归前序打印
	{
		if (NULL == root)
			return;
		Node* cur = root;
		cout << cur->_data<<" ";
		_PrintPrev(cur->_left);
		_PrintPrev(cur->_right);
	}

	void _PrintIn(Node* root)//递归中序打印
	{
		if (NULL == root)
			return;
		Node* cur = root;
		_PrintIn(cur->_left);
		cout << cur->_data<<" ";
		_PrintIn(cur->_right);
	}

	void _PrintBack(Node* root)//递归后序打印
	{
		if (root == NULL)
			return;
		Node* cur = root;
		_PrintBack(cur->_left);
		_PrintBack(cur->_right);
		cout << cur->_data << " ";
	}

	void _PrintPrevNon(Node* root)//非递归前序遍历
	{
		if (NULL == root)
			return;
		Node* cur = root;
		stack<Node*> s;
		while (cur||!s.empty())
		{
			while (cur)
			{
				cout << cur->_data << " ";
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();//定义top保存当前的位置防止出现野指针
			s.pop();
			cur = top->_right;
		}
	}

	void _PrintInNon(Node* root)//非递归中序遍历
	{
		Node* cur = root;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			cout << top->_data << " ";
			s.pop();
			if (top->_right)
				cur = top->_right;
		}
	}

	void _PrintBackNon(Node* root)//非递归后序遍历
	{
		Node* cur = root;
		Node* prev = NULL;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			if (top->_right == NULL || top->_right == prev)//如果等于当前节点的右为空，或者当前节点的右等于prev
			{
				cout << top->_data << " ";
				prev = top;
				s.pop();
			}
			else
			{
				cur = top->_right;
			}
		}
	}


private:
	Node* _root;
};

void TestBinaryTreeNon()
{
	/*int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t(array1, 10, '#');
	t.PrevOrder();
	cout << endl;
	BinaryTree<int> t1(t);
	t1.InOrder();
	cout << endl;
	BinaryTree<int> t2;
	t2 = t;
	t2.BackOrder();*/

	int array2[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> tt(array2, 10, '#');
	tt.PrevOrderNon();
	cout << endl;
	BinaryTree<int> tt1(tt);
	tt1.InOrderNon();
	cout << endl;
	BinaryTree<int> tt2;
	tt2 = tt;
	tt2.BackOrderNon();
}