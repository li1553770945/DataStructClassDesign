//#include<cstdio>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//const int maxn = 1000;
//int n,m;
//int ve[maxn], vl[maxn];
//struct Node
//{
//	int v, w;
//}node;
//int in_degree[maxn];
//stack<int> topOrder;
//vector<Node> G[maxn];
//vector<int> pre[maxn];
//bool topo_sort()
//{
//	queue<int> q;
//	int c = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (in_degree[i] == 0)
//			q.push(i);
//	}
//	while (!q.empty())
//	{
//		int u = q.front(); c++;
//		topOrder.push(u);
//		q.pop();
//		for (int i = 0; i < G[u].size(); i++)
//		{
//			int v = G[u][i].v, w = G[u][i].w;
//			in_degree[v]--;
//			if (in_degree[v] == 0)
//				q.push(v);
//			if (ve[u] + w > ve[v])ve[v] = ve[u] + w;//计算每个时间的最早开始时间
//		}
//	}
//	return c == n ? true : false;
//}
//vector<int> path;
//void DFS(int s, int e)
//{
//	if (s == e)
//	{
//		path.push_back(s);
//		for (int i = path.size() - 1; i >= 0; i--)
//		{
//			printf("%d", path[i]);
//			if (i > 0)printf("->");
//			else printf("\n");
//		}
//		path.pop_back();
//		return;
//	}
//	path.push_back(e);
//	for (int i = 0; i < pre[e].size(); i++)
//	{
//		DFS(s, pre[e][i]);
//	}
//	path.pop_back();
//}
//void criticalPath()
//{
//	for (int i = 0; i < n; i++)
//		ve[i] = 0;
//	if (!topo_sort())
//	{
//		cout << "存在环！！" << endl;
//		return;
//	}
//	for (int i = 0; i < n; i++)
//		vl[i] = ve[n - 1];//初始化一下
//	while (!topOrder.empty())
//	{
//		int u = topOrder.top();
//		topOrder.pop();
//		for (int i = 0; i < G[u].size(); i++)
//		{
//			int v = G[u][i].v, w = G[u][i].w;
//			if (vl[v] - w < vl[u])
//			{
//				vl[u] = vl[v] - w;//计算每个时间的最晚开始时间。
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << "活动" << i +1<< "开始的最早时间" << ve[i] << ",最晚时间" << vl[i] << endl;
//	}
//	for (int u = 0; u < n; u++)
//	{
//		for (int i = 0; i < G[u].size(); i++)
//		{
//			int v = G[u][i].v, w = G[u][i].w;
//			int e = ve[u], l = vl[v] - w;
//			if (e == l)
//			{
//				pre[v + 1].push_back(u + 1);
//			}
//		}
//	}
//	cout << "关键路径" << endl;
//	DFS(1, n);
//	return;
//}
//int main()
//{
//	cin >> n >> m;// n为点数，m为边数
//	
//	for (int i = 1; i <= m; i++)
//	{
//		int u, v, w;
//		cin>>u>>v>>w;
//		node.v = v - 1; node.w = w;
//		G[u - 1].push_back(node);
//	}
//	criticalPath();
//	return 0;
//}
///*
//输入为（即i.txt内容）：
//9 11
//1 2 6
//1 3 4
//1 4 5
//2 5 1
//3 5 1
//4 6 2
//5 7 9
//5 8 7
//6 8 4
//7 9 2
//8 9 4
//*/
////4 4
////1 2 6
////1 3 4
////3 4 1
////2 4 1
//
////10 13 
////1 2 3
////1 3 4
////2 5 6
////2 4 5
////3 4 8
////3 6 7
////4 5 3
////5 7 9
////5 8 4
////6 8 6
////7 10 2
////8 9 5
////9 10 3