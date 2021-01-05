//
//���ɢ�б�ʵ���ֻ��������ϵͳ�����ֻ��������Hash��
//[����Ҫ��]
//��1�� ����1141����¼��ÿ����¼����������������ֻ����롢�������Ա�
//��2�� ���ļ��������¼�����ֻ�����Ϊ�ؼ��ֽ���ɢ�б���p�������ÿ��Ŷ�ַ������ɢ�б����ж����ϣ�����Լ���ͻ������ƣ�
//��3���������к�������ʾ���ҳɹ�����£���ߵ�ɢ�д����Լ�ƽ�����ҳ���ASL��Ҫ�����ɢ�д������ܳ���100��ASL������5.0���ڡ�
//��4��Ȼ����ʾ�û����������ֻ�������в�ѯ���������ֻ�����󣬶Ը��ֻ�������й�ϣ���ң����ú�����ڣ�����ʾ�ھ������ٴ�ɢ�к󣬲��ҳɹ����������Ӧ��¼��ȫ�����ݣ����������Ա��ֻ����룻���ú��벻���ڣ�����ʾ�ھ������ٴ�ɢ�к�ȷ���ú��벻���ڡ�
//��5����ǰ���ҽ�������ʾ�û����Լ������룬������롰#�������ѫ���������򣬼����������Ĺ�ϣ����
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
	file.open("./6��ϣ����/data.txt");
	if (!file)
	{
		cout << "���ļ�ʧ�ܣ�";
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
	cout << "���ɢ�д���" << max_find_cnt << endl;
	cout << "ASL��"<< sum_find_cnt*1.0/n << endl;
	string input;
	cout << "�������ֻ���:" << endl;
	cin >> input;
	while (input != string("#"))
	{
		if (input.length() == 11)
		{
			int cnt=0;
			int pos = find(input, cnt);
			if (pos == -1)
			{
				cout << "��Ŭ����������" << cnt << "�Σ�����һ��Ҳû���ҵ���Ҫ����Ϣ" << endl;
			}
			else
			{
				cout << "��������" << cnt << "�Σ��ɹ��ҵ���Ҫ�ģ�" << hash1[pos].name << ' ' << hash1[pos].phone << ' ' << hash1[pos].sex << endl;
			}
		}
		else
		{
			cout << "��Ǹ��������ֻ֧�ֲ����й�11λ���ֻ�����" << endl;
		}

		cout << "�������ֻ���:" << endl;
		cin >> input;
	}
	return 0;
}

