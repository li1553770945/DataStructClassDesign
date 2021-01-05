//#include<iostream>
//#include<fstream>
//#include<string.h>
//#include<stdlib.h>
//using namespace std;
//#define OK 0
//#define STACKINITSIZE 256
//#define STACKINCREMENT 128
//#define TRUE 1
//#define FALSE 0
////////////栈的数据结构和相关函数 
//typedef struct SeqStack
//{
//	int* data;
//	int* pBase;
//	int* pTop;
//	int stacksize;
//}SeqStack;
//int InitStack(SeqStack& S)
//{
//	S.data = new int[STACKINITSIZE];
//	if (S.pBase == NULL)
//	{
//		exit(-1);
//	}
//	S.pTop = S.pBase=S.data;
//	S.stacksize = STACKINITSIZE;
//	return OK;
//}
//int DestroyStack(SeqStack& S)
//{
//	if (S.pBase != NULL)
//	{
//		delete[]S.pBase;
//		S.pBase = NULL;
//	}
//	S.pTop = NULL;
//	S.stacksize = 0;
//	cout << "Destroy Done!" << endl;
//	return OK;
//}
//bool StackEmpty(SeqStack S)
//{
//	if (S.pBase == NULL)
//	{
//		cout << "Stack doesn't exsit!" << endl;
//		return true;
//	}
//	if (S.pTop==S.pBase)
//	{
//		return TRUE;
//	}
//	return FALSE;
//}
//int ClearStack(SeqStack& S)
//{
//	S.pTop = S.pBase;
//	return OK;
//}
//int StackLength(SeqStack S)
//{
//	return S.pTop - S.pBase;
//}
//int Push(SeqStack& S, int e)
//{
//	if (S.pTop - S.pBase != S.stacksize)
//	{
//		*(S.pTop) = e;
//		S.pTop++;
//	}
//	else
//	{
//		int * tmp;
//		tmp = new int[S.stacksize + STACKINCREMENT];
//		for (int i = 0; i < S.stacksize; i++)
//		{
//			tmp[i] = S.data[i];
//		}
//		delete[]S.data;
//		S.data = tmp;
//		S.stacksize += STACKINCREMENT;
//		*(S.pTop) = e;
//		S.pTop++;
//	}
//	return 0;
//}
//int Pop(SeqStack& S)
//{
//	if (S.pTop == S.pBase)
//	{
//		return '\0';
//	}
//	S.pTop--;
//	return *(S.pTop);
//}
//int StackTraverse(SeqStack S)
//{
//	int* p = S.pBase;
//	while (p != S.pTop)
//	{
//		cout << *p << ",";
//		p++;
//	}
//	cout << endl;
//	return OK;
//}
//int GetTop(SeqStack S)
//{
//	return *(S.pTop - 1);
//}
//int* GetBaseloca(SeqStack S)
//{
//	return S.pBase;
//}
////////////////队列的数据结构和函数
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode, * QueuePtr;
//typedef struct LinkQueue
//{
//	QueuePtr front;
//	QueuePtr rear;
//}LinkQueue;
//int InitQueue(LinkQueue& Q)
//{
//	Q.front = Q.rear = new LNode;
//	if (Q.front == NULL)
//	{
//		cout << "Init fall!" << endl;
//		exit(-1);
//	}
//	Q.front->next = NULL;
//	return OK;
//}
//int DestroyQueue(LinkQueue& Q)
//{
//	LNode* p;
//	while (Q.front->next != NULL)
//	{
//		p = Q.front->next;
//		Q.front->next = p->next;
//		delete p;
//	}
//	delete Q.front;
//	Q.front = NULL;
//	Q.rear = NULL;
//	return OK;
//}
//int ClearQueue(LinkQueue& Q)
//{
//	if (Q.front->next == NULL)
//	{
//		cout << "Queue dosen't exsit!" << endl;
//		exit(-1);
//	}
//	LNode* p;
//	while (Q.front->next != NULL)
//	{
//		p = Q.front->next;
//		Q.front->next = p->next;
//		delete p;
//	}
//	Q.rear = Q.front;
//	Q.front->next = NULL;
//	return OK;
//}
//bool QueueEmpty(LinkQueue Q)
//{
//	if (Q.front->next == NULL)
//	{
//		cout << "Queue doesn't exist!" << endl;
//		exit(-1);
//	}
//	if (Q.front == Q.rear)
//	{
//		return TRUE;
//	}
//	else
//	{
//		return FALSE;
//	}
//}
//int QueueLength(LinkQueue Q)
//{
//	LNode* p;
//	int length = 0;
//	p = Q.front->next;
//	if (Q.front->next == NULL)
//	{
//		cout << "Queue doesn't exist!" << endl;
//		exit(-1);
//	}
//	while (p != NULL)
//	{
//		p = p->next;
//		length++;
//	}
//	return length;
//}
//LNode* GetHead(LinkQueue Q)
//{
//	if (Q.front->next != NULL)
//	{
//		return Q.front->next;
//	}
//	else
//	{
//		return NULL;
//	}
//}
//int EnQueue(LinkQueue& Q, int e)
//{
//	LNode* pNew = new LNode;
//	pNew->data = e;
//	Q.rear->next = pNew;
//	Q.rear = pNew;
//	Q.rear->next = NULL;
//	return OK;
//}
//int DeQueue(LinkQueue& Q)
//{
//	int e;
//	if (Q.front->next == NULL)
//	{
//		cout << "Queue dosen't exsit!" << endl;
//		exit(-1);
//	}
//	if (Q.front == Q.rear)
//	{
//		cout << "Queue is empty!" << endl;
//		return -1;
//	}
//	LNode* p;
//	p = Q.front->next;
//	e = p->data;
//	Q.front->next = p->next;
//	if (Q.rear == p)
//	{
//		Q.rear = Q.front;
//	}
//	delete p;
//	return e;
//}
//float min(float a, float b)
//{
//	if (a < b)
//	{
//		return a;
//	}
//	else
//	{
//		return b;
//	}
//}
/////////图相关的数据结构用类表示 
//struct ArcNode
//{
//	int adjvex;			//该弧所指向的顶点的位置vertices[adjvex]
//	int road;			//表示这一条弧是第几路车，方便构建车与车之间的图
//	ArcNode* nextarc;	//指向下一条弧的指针
//};
//struct VNode
//{
//	char name[50];		//站点名
//	ArcNode* firstarc;	//指向第一条依附于该顶点的弧的指针
//};
//class ALGraph {
//private:
//	VNode vertices[6000];					//顶点向量,每一站之间都有一个顶点
//	int vexnum, arcnum;						//图的当前顶点数和弧数
//	int* visited;							//用于深度优先搜索和广度优先搜索
//public:
//	void AddArcNode(int v1, int v2, int road)
//		//为vertices[v1]和vertices[v2]两个站之间添加一条无向边，并且记录这一条无向边第road路上的
//	{
//		ArcNode* Ap;
//		Ap = vertices[v1].firstarc;
//		if (Ap == NULL)
//		{
//			vertices[v1].firstarc = new ArcNode;
//			vertices[v1].firstarc->adjvex = v2;
//			vertices[v1].firstarc->road = road;
//			vertices[v1].firstarc->nextarc = NULL;
//		}
//		else
//		{
//			while (Ap->nextarc != NULL)
//			{
//				Ap = Ap->nextarc;
//			}
//			Ap->nextarc = new ArcNode;
//			Ap = Ap->nextarc;
//			Ap->adjvex = v2;
//			Ap->road = road;
//			Ap->nextarc = NULL;
//		}
//		Ap = vertices[v2].firstarc;
//		if (Ap == NULL)
//		{
//			vertices[v2].firstarc = new ArcNode;
//			vertices[v2].firstarc->adjvex = v1;
//			vertices[v2].firstarc->road = road;
//			vertices[v2].firstarc->nextarc = NULL;
//		}
//		else
//		{
//			while (Ap->nextarc != NULL)
//			{
//				Ap = Ap->nextarc;
//			}
//			Ap->nextarc = new ArcNode;
//			Ap = Ap->nextarc;
//			Ap->adjvex = v1;
//			Ap->road = road;
//			Ap->nextarc = NULL;
//		}
//		arcnum++;//边数++
//	}
//	ALGraph()
//	{
//		arcnum = 0;
//		int i, j, count;
//		int road;
//		int pre_p;
//		fstream file;
//		ArcNode* Ap;
//		char str[3000];
//		file.open("南京公交线路.txt", ios::in);
//		if (file.fail())
//		{
//			cout << "File open Error!" << endl;
//			exit(-1);
//		}
//		vexnum = 0;
//		road = 0;
//		count = 0;
//		while (!file.eof())
//		{
//			file >> road;
//			if (file.eof())
//			{
//				break;
//			}
//			file.getline(str, 3000, '\n');
//			i = 0;
//			while (str[i] != ' ') i++;
//			while (str[i] == ' ') i++;
//			while (1)
//			{
//				for (j = 0; str[i] != ',' && str[i] != '\0'; i++, j++)
//				{
//					vertices[vexnum].name[j] = str[i];
//				}
//				vertices[vexnum].name[j] = '\0';
//				for (j = 0; j < vexnum; j++)
//				{
//					if (strcmp(vertices[j].name, vertices[vexnum].name) == 0)
//					{
//						if (count > 0)
//						{
//							AddArcNode(j, pre_p, road);
//						}
//						pre_p = j;
//						count++;
//						break;
//					}
//				}
//				if (j == vexnum)
//				{
//					vertices[vexnum].firstarc = NULL;
//					if (count > 0)
//					{
//						AddArcNode(pre_p, vexnum, road);
//					}
//
//					pre_p = vexnum;
//					vexnum++;
//					count++;
//				}
//				if (str[i] != '\0')
//				{
//					i++;
//				}
//				else
//				{
//					break;
//				}
//			}
//			pre_p = 0;
//			count = 0;
//		}
//		file.close();
//		visited = new int[vexnum];
//	}
//	~ALGraph()
//	{
//		ArcNode* Ap, * pre_Ap;
//		for (int i = 0; i < vexnum; i++)
//		{
//			Ap = vertices[i].firstarc;
//			if (Ap == NULL);
//			else
//			{
//				pre_Ap = Ap;
//				while (1)
//				{
//					Ap = Ap->nextarc;
//					if (Ap == NULL)
//					{
//						break;
//					}
//					delete pre_Ap;
//					pre_Ap = Ap;
//				}
//			}
//		}
//	}
//	ArcNode* AdjVex(int i)
//	{
//		ArcNode* Ap;
//		Ap = vertices[i].firstarc;
//		if (Ap == NULL)
//		{
//			return NULL;
//		}
//		else
//		{
//			return Ap;
//		}
//	}
//	int GetVexNum()
//	{
//		return vexnum;
//	}
//	int FindRoad(char* n)
//	{
//		for (int i = 0; i < vexnum; i++)
//		{
//			if (strcmp(vertices[i].name, n) == 0)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//	VNode* GetVNode()
//	{
//		return vertices;
//	}
//	bool IsAdj(int i, int j)//判断vertices[i]与vertices[j]是否相邻
//	{
//		ArcNode* Ap;
//		Ap = vertices[i].firstarc;
//		if (Ap == NULL);
//		else
//		{
//			while (Ap != NULL)
//			{
//				if (Ap->adjvex == j)
//				{
//					return true;
//				}
//				Ap = Ap->nextarc;
//			}
//		}
//		Ap = vertices[j].firstarc;
//		if (Ap == NULL);
//		else
//		{
//			while (Ap != NULL)
//			{
//				if (Ap->adjvex == i)
//				{
//					return true;
//				}
//				Ap = Ap->nextarc;
//			}
//		}
//		return false;
//	}
//	void MiniRoad(char* start, char* end)			//用广度优先搜索求最短路径
//		//start是起始站点的名字，end的是结束站点的名字
//	{
//		for (int i = 0; i < vexnum; i++)
//		{
//			visited[i] = 0;
//		}
//		int v, u;
//		int s, e;
//		ArcNode* w = NULL;
//		int i, j;
//		int flag = 0;
//		LinkQueue Q;
//		InitQueue(Q);
//		for (i = 0; i < vexnum; i++)
//		{
//			if (strcmp(start, vertices[i].name) == 0)
//			{
//				s = i;
//			}
//			if (strcmp(end, vertices[i].name) == 0)
//			{
//				e = i;
//			}
//		}
//		v = s;
//		visited[v] = 1;
//		EnQueue(Q,v);
//		while (!QueueEmpty(Q))//广度优先搜索
//		{
//			if (flag == 1)
//			{
//				break;
//			}
//			u = DeQueue(Q);
//			for (w = vertices[u].firstarc; w != NULL; w = w->nextarc)
//			{
//				if (visited[w->adjvex] == 0)
//				{
//					visited[w->adjvex] = visited[u] + 1;//往深一层搜索
//					if (w->adjvex == e)
//					{
//						flag = 1;//已经走到了终点
//						break;
//					}
//					EnQueue(Q,w->adjvex);
//				}
//			}
//		}
//		ArcNode* Ap;
//		SeqStack S_sta;
//		SeqStack S_road;
//		InitStack(S_sta);
//		InitStack(S_road);
//		Push(S_sta,w->adjvex);
//		i = w->adjvex;
//		cout << "经过站最少的路线为：" << endl;
//		cout << "一共有：" << visited[w->adjvex] << "站" << endl;
//		for (int deep = visited[w->adjvex] - 1; deep > 1; deep--)//i是层数
//		{
//			for (j = 0; j < vexnum; j++)//j为下标
//			{
//				if (visited[j] == deep && IsAdj(i, j))//如果是上一层并且两站点相邻
//				{
//					Push(S_sta,j);//j可以在路线上，进栈
//					i = j;//i成为上一层
//					break;//结束循环并且往更上一层寻找
//				}
//			}
//		}
//		cout << vertices[s].name;
//		i = s;
//		while (!StackEmpty(S_sta))//输出路线
//		{
//			cout << "——>";
//			j = Pop(S_sta);
//			Ap = vertices[j].firstarc;
//			while (Ap->adjvex != i)
//			{
//				Ap = Ap->nextarc;
//			}
//			if (StackEmpty(S_road) || (GetTop(S_road) != Ap->road))//于此同时记录路线上的站点的乘车路线，并记录
//			{
//				Push(S_road,Ap->road);
//			}
//			cout << vertices[j].name;
//			i = j;
//		}
//		cout << endl << endl;
//		cout << "应搭乘的公交车路线为：" << endl;
//		cout << "一共有：" << StackLength(S_road) << "路车" << endl;
//		cout << Pop(S_road) << "路";
//		while (!StackEmpty(S_road))
//		{
//			cout << "—>";
//			cout << Pop(S_road) << "路";
//		}
//		cout << endl << endl;
//	}
//};
//struct Arc
//{
//	int adjvex;			//该弧所指向的顶点的位置vertices[adjvex]
//	Arc* nextarc;	//指向下一条弧的指针
//};
//struct BusNode
//{
//	Arc* firstarc;	//指向第一条依附于该顶点的弧的指针
//};
//class LGraph//这个类是车与车之间的图
//{
//private:
//	BusNode vertices[1000];							//顶点向量，从1开始
//	int vexnum, arcnum;						//图的当前顶点数和弧数
//	int* visited;
//public:
//
//	void AddArc(int v1, int v2)
//	{
//		int flag;
//		Arc* Ap;
//		Ap = vertices[v1].firstarc;
//		if (Ap == NULL)
//		{
//			vertices[v1].firstarc = new Arc;
//			vertices[v1].firstarc->adjvex = v2;
//			vertices[v1].firstarc->nextarc = NULL;
//		}
//		else
//		{
//			flag = 0;
//			while (Ap->nextarc != NULL)
//			{
//				if (Ap->adjvex == v2) flag = 1;//说明两辆车可以换乘的信息已经记录了
//				Ap = Ap->nextarc;
//				if (Ap->adjvex == v1) flag = 1;//说明两辆车可以换乘的信息已经记录了	
//			}
//			if (!flag)
//			{
//				Ap->nextarc = new Arc;
//				Ap = Ap->nextarc;
//				Ap->adjvex = v2;
//				Ap->nextarc = NULL;
//			}
//		}
//		Ap = vertices[v2].firstarc;
//		if (Ap == NULL)
//		{
//			vertices[v2].firstarc = new Arc;
//			vertices[v2].firstarc->adjvex = v1;
//			vertices[v2].firstarc->nextarc = NULL;
//		}
//		else
//		{
//			flag = 0;
//			while (Ap->nextarc != NULL)
//			{
//				if (Ap->adjvex == v1) flag = 1;//说明两辆车可以换乘的信息已经记录了	
//				Ap = Ap->nextarc;
//				if (Ap->adjvex == v1) flag = 1;//说明两辆车可以换乘的信息已经记录了			
//			}
//			if (!flag)
//			{
//				Ap->nextarc = new Arc;
//				Ap = Ap->nextarc;
//				Ap->adjvex = v1;
//				Ap->nextarc = NULL;
//			}
//		}
//		arcnum++;
//	}
//	LGraph(ALGraph* G)//用站与站之间的图来构建
//	{
//		vexnum = 0;
//		ArcNode* Ap;
//		Arc* Bp;
//		int i, j, k;
//		int count;
//		int Bus[500];
//		for (i = 0; i < G->GetVexNum(); i++)
//		{
//			Ap = G->GetVNode()[i].firstarc;
//			for (j = 0; j < 500; j++)
//			{
//				Bus[j] = 0;
//			}
//			if (Ap == NULL)
//			{
//				continue;
//			}
//			else
//			{
//				count = 0;
//				while (Ap != NULL)
//				{
//					for (k = 0; k < count; k++)
//					{
//						if (Ap->road == Bus[k])
//						{
//							break;
//						}
//					}
//					if (k == count)
//					{
//						Bus[count++] = Ap->road;
//						if (Ap->road > vexnum)
//						{
//							vexnum = Ap->road;
//						}
//					}
//					Ap = Ap->nextarc;
//				}
//				for (k = 0; k < count - 1; k++)
//				{
//					for (j = k + 1; j < count; j++)
//					{
//						if (Bus[j] != Bus[k])
//						{
//							AddArc(Bus[j], Bus[k]);
//						}
//					}
//				}
//			}
//		}
//		visited = new int[vexnum + 1];
//	}
//	~LGraph()
//	{
//		Arc* Ap, * pre_Ap;
//		for (int i = 1; i < vexnum + 1; i++)
//		{
//			Ap = vertices[i].firstarc;
//			if (Ap == NULL);
//			else
//			{
//				pre_Ap = Ap;
//				while (1)
//				{
//					Ap = Ap->nextarc;
//					if (Ap == NULL)
//					{
//						break;
//					}
//					delete pre_Ap;
//					pre_Ap = Ap;
//				}
//			}
//		}
//	}
//	bool IsAdj(int i, int j)//判断vertices[i]与vertices[j]是否相邻
//	{
//		Arc* Ap;
//		Ap = vertices[i].firstarc;
//		if (Ap == NULL);
//		else
//		{
//			while (Ap != NULL)
//			{
//				if (Ap->adjvex == j)
//				{
//					return true;
//				}
//				Ap = Ap->nextarc;
//			}
//		}
//		Ap = vertices[j].firstarc;
//		if (Ap == NULL);
//		else
//		{
//			while (Ap != NULL)
//			{
//				if (Ap->adjvex == i)
//				{
//					return true;
//				}
//				Ap = Ap->nextarc;
//			}
//		}
//		return false;
//	}
//	int FindMinTime(int start, int end)			//从v开始进行广度优先搜索
//	{
//		if (start == end)
//		{
//			return 0;
//		}
//
//		for (int i = 1; i < vexnum + 1; i++)
//		{
//			visited[i] = 0;
//		}
//		int v, u;
//		Arc* w = NULL;
//		int i, j;
//		int flag = 0;
//		LinkQueue Q;
//		InitQueue(Q);
//		v = start;
//		visited[v] = 1;
//		EnQueue(Q,v);
//		while (!QueueEmpty(Q))
//		{
//			if (flag == 1)
//			{
//				break;
//			}
//			u = DeQueue(Q);
//			for (w = vertices[u].firstarc; w != NULL; w = w->nextarc)
//			{
//				if (visited[w->adjvex] == 0)
//				{
//					visited[w->adjvex] = visited[u] + 1;
//					if (w->adjvex == end)
//					{
//						flag = 1;//已经走到了终点
//						break;
//					}
//					EnQueue(Q,w->adjvex);
//				}
//			}
//		}
//		return  visited[w->adjvex];
//	}
//	void PrintMinTransform(int start, int end)
//	{
//		if (start == end)
//		{
//			cout << "两站位于" << start << "路车路线上" << endl;
//			return;
//		}
//		for (int i = 1; i < vexnum + 1; i++)
//		{
//			visited[i] = 0;
//		}
//		int v, u;
//		Arc* w = NULL;
//		int i, j;
//		int flag = 0;
//		LinkQueue Q;
//		InitQueue(Q);
//		v = start;
//		visited[v] = 1;
//		EnQueue(Q,v);
//		while (!QueueEmpty(Q))
//		{
//			if (flag == 1)
//			{
//				break;
//			}
//			u = DeQueue(Q);
//			for (w = vertices[u].firstarc; w != NULL; w = w->nextarc)
//			{
//				if (visited[w->adjvex] == 0)
//				{
//					visited[w->adjvex] = visited[u] + 1;
//					if (w->adjvex == end)
//					{
//						flag = 1;//已经走到了终点
//						break;
//					}
//					EnQueue(Q,w->adjvex);
//				}
//			}
//		}
//		Arc* Ap;
//		SeqStack S;
//		InitStack(S);
//		Push(S,w->adjvex);
//		i = w->adjvex;
//		if (visited[w->adjvex] <= 2)
//		{
//			cout << "不用换乘" << endl;
//		}
//		else
//		{
//			cout << endl;
//			cout << "换乘最少的路线为：" << endl;
//			cout << "一共要换乘：" << visited[w->adjvex] - 1 << "次" << endl;
//		}
//		for (int deep = visited[w->adjvex] - 1; deep > 1; deep--)//i是层数
//		{
//			for (j = 0; j < vexnum; j++)//j为下标
//			{
//				if (visited[j] == deep && IsAdj(i, j))
//				{
//					Push(S,j);
//					i = j;
//					break;
//				}
//			}
//		}
//		cout << start;
//		i = start;
//		while (!StackEmpty(S))
//		{
//			cout << "——>换乘";
//			cout << Pop(S);
//		}
//		cout << endl << endl;
//	}
//	void MiniTransform(ALGraph* G, int start, int end)		//对G中每一个点都进行广度优先搜索
//	{
//		int i, j;
//		for (i = 1; i < vexnum + 1; i++)
//		{
//			visited[i] = 0;
//		}
//		ArcNode* Ap;
//		int s_road[100];
//		int e_road[100];
//		int s_count = 0;
//		int e_count = 0;
//		char s[50];
//		char e[50];
//		Ap = G->GetVNode()[start].firstarc;
//		while (Ap != NULL)
//		{
//			s_road[s_count++] = Ap->road;
//			Ap = Ap->nextarc;
//		}
//		Ap = G->GetVNode()[end].firstarc;
//		while (Ap != NULL)
//		{
//			e_road[e_count++] = Ap->road;
//			Ap = Ap->nextarc;
//		}
//		int min = 99999;
//		int tmp = 0;
//		int min_s = 0;
//		int min_e = 0;
//		for (i = 0; i < s_count; i++)
//		{
//			for (j = 0; j < e_count; j++)
//			{
//				tmp = FindMinTime(s_road[i], e_road[j]);
//				if (tmp <= min)
//				{
//					min = tmp;
//					min_s = s_road[i];
//					min_e = e_road[j];
//				}
//			}
//		}
//		PrintMinTransform(min_s, min_e);
//	}
//};
//int main()
//{
//	int start, end;
//	char s[50];
//	char e[50];
//	cout << "请输入起点：";
//	cin >> s;
//	cout << "请输入终点：";
//	cin >> e;
//	ALGraph A;
//	LGraph B(&A);
//	start = A.FindRoad(s);
//	end = A.FindRoad(e);
//	if (start == -1 || end == -1)//输入出错提示 
//	{
//		if (start == -1)
//			cout << "第一个站点有误！" << endl;
//		if (end == -1)
//			cout << "第二个站点有误！" << endl;
//		return 0;
//	}
//	if (start == end)
//	{
//		cout << "\n起点和终点位置相同！" << endl;
//		return 0;
//	}
//	A.MiniRoad(s, e);
//	cout << endl<< "最少换乘" << endl;
//	B.MiniTransform(&A, start, end);
//	return 0;
//}
