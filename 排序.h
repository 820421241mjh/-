#pragma once
#include<iostream>
using namespace std;
#include"随机序列.h"
void InsertSort(LineList r[], int n)//直接插入排序
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];
		j = i - 1;
		while (r[0].key < r[j].key)
		{
			r[j + 1] = r[j];
			j = j - 1;
		}
		r[j + 1] = r[0];
	}
}
void ShellSort(LineList r[], int n)//希尔排序
{
	int i, j, d;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i <= n; i++)
		{
			r[0] = r[i];
			j = i - d;
			while (j >= 0 && r[0].key < r[j].key)
			{
				r[j + d] = r[j];
				j = j - d;
			}
			r[j + d] = r[0];
			j = j - d;
		}
		d = d / 2;
	}
}
void BubbleSort(LineList r[],int n)//冒泡排序
{
	int i, j, exchange;
	LineList temp;
	for (i = 1; i < n; i++)
	{
		exchange = 0;
		for (j = 1; j <= n - 1; j++)
			if (r[j].key > r[j+1].key)
			{
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				exchange = 1;
			}
		if (exchange == 0)return;
	}
}
void QuickSort(LineList r[], int low, int high)//快速排序
{
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = r[low].key;
	while (true)
	{
		//从左向右找比key大的值
		while (r[++i].key < key)
		{
			if (i == high) {
				break;
			}
		}//从右向左找比key小的值
		while (r[--j].key > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		//交换i,j对应的值
		int temp = r[i].key;
		r[i].key = r[j].key;
		r[j].key = temp;
	}
	//中枢值与j对应值交换
	int temp = r[low].key;
	r[low].key = r[j].key;
	r[j].key = temp;
	QuickSort(r, low, j - 1);
	QuickSort(r, j + 1, high);
}
void SelectSort(LineList r[],int n)//选择排序
{
	int i, j, k;
	LineList x;
	for (i = 1; i <= n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; ++j)
			if (r[j].key < r[k].key)
				k = j;
		if (k != i)
		{
			x = r[i]; 
			r[i] = r[k];
			r[k] = x;
		}
	}
}
void Sift(LineList r[], int low, int high)//筛选函数
{
	int i = low, j = 2*i;
	LineList tmp=r[i];
	while (j<=high)
	{
		if (j < high && r[j].key < r[j + 1].key)
			j=j + 1;
		if (tmp.key < r[j].key)
		{
			r[i] = r[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	r[i] = tmp;
}
void  HeapSort(LineList r[], int n)
{
	int	i;
	LineList tmp;
	for (i = n / 2; i >= 1; i--)
		Sift(r, i, n);
	for (i = n; i >= 1; i--)
	{
		tmp = r[1];
		r[1] = r[i];
		r[i] = tmp;
		Sift(r, i, i - 1);
	}
}
void Merge(LineList r[], int low, int mid, int high)//合并函数
{
	LineList *r1;
	int i = low, j = mid + 1, k = 1;
	r1 = (LineList *)malloc((high - low + 1) * sizeof(LineList));
	while (i < mid && j <= high)
		if (r[i].key <= r[j].key)
			r1[k++] = r[i++];
		else
		{
			r1[k++] = r[j++];
		}
	while(i <= mid)
		r1[k++] = r[i++];
	while (j <= high)
		r1[k++] = r[j++];
	for (k = 1, i = low; i <= high; k++, i++)
		r[i] = r1[k];
}
void MergePass(LineList r[], int length, int n)//一趟合并
{
	int i;
	for (i = 1; i + 2 * length - 1 <= n; i = i + 2 * length)
		Merge(r, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 <= n)
		Merge(r, i, i + length - 1, n);
}
void MergeSort(LineList r[], int n)//归并排序
{
	int length;
	for (length = 1; length <= n; length = 2 * length)
		MergePass(r, length, n);
}
void menu()//菜单
{
	cout << "       请选择功能      " << endl;
	cout <<" -------排序系统-------" << endl;
	cout <<"     1.获取随机数列" << endl;
	cout <<"     2.直接插入排序"<<endl ;
	cout <<"     3.希尔排序" << endl;
	cout <<"     4.冒泡排序"<<endl;
	cout <<"     5.快速排序" << endl;
	cout <<"     6.直接选择排序"<<endl;
	cout <<"     7.堆排序" << endl;
	cout <<"     8.归并排序" << endl;
	cout <<"     9.排序性能比较" << endl;
	cout <<"	 0.退出系统" << endl;
}