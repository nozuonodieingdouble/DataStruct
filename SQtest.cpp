//#define _CRT_SECURE_NO_WARNINGS 1
//
////1. ʵ��һ��ջ��Ҫ��ʵ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1)
//#include<iostream>
//using namespace std;
//#include<assert.h>
//#include<stack>
//
//template<class T>
//class Stack
//{
//public:
//	void Push(const T& data)
//	{
//		s.push(data);
//		if (min.empty())
//		{
//			min.push(data);
//		}
//		else
//		{
//			if (s.top() <= min.top())
//				min.push(data);
//		}
//	}
//
//	void Pop()
//	{
//		if (s.top() == min.top())
//			min.pop();
//		s.pop();
//	}
//
//	T& Min()
//	{
//		assert(!min.empty());
//		return min.top();
//	}
//
//protected:
//	stack<int> s;
//	stack<int> min;
//};
//
//int main()
//{
//	Stack<int> s1;
//	s1.Push(2);
//	s1.Push(4);
//	s1.Push(5);
//	s1.Push(1);
//	s1.Push(3);
//	cout <<"��ǰջ�е���Сֵ�ǣ�"<< s1.Min() << endl;
//	s1.Pop();
//	s1.Pop();
//	s1.Pop();
//	cout <<"pop����֮��ǰջ�е���Сֵ�ǣ�"<< s1.Min() << endl;
//
//	system("pause");
//	return 0;
//}
//
////template<class T>
////class Stack
////{
////public:
////	Stack()
////		: _ptr(NULL)
////		, _min(NULL)
////		, _size(0)
////		, _capacity(0)
////	{}
////
////	~Stack()
////	{
////		delete[] _ptr;
////		delete[] _min;
////		_ptr = NULL;
////	}
////
////	void Push(const T& data);
////	void Pop();
////	size_t Size();
////	bool Empty();
////	T& Top();
////	T Min();
////	void CheckCapacity();
////protected:
////	T* _ptr;
////	T* _min;
////	size_t _size;
////	size_t _capacity;
////};
////
////template<class T>
////void Stack<T>::Push(const T& data)
////{
////	CheckCapacity();
////	_ptr[_size] = data;
////	if (_size == 0)
////	{
////		_min[_size] = data;
////	}
////	else
////	{
////		if (data < _min[_size - 1])
////		{
////			_min[_size] = data;
////		}
////		else
////		{
////			_min[_size] = _min[_size - 1];
////		}
////	}
////	_size++;
////}
////
////template<class T>
////void Stack<T>::Pop()
////{
////	assert(_size >= 0);
////	--_size;
////}
////
////template<class T>
////size_t Stack<T>::Size()
////{
////	return (size_t)_size;
////}
////
////template<class T>
////bool Stack<T>::Empty()
////{
////	return _size == 0;
////}
////
////template<class T>
////T& Stack<T>::Top()
////{
////	return _ptr[_size - 1];
////}
////
////template<class T>
////T Stack<T>::Min()
////{
////	assert(_size >= 0);
////	return _min[_size - 1];
////}
////
////template<class T>
////void Stack<T>::CheckCapacity()
////{
////	if (_size >= _capacity)
////	{
////		int newCapacity = 2 * _capacity + 3;
////		T* tmp1 = new T[newCapacity];
////		T* tmp2 = new T[newCapacity];
////		for (size_t i = 0; i < _size; ++i)
////		{
////			tmp1[i] = _ptr[i];
////		}
////		delete[] _ptr;
////		_ptr = tmp1;
////		for (size_t i = 0; i < _size; ++i)
////		{
////			tmp2[i] = _min[i];
////		}
////		delete[] _min;
////		_min = tmp2;
////		_capacity = newCapacity;
////	}
////}
//
////int main()
////{
////	Stack<int> s;
////	s.Push(1);
////	s.Push(2);
////	s.Push(3);
////	s.Push(4);
////	s.Push(5);
////	cout << s.Min() << endl;
////	system("pause");
////	return 0;
////}
//
////2. ʹ������ջʵ��һ������
//#include <iostream>
//using namespace std;
//#include <stack>
//
//template<class T>
//class Queue
//{
//public:
//	void Push(const T& data)		//�ڶ�β���Ԫ��
//	{
//		input.push(data);
//	}
//
//	void Pop()		//ɾ����ͷԪ��
//	{
//		while (!input.empty())		//�Ƚ�����ջ�е����ݵ��뵽���ջ
//		{
//			output.push(input.top());
//			input.pop();
//		}
//
//		if (!output.empty())		//�ٽ�ջ�еĴ�ջ������pop�����պ����Ƚ�ȥ��
//		{
//			//input.push(output.top());
//			output.pop();
//		}
//	}
//protected:
//	stack<int> input;		//����ջ
//	stack<int> output;		//���ջ
//};
//
//int main()
//{
//	Queue<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	q.Push(5);
//
//	q.Pop();
//	q.Pop();
//	q.Pop();
//	q.Pop();
//	q.Pop();
//
//	system("pause");
//	return 0;
//}


