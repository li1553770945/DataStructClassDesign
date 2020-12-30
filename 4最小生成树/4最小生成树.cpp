//#include<iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//const int maxn = 1000;
//
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
//void AddEdge(int u, int v, float w)
//{
//	e[++cnt].next = head[u];
//	head[u] = cnt;
//	e[cnt].w = w;
//	e[cnt].v = v;
//}
//void Print()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		cout << i;
//		int nex;
//		nex = head[i];
//		while (nex)
//		{
//			cout << "->" << e[nex].v;
//			nex = e[nex].next;
//		}
//		cout << endl;
//	}
//}
//int Fa(int x)
//{
//	if (x == fa[x])
//		return x;
//	else
//		return fa[x] = Fa(fa[x]);
//}
//void kruscal()
//{
//
//	for (int i = 1; i <= n; i++)
//	{
//		fa[i] = i;
//	}
//	struct EDGE {
//		int u, v, cnt;
//		float w;
//		EDGE(int _u, int _v, float _w, int _cnt)
//		{
//			u = _u;
//			v = _v;
//			w = _w;
//			cnt = _cnt;
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
//			edge.push_back(EDGE(i, e[nex].v, e[nex].w, nex));
//			nex = e[nex].next;
//		}
//	}
//	vector <int> ans[maxn];
//	sort(edge.begin(), edge.end());
//	int con = 0;//已经连接上去的边
//	for (int i = 0; i < 2 * m&&con < n-1; i++)
//	{
//		int u = edge[i].u, v = edge[i].v;
//		float w = edge[i].w;
//		if (Fa(u) != Fa(v))
//		{
//			fa[Fa(u)] = Fa(v);
//			ans[u].push_back(v);
//			ans[v].push_back(u);
//			con++;
//		}
//	}
//
//
//	if (con != n - 1)
//	{
//		cout << "该图不连通，无法生成树！" << endl;
//		return;
//	}
//	cout << "用Kruscal算法生成的最小生成树如下（邻接表表示):" << endl;//要按邻接表输出可真是太麻烦了
//	//排序只能用新的结构体，但是输出要按邻接表输出，可把我愁坏了	 
//	for (int i = 1; i <= n; i++)
//	{
//		cout << i;
//		for (auto& v : ans[i])
//		{
//			cout << "->" << v;
//		}
//		cout << endl;
//	}
//
//}
//void prime()
//{
//
//}
//int main()
//{
//
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> edge_name[i];
//	}
//
//	for (int i = 1; i <= m; i++)
//	{
//		int u, v;
//		float w;
//		cin >> u >> v >> w;
//		AddEdge(u, v, w);
//		AddEdge(v, u, w);
//	}
//	Print();
//	kruscal();
//	return 0;
//}
///*
//5 5
//1 2 3 4 5
//1 2 9
//1 3 4
//2 4 6
//3 5 8
//1 5 3
//*/