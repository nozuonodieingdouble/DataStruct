#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <vector>
#include<string>
#include<assert.h>
#include<queue>
using namespace std;

template<class V,class W>
class GraphMatrix
{
public:
	GraphMatrix(V* v, size_t n, const W& invalid = W(), bool isDirected = false)
		: _v(v, v + n)
		, _isDirected(isDirected)
	{
		_matrix = new W*[_v.size()];
		for (size_t i = 0; i < _v.size(); ++i)
		{
			_matrix[i] = new W[_v.size()];
			for (size_t j = 0; j < _v.size(); ++j)
			{
				_matrix[i][j] = invalid;
			}
		}
	}

	~GraphMatrix()
	{}

	size_t GetVertexIndex(const V& v)
	{
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (_v[i] == v)
			{
				return i;
			}
		}
		assert(false);
		return 0;
	}

	void AddEdge(const V& v1, const V& v2, const W& w)
	{
		size_t src = GetVertexIndex(v1);
		size_t dst = GetVertexIndex(v2);
		_matrix[src][dst] = w;
		if (_isDirected == false)
		{
			_matrix[dst][src] = w;
		}
	}
protected:
	vector<V> _v;	//���㼯��
	W** _matrix;	//�ߵļ���
	bool _isDirected;	//�Ƿ�������ͼ
};


void TestGraphMatrix()
{
	string city[] = { "����", "����","����","μ��","�Ӱ�","����" };
	GraphMatrix<string, int> g1(city, sizeof(city) / sizeof(city[0]));
	g1.AddEdge("����","����",25.5);
	g1.AddEdge("����", "����", 6.5);
	g1.AddEdge("����", "μ��", 19.5);
	g1.AddEdge("����", "�Ӱ�", 50.5);
}


template<class W>
struct LinkEdge
{
	W _w;
	LinkEdge<W>* _next;
	size_t _src;
	size_t _dst;

	LinkEdge(size_t src = 0, size_t dst = 0, const W& w = W())
		: _src(src)
		, _dst(dst)
		, _w(w)
		, _next()
	{}
};

template<class V, class W>
class GraphLink
{
	typedef LinkEdge<W> Edge;
public:
	GraphLink(V* v, size_t n, const W& invalid = W(), bool isDirected = false)
		:_isDirected(isDirected)
	{
		_v.resize(n);
		_v.assign(v, v + n);
		_linktable.resize(n, NULL);
	}

	size_t GetVertexIndex(const V& v)
	{
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (_v[i] == v)
			{
				return i;
			}
		}
	}

	void _AddEdge(size_t src, size_t dst, const W& w)
	{
		LinkEdge<W>* edge = new Edge(src, dst, w);
		edge->_next = _linktable[src];
		_linktable[src] = edge;
	}

	void AddEdge(const V& v1, const V& v2, const W& w)
	{
		size_t src = GetVertexIndex(v1);
		size_t dst = GetVertexIndex(v2);
		_AddEdge(src, dst, w);
		if (_isDirected == false)
		{
			_AddEdge(dst, src, w);
		}
	}

	void DFS(const V& src)//������ȱ���
	{
		size_t index = GetVertexIndex(src);
		vector<bool> visited(_v.size(), false);
		_DFS(index, visited);
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (visited[i] == false)//�������δ��ǵ�
			{
				_DFS(i, visited);
			}
		}

	}

	void _DFS(size_t src,vector<bool>& visited)
	{
		Node* cur = _linktable[src];
		cout << _v[src].c_str() << " ";
		visited[cur->_src] = true;
		while (cur)
		{
			if (visited[cur->_dst] == false)
			{
				_DFS(cur->_dst, visited);
			}
			cur = cur->_next;

		}
	}

	void BFS(const V& src)//������ȱ���
	{
		size_t index = GetVertexIndex(src);
		vector<bool> visited(_v.size(), false);//�������
		queue<int> q;
		q.push(index);
		while (!q.empty())
		{
			size_t front = q.front();//front���ض��е�һ��Ԫ�ص�����
			q.pop();
			cout << _v[front].c_str() << " ";
			visited[front] = true;//�޸ı��
			Edge* cur = _linktable[front];
			while (cur)
			{
				if (visited[cur->_dst] == false)//������˳���û�б�����
				{
					q.push(cur->_dst);
					visited[cur->_dst] = true;
				}
				cur = cur->_next;
			}
		}
	}
protected:
	vector<V> _v;
	vector<Edge*> _linktable;
	bool _isDirected;
};




void TestGraphLink()
{
	string city[] = { "����", "����", "����", "μ��", "�Ӱ�", "����" };
	GraphLink<string, int> g1(city, sizeof(city) / sizeof(city[0]));
	g1.AddEdge("����", "����", 25.5);
	g1.AddEdge("����", "����", 6.5);
	g1.AddEdge("����", "μ��", 19.5);
	g1.AddEdge("����", "�Ӱ�", 50.5);
	g1.BFS("����");
}