//////3. ʹ����������ʵ��һ��ջ
//#include<iostream>
//using namespace std;
//
//#include<queue>
//#include<stack>
//
//template<class T>
//class Stack
//{
//public:
//	void Push(const T& data)
//	{
//		input.push(data);
//	}
//
//	void Pop()
//	{
//		while (input.size()>0)
//		{
//			output.push(input.front());
//			input.pop();
//		}
//		if (!output.empty())
//		{
//			//input.push(output.front());
//			output.pop();
//		}
//	}
//protected:
//	queue<int> input;
//	queue<int> output;
//};
//int main()
//{
//	Stack<int> s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	s.Push(5);
//
//	s.Pop();
//	s.Pop();
//	s.Pop();
//	s.Pop();
//	s.Pop();
//
//	system("pause");
//	return 0;
//}
//////4. Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�����ջ�����У�1, 2, 3, 4, 5������ջ����Ϊ��4, 5, 3, 2, 1��
//#include<iostream>
//using namespace std;
//#include<stack>
//#include<assert.h>
//#include<vector>
//�ж�һ����ջ�����Ƿ��ǺϷ��ĳ�ջ����
//template<class T>
//bool CheckStack(vector<T>& in, vector<T>& out)
//{
//	if (in.size() != out.size())
//		return false;
//
//	int idx_in = 0, idx_out = 0;
//	stack<T> s;
//	while (idx_out != out.size())
//	{
//		if (s.empty() || s.top() != out[idx_out])
//		{
//			if (idx_in == in.size())
//				return false;
//			s.push(in[idx_in++]);
//		}
//		else
//		{
//			++idx_out;
//			s.pop();
//		}
//	}
//	return true;
//}
//
//
//int main()
//{
//	vector<int> in;
//	in.push_back(1);
//	in.push_back(2);
//	in.push_back(3);
//	in.push_back(4);
//	in.push_back(5);
//
//	vector<int> out;
//	out.push_back(4);
//	out.push_back(5);
//	out.push_back(3);
//	out.push_back(2);
//	out.push_back(1);
//
//	vector<int> out1;
//	out1.push_back(4);
//	out1.push_back(5);
//	out1.push_back(3);
//	out1.push_back(1);
//	out1.push_back(2);
//
//	bool ret = CheckStack(in, out);
//	cout << ret << endl;
//
//	bool ret1 = CheckStack(in, out1);
//	cout << ret1 << endl;
//
//	system("pause");
//	return 0;
//}

