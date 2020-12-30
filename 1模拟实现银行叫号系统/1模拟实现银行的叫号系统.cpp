//#include <iostream>
//#include <queue>
//#include <vector>
//#include <list>
//#include <functional>
//#include <string>
//#include <iomanip>
//using namespace std;
//class Time {
//public:
//	int hour,minute;
//	Time(int _hour=0, int _minute=0)
//	{
//		hour = _hour;
//		minute = _minute;
//	}
//	Time operator +(const int &_minute)
//	{
//		Time t;
//		t.hour = this->hour;
//		t.minute = this->minute + _minute;
//		if (t.minute >= 60)
//		{
//			t.minute = t.minute % 60;
//			t.hour += 1;
//		}
//		return t;
//	}
//	Time operator+(Time &rhs)
//	{
//		Time t;
//		t.hour = this->hour + rhs.hour;
//		t.minute = this->hour + rhs.minute;
//		if (t.minute >= 60)
//		{
//			t.minute = t.minute % 60;
//			t.hour += 1;
//		}
//		return t;
//	}
//	bool operator <(const Time& rhs)
//	{
//		if (hour < rhs.hour)
//			return true;
//		else if (hour == rhs.hour)
//		{
//			return minute < rhs.minute;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	string Str()
//	{
//		if (minute < 10)
//			return to_string(hour) + ":0" + to_string(minute);
//		else
//			return to_string(hour) + ":" + to_string(minute);
//	}
//	int operator -(const Time& rhs)
//	{
//		return (hour - rhs.hour) * 60 + minute - rhs.minute;
//	}
//	bool operator <=(const Time& rhs)
//	{
//		if (hour < rhs.hour)
//			return true;
//		else if (hour == rhs.hour)
//		{
//			return minute <= rhs.minute;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
//
//class People {
//public:
//	Time time;
//	int wait;
//	People(Time _time = Time(0,0), int _wait=0)
//	{
//		time = _time;
//		wait = _wait;
//	}
//	bool operator < (const People rhs)
//	{
//		return time < rhs.time;
//	}
//};
//class Window {
//public:
//	int no, served;
//	Time time;
//	Window(int _no, int _served, Time _time)
//	{
//		no = _no;
//		served = _served;
//		time = _time;
//	}
//	bool operator < (const Window& rhs)
//	{
//		return time < rhs.time;
//	}
//	bool operator > (const Window& rhs)const 
//	{
//		if (time.hour > rhs.time.hour)
//		{
//			return true;
//		}
//		else if (time.hour == rhs.time.hour)
//		{
//			return time.minute > rhs.time.minute;
//		}
//		else
//		{
//			return false;
//		}
//
//	}
//};
//void SwapWindow(Window& a, Window& b)
//{
//	int temp;
//	temp = a.no;
//	a.no = b.no;
//	b.no = temp;
//	temp = a.served;
//	a.served = b.served;
//	b.served = temp;
//	Time t = a.time;
//	a.time = b.time;
//	b.time = t;
//}
//int main()
//{
//	srand(time(0));
//	int GetWaitTime();
//	Time GetArriveTime(int);
//	People people[1000];
//	int windows_num ;
//	cout << "�����봰��������";
//	cin >> windows_num;
//	while(windows_num)
//	{
//		int wait_time[1000];
//		priority_queue < Window, vector<Window>, greater<Window> > windows;
//		int people_count = 0, people_served = 0;
//		for (int i = 1; i <= windows_num; i++)//create windows
//		{
//			windows.push(Window(i, 0, Time(9, 0)));
//		}
//		for (int i = 9; i < 17; i++)//create people
//		{
//			int k = rand() % 35+1;
//			for (int j = 1; j <= k; j++)
//			{
//				people[++people_count]=People(GetArriveTime(i), GetWaitTime());
//			}
//		}
//		sort(people + 1, people + 1 + people_count);
//		Time end_time = Time(17, 0);
//
//		while (people_served < people_count && Time(windows.top().time) < end_time)
//		{
//			Window temp_window = windows.top();
//			windows.pop();
//			++people_served;
//			if (!people[people_served].wait)
//			{
//				cout << "��" << people_served << "�ſͻ���" << people[people_served].time.Str() << "����,��ǰ�뿪" << endl;
//				wait_time[people_served] = 0;
//		
//			}
//			else if (people[people_served].time < temp_window.time)
//			{
//				int wait = temp_window.time - people[people_served].time;
//				wait_time[people_served] = wait;
//				cout << "��" << people_served << "�ſͻ���" << people[people_served].time.Str() << "����,�ڵȴ���" << wait << "���Ӻ���" << temp_window.no << "�Ŵ��ڰ���ҵ�񣬳���" << people[people_served].wait << "����" << endl;
//			}
//			else
//			{
//				wait_time[people_served] = 0;
//				temp_window.time = people[people_served].time;
//				cout << "��" << people_served << "�ſͻ���" << people[people_served].time.Str() << "����,�ڵȴ���0���Ӻ���" << temp_window.no << "�Ŵ��ڰ���ҵ�񣬳���" << people[people_served].wait << "����" << endl;
//			}
//			temp_window.time = temp_window.time + people[people_served].wait; 
//			temp_window.served++;
//			windows.push(temp_window);
//			
//		}
//		int max_time = 0;
//		long long sum_wait_time = 0;
//		int served_sum = 0;
//		for (int i = 1; i <= people_served; i++)
//		{
//
//			if (wait_time[i] > max_time)
//			{
//				max_time = wait_time[i];
//			}
//			sum_wait_time += wait_time[i];
//		}
//		list <Window> windows_list;
//		while (!windows.empty())
//		{
//			windows_list.push_back(windows.top());
//			windows.pop();
//		}
//		windows_list.sort([](Window& a, Window& b) {return a.no < b.no; });
//		for (auto &window:windows_list)
//		{
//			served_sum += window.served;
//			cout << window.no << "�Ŵ��ڷ�����" << window.served << "���ͻ�" << endl;
//		}
//		cout << "����һ��������" << served_sum << "���ͻ�" << endl;
//		cout << "��ȴ�ʱ��" << max_time << "���ӣ�ƽ���ȴ�ʱ��" <<fixed<<setprecision(2)<< sum_wait_time*1.0 / people_served << "����" << endl;
//		cout << "�����봰��������";
//		cin >> windows_num;
//	}
//	return 0;
//}
//int GetWaitTime()
//{
//	return rand() % 31;
//}
//Time GetArriveTime(int hour)
//{
//	return Time(hour,rand()%60);
//}