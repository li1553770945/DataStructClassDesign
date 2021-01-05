//
//设计散列表实现手机号码查找系统，对手机号码进行Hash。
//[基本要求]
//（1） 现有1141条记录，每条记录包含有下列数据项：手机号码、姓名、性别
//（2） 从文件读入各记录，以手机号码为关键字建立散列表（表长p）。采用开放定址法建立散列表，自行定义哈希函数以及冲突解决机制；
//（3）程序运行后，首先显示查找成功情况下，最高的散列次数以及平均查找长度ASL。要求最高散列次数不能超过100，ASL控制在5.0以内。
//（4）然后提示用户可以输入手机号码进行查询。待输入手机号码后，对该手机号码进行哈希查找，若该号码存在，则显示在经过多少次散列后，查找成功，并输出对应记录的全部内容，即姓名、性别、手机号码；若该号码不存在，则显示在经过多少次散列后确定该号码不存在。
//（5）当前查找结束后，提示用户可以继续输入，如果输入“#”，则程勋结束；否则，继续做上述的哈希查找
#include <iostream>
#include <fstream>
#include <vector>
const int n = 1141;
const int p = 1171;
using namespace std;
int max_find_cnt;
int sum_find_cnt;
struct Node {
	string phone, name, sex;
};
Node hash1[p];
int get_hash(string str)
{
	int s = 4;
	return atoi(str.substr(s, 11-s).data()) % p;
}
int load_file()
{
	ifstream file;
	file.open("./6哈希查找/data.txt");
	if (!file)
	{
		cout << "打开文件失败！";
		return -1;
	}
	while(!file.eof())
	{
		
		Node temp;
		file >> temp.name >> temp.sex >> temp.phone;
		if (file.fail())
			break;
		
		int key = get_hash(temp.phone);
		int find_cnt = 0;
		for (int i = 0; i<=(n-1)/2; i++)
		{
			
			find_cnt++;
			if (hash1[(key + i * i) % p].phone == string(""))
			{
				hash1[(key + i * i) % p] = temp;
				break;
			}
			if(i)
				find_cnt++;
			if (key - i * i >= 0)
			{
				if (hash1[key - i * i].phone == string(""))
				{
					hash1[key - i * i] = temp;
					break;
				}
			}
			else
			{
				int t = (key - i * i) % p + p;
				if (hash1[t].phone == string(""))
				{
					hash1[t] = temp;
					break;
				}
			}

		}
		max_find_cnt = max(find_cnt, max_find_cnt);
		sum_find_cnt += find_cnt;

	}
	return 0;
}

int find(string phone,int &cnt)
{
	int key = get_hash(phone);
	for (int i = 0; i <= (n - 1) / 2; i++)
	{
		cnt++;
		if (hash1[(key + i * i) % p].phone == phone)
		{
			return (key + i * i) % p;
		}
		else if (hash1[(key + i * i) % p].phone == string())
			return -1;
		if (i)
			cnt++;
		if (key - i * i >= 0)
		{
			if (hash1[key - i * i].phone == phone)
			{
				return key - i * i;
			}
			else if (hash1[key - i * i].phone == string())
				return -1;
		}
		else
		{
			int t = (key - i * i) % p + p;
			if (hash1[t].phone == phone)
			{
				return t;
			}
			else if (hash1[t].phone == string())
				return -1;
		}

	}
}
void show()
{
	for (auto &person : hash1)
	{
		cout << person.name << " " << person.sex << " " << person.phone << endl;
	}
}
int main()
{
	if (load_file() == -1)
		return 0;
	//show();
	cout << "最高散列次数" << max_find_cnt << endl;
	cout << "ASL："<< sum_find_cnt*1.0/n << endl;
	string input;
	cout << "请输入手机号:" << endl;
	cin >> input;
	while (input != string("#"))
	{
		if (input.length() == 11)
		{
			int cnt=0;
			int pos = find(input, cnt);
			if (pos == -1)
			{
				cout << "我努力的搜索了" << cnt << "次，搜了一身汗也没有找到您要的信息" << endl;
			}
			else
			{
				cout << "我搜索了" << cnt << "次，成功找到您要的：" << hash1[pos].name << ' ' << hash1[pos].phone << ' ' << hash1[pos].sex << endl;
			}
		}
		else
		{
			cout << "抱歉，本程序只支持查找中国11位的手机号码" << endl;
		}

		cout << "请输入手机号:" << endl;
		cin >> input;
	}
	return 0;
}

