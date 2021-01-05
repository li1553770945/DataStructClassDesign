//#include <iostream>
//#include <stack>
//#include <algorithm>
//#include <iomanip>
//using namespace std;
//enum class Status
//{
//	ERROR,
//	END,
//	OK,
//};
//inline bool is_num(char c)
//{
//	return c >= '0' && c <= '9';
//}
//inline bool is_ope(char c)
//{
//	return c == '+' || c == '-' || c == '*' || c == '/';
//}
//Status cal(const string &suffix,double &ans)
//{
//	stack <double> st;
//	for (unsigned int i = 0; i < suffix.length(); i++)
//	{
//		char cur = suffix[i];
//		
//		if (is_num(cur) || cur == '.')
//		{
//			double temp = 0;
//			int point = 0;
//			while (i < suffix.length() && (is_num(cur) || cur == '.'))
//			{
//				if (cur == '.')
//				{
//					point++;
//				}
//				else
//				{
//					int t = cur - '0';
//					if (point)
//					{
//						/*cout<< "pow"<<pow(0.1, point)<<endl;
//						cout <<"pow*cur"<< cur * pow(0.1, point) << endl;
//						cout << "cur" << cur << endl;*/
//						temp = temp + t * pow(0.1, point);
//						point++;
//					}
//					else
//					{
//						temp = temp * 10 + t;
//					}
//				}
//				cur = suffix[++i];
//			}
//			st.push(temp);
//			i--;
//		}
//		else if (is_ope(cur))
//		{
//			double a, b;
//			if (st.empty())
//			{
//				cout << "输入错误，表达式有误" << endl;
//				return Status::ERROR;
//			}
//			a = st.top();
//			st.pop();
//			if (st.empty())
//			{
//				cout << "输入错误，表达式有误" << endl;
//				return Status::ERROR;
//			}
//			b = st.top();
//			st.pop();
//			if (cur == '+')
//			{
//				st.push(b + a);
//			}
//			else if (cur == '-')
//			{
//				st.push(b - a);
//			}
//			else if (cur == '*')
//			{
//				st.push(a * b);
//			}
//			else if (cur == '/')
//			{
//				if (a == 0)
//				{
//					cout << "输入错误，除数不能为0" << endl;
//					return Status::ERROR;
//				}
//				st.push(b/a);
//			}
//		}
//	}
//	if (st.size() != 1)
//	{
//		cout << "表达式不正确，请注意程序不支持省略乘号" << endl;
//		return Status::ERROR;
//	}
//	ans = st.top();
//	return Status::OK;
//}
//int Priority(char operate)//栈中优先级
//{
//    switch (operate)
//    {
//	case '*':
//	case '/':
//		return 3;
//    case '+':
//    case '-':
//        return 2;
//    case '(':
//    case ')':
//        return 1;
//    default:
//        return 0;
//    }
//}
//Status input(string &suffix)
//{
//	cout << "请输入表达式，按↑键可以重新输入上次的表达式" << endl;
//	string str;
//	cin >> str;
//	if (str == "#")
//	{
//		return Status::END;
//	}
//	if (is_ope(str[0]))
//	{
//		cout << "↑输入错误，以操作符开始"<<endl;
//		return Status::ERROR;
//	}
//	stack <char> temp;
//	bool last_is_ope = true;
//	bool point = false;
//	for (unsigned int i = 0;i<str.length();i++)
//	{
//		char cur = str[i];
//		if (is_num(cur)||cur=='.')
//		{
//			bool point = false;
//			while (i<str.length()&&(is_num(cur) || cur == '.'))
//			{
//				if (cur == '.')
//				{
//					if (point)
//					{
//						for (unsigned int j = 0; j < i; j++)
//							cout << ' ';
//						cout << "↑输入错误，您输入了连续的两个小数点" << endl;
//						return Status::ERROR;
//					}
//					else
//					{
//						point = true;
//					}
//				}
//				suffix.push_back(cur);
//				i++;
//				cur = str[i];
//			}
//			suffix.push_back(' ');
//			i--;
//			last_is_ope = false;
//		}
//		else if (is_ope(cur))
//		{
//			if (last_is_ope)
//			{
//				for (unsigned int j = 0; j < i; j++)
//					cout << ' ';
//				cout << "↑输入错误，您输入了连续两个运算符" << endl;
//				return Status::ERROR;
//			}
//			else
//			{
//				while (!temp.empty() && Priority(cur) <= Priority(temp.top()))
//				{
//					
//					suffix.push_back(temp.top());
//					suffix.push_back(' ');
//					temp.pop();
//				}
//				temp.push(cur);
//				last_is_ope = true;
//				point = false;
//			}
//		}
//		else if (cur == '(')
//		{
//			temp.push(cur);
//			point = false;
//			last_is_ope = true;
//		}
//		else if (cur== ')')
//		{
//			
//			while (!temp.empty() && temp.top() != '(')
//			{
//				suffix.push_back(temp.top());
//				suffix.push_back(' ');
//				temp.pop();
//			}
//			if (temp.empty())
//			{
//				cout << "括号不匹配" << endl;
//				return Status::ERROR;
//			}
//			temp.pop();
//			point = false;
//			last_is_ope = false;
//		}
//		else
//		{
//			for (unsigned int j = 0; j < i; j++)
//				cout << ' ';
//			cout << "↑输入错误，不属于任何数字或操作符，请注意操作符只能为英文" << endl;
//			return Status::ERROR;
//		}
//		
//	}
//	if (last_is_ope)
//	{
//		for (unsigned int j = 0; j < str.length()-1; j++)
//			cout << ' ';
//		cout << "↑输入错误，以操作符结尾" << endl;
//		return Status::ERROR;
//	}
//	while (!temp.empty())
//	{
//		if (temp.top() == '(')
//		{
//			cout << "括号不匹配" << endl;
//			return Status::ERROR;
//		}
//		suffix.push_back(temp.top());
//		suffix.push_back(' ');
//		temp.pop();
//	}
//	return Status::OK;
//}
//int main()
//{
//	while(true)
//	{
//		string suffix;
//		Status legal = input(suffix);
//		if (legal == Status::OK)
//		{
//			double ans;
//			cout << "后缀表达式:" <<suffix<< endl;
//			Status status = cal(suffix, ans);
//			if (status==Status::OK)
//			{
//				cout << fixed << setprecision(2) << ans << endl;
//			}
//			else
//			{
//				cout << "请重新输入" << endl;
//				continue;
//			}
//			
//		}
//		else if (legal == Status::END)
//		{
//			break;
//		}
//		else if (legal == Status::ERROR)
//		{
//			continue;
//		}
//	}
//	return 0;
//}
