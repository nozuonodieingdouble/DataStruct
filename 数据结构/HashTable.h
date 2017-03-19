//#pragma once
//#include<iostream>
//#include <Vector>
//#include<string>
//#include<assert.h>
//
//using namespace std;
//
//enum Status//����Vector������״̬
//{
//	EXIST,//����
//	DELETE,//ɾ��
//	EMPTY,//��
//};
//
//template<typename K,typename V>
//struct HashTableNode
//{
//	K _key;
//	V _Value;
//	Status _status;
//
//	HashTableNode(const K& key = K(), const V& Value = V())//Ĭ�ϸ�ȱʡ�����ֵ
//		: _key(key)
//		, _Value(Value)
//		, _status(EMPTY)
//	{}
//};
//
//template<class K>//����º���
//struct __HashFun
//{
//	size_t operator()(const K& key)//�����ǻ������͵�Kֵ�����������ʹ���ȥ
//	{
//		return key;
//	} 
//};
//
//template<>//�ػ�string�İ汾
//struct __HashFun<string>
//{
//	size_t operator()(const string& s)
//	{
//		size_t ret = 0;
//		//���õ���������ÿһ���ַ���ֵ��Ȼ����ϸ��ַ���ASCII��ֵ
//		string::const_iterator  it = s.begin();
//		while (it!=s.end())
//		{
//			ret = ret * 131 + *it;//���˵�ֵ�Ǹ���BKDR����������
//			it++;
//		}
//		return ret;//���ؼ�����Kֵ
//	}
//};
//
//template<class K,class V,class HashFun=__HashFun<K>>//ͨ���º�����ȷ�ϵ��û������ͻ����Զ�������
//class HashTable
//{
//	typedef HashTableNode<K,V> Node;
//public:
//	HashTable()
//	{}
//
//	HashTable(size_t size)
//		:_size(0)
//	{
//		assert(size > 0);
//		_table.resize(size);
//	}
//
//	~HashTable()
//	{}
//
//	//��Kֵת���ɹ�ϣֵ
//	size_t HashFunC(const K& key)
//	{
//		HashFun hf;
//		size_t hash = hf(key);//����hashfun�ķº��������ض�Ӧ������ֵ
//		return hash%_table.size();//����hashֵ������
//	}
//
//	pair<Node*,bool>Insert(const K& key,const V& Value)
//	{
//		/*size_t index = 0;//������ʱ����һ
//		if (_table.size() == size)
//		{
//			cout << "HashTable is full" << endl;
//		}*/
//		//����Ƿ���Ҫ����
//		ChecKCapacity();
//
//		//��key����ȡ�����жϲ���λ��
//		size_t index = HashFunC(key);
//
//		//���������ѭ������Ѱ��
//		while (_table[index]._status == EXIST)
//		{
//			index++;
//			if (index == _table.size())//�����鵽���һ��λ�ã���index��Ϊ0
//				index = 0;
//		}
//		_table[index]._key = key;
//		_table[index]._Value = Value;
//		_table[index]._status = EXIST;
//		_size++;
//		return maKe_pair<Node*, bool>(&_table[index], true);
//	}
//
//	Node* Find(const K& key)
//	{
//		//��K����ȡ�࣬�жϲ���λ��
//		size_t index = HashFunC(key);
//
//		//������ڼ�������
//		while (_table[index]._status == EXIST)
//		{
//			//����ȣ��ж�״̬�Ƿ���ɾ��
//			//�����ɾ��������NULL
//			//�����Ǵ��ڷ��ظ�λ�õĵ�ַ
//			if (_table[index]._key == key)
//			{
//				if (_table[index]._status == DELETE)
//					return NULL;
//				return &_table[index];
//			}
//			index++;
//			if (index == _size)
//				index = 0;
//		}
//		return &_table[index];
//	}
//
//	Void RemoVe(const K& key)
//	{
//		//ɾ��ʱֻ��Ҫ��״̬��ΪDELETE
//		Node* del = Find(key);
//		if (del)
//			del->_status = DELETE;
//	}
//
//protected:
//	Void Swap(HashTable<K, V>& ht)//������ϣ��
//	{
//		swap(_table, ht._table);
//		swap(_size, ht._size);
//	}
//
//	/*const int_PrimeSize = 28;
//	static const unsigned long_PrimeList[_PrimeSize] =
//	{
//		53ul, 97ul, 193ul, 389ul, 769ul,
//		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
//		49157ul, 98317ul, 196613ul, 393241ul,
//		786433ul,
//		1572869ul, 3145739ul, 6291469ul, 12582917ul,
//		25165843ul,
//		50331653ul, 100663319ul, 201326611ul, 402653189ul,
//		805306457ul,
//		1610612741ul, 3221225473ul, 4294967291ul
//	};
//*/
//	Void ChecKCapacity()
//	{
//		if (_table.empty())//�������Ϊ�գ����ݵ�7
//		{
//			_table.resize(7);
//			return;
//		}
//
//		if (_size * 10 / _table.size() >= 7)//����0.7��ʱ��ͽ�������
//		{
//			size_t newSize = _table.size() * 2;//���ݵ�2��
//
//
//			/*size_t index = 0;
//			while (_primeList[index] < _table.size())
//			{
//				index++;
//			}
//			size_t newSize = _PrimeList[index];*/
//
//
//			//����ʱ�������洢�����ɵı������������߽��н���
//			HashTable<K, V> tmp(newSize);
//			for (size_t i = 0; i < _table.size(); i++)
//			{
//				if (_table[i]._status == EXIST)
//					tmp.Insert(_table[i]._key, _table[i]._Value);
//			}
//			Swap(tmp);
//		}
//	}
//
//priVate:
//	Vector<Node> _table;
//	size_t _size;
//};
//
//Void TestHashTable()
//{
//	HashTable<int, int> ht1(10);
//	ht1.Insert(49, 0);
//	ht1.Insert(28, 0);
//	ht1.Insert(29, 0);
//	ht1.Insert(18, 0);
//	ht1.Insert(19, 0);
//	ht1.Insert(14, 0);
//	ht1.Insert(16, 0);
//	ht1.Insert(11, 0);
//	ht1.Insert(17, 0);
//	ht1.Insert(19, 0);
//	ht1.Insert(15, 0);
//	ht1.RemoVe(19);
//	ht1.RemoVe(12);//ɾ��һ�������ڵĵ�ʱҲ�ǽ���λ�õ�״̬��ΪDELETE
//	ht1.RemoVe(16);
//
//	HashTable<string, string> dic(10);
//	dic.Insert("sort", "����");
//	dic.Insert("sort", "����");
//	dic.Insert("sort", "����");
//}