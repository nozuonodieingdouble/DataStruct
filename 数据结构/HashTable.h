//#pragma once
//#include<iostream>
//#include <Vector>
//#include<string>
//#include<assert.h>
//
//using namespace std;
//
//enum Status//定义Vector的三种状态
//{
//	EXIST,//存在
//	DELETE,//删除
//	EMPTY,//空
//};
//
//template<typename K,typename V>
//struct HashTableNode
//{
//	K _key;
//	V _Value;
//	Status _status;
//
//	HashTableNode(const K& key = K(), const V& Value = V())//默认给缺省构造的值
//		: _key(key)
//		, _Value(Value)
//		, _status(EMPTY)
//	{}
//};
//
//template<class K>//定义仿函数
//struct __HashFun
//{
//	size_t operator()(const K& key)//若果是基本类型的K值，将基本类型传过去
//	{
//		return key;
//	} 
//};
//
//template<>//特化string的版本
//struct __HashFun<string>
//{
//	size_t operator()(const string& s)
//	{
//		size_t ret = 0;
//		//利用迭代器访问每一个字符的值，然后加上该字符的ASCII的值
//		string::const_iterator  it = s.begin();
//		while (it!=s.end())
//		{
//			ret = ret * 131 + *it;//这块乘的值是根据BKDR规则来定的
//			it++;
//		}
//		return ret;//返回计算后的K值
//	}
//};
//
//template<class K,class V,class HashFun=__HashFun<K>>//通过仿函数来确认调用基类类型还是自定义类型
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
//	//将K值转换成哈希值
//	size_t HashFunC(const K& key)
//	{
//		HashFun hf;
//		size_t hash = hf(key);//调用hashfun的仿函数，返回对应的整形值
//		return hash%_table.size();//计算hash值并返回
//	}
//
//	pair<Node*,bool>Insert(const K& key,const V& Value)
//	{
//		/*size_t index = 0;//容量满时处理一
//		if (_table.size() == size)
//		{
//			cout << "HashTable is full" << endl;
//		}*/
//		//检查是否需要扩容
//		ChecKCapacity();
//
//		//对key进行取摸，判断插入位置
//		size_t index = HashFunC(key);
//
//		//如果存在则循环继续寻找
//		while (_table[index]._status == EXIST)
//		{
//			index++;
//			if (index == _table.size())//如果检查到最后一个位置，将index置为0
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
//		//对K进行取余，判断插入位置
//		size_t index = HashFunC(key);
//
//		//如果存在继续查找
//		while (_table[index]._status == EXIST)
//		{
//			//若相等，判断状态是否是删除
//			//如果是删除，返回NULL
//			//若果是存在返回该位置的地址
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
//		//删除时只需要将状态置为DELETE
//		Node* del = Find(key);
//		if (del)
//			del->_status = DELETE;
//	}
//
//protected:
//	Void Swap(HashTable<K, V>& ht)//交换哈希表
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
//		if (_table.empty())//如果容量为空，增容到7
//		{
//			_table.resize(7);
//			return;
//		}
//
//		if (_size * 10 / _table.size() >= 7)//超过0.7的时候就进行增容
//		{
//			size_t newSize = _table.size() * 2;//扩容到2倍
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
//			//用临时变量来存储新生成的变量，并将两者进行交换
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
//	ht1.RemoVe(12);//删除一个不存在的点时也是将该位置的状态置为DELETE
//	ht1.RemoVe(16);
//
//	HashTable<string, string> dic(10);
//	dic.Insert("sort", "分类");
//	dic.Insert("sort", "整理");
//	dic.Insert("sort", "种类");
//}