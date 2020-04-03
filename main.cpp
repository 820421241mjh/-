#include<iostream>
#include"排序.h"
#include<fstream>
using namespace std;
int main()
{   
	clock_t startTime[10],endTime[10];
	ofstream fout;
	int n;
	n = MAXSIZE;
	LineList r[MAXSIZE];
	char ch1, ch2;
	ch1 = 'y';
	while (ch1=='y'||ch1=='Y')
	{
		menu();
		cin >> ch2;
		switch (ch2)
		{
		case '1':
			Random(r,0, 1000);
			cout << "随机序列已生成" << endl;
			OutList(r, n);
			Fout(r, n);
			break;
		case'2':
			InsertSort(r, n);
			cout << "进行直接插入排序" << endl;
			cout << "排序后的记录为:" << endl;
			OutList(r, n);
			Fout(r, n);
			cout << "\n" << r[1].key;
			break;
		case'3':
			ShellSort(r, n);
			cout << "进行希尔排序" << endl;
			cout << "排序后的记录为:" << endl;
			OutList(r, n);
			Fout(r, n);
			break;
		case'4':
			BubbleSort(r, n);
			cout << "进行冒泡排序" << endl;
			cout << "排序后的记录为:" << endl;
			OutList(r, n);
			Fout(r, n);
			break;
		case'5':
			QuickSort(r,1,n);
			cout << "进行快速排序" << endl;
			cout << "排序后的记录为:" << endl;
			OutList(r, n);
			Fout(r, n);
			break;
		case'6':
			SelectSort(r, n);
			cout << "进行直接选择排序" << endl;
			cout << "排序后的记录为:" << endl;
			OutList(r, n);
			Fout(r, n);
			break;
		case'7':
			HeapSort(r, n);
			cout << "进行堆排序" << endl;
			cout << "排序后的记录为:" << endl;
			OutList(r, n);
			Fout(r, n);
			break;
		case'8':
			MergeSort(r, n);
			cout << "进行归并排序" << endl;
			cout << "排序后的记录为:" << endl;
			OutList(r, n);
			Fout(r, n);
			break;
		case'9':
			startTime[1] = clock();
			InsertSort(r, n);
			endTime[1] = clock();
			startTime[2] = clock();
			ShellSort(r, n);
			endTime[2] = clock();
			startTime[3] = clock();
			BubbleSort(r, n);
			endTime[3] = clock();
			startTime[4] = clock();
			QuickSort(r, 1, n);
			endTime[4] = clock();
			startTime[5] = clock();
			SelectSort(r, n);
			endTime[5] = clock();
			startTime[6] = clock();
			HeapSort(r, n);
			endTime[6] = clock();
			startTime[7] = clock();
			MergeSort(r, n);
			endTime[7] = clock();
			cout << "进行排序性能比较" << endl;
			cout << "直接插入排序用了："<<(float(endTime[1]-startTime[1])/CLOCKS_PER_SEC*1000)<<"ms\n";
			fout << "直接插入排序：" << (float(endTime[1] - startTime[1]) / CLOCKS_PER_SEC * 1000) << "ms\n";
			cout << "希尔排序用了：" <<(float(endTime[2] - startTime[2]) / CLOCKS_PER_SEC*1000) << "ms\n";
			cout<<"冒泡排序用了："<<(float(endTime[3] - startTime[3]) / CLOCKS_PER_SEC*1000) << "ms\n";
			cout<<"快速排序用了："<< (float(endTime[4] - startTime[4]) / CLOCKS_PER_SEC*1000) << "ms\n";
			cout << "选择排序用了：" <<(float(endTime[5] - startTime[5]) / CLOCKS_PER_SEC*1000) << "ms\n";
			cout << "堆排序用了：" << (float(endTime[6] - startTime[6]) / CLOCKS_PER_SEC*1000) << "ms\n";
			cout << "归并排序用了：" << (float(endTime[7] - startTime[7]) / CLOCKS_PER_SEC*1000) << "ms\n";
			break;
		case'0':
			ch1 = 'n';
			break;
		default:
			cout << "请输入正确的数字!" << endl;
		}
	}
}