//#include "LongInt.h"
#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cassert>
#include <cmath>
#include <QString>
using namespace std;
ifstream fin; 
ofstream fout;

void preWork();
void work();
void work1();



int main(int argc, char *argv[])
{
	preWork();
	QCoreApplication a(argc, argv);

	//char * inputName="A-large.in";
	//fin.open(inputName);
	//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
	fin.open ( "NO3_input.txt");

	fout.open("output.txt");
	int n;
	fin >>n;
	for (int i=0; i<n; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		work();
		cout<<i+1<<endl;
		fout<<endl;
	}


	fin.close();

	fout.close();



	//	return a.exec();
}



void preWork()
{

}

void work()
{
	int n,m;
	__int64 num[2][200];
	int type[2][200];
	fin>>n>>m;
	for (int i=0; i<n; i++)
	{
		fin>>num[0][i]>>type[0][i];
	}
	for (int i=0; i<m; i++)
	{
		fin>>num[1][i]>>type[1][i];
	}

	__int64 dyn [200][200];
	memset(dyn,0,sizeof(dyn));
	dyn[0][0]=0;
	__int64 acc[2][200][200];
	memset(acc,0,sizeof(acc));

	for (int i=0; i<n; i++)
	{
		for (int t=1; t<=100; t++)
		{
			acc[0][t][i+1] = acc[0][t][i];
		}
		acc[0][type[0][i]][i+1]+= num[0][i];

	}
	for (int i=0; i<m; i++)
	{
		for (int t=1; t<=100; t++)
		{
			acc[1][t][i+1] = acc[1][t][i];
		}
		acc[1][type[1][i]][i+1]+= num[1][i];

	}
	for (int i1=0; i1<n; i1++)
	{
		for (int j1=0; j1<m; j1++)
		{
			for (int i2=i1+1; i2<=n; i2++)
			{
				for (int j2=j1+1; j2<=m; j2++)
				{
					if (type[0][i2-1] != type[1][j2-1] ) continue;
					int t = type[0][i2-1];
					__int64 z = dyn[i1][j1]+ min(  acc[0][t][i2]- acc[0][t][i1], acc[1][t][j2]- acc[1][t][j1]);
					if (z > dyn[i2][j2]) dyn[i2][j2] =z;
				}
			}
		}
	}
	__int64 result =0;
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=m; j++)
		{
			if (dyn[i][j]>result)
			{
				result= dyn[i][j];
			}
		}
	}
	fout<<result;
}


