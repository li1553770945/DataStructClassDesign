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
using namespace std;
class Date {
public:
	int year, month, day;
	Date(int _year, int _month , int _day );
	Date(string str);
	string str();
	bool operator <(const Date rhs);
};
class People {
public:
	int id;
	int gen;
	string name;
	string sex;
	Date birthday;
	bool married;
	string addr;
	string work;
	string live;
	Date death_date;
	People();
};
class Node :public QLabel {
public:
	static int max_id;
	People* people;
	Node* father;
	Node* mate;
	int x, y;
	vector <Node*>  son;
	Node();
	string get_name();
	bool add_son(People* _son);
	bool add_mate(People* _mate);
	int occupy_width;
};
Node* load();
bool save(Node*);
void clear_node(Node*);
void print_node(Node* p);
string relative(Node* a, Node* b);
Node* find_date(Node* p, int y, int m, int d);//根绝日期查找
Node* find_name(Node* p, string name);//根绝姓名查找
void mark(Node* p);