#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
//const size_t N=10;

//template <typename T,size_t N>
//class Stack{
//public:
//protected:
//	int a[N];
//};
//template<typename T,size_t N>
//void TestStack()
//{
//	Stack<T,10> si;
//	Stack<T,20> s2;
//}
template<typename T>
class Stack{
public:
	Stack()
		:_a(NULL)
		,_size(0)
		,_capacity(0)
	{

	}
	~Stack(){
		delete[] _a;
		_a=NULL;
		_size=0;
		_capacity=0;
	}
	//拷贝构造
	//赋值重载
public:
	void Push(const T& x)
	{
		_CheckCapacity();
		_a[_size++]=x;
	}
	void Pop()
	{
		assert(_size);//条件为假时报错
		--_size;
	}
	T& Top() //出了作用域还有对象存在就用引用，否则传值//在前面加const防止s.Top()=10;//后const修饰this指针所指的对象
	{
		assert(_size);
		return _a[_size-1];
	}
	const T& Top() const//在前面加const防止s.Top()=10;//后const修饰this指针所指的对象fun(const Stack<int>&x)
	{
		assert(_size);
		return _a[_size-1];
	}
	size_t Size()
	{
		return _size;
	}
	bool Empty()
	{
		return _size==0;
	}
protected:
	void _CheckCapacity()
	{
		if (_size>=_capacity)
		{
			size_t newCapacity=_capacity*2+3;
			T* tmp=new T[newCapacity];
			if (_a!=NULL)
			{
				//memcpy(tmp,_a,_size*sizeof(T));//memcpy函数只能用于内置类型
				//用类型萃取解决
				for (size_t i=0;i<_size;i++)
				{
					tmp[i]=_a[i];
				}
			}
			_capacity=newCapacity;
			delete[] _a;
			_a=tmp;
		}
	}
private:
	T* _a;
	size_t _size;
	//size_t _top;
	size_t _capacity;
};
void TestStack()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	while (!s.Empty())
	{
		cout<<s.Top()<<endl;
		s.Pop();
	}
}
enum Type
{
	OP_SYMBOL,
	OP_NUM,
	ADD,
	SUB,
	MUL,
	DIV,
};
struct Cell
{
	Type _type;
	int _value;
};
int ConutRPN(Cell* rpn,size_t n)//返回结构体结果+正误
{
	assert(rpn);
	Stack<int> s;
	for (size_t i=0;i<n;++i)
	{
		if (rpn[i]._type==OP_NUM)
		{
			s.Push(rpn[i]._value);
		}
		else if(rpn[i]._type==OP_SYMBOL)
		{
			int right=s.Top();//注意获取顺序限右后左
			s.Pop();
			int left=s.Top()
			s.Pop();
			switch ()
			{
			case ADD:
				s.Push(left+right);
				break;
			case MUL:
				s.Push(left*right);
				break;
			case SUB:
				s.Push(left-right);
				break;
			case DIV:
				s.Push(left/right);
				break;
			default:
				//assert(0);
				throw std::invalid_argument("epn表达式错误");
			}
		}
		else
		{
			//assert(0);
			throw std::invalid_argument("epn表达式错误");
		}
	}
}
void RPN()
{

}
void TestRPN()
{
	Cell RPN[]={
		{OP_NUM,12},
		{OP_NUM,3},
		{OP_NUM,4},
		{OP_SYMBOL,ADD},
		{OP_SYMBOL,MUL},
		{OP_NUM,6},
		{OP_SYMBOL,SUB},
		{OP_NUM,8},
		{OP_NUM,2},
		{OP_SYMBOL,DIV},
		{OP_SYMBOL,ADD},
	};
	cout<<"计算结果"<<ConutRPN(RPN,11)<<endl;
}