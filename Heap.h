#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

//������һ����̬�Ķ��������ײ�Ĵ洢��ʽʵ����������

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
	Heap()	//�޲εĹ��캯��
	{}

	Heap(T* a, size_t n)	//�ҲεĹ��캯��
	{
		//������
		_a.reserve(n);		//ֻ�ǵ����Ŀ��ռ䣬�ڴ�ʹ��reserve����һ�¿��Լ���һ�ο��ռ�Ŀ���
		for (size_t i = 0; i < n; ++i)
		{
			_a.push_back(a[i]);
		}

		//_a.resize(n);			//���ռ䲢��ʼ��
		//for (size_t i = 0; i < n; ++i)
		//{
		//	_a[i] = a[i];
		//}

		//���������ӵ�һ��Ҷ�ڵ㿪ʼ��������Ϊ��ΪҶ�ӽڵ��Ǵ��

		for (size_t i = (_a.size() - 2) / 2; i >= 0; --i)	//���1���±꣬�ڼ�1������
		{
			AdjustDown(i);
		}
	}

	void Push(const T& x)	//����������һ�����ݣ�����֮��Ҫ���е���
	{
		_a.push_back(x);
		AdjustUp(_a.size() - 1);
	}

	void Pop()		//ɾ���Ѷ�,�Ⱥ����һ��Ҷ�ӽڵ��ཻ����Ȼ��ɾ����βԪ�أ��ڽ������µ���
	{
		assert(!_a.empty());
		swap(a[0], a[_a.size() - 1]);
		_a.pop_back();
		AdjustDown(0);
	}

	bool isHeap();	//�ж��Ƿ��Ƕ�

protected:
	void AdjustUp(int child)		//������֤�����Ժ���ȻΪ��
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


	void AdjustDown(int root)	//��������
	{
		Compare comFunc;
		int parent = root;
		int child = parent * 2 + 1;
		while (child < _a.size())
		{
			if (child + 1 < _a.size() && comFunc(_a[child + 1], _a[child])/* && a[child + 1]*/)//��ֹ�Һ��Ӳ����ڷ���Խ��
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