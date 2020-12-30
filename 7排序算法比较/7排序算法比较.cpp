//#include <iostream>
//const int maxn = 100;
//using namespace std;
//void quick_sort(int* a, int low, int high, int& comp, int& move)
//{
//	if (high - low <= 1)
//		return;
//	int low_true = low, high_true = high;
//	int x = a[low];
//	while (low < high)
//	{
//		cout << low << " " << high<<endl;
//		while (low < high && a[high] >= x)
//		{
//			comp++;
//			high--;
//		}
//		if (high > low)
//		{
//			move++;
//			a[low] = a[high];
//			low++;
//		}
//		while (low < high && a[low] <= x)
//		{
//			comp++;
//			low++;
//		}
//		if (high > low)
//		{
//			move++;
//			a[high] = a[low];
//			high--;
//		}
//	}
//	a[high] = x;
//	quick_sort(a,low_true,low-1,comp,move);
//	quick_sort(a,low+1,high_true,comp,move);	
//}
//void gulugulu_sort(int *a,int size,int &comp,int &move)
//{
//	for (int i = 1; i < size; i++)
//	{
//		for (int j = 1; j <= size - i; j++)
//		{
//			comp++;
//			if (a[j + 1] < a[j])
//			{
//				move+=3;
//				a[j] ^= a[j + 1];
//				a[j + 1] ^= a[j];
//				a[j] ^= a[j + 1];
//			}
//		}
//	}
//}
//void radix_sort()
//{
//
//}
//void select_sort(int* a, int size, int& comp, int& move)
//{
//	for (int i = 1; i < size; i++)
//	{
//		int p = i;
//		for (int j = i + 1; j <= size; j++)
//		{
//			comp++;
//			if (a[j] < a[p])
//			{
//				p = j;
//				move++;
//			}
//		}
//		if (p != i)
//		{
//			int temp = a[i];
//			a[i] = a[p];
//			a[p] = a[i];
//			move += 3;
//		}
//	}
//}
//void create_data(int* p, int size)
//{
//	srand(time(0));
//	for (int i = 0; i < size; i++)
//	{
//		p[i] = rand() % 10000;
//		p[i] = i;
//		p[i] = size - i;
//	}
//}
//int main()
//{
//	int a[maxn+1];
//	int b[maxn+1];
//	create_data(a, maxn+1);
//	int comp = 0, move = 0;
//
//	comp = 0, move = 0;
//	memcpy(b, a, (maxn + 1) * sizeof(int));
//	quick_sort(b,1, maxn, comp, move);
//	cout << "快速排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
//	for (int i = 1; i <= maxn; i++)
//	{
//		cout << b[i] << " ";
//	}
//	cout << endl;
//
//	comp = 0, move = 0;
//	memcpy(b, a, (maxn + 1) * sizeof(int));
//	gulugulu_sort(b,maxn, comp, move);
//	cout << "冒泡排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
//	for (int i = 1; i <= maxn; i++)
//	{
//		cout << b[i] << " ";
//	}
//	cout << endl;
//
//	comp = 0, move = 0;
//	memcpy(b, a, (maxn + 1) * sizeof(int));
//	select_sort(b, maxn, comp, move);
//	cout << "选择排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
//	for (int i = 1; i <= maxn; i++)
//	{
//		cout << b[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}