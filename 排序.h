#pragma once
#include<iostream>
using namespace std;
#include"�������.h"
void InsertSort(LineList r[], int n)//ֱ�Ӳ�������
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
void ShellSort(LineList r[], int n)//ϣ������
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
void BubbleSort(LineList r[],int n)//ð������
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
void QuickSort(LineList r[], int low, int high)//��������
{
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = r[low].key;
	while (true)
	{
		//���������ұ�key���ֵ
		while (r[++i].key < key)
		{
			if (i == high) {
				break;
			}
		}//���������ұ�keyС��ֵ
		while (r[--j].key > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		//����i,j��Ӧ��ֵ
		int temp = r[i].key;
		r[i].key = r[j].key;
		r[j].key = temp;
	}
	//����ֵ��j��Ӧֵ����
	int temp = r[low].key;
	r[low].key = r[j].key;
	r[j].key = temp;
	QuickSort(r, low, j - 1);
	QuickSort(r, j + 1, high);
}
void SelectSort(LineList r[],int n)//ѡ������
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
void Sift(LineList r[], int low, int high)//ɸѡ����
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
void Merge(LineList r[], int low, int mid, int high)//�ϲ�����
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
void MergePass(LineList r[], int length, int n)//һ�˺ϲ�
{
	int i;
	for (i = 1; i + 2 * length - 1 <= n; i = i + 2 * length)
		Merge(r, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 <= n)
		Merge(r, i, i + length - 1, n);
}
void MergeSort(LineList r[], int n)//�鲢����
{
	int length;
	for (length = 1; length <= n; length = 2 * length)
		MergePass(r, length, n);
}
void menu()//�˵�
{
	cout << "       ��ѡ����      " << endl;
	cout <<" -------����ϵͳ-------" << endl;
	cout <<"     1.��ȡ�������" << endl;
	cout <<"     2.ֱ�Ӳ�������"<<endl ;
	cout <<"     3.ϣ������" << endl;
	cout <<"     4.ð������"<<endl;
	cout <<"     5.��������" << endl;
	cout <<"     6.ֱ��ѡ������"<<endl;
	cout <<"     7.������" << endl;
	cout <<"     8.�鲢����" << endl;
	cout <<"     9.�������ܱȽ�" << endl;
	cout <<"	 0.�˳�ϵͳ" << endl;
}