//*********************
//template<class T>
//class StackIsSame
//{
//public:
//	void SetInQuence(const T& data)
//	{
//		inSequence.push_back(data);
//	}
//
//	void SetOutQuence(const T& data)
//	{
//		outSequence.push_back(data);
//	}
//
//	bool IsSame()
//	{
//		if (inSequence.size() != outSequence.size())
//		{
//			return false;
//		}
//
//		int sz = inSequence.size();
//		int idx = 0, jdx = 0;
//		while (idx < sz)
//		{
//			if (s.empty())		//���ջΪ�գ����������е�ֵѹջ
//			{
//				s.push(inSequence[idx]);
//					idx++;
//			}
//
//			if (s.top()!=outSequence[idx])		//����ջ��Ԫ�ز�����������еĵ�һ��Ԫ�أ�����������ѹջ
//			{
//				s.push(inSequence[idx])
//					idx++;
//			}
//
//			while (!s.empty() && s.top() == outSequence[idx])	//ֻҪջ��Ϊ����ջ��Ԫ�ص����������
//			{
//				s.pop();
//				idx++;
//				int i = 0, j = 0;
//				while (i < sz)
//				{
//					if (s.empty())	//���ջΪ����Ҫ��ջ
//					{
//						s.push(inSequence[i]);
//						i++;
//					}
//
//					while (s.top() != outSequence[i])	//���ջ��Ԫ��һֱ���������Ԫ��һֱ��ջ
//					{
//						s.push(inSequence[i]);
//						i++;
//					}
//
//					while (!s.empty() && s.top() == outSequence[i])
//					{
//						s.pop();
//						j++;
//					}
//				}
//				if (j == sz)
//				{
//					return true;
//				}
//				else
//				{
//					j--;
//					while (s.size() >= i)
//					{
//						s.pop();
//					}
//				}
//				s.push(inSequence[i - 1]);
//				s.push(inSequence[i]);
//				i++;
//			}
//		}
//		if (jdx == sz)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//protected:
//	stack<T> s;
//	vector<int> inSequence;
//	vector<int> outSequence;
//};
//
//int main()
//{
//	StackIsSame<int> SI;
//	SI.SetInQuence(1);
//	SI.SetInQuence(2);
//	SI.SetInQuence(3);
//	SI.SetInQuence(4);
//	SI.SetInQuence(5);
//
//	SI.SetOutQuence(4);
//	SI.SetOutQuence(5);
//	SI.SetOutQuence(3);
//	SI.SetOutQuence(2);
//	SI.SetOutQuence(1);
//
//	cout << SI.IsSame() << endl;
//
//	system("pause");
//	return 0;
//}

////5. һ������ʵ������ջ
//#include<iostream>
//using namespace std;
//#include<assert.h>
//
//template<class T>
//class DoubleStack
//{
//public:
//	DoubleStack()
//		: arr(NULL)
//		, size(0)
//		, capacity(0)
//		, top1(0)
//		, top2(0)
//	{}
//
//	~DoubleStack()
//	{
//		delete[] arr;
//	}
//
//	void Push(const T& data, int flag)
//	{
//		CheckCapacity();
//		if (flag == 0)
//		{
//			arr[top1++] = data;
//		}
//		else
//		{
//			arr[top2--] = data;
//		}
//	}
//
//	void Pop(int flag)
//	{
//		if (flag == 0)
//		{
//			assert(top1 > 0);
//			top1--;
//		}
//		else
//		{
//			assert(top2 < size);
//			top2++;
//		}
//	}
//
//	int& Top(int flag)
//	{
//		if (flag == 0)
//		{
//			assert(top1 > 0);
//			return arr[top1 - 1];
//		}
//		else(flag == 1)
//		{
//			assert(top2 < size);
//			return arr[top2 + 1];
//		}
//	}
//
//	void CheckCapacity()
//	{
//		if (top1 == top2)
//		{
//			size_t newCapacity = 2 * capacity + 5;
//			T* tmp = new T[newCapacity];
//			for (size_t i = 0; i < top1; ++i)
//			{
//				tmp[i] = arr[i];
//			}
//
//			int j = capacity - 1;
//			for (size_t i = newCapacity - 1; j>top2; --i,--j)
//			{
//				tmp[i] = arr[j];
//			}
//
//			delete[] arr;
//			arr = tmp;
//			size_t count = 0;		//����ڶ���ջԪ�صĸ���
//			if (capacity != 0)
//			{
//				count = capacity - 1 - top2;
//			}
//			capacity = newCapacity;
//			top2 = capacity - 1 - count;	//�޸�top2��ֵ
//			cout << capacity << endl;
//		}
//	}
//
//protected:
//	T* arr;
//	size_t size;
//	size_t capacity;
//	int top1;
//	int top2;
//};
//
//int main()
//{
//	DoubleStack<int> s;
//	s.Push(1,1);
//	s.Push(2,1);
//	s.Push(3,1);
//	s.Push(4,0);
//	s.Push(5,0);
//	s.Push(6,1);
//	s.Push(7,0);
//	s.Push(8,0);
//	s.Push(9,0);
//
//	system("pause");
//	return 0;
//}


