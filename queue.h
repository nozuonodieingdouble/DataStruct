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
	Queue()		//���캯��
		: _head(NULL)
		, _tail(NULL)
	{}

	~Queue()		//��������
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}
	}

	void Push(const T& data)	//��ĩβ����һ����
	{
		if (_head == NULL)		//Ϊ��
		{
			_head = _tail = new Node(data);
		}
		else      //��Ϊ��
		{
			_tail->_next = new Node(data);
			_tail = _tail->_next;
		}
	}

	void Pop()					//ɾ����һ��Ԫ��
	{
		if (_head == _tail)	//ֻ��һ��Ԫ��ʱ
		{
			delete _head;
			_head = _tail = NULL;
		}
		else               //�ж��Ԫ��ʱ
		{
			Node* del = _head;
			_head = _head->_next;

			delete del;
		}
	}

	size_t Size()	//���ض�����Ԫ�صĸ���
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

	T& Front()	//���ض����еĵ�һ��Ԫ��
	{
		assert(_head);
		return _head->_data;
	}

	T& Back()	//���ض��е����һ��Ԫ��
	{
		assert(_tail);
		return _tail->_data;
	}

	bool Empty()	//�ж�һ�������Ƿ�Ϊ��
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
