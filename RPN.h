#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;


enum OP_TYPE
{
	OP_SYMBOL,
	OP_VALUE,
	ADD,
	SUB,
	MUL,
	DIV,
};

struct Cell
{
	int _type;
	int _value;
};

int CountRPN(Cell* rpn, size_t n)
{
	assert(rpn);
	stack<int> s;
	for (size_t i = 0; i < n; ++i)
	{
		if (rpn[i]._type == OP_VALUE)
		{
			s.push(rpn[i]._value);
		}



		else if (rpn[i]._type == OP_SYMBOL)
		{
			int left = s.top();
			s.pop();
			int right = s.top();
			s.pop();

			switch (rpn[i]._value)
			{
			case ADD:
				s.push(left + right);
				break;
			case SUB:
				s.push(right - left);
				break;
			case MUL:
				s.push(right * left);
				break;
			case DIV:
				if (left != 0)
				{
					s.push(right / left);
				}
				else
				{
					cout << "分母不能为0"<<endl;
					assert(left);
				}
				break;
			default:
				throw std::invalid_argument("epn表达式错误");
				break;
			}
		}
		else
		{
			throw std::invalid_argument("epn表达式错误");
			/*cout << "输入参数有误" << endl;
			assert(false);*/
		}
	}
	return s.top();
}


void TestRPN()
{
	//char* a[] = { "12", "3","4","+" , "*", "6", "-", "8", "2", "/" , "+"};
	Cell RPN[] =
	{
		{ OP_VALUE, 12 },
		{ OP_VALUE, 3 },
		{ OP_VALUE, 4 },
		{ OP_SYMBOL, ADD },
		{ OP_SYMBOL, MUL },
		{ OP_VALUE, 6 },
		{ OP_SYMBOL, SUB },
		{ OP_VALUE, 8 },
		{ OP_VALUE, 2 },
		{ OP_SYMBOL, DIV },
		{ OP_SYMBOL, ADD },
	};


	cout << "计算结果为" << CountRPN(RPN, sizeof(RPN) / sizeof(Cell)) << endl;
}

