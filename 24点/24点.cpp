//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include <string>
//#include <set>
//using namespace std;
//const float inf = 1000;
//const float esp = 1e-5;
//float add(float a, float b)
//{
//	return a + b;
//}
//float sub(float a, float b)
//{
//	return a - b;
//}
//float mul(float a, float b)
//{
//	return a * b;
//}
//float div1(float a, float b)//重定义？
//{
//	if (b == 0)
//		return inf;
//	return a / b;
//}
//set <string> ans;
//float(*operat_fun[4])(float, float) = { add, sub, mul, div1 };
//char operation_name[5] = "+-*/";
//void fun(int a,int b,int c,int d)
//{
//	bool have_ans = false;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			for (int k = 0; k < 4; k++)
//			{
//				//123((a#b)#c)#d
//				float result = operat_fun[k](operat_fun[j](operat_fun[i](a, b), c), d);
//				if (fabs(result -24)<esp)
//					ans.insert(string("((" + to_string(a) + operation_name[i] + to_string(b) + ")" + operation_name[j] + to_string(c) + ")" + operation_name[k] + to_string(d)));
//
//				//132(a#b)#(c#d)
//				result = operat_fun[k](operat_fun[i](a, b), operat_fun[j](c, d));
//				if (fabs(result - 24) < esp)
//					ans.insert(string("(" + to_string(a) + operation_name[i] + to_string(b) + ")" + operation_name[k] + "(" + to_string(c) + operation_name[j] + to_string(d) + ")"));
//
//				//213(a#(b#c))#d
//				result = operat_fun[k](operat_fun[j](a, operat_fun[i](b, c)), d);
//				if (fabs(result - 24) < esp)
//					ans.insert(string("(" + to_string(a) + operation_name[j] + "(" + to_string(b) + operation_name[i] + to_string(c) + "))" + operation_name[k] + to_string(d)));
//
//				//231 a#b#(c#d) 凑不出来
//
//				//312a#((b#c)#d)
//				result = operat_fun[k](a, operat_fun[j](operat_fun[i](b, c), d));
//				if (fabs(result - 24) < esp)
//					ans.insert(string(to_string(a) + operation_name[k] + "((" + to_string(b) + operation_name[i] + to_string(c) + ")" + operation_name[j] + to_string(d) + ")"));
//
//				//321a#(b#(c#d))
//				result = operat_fun[k](a, operat_fun[j](b, operat_fun[i](c, d)));
//				if (fabs(result - 24) < esp)
//					ans.insert(string(to_string(a) + operation_name[k] + "(" + to_string(b) + operation_name[j] + "(" + to_string(c) + operation_name[i] + to_string(d) + "))"));
//			}
//		}
//	}
//}
//int main()
//{
//	srand(time(0));
//	int num[10];
//	bool have_ans = false;;
//	for (int i = 1; i <= 4; i++)
//	{
//		num[i] = rand() % 13 + 1;
//		cin >> num[i];
//	}
//	cout << "原始数据" << num[1] << ' ' << num[2] << ' ' << num[3] << ' ' << num[4] << endl;
//	for (int i = 1; i <= 4; i++)
//		for (int j = 1; j <= 4; j++)
//			for (int k = 1; k <= 4; k++)
//			{
//				if (i == j || i == k || j == k)
//					continue;
//				int l = 10 - i - j - k;
//				fun(num[i], num[j], num[k], num[l]);
//			}
//	//freopen("1.txt", "w", stdout);
//	if (ans.size() == 0)
//	{
//		cout << -1 << endl;
//	}
//	else
//	{
//		for (auto a : ans)
//			cout << a << endl;
//	}
//	return 0;
//}
