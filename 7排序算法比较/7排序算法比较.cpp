//[��������]
//���������������n�����������n = 500��1000��1500��2000��2500����, 30000��������ֱ�Ӳ��������۰��������ϣ�����򣨶��ڲ�ͬ���������ݣ����ɲ�ͬ���������У����������򡢿�������ѡ�����򡢶�������·�鲢���򣨷ǵݹ飩8�ַ�����������ͳ��ÿһ����������Ҫ�ıȽϴ����Լ��ƶ�������
//[����Ҫ��]
//��1�� ԭʼ����������ɡ�
//��2�� ���ڲ�ͬ�����ݹ�ģ����ʾÿ����������ıȽϴ����Լ��ƶ�������
//��3�� ����ÿһ�������㷨���ص�

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
				b[j + 1] = b[j];    //�������б��б�tempֵ���Ԫ�غ���           
				move++;
			}
			else
			{
				break;
			}//temp����������е����һλ����Ҫ�ƶ�
		}
		if (j + 1 != i)
		{
			b[j + 1] = temp;//�����ڲ�ѭ��������ں��ʵ�λ��
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
		{//�۰������������λ��
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
	quick_sort(a, low_true, low - 1, comp, move);//�ݹ����
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
	for (int len = 2; len <2 * size; len *= 2) // ������2,4,8����
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
	if (right<=len && arr[right] > arr[max_index]) max_index = right;  // maxIdx��3��������������±�
	comp += 2;
	if (max_index != index)                 // ���maxIdx��ֵ�и���
	{
		move++;
		swap(arr[max_index], arr[index]);
		adjust(arr, len, max_index,comp,move);       // �ݹ������������������ʵĲ���
	}

}
void heap_sort(int *b, int size,long long  &comp,long long &move)
{
	for (int i = size / 2 ; i > 0; i--)  // ��ÿһ����Ҷ�����жѵ���(�����һ����Ҷ��㿪ʼ)
	{
		adjust(b, size, i,comp,move);
	}
	for (int i = size ; i >1; i--)
	{
		move++;
		swap(b[1], b[i]);           // ����ǰ���ķ��õ�����ĩβ
		adjust(b, i-1, 1,comp,move);              // ��δ�������Ĳ��ּ������ж�����
	}
}
void create_data(int* p, int size)//��������
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
				cout << "�������" << endl;
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

	cout << "���ݹ�ģ" << maxn << "ԭʼ����" << endl;
	show(a, maxn);

	reset(comp, move, a, b);
	insert_sort(b, maxn, comp, move);
	cout << "ֱ�Ӳ������򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);
	

	reset(comp, move, a, b);
	insert_half_sort(b, maxn, comp, move);
	cout << "�۰�������򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	shell_sort(b, maxn, comp, move);
	cout << "ϣ�����򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	gulugulu_sort(b, maxn, comp, move);
	cout << "ð�����򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	quick_sort(b, 1, maxn, comp, move);
	cout << "�������򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	select_sort(b, maxn, comp, move);
	cout << "ѡ�����򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	merge_sort(b, maxn, comp, move);
	cout << "��·�鲢���򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);

	reset(comp, move, a, b);
	heap_sort(b, maxn, comp, move);
	cout << "�����򣬹�����" << comp << "�αȽϣ�" << move << "���ƶ�" << endl;
	check(b, maxn);
	show(b, maxn);

	delete[] a;
	delete[] b;
	return 0;
}