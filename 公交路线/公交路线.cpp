//#include <iostream>	
//#include <fstream>
//#include <string>
//#include <vector>
//#include <map>
//#include <queue>
//const int int_inf = 2147483647;
//const int max_n = 1000001,max_e = 3000001;
//using namespace std;
//struct EDGE {
//	int w, v, next;
//}e[max_e];
//
//int head[max_n];
//string buses_name[1000];
//int disc[max_n];
//map <string, vector<int>> stops_to_node;//map[i]里面的所有数字表示所有站点相同但是公交路线不同的点的序号
//void addedge(int,int,int);
//struct Stop {
//	string name;
//	int bus_num;
//	Stop(string _name, int id)
//	{
//		name = _name;
//		bus_num = id;
//	}
//};
//vector <Stop> bus_stops;
//vector <int> bus_to_stop[1000];
//int bus_num, stop_num, cnt;
//int main()
//{
//	void load_file();
//	void add_all_edge();
//	void print_all_path();
//	void input();
//	load_file();
//	add_all_edge();
//	//print_all_path();
//	input();
//	return 0;
//
//}
//vector <string> get_stops(string str)
//{
//	vector <string> ans;
//	str += ' ';
//	bool last_is_space = true;
//	int left=-1;
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i] == ' ')
//		{
//			
//			if (last_is_space)
//			{
//				continue;
//			}
//			else
//			{
//				ans.push_back(str.substr(left,i- left));
//				left = -1;
//
//			}
//			last_is_space = true;
//		}
//		else
//		{
//			last_is_space = false;
//			if (left == -1)
//				left = i;
//			
//		}
//	}
//	return ans;
//}
//void input()
//{
//	void dj1(string,int*);
//	void task(string start, string end,int);
//	string start, end;
//	while (1)
//	{
//		cout << "请输入起点:" << endl;
//		cin >> start;
//		while (!stops_to_node[start].size())
//		{
//			cout << "输入错误，请重新输入" << endl;
//			cin >> start;
//		}
//		cout << "请输入终点:" << endl;
//		cin >> end;
//		while (!stops_to_node[end].size()||start==end)
//		{
//			cout << "输入错误，请重新输入" << endl;
//			cin >> end;
//		}
//		task(start, end, 0);
//		task(start, end, 1);
//	}
//	
//}
//void task(string start, string end,int type)
//{	
//	if(type==0)
//		cout << "最短路径" << endl;
//	else
//		cout << "最小换乘" << endl;
//	pair<int, int> dj(string,string,int*,int);
//	int path[max_e];
//	pair<int,int> result=dj(start,end, path,type);
//	int end_pos = result.second;
//	if (end_pos==-1)
//	{
//		cout << "抱歉，暂时没有找到您需要的线路" << endl;
//		return;
//	}
//	vector<Stop> stops;
//	int t = end_pos;
//	while (bus_stops[t].name != start)
//	{
//		stops.push_back(bus_stops[t]);
//		t = path[t];
//	}
//	reverse(stops.begin(), stops.end());
//	cout << "从" << start << "开始" << endl;
//	cout << "乘坐" << buses_name[stops[0].bus_num];
//	int sum_transfor = 0, sum_pass = 0;
//	for (int i = 0; i < stops.size(); i++)
//	{
//		if (i && stops[i].bus_num != stops[i - 1].bus_num)//换线
//		{
//			if (i + 1 < stops.size() && stops[i].name != stops[i + 1].name)//换了好几次，选择最后一次
//			{
//				cout << endl << "转乘" << buses_name[stops[i].bus_num];
//				sum_transfor++;
//			}
//		}
//		else
//		{
//			sum_pass++;
//			cout << "->" << stops[i].name << " ";
//		}
//		if (stops[i].name == end)
//			break;
//
//	}
//	cout << endl << "中途共经过" << sum_pass << "个站，转乘" << sum_transfor << "次" << endl;
//
//}
//void load_file()
//{
//	bus_stops.push_back(Stop("", 1));
//	ifstream file("./公交路线/routine.txt");
//	if (file.fail())
//	{
//		cout << "打开文件失败!!!" << endl;
//		exit(EXIT_FAILURE);
//	}
//	while (!file.eof())
//	{
//		++bus_num;
//		char str_temp[3000];
//		string bus_name,str;
//		file >> bus_name;
//		if (file.fail())
//		{
//			bus_num--;
//			break;
//		}
//		file.getline(str_temp,3000);
//		str = string(str_temp);
//		vector <string> stops = get_stops(str);
//		//cout << bus_name;
//		buses_name[bus_num] = bus_name;
//		for (int i = 0;i<stops.size();i++)
//		{
//			bus_to_stop[bus_num].push_back(++stop_num);
//			bus_stops.push_back(Stop(stops[i], bus_num));
//			stops_to_node[stops[i]].push_back(stop_num);
//		}
//		//cout << endl;
//	}
//}
//void add_all_edge()
//{
//	for (int i = 1; i <= bus_num; i++)
//	{
//		for (int j = 0; j < bus_to_stop[i].size() - 1; j++)
//		{
//			
//			addedge(bus_to_stop[i][j], bus_to_stop[i][j + 1], 1);
//			addedge(bus_to_stop[i][j+1], bus_to_stop[i][j], 1);
//		}
//	}
//	
//
//	for (auto nodes:stops_to_node)
//	{
//		for (vector<int>::iterator it = nodes.second.begin(); (it+1) != nodes.second.end(); it++)
//		{
//			addedge(*it,*(it+1),0 );
//			addedge(*(it + 1), *it, 0);
//		}
//	}
//}
//void print_all_path()
//{
//	for (int i = 1; i <= stop_num; i++)
//	{
//		cout << buses_name[bus_stops[i].bus_num] << "上的" << bus_stops[i].name << "可到达的站点有" << endl;
//		for (int j = head[i]; j; j = e[j].next)
//		{
//
//			cout << buses_name[bus_stops[e[j].v].bus_num] << "上的" << bus_stops[e[j].v].name << "权值为:" << e[j].w << endl;
//
//			//cout << j;
//		}
//		cout << endl;
//	}
//}
//void addedge(int u, int v, int w)
//{
//	cnt++;
//	e[cnt].v = v;
//	e[cnt].w = w;
//	e[cnt].next = head[u];
//	head[u] = cnt;
//}
//pair<int,int> dj(string start,string end,int *path,int type)
//{
//	int path_all[max_e], min_disc_all = int_inf,end_all=-1,s_all=-1;
//	for (int k = 0; k < stops_to_node[start].size();k++)
//	{
//		int s = stops_to_node[start][k];
//		for (int j = 0; j < max_n; j++)
//			disc[j] = int_inf;
//		bool visit[max_n];
//		memset(visit, 0, sizeof visit);
//
//		struct node {
//			int u, dis;
//			bool operator <(const node& rhs) const {
//				return dis > rhs.dis;
//
//			}
//		};
//		priority_queue <node> Q;
//		disc[s] = 0;
//		Q.push(node{ s, 0 });
//		while (!Q.empty())
//		{
//			node fnt = Q.top();
//			Q.pop();
//			int u = fnt.u, d = fnt.dis;
//			visit[u] = true;
//			for (int i = head[u]; i; i = e[i].next)
//			{
//				int v = e[i].v, w = e[i].w;
//				if (type == 1)
//					w = 1 - w;
//				if (disc[v] > disc[u] + w && !visit[v])
//				{
//					path[v] = u;
//					disc[v] = disc[u] + w;
//					Q.push(node{ v,disc[v] });
//				}
//			}
//		}
//		int min_disc = int_inf;
//		int end_temp;
//		for (int j = 0; j < stops_to_node[end].size();j++)
//		{
//			if (min_disc > disc[stops_to_node[end][j]])
//			{
//				min_disc = disc[stops_to_node[end][j]];
//				end_temp = stops_to_node[end][j];
//			}
//		}
//		if (min_disc_all > min_disc)
//		{
//			for (int i = 0; i < max_e; i++)
//				path_all[i] = path[i];
//			end_all = end_temp;
//			s_all = s;
//		}
//	}
//	for (int i = 0; i < max_e; i++)
//	{
//		path[i] = path_all[i];
//	}
//	return make_pair(s_all, end_all);
//}