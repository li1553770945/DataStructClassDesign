////
////设计散列表实现手机号码查找系统，对手机号码进行Hash。
////[基本要求]
////（1） 现有1141条记录，每条记录包含有下列数据项：手机号码、姓名、性别
////（2） 从文件读入各记录，以手机号码为关键字建立散列表（表长1171）。采用开放定址法建立散列表，自行定义哈希函数以及冲突解决机制；
////（3）程序运行后，首先显示查找成功情况下，最高的散列次数以及平均查找长度ASL。要求最高散列次数不能超过100，ASL控制在5.0以内。
////（4）然后提示用户可以输入手机号码进行查询。待输入手机号码后，对该手机号码进行哈希查找，若该号码存在，则显示在经过多少次散列后，查找成功，并输出对应记录的全部内容，即姓名、性别、手机号码；若该号码不存在，则显示在经过多少次散列后确定该号码不存在。
////（5）当前查找结束后，提示用户可以继续输入，如果输入“#”，则程勋结束；否则，继续做上述的哈希查找
//#include <iostream>
//#include <fstream>
//#include <vector>
//using namespace std;
//struct Node {
//	string phone, name, sex;
//};
//vector <Node> node;
//int load_file()
//{
//	ifstream file;
//	file.open("./6哈希查找/data.txt");
//	if (!file)
//	{
//		cout << "打开文件失败！";
//		return -1;
//	}
//	while(!file.eof())
//	{
//		
//		Node temp;
//		file >> temp.name >> temp.sex >> temp.phone;
//		if (file.fail())
//			break;
//		node.push_back(temp);
//	}
//	return 0;
//}
//void hash1()
//{
//
//}
//int find(string phone)
//{
//	return 1;
//}
//void show()
//{
//	for (auto &person : node)
//	{
//		cout << person.name << " " << person.sex << " " << person.phone << endl;
//	}
//}
//int main()
//{
//	if (load_file() == -1)
//		return 0;
//	show();
//	hash1();
//	string input;
//	cout << "请输入手机号:" << endl;
//	cin >> input;
//	while (input != string("#"))
//	{
//		int pos = find(input);
//		if (pos==-1)
//		{
//			cout << "没有找到相关信息" << endl;
//		}
//		else
//		{
//
//		}
//
//		cout << "请输入手机号:" << endl;
//		cin >> input;
//	}
//	return 0;
//}
//
