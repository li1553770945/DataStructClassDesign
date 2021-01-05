//[问题描述]
//利用随机函数产生n个随机整数（n = 500，1000，1500，2000，2500，…, 30000），利用直接插入排序、折半插入排序、希尔排序（对于不同数量的数据，生成不同的增量序列）、起泡排序、快速排序、选择排序、堆排序、两路归并排序（非递归）8种方法进行排序，统计每一种排序所需要的比较次数以及移动次数。
//[基本要求]
//（1） 原始数据随机生成。
//（2） 对于不同的数据规模，显示每种排序所需的比较次数以及移动次数。
//（3） 分析每一种排序算法的特点

#include <iostream>
const int maxn = 1000;
using namespace std;
const bool is_show = false;
const bool is_check = true;
void insert_sort(int* b, int size, long long& comp, long long& move)
{
	int i, j;
	for (i = 1; i <= size; ++i)
	{
		int temp = b[i];
		for (j = i - 1; j >= 1; --j)
		{
			comp++;
			if (temp < b[j])
			{
				b[j + 1] = b[j];    //在有序列表中比temp值大的元素后移           
				move++;
			}
			else
			{
				break;
			}//temp大于有序表中的最后一位则不需要移动
		}
		if (j + 1 != i)
		{
			b[j + 1] = temp;//跳出内层循环后插入在合适的位置
			move++;
		}
	}
}
void insert_half_sort(int* b, int size, long long& comp, long long& move)
{
	for (int i = 2; i <= size; i++)
	{
		int temp = b[i];
		int low = 1;
		int high = i - 1;
		while (low <= high)
		{//折半查找有序插入的位置
			int mid = (low + high) / 2;
			comp++;
			if (temp < b[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (int j = i - 1; j >= high + 1; j--)
		{
			b[j + 1] = b[j];
			move++;
		}
		b[high + 1] = temp;
		move++;
	}

}
void shell_sort(int* b, int size, long long& comp, long long& move)
{
	int gap = size;
	while (gap)
	{
		gap = gap / 2;
		for (int i = gap + 1; i <= size; i++)
		{
			int temp = b[i];
			int j = i - gap;
			while (j >= 0 && temp < b[j])
			{
				comp++;
				move++;
				b[j + gap] = b[j];
				j -= gap;
			}
			b[j + gap] = temp;
			move++;
		}

	}
}
void gulugulu_sort(int* a, int size, long long& comp, long long& move)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j <= size - i; j++)
		{
			comp++;
			if (a[j + 1] < a[j])
			{
				move += 3;
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];
			}
		}
	}
}
void quick_sort(int* a, int low, int high, long long& comp, long long& move)
{
	if (low >= high)
		return;
	int low_true = low, high_true = high;
	int x = a[low];
	while (low < high)
	{
		//cout << low << " " << high<<endl;
		while (low < high && a[high] >= x)
		{
			comp++;
			high--;
		}
		if (high > low)
		{
			move++;
			a[low] = a[high];
			low++;
		}
		while (low < high && a[low] <= x)
		{
			comp++;
			low++;
		}
		if (high > low)
		{
			move++;
			a[high] = a[low];
			high--;
		}
	}
	a[high] = x;
	quick_sort(a, low_true, low - 1, comp, move);//递归调用
	quick_sort(a, low + 1, high_true, comp, move);
}
void select_sort(int* a, int size, long long& comp, long long& move)
{
	for (int i = 1; i < size; i++)
	{
		int p = i;
		for (int j = i + 1; j <= size; j++)
		{
			comp++;
			if (a[j] < a[p])
			{
				p = j;
				move++;
			}
		}
		if (p != i)
		{
			int temp = a[i];
			a[i] = a[p];
			a[p] = temp;
			move += 3;
		}
	}
}
void merge_sort(int b[], int size, long long& comp, long long& move)
{
	int *temp = new int[maxn+1];
	for (int len = 2; len <2 * size; len *= 2) // 步长，2,4,8……
	{
		for (int left = 1; left <size; left+=len)
		{
			int j=0;
			int right = min(size,left + len - 1);
			int mid = left + len / 2;
			if (mid > right)
				continue;
			int p1 = left, p2 = mid;
			while (p1 < mid && p2 <= right)
			{
				comp++;
				move++;
				if (b[p1] < b[p2])
				{
					temp[++j] = b[p1++];
				}
				else
				{
					temp[++j] = b[p2++];
				}
			}
			while (p1 < mid)
			{
				move++;
				temp[++j] = b[p1++];
			}
			while (p2 <= right)
			{
				move++;
				temp[++j] = b[p2++];
			}
			j = 1;
			for (int k = left; k <= right; k++,j++)
			{
				move++;
				b[k] = temp[j];
			}
		}
	}
	delete[] temp;
}
void adjust(int arr[], int len, int index,long long &comp,long long &move)
{
	int left = 2 * index ;
	int right = 2 * index + 1;
	int max_index = index;
	if (left<=len && arr[left] > arr[max_index]) max_index = left;
	if (right<=len && arr[right] > arr[max_index]) max_index = right;  // maxIdx是3个数中最大数的下标
	comp += 2;
	if (max_index != index)                 // 如果maxIdx的值有更新
	{
		move++;
		swap(arr[max_index], arr[index]);
		adjust(arr, len, max_index,comp,move);       // 递归调整其他不满足堆性质的部分
	}

}
void heap_sort(int *b, int size,long long  &comp,long long &move)
{
	for (int i = size / 2 ; i > 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
	{
		adjust(b, size, i,comp,move);
	}
	for (int i = size ; i >1; i--)
	{
		move++;
		swap(b[1], b[i]);           // 将当前最大的放置到数组末尾
		adjust(b, i-1, 1,comp,move);              // 将未完成排序的部分继续进行堆排序
	}
}
void create_data(int* p, int size)//生成数据
{
	srand(time(0));
	for (int i = 1; i < size; i++)
	{
		p[i] = rand() % 10000;
		//p[i] = i;
		//p[i] = size - i;
	}
}

template<typename T>
void show(T* data, int size)
{
	if (is_show)
	{
		for (int i = 1; i <= size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

}
void reset(long long & comp, long long& move, int* a, int* b)
{
	comp = 0, move = 0;
	memcpy(b, a, (maxn + 1) * sizeof(int));
}
void check(int* b, int size)
{
	if (is_check)
	{
		for (int i = 2; i <= size; i++)
		{
			if (b[i - 1] > b[i])
			{
				cout << "排序出错" << endl;
			}
		}
	}
	
}
int main()
{
	int* a = new int [maxn+1];
	int* b = new int [maxn + 1];
	create_data(a, maxn + 1);
	long long  comp, move;

	cout << "数据规模" << maxn << "原始数据" << endl;
	show(a, maxn);

	reset(comp, move, a, b);
	insert_sort(b, maxn, comp, move);
	cout << "直接插入排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);
	

	reset(comp, move, a, b);
	insert_half_sort(b, maxn, comp, move);
	cout << "折半插入排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	shell_sort(b, maxn, comp, move);
	cout << "希尔排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	gulugulu_sort(b, maxn, comp, move);
	cout << "冒泡排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	quick_sort(b, 1, maxn, comp, move);
	cout << "快速排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	select_sort(b, maxn, comp, move);
	cout << "选择排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	merge_sort(b, maxn, comp, move);
	cout << "二路归并排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	heap_sort(b, maxn, comp, move);
	cout << "堆排序，共经过" << comp << "次比较，" << move << "次移动" << endl;
	check(b, maxn);
	show(b, maxn);

	delete[] a;
	delete[] b;
	return 0;
}