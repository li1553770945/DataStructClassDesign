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
//void AddEdge(int u, int v, float w)//加边
//{
//	e[++cnt].next = head[u];
//	head[u] = cnt;
//	e[cnt].w = w;
//	e[cnt].v = v;
//}
//void Print()//输出图
//{
//	cout << "您输入的图如下" << endl;
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
//int Fa(int x)//并查集找父亲
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
//	sort(edge.begin(), edge.end());//按照权值排序
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
//		cout << "该图不连通，无法生成最小生成树!" << endl;
//		return;
//	}
//	cout << "用Kruscal算法生成的最小生成树如下（邻接表表示):" << endl;//要按邻接表输出可真是太麻烦了
//	//排序只能用新的结构体，但是输出要按邻接表输出 
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
//	priority_queue <EDGE> q;//堆优化，每次找出和当前相连的边中权值最小的那个
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
//		cout << "该图不连通，无法生成最小生成树!" << endl;
//		return;
//	}
//	cout << "用Prim算法生成的最小生成树如下（邻接表表示):" << endl;
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
//	cout << "请输入点数 边数" << endl;
//	cin >> n >> m;
//	cout << "请输入点的名称" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> edge_name[i];
//	}
//	cout << "请输入边及其权值" << endl;
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