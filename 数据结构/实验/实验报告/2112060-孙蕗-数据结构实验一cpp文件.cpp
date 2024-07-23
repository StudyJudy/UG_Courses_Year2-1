#include <iostream>
using namespace std;
void Quick_Sort(int* arr, int begin, int end) {
	if (begin > end)
		return;
	int tmp = arr[begin];
	int i = begin;
	int j = end;
	while (i != j) {
		while (arr[j] >= tmp && j > i)
			j--;
		while (arr[i] <= tmp && j > i)
			i++;
		if (j > i) {
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	arr[begin] = arr[i];
	arr[i] = tmp;
	Quick_Sort(arr, begin, i - 1);
	Quick_Sort(arr, i + 1, end);
}

int main()
{
	int array[13] = { 12,61,5,30,12,4,12,60,61,30,12,5,61 };
	int odd = 0;
	int tmp1, tmp2, tmp;
	for (int i = 0; i <= 12; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	//确定奇数个数
	for (int i = 0; i < 13; i++)
	{
		if (array[i] % 2 != 0)
		{
			odd++;
		}
	}
	//奇偶分开
	for (int i = 0; i <= odd - 1; i++)
	{
		tmp1 = i;
		if (array[tmp1] % 2 == 0)
		{
			for (int j = 12; j >= odd - 1; j--)
			{
				tmp2 = j;
				if (array[tmp2] % 2 == 1)
				{
					tmp = array[tmp1];
					array[tmp1] = array[tmp2];
					array[tmp2] = tmp;
					break;
				}
			}
		}
	}
    //快速排序
	Quick_Sort(array, 0, odd-1);
	Quick_Sort(array, odd, 12);
	for (int i = 0; i <= 12; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}
