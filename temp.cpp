//#include <iostream>
//using namespace std;
//int b[11];
//void adjust(int* b, int len, int index)
//{
//	int left = index * 2;
//	int right = index * 2 + 1;
//	int max_index = index;
//	if (left <= len && b[left] > b[max_index])
//	{
//		max_index = left;
//	}
//	if (right <= len && b[right] > b[max_index])
//	{
//		max_index = right;
//	}
//
//	if (index != max_index)
//	{
//		swap(b[index], b[max_index]);
//		adjust(b, len, max_index);
//	}
//
//}
//void heap_sort(int len)
//{
//	for (int i = len / 2; i >= 1; i--)
//	{
//		adjust(b, len, i);
//	}
//	for (int i = len; i > 1; i--)
//	{
//		swap(b[i], b[1]);
//		adjust(b, i-1, 1);
//	}
//}
//int main()
//{
//
//	for (int i = 1; i <= 10; i++)
//		cin >> b[i];
//	heap_sort(10);
//	for (int i = 1; i <= 10; i++)
//		cout << b[i] << ' ';
//	return 0;
//}