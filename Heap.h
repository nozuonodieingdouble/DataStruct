#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

//堆属于一个静态的二叉树，底层的存储方式实际上是数组

template<class T>
struct Less
{
	bool operator()(const T&l, const T& r)
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T&l, const T& r)
	{
		return l > r;
	}
};



template<class T,class Compare>
class Heap
{
public:
	Heap()	//无参的构造函数
	{}

	Heap(T* a, size_t n)	//右参的构造函数
	{
		//建初堆
		_a.reserve(n);		//只是单纯的开空间，在此使用reserve更好一下可以减少一次开空间的开销
		for (size_t i = 0; i < n; ++i)
		{
			_a.push_back(a[i]);
		}

		//_a.resize(n);			//开空间并初始化
		//for (size_t i = 0; i < n; ++i)
		//{
		//	_a[i] = a[i];
		//}

		//调整——从第一非叶节点开始调整，因为认为叶子节点是大堆

		for (size_t i = (_a.size() - 2) / 2; i >= 0; --i)	//相减1算下标，在减1算左孩子
		{
			AdjustDown(i);
		}
	}

	void Push(const T& x)	//在最后面插入一个数据，插入之后要进行调整
	{
		_a.push_back(x);
		AdjustUp(_a.size() - 1);
	}

	void Pop()		//删除堆顶,先和最后一个叶子节点相交换，然后删除堆尾元素，在进行向下调整
	{
		assert(!_a.empty());
		swap(a[0], a[_a.size() - 1]);
		_a.pop_back();
		AdjustDown(0);
	}

	bool isHeap();	//判断是否是堆

protected:
	void AdjustUp(int child)		//用来保证插入以后依然为堆
	{
		Compare comFunc;
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (comFunc(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}

	}


	void AdjustDown(int root)	//用来建堆
	{
		Compare comFunc;
		int parent = root;
		int child = parent * 2 + 1;
		while (child < _a.size())
		{
			if (child + 1 < _a.size() && comFunc(_a[child + 1], _a[child])/* && a[child + 1]*/)//防止右孩子不存在发生越界
			{
				++child;
			}

			if (comFunc(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	vector<T> _a;
};

void TestHeap()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int, Less<int>> hp(a, sizeof(a) / sizeof(a[0]));
	hp.Pop();
	hp.Push(30);
}