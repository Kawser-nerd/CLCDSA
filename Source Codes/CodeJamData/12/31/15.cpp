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

//	char * inputName="A-large.in";
//	fin.open(inputName);
//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
	fin.open ( "NO1_input.txt");

	fout.open("output.txt");
	int n;
	fin >>n;
	//char zzzz[100];
	//fin.getline(zzzz,100);
	for (int i=0; i<n; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		work();
		fout<<endl;
	}


	fin.close();

	fout.close();



//	return a.exec();
}



void preWork()
{
	
}
const int MAX = 1100;
bool x[MAX][MAX];


void work()
{
	int n;
	fin>>n;
	int z[MAX][100];
	int t[MAX];
	int topo[MAX];
	fill(topo,topo+MAX,0);
	for (int i=0; i<n; i++)
	{
		fin>>t[i];
		for (int j=0; j<t[i]; j++)
		{
			fin>> z[i][j];
			z[i][j]--;
			topo[z[i][j]]++;
		}
	}

	memset(x,0,sizeof(x));
	int count =0;
	while (count<n)
	{
		int f;
		for (int i=0; i<n; i++)
		{
			f=i;
			if (topo[i]==0) break;
		}
		topo[f]--;
		x[f][f] = true;
		for (int i=0; i<t[f]; i++)
		{
			int d = z[f][i];
			topo[d]--;
			for (int j=0; j<n; j++)
			{
				if (!x[f][j]) continue;
				if ( x[d][j])
				{
					fout<<"Yes";
					return;
				}
				x[d][j]= true;
			}
		}
		count++;
	}
	fout<<"No";
}
const int MAX2 = 100;
int n;
int z[MAX2][100];
int t[MAX2];
int son[MAX2];
void check(int x)
{
	for (int i=0; i<t[x]; i++)
	{
		int f = z[x][i];
		son[f]++;
		check(f);
	}
}

void work1()
{
	fin>>n;
	for (int i=0; i<n; i++)
	{
		fin>>t[i];
		for (int j=0; j<t[i]; j++)
		{
			fin>> z[i][j];
			z[i][j]--;
		}
	}
	for (int i=0; i<n; i++)
	{
		fill(son,son+MAX2,0);
		check(i);
		for (int j=0; j<n; j++)
		{
			if (son[j]>1) 
			{
				fout<<"Yes";
				return;
			}
		}
	}
	fout<<"No";
}