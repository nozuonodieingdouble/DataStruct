#pragma once
#include<assert.h>
#include<iostream>
#include<queue>

using namespace std;
//递归版本
template<typename T>
struct TreeNode
{
	T _data;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	TreeNode(const T& data=T())
		: _data(data)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<typename T>
class Tree
{
	typedef TreeNode<T> Node;
public:
	Tree()
		:_root(NULL)
	{}

	Tree(const T* arr, size_t size, const T& invalid)
	{
		size_t index = 0;
		_root = _CreateTree(arr, size, index, invalid);
	}

	Tree(const Tree<T>& t)//拷贝构造
	{
		_root = _Copy(t._root);
	}

	Tree& operator=(Tree<T>& t)//赋值运算符重载
	{
		if (_root != t._root)
		{
			Tree<T> tmp(t);
			swap(_root, t._root);
		}
		return *this;
	}

	~Tree()//析构
	{
		_Destory(_root);
	}

	size_t Depth()//求树的深度
	{
		return _Depth(_root);
	}

	size_t LeafCount()//求叶结点个数
	{
		return _LeafCount(_root);
	}

	size_t NodeCount()//求节点个数
	{
		return _NodeCount(_root);
	}

	void PreOrder()//前序遍历
	{
		_PrinPrev(_root);
	}

	void InOrder()//中序遍历
	{
		_PrinIn(_root);
	}

	void BackOrder()//后序遍历
	{
		_PrinBack(_root);
	}

	void CenOrder()
	{
		_PrintTier(_root);
	}

	Node* Find(const T& x)//查找一个结点
	{
		return _Find(_root, x);
	}

	size_t GetLeafK(size_t k)
	{
		return _GetLeafK(_root, k);
	}

protected:
	Node* _CreateTree(const T* arr, size_t size, size_t& index, const T& invalid)//建树
	{
		assert(arr);
		Node* root = NULL;
		if (index < size && arr[index] != invalid)
		{
			root = new Node(arr[index]);
			root->_left = _CreateTree(arr, size, ++index, invalid);
			root->_right = _CreateTree(arr, size, ++index, invalid);
		}
		return root;
	}

	Node* _Copy(Node* node)//拷贝构造
	{
		Node* root = NULL;
		Node* cur = node;
		if (cur)
		{
			root = new Node(cur->_data);
			root->_left = _Copy(cur->_left);
			root->_right = _Copy(cur->_right);
		}
		return root;
	}

	void _Destory(Node* node)
	{
		Node* cur = node;
		if (cur)
		{
			_Destory(cur->_left);
			_Destory(cur->_right);
			delete cur;
			cur = NULL;
		}
	}

	size_t _Depth(Node* root)
	{
		Node* cur = root;
		if (root == NULL)
			return NULL;
		return _Depth(root->_left) > _Depth(root->_right) ? _Depth(root->_left) + 1 : _Depth(root->_right) + 1;
	}

	size_t _LeafCount(Node* root)
	{
		Node* cur = root;
		if (NULL == root)
			return 0;
		if (cur->_left == NULL && cur->_right == NULL)
			return 1;
		return _LeafCount(cur->_left) + _LeafCount(cur->_right);
	}
	
	size_t _NodeCount(Node* root)
	{
		Node* cur = root;
		if (NULL == root)
			return 0;
		if (cur)
			return 1;
		return (_NodeCount(cur->_left) + _NodeCount(cur->_right) + 1);
	}

	void _PrinPrev(Node* root)//前序输出
	{
		if (NULL == root)
			return;
		cout << root->_data << " ";
		_PrinPrev(root->_left);
		_PrinPrev(root->_right);
	}

	void _PrinIn(Node* root)//中序输出
	{
		if (NULL == root)
			return;
		_PrinIn(root->_left);
		cout << root->_data << " ";
		_PrinIn(root->_right);
	}

	void _PrinBack(Node* root)//后序输出
	{
		Node* cur = root;
		if (NULL == root)
			return;
		if (cur)
		{
			_PrinBack(cur->_left);
			_PrinBack(cur->_right);
			cout << cur->_data << " ";
		}
	}

	void _PrintTier(Node* root)//层序遍历
	{
		if (root == NULL)
			return;
		queue<Node*> q;
		Node* cur = root;
		q.push(cur);
		while (cur)
		{
			Node* tmp = q.front();
			cout << tmp->_data << endl;
			if (tmp->_left)
				q.push(tmp->_left);
			if (tmp->_right)
				q.push(tmp->_right);
			q.pop();
		}
	}

	Node* _Find(Node* root, const T& x)
	{
		if (NULL == root)
			return NULL;
		if (root->_data == x)
			return root;
		Node* cur = _Find(root->_left,x);
		if (cur == NULL)
			cur = _Find(root->_right, x);
		return cur;
	}

	size_t _GetLeafK(Node* root, size_t k)
	{
		if (root == NULL)
			return NULL;
		if (k <= 1)
			return k;
		return _GetLeafK(root->_left, k - 1) + _GetLeafK(root->_right, k - 1);
	}
private:
	Node* _root;
};


void TestTree()
{
	int array[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	Tree<int> t(array, 10, '#');
	Tree<int> t1(t);
	Tree<int> t2;
	t2 = t1;
	size_t retDep = t.Depth();
	size_t retLea = t.LeafCount();
	size_t retNodeCount = t.NodeCount();
	cout << retDep << endl;
	cout << retLea << endl;
	cout << retNodeCount << endl;
	t.PreOrder();
	cout << endl;
	t2.BackOrder();
	cout << endl;
	int array1[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	Tree<int> t4(array1, 15, '#');
	t4.InOrder();
	cout << endl;
	cout << t.Find(2) << endl;
	cout << t.GetLeafK(2) << endl;
}