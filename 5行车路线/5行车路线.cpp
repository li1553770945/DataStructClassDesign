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
//
////#include<iostream>
////#include<queue>
////using namespace std;
////const long long inf = pow(2,30);
////const long long maxn = 100001;
////long long n, m, big[maxn][maxn], small[maxn][maxn], disc_big[maxn], disc_small[maxn];
////bool visit[maxn];
////void fun()
////{
////	for (int i = 0; i < maxn; i++)
////	{
////		disc_big[i] = inf;
////		disc_small[i] = inf;
////	}
////	queue<int> q;
////	disc_big[1] = disc_small[1] = 0;
////	q.push(1);
////	visit[1] = 1;
////	while (!q.empty())
////	{
////		int u = q.front();
////		q.pop();
////		visit[u] = 0;
////		for (int i = 1; i <= n; i++)
////		{
////			long long w = big[u][i];
////			if (disc_big[i] > disc_big[u] + w)//大路->大路 
////			{
////				disc_big[i] = disc_big[u] + w;
////				if (!visit[i])
////				{
////					q.push(i);
////					visit[i] = 1;
////				}
////			}
////			if (disc_big[i] > disc_small[u] + w)//小路->大路
////			{
////				disc_big[i] = disc_small[u] + w;
////				if (!visit[i])
////				{
////					q.push(i);
////					visit[i] = 1;
////				}
////			}
////			if (small[u][i] < inf)//如果小路能到达 
////			{
////				w = small[u][i] * small[u][i];
////				if (disc_small[i] > disc_big[u] + w)//走小路
////				{
////					disc_small[i] = disc_big[u] + w;
////					if (!visit[i])
////					{
////						q.push(i);
////						visit[i] = 1;
////					}
////				}
////			}
////		}
////	}
////}
////int main()
////{
////	memset(small, inf, sizeof(small));
////	memset(big, inf, sizeof(big));
////	cin >> n >> m;
////	for (int i = 1; i <= m; i++)
////	{
////		int t,u, v, w;
////		cin >> t >> u >> v >>w;
////		if (t == 1 && small[u][v] > w)
////			small[u][v] = small[v][u] = w;
////		else if (t == 0 && big[u][u] > w)
////			big[u][v] = big[v][u] = w;
////	}
////	for (int k = 1; k <= n; k++)
////		for (int i = 1; i <= n; i++)
////			for (int j = 1; j <= n; j++)
////				if (small[i][j] > small[i][k] + small[k][j])
////					small[i][j] = small[j][i] = small[i][k] + small[k][j];
////	fun();
////	cout << min(disc_big[n], disc_small[n]);
////	return 0;
////}