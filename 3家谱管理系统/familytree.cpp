//3、家谱管理系统（指定数据文件）
//[问题描述]
//实现具有下列功能的家谱管理系统
//[基本要求]
//（1）每个成员应包含如下基本信息：姓名、性别、出生日期、婚否、地址、工作、健在否、死亡日期（若其已死亡），也可附加其它信息、但不是必需的
//（2）以图形方式显示家谱，并可以实现以下功能：
//	按照姓名查询，若该姓名存在，输出其基本信息以外，还应该输出包括：父母姓名、配偶姓名、子女姓名等相关信息；
//	按照年份查询，将出生于某年的族谱中所有人名输出；
//	按照年月查询，将出生于某年某月的族谱中所有人名输出；
//	按照年月日查询，将出生于某年某月某日的族谱中所有人名输出；
//	关系查询：输入两个人名，若都存在于族谱中，则确定两人的关系（一共5代人，存在多少种关系，需要自己定义）；
//	添加：可以为某成员添加子女或者配偶；
//	删除：可以将某个族谱成员删除（删掉某成员，若该成员是族谱直系成员，配偶不算，意味着他的配偶以及后代全部都要删除；如果删除的仅仅是某族谱成员的配偶，则不需要删除后代）
//	修改：可以修改某族谱成员的基本信息
//（3）界面要求：有合理的提示，每个功能可以设立菜单，根据提示，可以完成相关的功能要求。
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <qlabel.h>
#include <QtWidgets/QApplication>
#include "familytree.h"
#include <queue>
using namespace std;
int Node::max_id = 0;
map <string, string> all_relative;
Date::Date(int _year = 0, int _month = 0, int _day = 0)
{
	year = _year;
	month = _month;
	day = _day;
}
Date::Date(string str)
{

}
bool Date::operator<(const Date rhs)
{
	if (year == rhs.year)
	{
		if (month == rhs.month)
			return day < rhs.day;
		return month < rhs.month;
	}
	else
	{
		return year < rhs.year;
	}
}
string Date::str()
{
	char y[5], m[3], d[3];
	sprintf(y, "%4d", year);
	sprintf(m, "%2d", month);
	sprintf(d, "%2d", day);
	if (year)
		return string(string(y) +'-' +string(m) +'-'+ string(d));
	return string("不详");

}
People::People()
{
	married = false;
	id = 0;
	death_date = Date(9999, 9, 9);
	gen = 0;
}
Node::Node()
{
	setStyleSheet("border:2px solid red;");
	QFont font("Microsoft YaHei", 10, 50); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
	setFont(font);
	people = NULL;
	father = mate = NULL;
	x = y = 0;
}
bool Node::add_son(People* _son)
{
	//TODO: 不应该为非直系亲属添加孩子
	//TODO: 改用异常处理
	if (_son->birthday < people->birthday)
		return false;
	
	Node* p = new Node;
	p->people = _son;
	if(!_son->id)
		_son->id = ++max_id;
	extern Node* ancestor;
	p->people->gen = this->people->gen + 1;
	if (!this->father && this != ancestor)
	{
		p->father = this->mate;
		this->mate->son.push_back(p);
	}
	else
	{
		p->father = this;
		son.push_back(p);
	}
	return true;
}
bool Node::add_mate(People* _mate)
{
	if (this->people->married)
		return false;
	this->people->married = true;
	Node* p = new Node;
	p->people = _mate;
	if(!_mate->id)
		_mate->id = ++max_id;
	p->mate = this;
	p->people->gen = this->people->gen;
	this->mate = p;
	return true;
}

