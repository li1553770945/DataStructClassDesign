//#include<iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <queue>
//using namespace std;
//const int maxn = 400010;
//const float inf = 1e20;
//int n, m;
//struct Edge {
//	int v, next;
//	float w;
//};
//int head[maxn];
//Edge e[maxn];
//string edge_name[maxn];
//int cnt = 0;
//int fa[maxn];
//void AddEdge(int u, int v, float w)//�ӱ�
//{
//	e[++cnt].next = head[u];
//	head[u] = cnt;
//	e[cnt].w = w;
//	e[cnt].v = v;
//}
//void Print()//���ͼ
//{
//	cout << "�������ͼ����" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		cout << edge_name[i];
//		int nex;
//		nex = head[i];
//		while (nex)
//		{
//			cout << "->" << edge_name[e[nex].v];
//			nex = e[nex].next;
//		}
//		cout << endl;
//	}
//}
//int Fa(int x)//���鼯�Ҹ���
//{
//	if (x == fa[x])
//		return x;
//	else
//		return fa[x] = Fa(fa[x]);
//}
//void Kruscal()
//{
//	for (int i = 0; i < maxn; i++)
//		fa[i] = i;
//	bool vis[maxn];
//	for (int i = 0; i < maxn; i++)
//		vis[i] = false;
//	struct EDGE {
//		int u, v;
//		float w;
//		EDGE(int _u, int _v, float _w)
//		{
//			u = _u;
//			v = _v;
//			w = _w;
//		}
//		bool operator <(const EDGE& rhs)
//		{
//			return w < rhs.w;
//		}
//	};
//	vector <EDGE> edge;
//	for (int i = 1; i <= n; i++)
//	{
//		int nex = head[i];
//		while (nex)
//		{
//			edge.push_back(EDGE(i, e[nex].v, e[nex].w));
//			nex = e[nex].next;
//		}
//	}
//	vector <int> ans[maxn];
//	sort(edge.begin(), edge.end());//����Ȩֵ����
//	int count = 0;
//	for (int i = 0; i < 2 * m&&count < n-1; i++)
//	{
//		int u = edge[i].u, v = edge[i].v;
//		if (Fa(u) != Fa(v))
//		{
//			fa[Fa(u)] = Fa(v);
//			ans[u].push_back(v);
//			ans[v].push_back(u);
//			count++;
//		}
//	}
//	if (count != n-1)
//	{
//		cout << "��ͼ����ͨ���޷�������С������!" << endl;
//		return;
//	}
//	cout << "��Kruscal�㷨���ɵ���С���������£��ڽӱ��ʾ):" << endl;//Ҫ���ڽӱ����������̫�鷳��
//	//����ֻ�����µĽṹ�壬�������Ҫ���ڽӱ���� 
//	for (int i = 1; i <= n; i++)
//	{
//		cout << edge_name[i];
//		for (auto& v : ans[i])
//		{
//			cout << "->" << edge_name[v];
//		}
//		cout << endl;
//	}
//}
//void Prim()
//{
//	struct EDGE{
//		int u, v;
//		float w;
//		bool operator <(const EDGE rhs) const
//		{
//			return rhs.w <w;
//		}
//	};
//	priority_queue <EDGE> q;//���Ż���ÿ���ҳ��͵�ǰ�����ı���Ȩֵ��С���Ǹ�
//	float dis[maxn];
//	bool vis[maxn];
//	memset(vis, 0, sizeof vis);
//	int count = 0;
//	for (int i = 0; i < maxn; i++)
//		dis[i] = inf;
//	dis[1] = 0;
//	q.push(EDGE{ 1,1,0 });
//	vector <int> ans[maxn];
//	while (!q.empty() && count < n)
//	{
//		int u = q.top().v;
//		int pre = q.top().u;
//		q.pop();
//		if (vis[u])
//			continue;
//		if (count != 0)
//		{
//			ans[pre].push_back(u);
//			ans[u].push_back(pre);
//		}
//		count++;
//		vis[u] = 1;
//		for (int i = head[u]; i; i = e[i].next)
//		{
//			int v = e[i].v;
//			if (dis[v] > e[i].w)
//			{
//				dis[v] = e[i].w;
//				q.push(EDGE{ u,v,dis[v] });
//			}
//		}
//	}
//	if(count!=n)
//	{
//		cout << "��ͼ����ͨ���޷�������С������!" << endl;
//		return;
//	}
//	cout << "��Prim�㷨���ɵ���С���������£��ڽӱ��ʾ):" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		cout << edge_name[i];
//		for (auto& v : ans[i])
//		{
//			cout << "->" << edge_name[v];
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	cout << "��������� ����" << endl;
//	cin >> n >> m;
//	cout << "������������" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> edge_name[i];
//	}
//	cout << "������߼���Ȩֵ" << endl;
//	for (int i = 1; i <= m; i++)
//	{
//		int u, v;
//		float w;
//		cin >> u >> v >> w;
//		AddEdge(u, v, w);
//		AddEdge(v, u, w);
//	}
//	Print();
//	Kruscal();
//	Prim();
//	return 0;
//}
///*
//5 5
//a b c d e
//1 2 9
//1 3 4
//2 4 6
//3 5 8
//1 5 3
//*/