//#include<iostream>
//#include <string>
//#include <set>
//using namespace std;
//const int inf = 2147483647;
//int add(int a, int b)
//{
//    return a + b;
//}
//int sub(int a, int b)
//{
//    return a - b;
//}
//int mul(int a, int b)
//{
//    return a * b;
//}
//int div1(int a, int b)//重定义？
//{
//    if (b == 0)
//        return -inf;
//    if (a % b != 0)
//        return -inf;
//    return a / b;
//}
//set <string> anss;
//int(*op[4])(int, int) = { add, sub, mul, div1 };
//char operation_name[5] = "+-*/";
//int fun(int a, int b, int c, int d)
//{
//    string ans = "";
//    bool have_ans = false;
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            for (int k = 0; k < 4; k++)
//            {
//                //((a#b)#c)#d
//                int result = op[k](op[j](op[i](a, b), c), d);
//                if (result == 24)
//                {
//                    if (ans != "")ans += "\n";
//                    ans += "((";
//                    ans += to_string(a);
//                    ans += operation_name[i];
//                    ans += to_string(b);
//                    ans += ")";
//                    ans += operation_name[j];
//                    ans += to_string(c);
//                    ans += ")";
//                    ans += operation_name[k];
//                    ans += to_string(d);
//                    anss.insert(ans);
//                    ans = "";
//                    have_ans = true;
//                }
//                //(a#(b#c))#d
//                result = op[k](op[j](a, op[i](b, c)), d);
//                if (result == 24)
//                {
//                    if (ans != "")ans += "\n";
//                    ans += "(";
//                    ans += to_string(a);
//                    ans += operation_name[j];
//                    ans += "(";
//                    ans += to_string(b);
//                    ans += operation_name[i];
//                    ans += to_string(c);
//                    ans += "))";
//                    ans += operation_name[k];
//                    ans += to_string(d);
//                    anss.insert(ans);
//                    ans = "";
//                    have_ans = true;
//                }
//                //a#((b#c)#d)
//                result = op[k](a, op[j](op[i](b, c), d));
//                if (result == 24)
//                    if (result == 24)
//                    {
//                        if (ans != "")ans += "\n";
//                        ans += to_string(a);
//                        ans += operation_name[k];
//                        ans += "((";
//                        ans += to_string(b);
//                        ans += operation_name[i];
//                        ans += to_string(c);
//                        ans += ")";
//                        ans += operation_name[j];
//                        ans += to_string(d);
//                        ans += ")";
//                        anss.insert(ans);
//                        ans = "";
//                        have_ans = true;
//                    }
//                //(a#b)#(c#d)
//                result = op[k](op[i](a, b), op[j](c, d));
//                if (result == 24)
//                {
//                    if (ans != "")ans += "\n";
//                    ans += "(";
//                    ans += to_string(a);
//                    ans += operation_name[i];
//                    ans += to_string(b);
//                    ans += ")";
//                    ans += operation_name[k];
//                    ans += "(";
//                    ans += to_string(c);
//                    ans += operation_name[j];
//                    ans += to_string(d);
//                    ans += ")";
//                    anss.insert(ans);
//                    ans = "";
//                    have_ans = true;
//                }
//                //a#(b#(c#d))
//                result = op[k](a, op[j](b, op[i](c, d)));
//                if (result == 24)
//                {
//                    if (ans != "")ans += "\n";
//                    ans += to_string(a) + operation_name[k] + "(" + to_string(b) + operation_name[j] + "(" + to_string(c) + operation_name[i] + to_string(d) + "))";
//                    anss.insert(ans);
//                    ans = "";
//                    have_ans = true;
//                }
//            }
//        }
//    }
//    for (auto& ans : anss)
//        cout << ans<<endl;
//    return have_ans;
//}
//int main()
//{
//    srand(time(0));
//    int num[10];
//    bool have_ans = false;;
//    for (int i = 1; i <= 4; i++)
//    {
//        num[i] = rand() % 13 + 1;
//        cin >> num[i];
//    }
//    cout << "原始数据" << num[1]<< ' ' << num[2] << ' ' << num[3] << ' ' << num[4] << endl;
//    for(int i=1;i<=4;i++)
//         for(int j=1;j<=4;j++)
//             for (int k = 1; k <= 4; k++)
//             {
//                 if (i == j || i == k || j == k)
//                     continue;
//                 int l=10-i-j-k;
//                 if (fun(num[i], num[j], num[k], num[l]))
//                     have_ans = true;
//             }
//    if (!have_ans)
//        cout << -1;
//    return 0;
//}