#include<iostream>
using namespace std;
#include<stack>
#include<vector>


//vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//{
//	vector<int> vec;
//	if (size == 0 || num.size() < size)
//		return vec;
//	int max = 0;
//	int length = num.size();
//	for (int i = 0; i<size; i++)
//	{
//		if (num[i]>max)
//			max = num[i];
//	}
//	vec.push_back(max);	

//	for (int i = 1; i<length - size + 1; i++)
//	{
//		if (num[i + size - 1]>max)	//�����һ����ӵ�Ԫ�ش������ֵ������ֵ���
//		{
//			vec.push_back(num[i + size - 1]);
//			continue;
//		}
//		else
//		{
//			max = 0;		//�Ƚ�max�ó�0
//			for (int j = i; j<i + size; j++)
//			{
//				if (num[j]>max)
//					max = num[j];
//			}
//			vec.push_back(max);
//			continue;
//		}

//	}
//	return vec;
//}

//vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//{
//	vector<int> res;
//	deque<int> s;
//	for (unsigned int i = 0; i<num.size(); ++i)
//	{
//		while (s.size() && num[s.back()] <= num[i])//�Ӻ������ε��������бȵ�ǰnumֵС��Ԫ�أ�ͬʱҲ�ܱ�֤������Ԫ��Ϊ��ǰ�������ֵ�±�  
//			s.pop_back();
//		while (s.size() && i - s.front() + 1>size)//����ǰ�����Ƴ�����Ԫ�����ڵ�λ�ã�������Ԫ�������Ӧ��num���ڴ����У���Ҫ����        
//			s.pop_front();
//		s.push_back(i);//��ÿ�λ�����num�±�������          
//		if (size&&i + 1 >= size)//�����������׵�ַi���ڵ���sizeʱ�ſ�ʼд�봰�����ֵ             
//			res.push_back(num[s.front()]);
//	}
//	return res;
//}


//vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//{
//	vector<int> ret;			//���滬�����ڵ����ֵ
//	if (size == 0 || num.size()<size)	//�ų��Ƿ�����
//		return ret;
//
//	int max = 0;
//	int length = num.size();
//	for (int i = 0; i<size; ++i)		//Ѱ�ҵ�һ�λ������ڵ����ֵ
//	{
//		if (num[i] > max)
//			max = num[i];
//	}
//	ret.push_back(max);
//
//	for (int i = 1; i<length - size + 1; ++i)	//Ѱ����һ���������ڵ����ֵ
//	{
//		if (num[i + size - 1] > max)
//		{
//			ret.push_back(num[i + size - 1]);
//			continue;
//		}
//		else
//		{
//			max = 0;
//			for (int j = i; j<i + size; ++j)
//			{
//				if (num[j] > max)
//					max = num[j];
//			}
//			ret.push_back(max);
//			continue;
//		}
//	}
//	return ret;
//}
//
//
////�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ��
////����6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��
//int main()
//{
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(2);
//	v.push_back(6);
//	v.push_back(2);
//	v.push_back(5);
//	v.push_back(1);
//
//
//	vector<int> v1;
//	v1 = maxInWindows(v, 3);
//
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}





