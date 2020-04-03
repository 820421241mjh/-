#pragma once
#include<ctime>
#include<iostream>
#include<cstdlib>
#include<fstream>
#define MAXSIZE 1000
ofstream fout;
typedef int KeyType;
typedef struct {
	KeyType key;
}LineList;
void OutList(LineList r[], int n)//显示函数
{
	int i;
	for (i =1; i <n; i++)
		cout <<r[i].key<<"," ;
	cout<<"\n";
}
void Random(LineList r[],int rangeL, int rangeR)//随机数函数
{
	srand((int)time(0));
	for (int i = 0; i < MAXSIZE; i++)
	{
		r[i].key = rand() % (rangeR - rangeL + 1) + rangeL;
	}
	
}
void Fout(LineList r[],int n)
{
	fout.open("outpu.txt");
	for (int i = 1;  i <n;  i++)
	{
		fout << r[i].key<<" ";
	}
	fout << "\n";
	fout << flush; fout.close();
}