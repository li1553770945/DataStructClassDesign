//#include <iostream>
//#include <memory.h>
//#include <queue>
//const long long  maxn = 1000;
//using namespace std;
//long long  big[maxn][maxn];
//long long  small[maxn][maxn];
//long long disc1[maxn], disc2[maxn];
//long long  n, m;
//struct node {
//	long long  u, dis, type;
//
//	bool operator <(const node& rhs) const {
//		return dis > rhs.dis;
//
//	}
//};
//void dijkstra()
//{
//	priority_queue <node> Q;
//	disc1[1] = 0;
//	disc2[1] = 0;
//	Q.push(node{ 1 , 0,1 });
//	Q.push(node{ 1 , 0,0 });
//	long long  visit[maxn][2];
//	memset(visit, 0, sizeof visit);
//	while (!Q.empty())
//	{
//		node fnt = Q.top();
//		Q.pop();
//		long long  u = fnt.u, d = fnt.dis;
//		if (visit[u][fnt.type])
//			continue;
//		visit[u][fnt.type] = true;
//		if (fnt.type == 0)//上一次走的大路，这次两种都可以走
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				if (disc1[i] > disc1[u] + big[u][i])
//				{
//					disc1[i] = disc1[u] + big[u][i];
//					Q.push(node{ i,disc1[i],0 });
//				}
//				if (disc2[i] > disc1[u] + small[u][i] * small[u][i])
//				{
//					disc2[i] = disc1[u] + small[u][i] * small[u][i];
//					Q.push(node{ i,disc2[i],1 });
//				}
//			}
//		}
//		else
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				if (disc1[i] > disc2[u] + big[u][i])
//				{
//					disc1[i] = disc2[u] + big[u][i];
//					Q.push(node{ i,disc1[i],0 });
//				}
//			}
//		}
//
//	}
//}
//int  main()
//{
//	const int inf = 1e9;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		disc1[i] = inf;
//		disc2[i] = inf;
//	}
//	for (int i = 1; i <= n; i++)
//		for (long long j = 1; j <= n; j++)
//		{
//			big[i][j] = inf;
//			small[i][j] = inf;
//		}
//	for (int i = 1; i <= m; i++)
//	{
//		long long  t, u, v, w;
//		cin >> t >> u >> v >> w;
//		if (t == 0)
//		{
//			big[u][v] = min(w, big[u][v]);
//			big[v][u] = min(w, big[u][v]);
//		}
//		else
//		{
//			small[u][v] = min(w, small[u][v]);
//			small[v][u] = min(w, small[v][u]);
//		}
//	}
//	for (int k = 1; k <= n; k++)
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				if (small[i][j] > small[i][k] + small[k][j])
//					small[i][j] = small[i][k] + small[k][j];
//	dijkstra();
//	cout << min(disc1[n], disc2[n]);
//	return 0;
//}
////4 4
////1 1 2 1
////1 2 3 2
////1 3 4 1
////0 1 2 6