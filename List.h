#pragma once

//˫������
template<class T>
struct ListNode
{
	T _data;		//��ǰ�ڵ��е�����
	ListNode<T>* _prev;		//��ǰ�ڵ��ǰһ��
	ListNode<T>* _next;		//��ǰ�ڵ�ĺ�һ��

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
	List()		//�޲ι��캯��
		: _head(NULL)
		, _tail(NULL)
		, _size(0)
	{}

	List(const T* arr, size_t size)		//�вι��캯��
		: _head(NULL)
		, _tail(NULL)
		, _size(0)
	{
		for (size_t i = 0; i < size; ++i)
		{
			PushBack(arr[i]);
		}
	}

	List(const List<T>& l)		//�������캯��
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

	//List& operator=(const list<T>& l)		//�������������
	//{
	//	if (Empty())	//���������Ϊ��ʱ
	//	{
	//		Node* cur = l._head;
	//		for (size_t i = 0; i < l._size; ++i)
	//		{
	//			PushBack(cur->_data);
	//			cur = cur->_next;
	//		}
	//	}
	//	else if (_size>l._size)		//������ֵ���������Ҫ��ֵ������ʱ
	//	{
	//		Node* cur = _head;
	//		Node* lcur = l._head;
	//		//�Ƚ�l._size������ȥ
	//		for (size_t i = 0; i < l._size; ++i)
	//		{
	//			cur->_data = lcur->_data;
	//			cur = cur->_data;
	//			lcur = lcur->_data;
	//		}
	//		//�ٽ�ʣ���l._size��_size֮���Ԫ��ɾ��
	//		for (size_t i = l._size; i < _size; ++i)
	//		{
	//			PopBack();
	//			cur = cur->_next;
	//		}
	//	}
	//	else      //_sizeС�ڵ���l._size����_size��Ԫ�ع�ȥ����
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

	~List()			//��������
	{
		Clear();
	}

	bool Empty()		//�ж������Ƿ�Ϊ��
	{
		return _size == 0;
	}

	size_t Size()		//�������е�Ԫ�ظ���
	{
		return _size;
	}

	T& Front()			//���ص�һ��Ԫ��
	{
		return _head;
	}

	T& Front() const
	{
		return _head;
	}

	T& Back()			//�������һ��Ԫ��
	{
		return _tail;
	}

	T& Back() const
	{
		return _tail;
	}

	void PushBack(const T& data)		//β��
	{
		if (Empty())		//����Ϊ��ʱ
		{
			Node* cur = BuyNewNode(data);
			_head = _tail = cur;
		}
		else      //����Ϊ��ʱ
		{
			Node* cur = BuyNewNode(data);
			cur->_prev = _tail;
			_tail->_next = cur;
			_tail = cur;
		}
		++_size;
	}

	void PopBack()					//βɾ
	{
		if (Empty())		//����Ϊ�յ����
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

	void PushFront(const T& data)		//ͷ��
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

	void PopFront()					//ͷɾ
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

	Node* Find(const T& data)		//�����ض�Ԫ���������еĵ�һ�γ���λ��
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

	void Insert(Node* pos, const T& data)		//��ָ��λ�ò���Ԫ��
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

	void Erase(Node* pos)		//ɾ��ָ��λ�õ�Ԫ��
	{
		if (Empty())
			return;
		if (pos == _head)		//�����ͷ���
		{
			PopFront();
		}
		else if (pos == _tail)	//�����β���
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

	void Clear()		//�������
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

	void Sort()		//����
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

	void Remove(const T& data)		//ɾ����һ��ֵΪdata�Ľڵ�
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

	void Print()		//��ӡ����
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

	void ReversePrint()			//�����ӡ
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

