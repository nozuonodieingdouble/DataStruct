#pragma once

//双向链表
template<class T>
struct ListNode
{
	T _data;		//当前节点中的数据
	ListNode<T>* _prev;		//当前节点的前一个
	ListNode<T>* _next;		//当前节点的后一个

	ListNode(const T& data)
		: _data(data)
		, _prev(NULL)
		, _next(NULL)
	{}
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()		//无参构造函数
		: _head(NULL)
		, _tail(NULL)
		, _size(0)
	{}

	List(const T* arr, size_t size)		//有参构造函数
		: _head(NULL)
		, _tail(NULL)
		, _size(0)
	{
		for (size_t i = 0; i < size; ++i)
		{
			PushBack(arr[i]);
		}
	}

	List(const List<T>& l)		//拷贝构造函数
		: _head(NULL)
		, _tail(NULL)
		, _size(0)
	{
		Node<T>* cur = l._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}

	//List& operator=(const list<T>& l)		//复制运算符重载
	//{
	//	if (Empty())	//对象的链表为空时
	//	{
	//		Node* cur = l._head;
	//		for (size_t i = 0; i < l._size; ++i)
	//		{
	//			PushBack(cur->_data);
	//			cur = cur->_next;
	//		}
	//	}
	//	else if (_size>l._size)		//当被赋值的链表大于要赋值的链表时
	//	{
	//		Node* cur = _head;
	//		Node* lcur = l._head;
	//		//先将l._size拷贝过去
	//		for (size_t i = 0; i < l._size; ++i)
	//		{
	//			cur->_data = lcur->_data;
	//			cur = cur->_data;
	//			lcur = lcur->_data;
	//		}
	//		//再将剩余的l._size到_size之间的元素删除
	//		for (size_t i = l._size; i < _size; ++i)
	//		{
	//			PopBack();
	//			cur = cur->_next;
	//		}
	//	}
	//	else      //_size小于等于l._size拷贝_size个元素过去即可
	//	{
	//		Node* cur = _head;
	//		Node* lcur = l._head;
	//		for (size_t i = 0; i < _size; ++i)
	//		{
	//			cur->_data = lcur->_data;
	//			cur = cur->_next;
	//			lcur = lcur->_next;
	//		}
	//	}
	//	return *this;
	//}

	~List()			//析构函数
	{
		Clear();
	}

	bool Empty()		//判断链表是否为空
	{
		return _size == 0;
	}

	size_t Size()		//求链表中的元素个数
	{
		return _size;
	}

	T& Front()			//返回第一个元素
	{
		return _head;
	}

	T& Front() const
	{
		return _head;
	}

	T& Back()			//返回最后一个元素
	{
		return _tail;
	}

	T& Back() const
	{
		return _tail;
	}

	void PushBack(const T& data)		//尾插
	{
		if (Empty())		//链表为空时
		{
			Node* cur = BuyNewNode(data);
			_head = _tail = cur;
		}
		else      //链表不为空时
		{
			Node* cur = BuyNewNode(data);
			cur->_prev = _tail;
			_tail->_next = cur;
			_tail = cur;
		}
		++_size;
	}

	void PopBack()					//尾删
	{
		if (Empty())		//链表为空的情况
			return;
		else if (_head->_next == NULL)
		{
			Node* del = _head;
			_head = _tail = NULL;
			delete del;
		}
		else
		{
			Node* del = _tail;
			_tail = _tail->_prev;
			_tail->_next = NULL;
			delete del;
		}
	}

	void PushFront(const T& data)		//头插
	{
		if (Empty())
		{
			Node* cur = BuyNewNode(data);
			_head = _tail = cur;
		}
		else
		{
			Node* cur = BuyNewNode(data);
			cur->_next = _head;
			_head->_prev = cur;
			cur = _head;
		}
	}

	void PopFront()					//头删
	{
		if (Empty())
			return;
		else if (_head->_next = NULL)
		{
			Node* del = _head;
			_head = _tail = NULL;
			delete del;
		}
		else
		{
			Node* del = _head;
			_head = _head->_next;
			_head->_prev = NULL;
			delete del;
		}
		--_size;
	}

	Node* Find(const T& data)		//查找特定元素在链表中的第一次出现位置
	{
		Node* cur = _head;
		while (cur)
		{
			if (cur->_data == data)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}

	void Insert(Node* pos, const T& data)		//在指定位置插入元素
	{
		assert(pos);
		if (pos->_next == NULL)
		{
			PushBack(data);
		}
		else
		{
			Node* cur = BuyNewNode(data);
			cur->_prev = pos;
			cur->_next = pos->_next;

			pos->_next->_prev = cur;
			pos->_next = cur;
		}
		++_size;
	}

	void Erase(Node* pos)		//删除指定位置的元素
	{
		if (Empty())
			return;
		if (pos == _head)		//如果是头结点
		{
			PopFront();
		}
		else if (pos == _tail)	//如果是尾结点
		{
			PopBack();
		}
		else
		{
			Node* cur = pos;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = cur->_next;
			next->_prev = cur->_prev;

			delete pos;
		}
		--_size;
	}

	void Clear()		//清空链表
	{
		if (Empty())
			return;
		else
		{
			Node* del = _head;
			Node* cur = _head->_next;
			while (cur->_next)
			{
				cur = cur->_next;
				del = cur->_prev;
				delete del;
			}
			delete cur;
			_tail = NULL;
			del = _head;
			delete del;
			_head = NULL;
			_size = 0;
		}
	}

	void Sort()		//排序
	{
		bool flag = true;
		Node* cur = _head;
		Node* tail = NULL;
		while (cur != tail)
		{
			while (cur->_next != tail)
			{
				if (cur->_data > cur->_next->_data)
				{
					T tmp = cur->_data;
					cur->_data = cur->_next->_data;
					cur->_next->_data = tmp;
					flag = false;
				}
				cur = cur->_next;
			}
			if (flag)
				break;
			tail = cur;
			cur = _head;
		}
	}

	void Remove(const T& data)		//删除第一个值为data的节点
	{
		Node* pos = Find(data);
		if (pos)
		{
			if (pos == _head)
			{
				PopFront();
			}
			else if (pos == _tail)
			{
				PopBack();
			}
			else
			{
				Erase(pos);
			}
		}
	}

	void Print()		//打印链表
	{
		if (Empty())
			return;
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

	void ReversePrint()			//逆序打印
	{
		if (Empty())
		{
			return;
		}
		Node* cur = _tail;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_prev;
		}
		cout << endl;
	}

protected:
	Node* BuyNewNode(const T& data)
	{
		Node* tmp = new Node(data);
		return tmp;
	}

protected:
	Node* _head;
	Node* _tail;
	size_t _size;
};

