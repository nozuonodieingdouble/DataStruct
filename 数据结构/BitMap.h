#pragma once 
#include<vector>


template<typename T>
class BitMap
{
public:
	void Set(size_t value)//����ĳһλ���ڻ��߲�����
	{
		size_t index = value >> 5;//����value����������
		size_t num = value % 32;  //������������Ǹ�λ��

		return _arr[index] |= (1 << num);//����Ӧ��λ��1�������ý����ʾ����λ��Ϊ1��������
	}

	void ReSet(size_t value)
	{
		size_t index = value >> 5;
		size_t num = value % 32;

		return _arr[index] &= ~(1 << 5);//����Ӧ��λ����0��������λ����1���뱣�ֲ���
	}

	void Test(size_t value)
	{
		size_t index = value >> 5;
		size_t num = value % 32;

		return _arr[index] & (1 << num);//����Ӧ��λ����1���뿴��ֵ�Ƿ����
	}

protected:
	vector<size_t> _arr;
	size_t _size;
};

void TestBitMap()
{

}