#pragma once 
#include<vector>


template<typename T>
class BitMap
{
public:
	void Set(size_t value)//设置某一位存在或者不存在
	{
		size_t index = value >> 5;//计算value所处的区间
		size_t num = value % 32;  //计算在区间的那个位置

		return _arr[index] |= (1 << num);//将对应的位与1想与所得结果表示将那位置为1，即存在
	}

	void ReSet(size_t value)
	{
		size_t index = value >> 5;
		size_t num = value % 32;

		return _arr[index] &= ~(1 << 5);//将对应的位置与0想与其他位置与1相与保持不变
	}

	void Test(size_t value)
	{
		size_t index = value >> 5;
		size_t num = value % 32;

		return _arr[index] & (1 << num);//将对应的位置与1相与看该值是否存在
	}

protected:
	vector<size_t> _arr;
	size_t _size;
};

void TestBitMap()
{

}