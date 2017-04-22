#include<assert.h>

template<class T>
struct QueueNode
{
	T _data;
	QueueNode<T>* _next;

	QueueNode(const T& data)
		: _data(data)
		, _next(NULL)
	{}
};

template<class T>
class Queue
{
	typedef QueueNode<T> Node;
public:
	Queue()		//构造函数
		: _head(NULL)
		, _tail(NULL)
	{}

	~Queue()		//析构函数
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}
	}

	void Push(const T& data)	//在末尾插入一个数
	{
		if (_head == NULL)		//为空
		{
			_head = _tail = new Node(data);
		}
		else      //不为空
		{
			_tail->_next = new Node(data);
			_tail = _tail->_next;
		}
	}

	void Pop()					//删除第一个元素
	{
		if (_head == _tail)	//只有一个元素时
		{
			delete _head;
			_head = _tail = NULL;
		}
		else               //有多个元素时
		{
			Node* del = _head;
			_head = _head->_next;

			delete del;
		}
	}

	size_t Size()	//返回队列中元素的个数
	{
		size_t count = 0;
		Node* cur = _head;
		while (cur)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}

	T& Front()	//返回队列中的第一个元素
	{
		assert(_head);
		return _head->_data;
	}

	T& Back()	//返回队列的最后一个元素
	{
		assert(_tail);
		return _tail->_data;
	}

	bool Empty()	//判断一个队列是否为空
	{
		return _head == NULL;
	}

protected:
	Node* _head;
	Node* _tail;
};


void TestQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	cout << q.Size() << endl;
	while (!q.Empty())
	{
		cout << q.Front() << " ";
		q.Pop();
	}
	cout << endl;
}
