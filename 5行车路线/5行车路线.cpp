//#include <iostream>
//#include <queue>
//using namespace std;
//struct EDGE {
//	long long  w, v, next, type;
//}e[200010];
//long long  next[100001];
//long long  disc[100001];
//long long  head[100001];
//long long  little[1000001];//到某个节点连续走小路的长度
//long long  n, m, s, cnt;
//struct node {
//	long long  u, dis, type;
//	bool operator <(const node& rhs) const {
//		return dis > rhs.dis;
//	}
//};
//void addedge(long long  u, long long  v, long long  w, long long  type)
//{
//	cnt++;
//	e[cnt].v = v;
//	e[cnt].w = w;
//	e[cnt].next = head[u];
//	e[cnt].type = type;
//	head[u] = cnt;
//}
//void dijkstra()
//
//{
//	priority_queue <node> Q;
//	disc[s] = 0;
//	Q.push(node{ s, 0 });
//	while (!Q.empty())
//	{
//		node fnt = Q.top();
//		Q.pop();
//		long long  u = fnt.u, d = fnt.dis;
//
//		if (d > disc[u]) continue;
//		for (long long  i = head[u]; i; i = e[i].next)
//		{
//			long long  v = e[i].v, w = e[i].w;
//			if (e[i].type == 0)
//			{
//				if (disc[v] > disc[u] + w)
//				{
//					disc[v] = disc[u] + w;
//					Q.push(node{ v,disc[v] });
//					little[v] = 0;
//				}
//			}
//			else
//			{
//				if (disc[u] - little[u] * little[u] + (little[u] + w) * (little[u] + w)<disc[v])
//				{
//					disc[v] = disc[u] - little[u] * little[u] + (little[u] + w) * (little[u] + w);
//					little[v] = little[u] + w;
//					Q.push(node{ v,disc[v] });
//				}
//			}
//			
//		}
//	}
//}
//int  main()
//{
//	cin >> n >> m;
//	s = 1;
//	for (long long  i = 1; i <= n; i++)
//	{
//		disc[i] = 2147483647;
//	}
//	for (long long  i = 1; i <= m; i++)
//	{
//		long long  type, u, v, w;
//		cin >> type >> u >> v >> w;
//		addedge(v, u, w, type);
//		addedge(u, v, w, type);
//	}
//	dijkstra();
//
//	cout << disc[n];
//	return 0;
//}