void clear_node(Node* p)
{
	if (!p)
		return;
	extern Node* ancestor;
	if (p->father || p == ancestor)
	{
		clear_node(p->mate);
	}
	
	for (auto s : p->son)
	{
		clear_node(s);
	}
	delete p->people;
	delete p;
}
void write(ofstream& file, Node* p)
{
	if (!p)
		return;
	People* pe = p->people;
	file << p->people->id << " " << p->people->gen << " " << p->people->name << " " <<p->people->live<<" "<< p->people->sex << " " << p->people->birthday.year << " " << p->people->birthday.month << " " << p->people->birthday.day << " " << p->people->addr << " " << p->people->work << " " << p->people->death_date.year << " " << p->people->death_date.month << " " << p->people->death_date.day<<endl;
	extern Node* ancestor;
	if (p == ancestor || p->father)
	{
		write(file, p->mate);
	}
	for (auto s : p->son)
		write(file, s);
}
void write_relation(ofstream& file, Node* p)
{
	if (!p)
		return;
	file << p->people->id << endl;
	if (p->mate)
	{
		file << p->mate->people->id << endl;
	}
	else
	{
		file << '#' << endl;
	}

	for (auto s : p->son)
	{
		file << s->people->id << " ";
	}
	file << "#"<<endl;
	for (auto s : p->son)
		write_relation(file, s);

}
bool save(Node* ancestor)//保存数据
{
	ofstream file("people.txt");
	if (!file.is_open())
	{
		return NULL;
	}
	write(file, ancestor);
	file.close();


	file.open("relation.txt");
	if (!file.is_open())
	{
		return NULL;
	}
	write_relation(file, ancestor);
	file.close();
	return true;
}
Node *find_people(Node* p,int id)
{
	if (!p)
		return NULL;
	if (p->people->id == id)
		return p;
	extern Node* ancestor;
	if (p == ancestor||p->father)
	{
		Node* mate = find_people(p->mate, id);
		if (mate)
			return mate;
	}
	
	for (auto pe : p->son)
	{
		Node* s = find_people(pe, id);
		if (s)
			return s;
	}
	return NULL;
}
void load_all_relative()
{
	ifstream file("all_relation.txt");
	if (file.fail())
	{
		cout << "关系表不存在";
		exit(EXIT_FAILURE);
	}
	while (!file.eof())
	{
		string s1, s2;
		file >> s1 >> s2;
		if (file.fail())
			return;
		all_relative[s1] = s2;
	}
	
}
Node* load()//从文件中加载数据
{

	ifstream file;
	file.open("people.txt");
	if (file.fail())
	{
		return NULL;
	}
	vector <People*> ps;
	while (!file.eof())//加载个人信息
	{
		int id;
		int gen;
		string name;
		string sex;
		Date birthday;
		string addr;
		string work;
		Date death_date;
		string live;
		file >> id >> gen>> name >>live>> sex >> birthday.year >> birthday.month >> birthday.day >> addr >> work >> death_date.year >> death_date.month >> death_date.day;
		if (file.fail())
			break;
		People* temp = new People;
		temp->id = id;
		temp->name = name;
		temp->sex = sex;
		temp->birthday = birthday;
		temp->addr = addr;
		temp->work = work;
		temp->death_date = death_date;
		temp->gen = gen;
		temp->live = live;
		ps.push_back(temp);
	}
	Node::max_id = ps.size();
	Node* p = new Node;
	extern Node* ancestor;
	p->people = *ps.begin();
	ancestor = p;
	file.close();
	file.open("relation.txt");
	if (file.fail())
	{
		return NULL;
	}
	while (!file.eof())//加载关系
	{
		int id;
		string male, son;
		file >> id ;
		if (file.fail())
			break;
		Node* now = find_people(p,id);
		if (now == NULL)
		{
			cout << "无法找到此人，id为" << id;
			return NULL;
		}
		file >> male;
		if (male == string("#"))
		{

		}
		else
		{
			for (auto pe : ps)
			{
				if (pe->id == atoi(male.data()))
				{
					now->add_mate(pe);
					break;
				}
			}
		}
		file >> son;
		while (son != string("#"))
		{
			for (auto pe : ps)
			{
				if (pe->id == atoi(son.data()))
				{
					now->add_son(pe);
					break;
				}
			}
			file >> son; 
		}
		
	}
	load_all_relative();
	//void temp_add();
	//temp_add();
	return p;
}
void print_node(Node* p)
{
	cout << p->people->name<<"地址： "<<p->people->addr<<"出生日期 "<<p->people->birthday.str() << endl;
}
void dfs(Node* a, Node* b,bool &find, deque <string> &q,Node* last)
{
	if (find)
		return;
	if (a == NULL || b == NULL)
	{
		return;
	}
	if (a == b)
	{
		find = true;
		return;
	}
	if (find)
		return;
	if (q.back() != "女儿" && q.back() != "儿子")
	{
		if (b->father)
		{
			q.push_back("爸爸");
			dfs(a, b->father, find, q,b);
			if (find)
				return;
			q.pop_back();

		}
	}
	
	
	for (int i = 0; i < b->son.size(); i++)
	{
		if (b->son[i] == last)
			continue;
		if (b->son[i]->people->sex == "男")
			q.push_back("儿子");
		else
			q.push_back("女儿");
		dfs(a, b->son[i], find, q,b);
		if (find)
			return;
		q.pop_back();
	}
	
	
	extern Node* ancestor;
	if (q.back() != "老婆" && q.back() != "老公")
	{
		if (b->mate)
		{
			if (b->mate->people->sex == "男")
				q.push_back("老公");
			else
				q.push_back("老婆");
			dfs(a, b->mate, find, q,b);
			if (find)
				return;
			q.pop_back();
		}
	}
	
}

string relative(Node* a, Node* b)
{
	if (a == b)
		return "自己";
	deque <string> q;
	bool find = false;
	q.push_back("");
	dfs(a, b, find, q,NULL);
	if (q.size() == 1)
	{
		return "未知";
	}
	string str,str1;
	q.pop_front();
	while (q.size())
	{
		string temp = q.front();
		q.pop_front();
		if (temp == "爸爸")
			str1 += 'f';
		if (temp == "老婆")
			str1 += 'w';
		if (temp == "老公")
			str1 += 'h';
		if (temp == "女儿")
			str1 += 'd';
		if (temp == "儿子")
			str1 += 's';
		str += temp;
		if (q.size())
		{
			str += "的";
			str1 += ",";
		}
	}
	if (all_relative[str1] == string(""))
	{
		cout << str1 << " " << str << endl;
		return str;
	}
	else
	{
		return all_relative[str1];
	}
	
}
//void temp_add()
//{
//	extern Node* ancestor;
//	ifstream file;
//	file.open("temp.txt");
//	vector <People*> ps;
//	while (!file.eof())//加载个人信息
//	{
//		int id;
//		int gen;
//		string name;
//		string sex;
//		Date birthday;
//		string addr;
//		string work;
//		Date death_date;
//		string live;
//		string relation;
//		file >> id >> gen >> name >> live >> sex >> birthday.year >> birthday.month >> birthday.day >> addr >> work >> death_date.year >> death_date.month >> death_date.day >>relation;
//		if (file.fail())
//			break;
//		People* temp = new People;
//		temp->id = id;
//		temp->name = name;
//		temp->sex = sex;
//		temp->birthday = birthday;
//		temp->addr = addr;
//		temp->work = work;
//		temp->death_date = death_date;
//		temp->gen = gen;
//		temp->live = live;
//		string father = relation.substr(0, 6);
//		Node* f =find_name(ancestor, father);
//		if (!f)
//		{
//			cout << "无法添加" << father<<endl;
//		}
//		string re_last = relation.substr(8, 2);
//		if (re_last == "子" || re_last == "女")
//		{
//			f->add_son(temp);
//		}
//		if (re_last == "妻")
//		{
//			f->add_mate(temp);
//		}
//
//	}
//}
Node * find_date(Node* p, int y, int m, int d)//根绝日期查找
{
	if (!p)
		return NULL;

	p->setStyleSheet("border:2px solid red;");
	extern Node* ancestor;
	if (p->people->birthday.year == y && p->people->birthday.month == m && p->people->birthday.day == d)
	{
		mark(p);
		return p;
	}
	if (p->people->birthday.year == y && p->people->birthday.month == m && d == 0)
	{
		mark(p);
		return p;
		
	}
	if (p->people->birthday.year == y && m == 0 && d == 0)
	{
		mark(p);
		return p;
	}

	if (p == ancestor || p->father)
	{
		find_date(p->mate, y, m, d);
	}
	for (auto pe : p->son)
	{
		find_date(pe, y, m, d);
	}
}
Node* find_name(Node* p, string name)//根绝姓名查找
{
	if (!p)
		return NULL;

	p->setStyleSheet("border:2px solid red;");

	extern Node* ancestor;
	if (name == p->people->name)
	{
		mark(p);
		return p;
	}

	if (p == ancestor || p->father)
	{
		Node * temp = find_name(p->mate, name);
		if (temp)
			return temp;
	}
	for (auto pe : p->son)
	{
		Node* temp = find_name(pe, name);;
		if (temp)
			return temp;
	}
	return NULL;

}
void mark(Node* p)//找到标记
{
	p->setStyleSheet("border:2px solid blue;");
	print_node(p);
}
string Node::get_name()
{
	string text;
	for (int i = 0; i < people->name.length() - 1; i+=2)
	{
		text = text + people->name.substr(i, 2)+'\n';
	}
	return text;
} 
