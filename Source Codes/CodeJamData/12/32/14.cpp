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
#include <ctime>

using namespace std;
ifstream fin; 
ofstream fout;

//  越界 问题  浮点 除 变 整除，  abs 问题


void preWork();
void work();
void work1();
int sorttime;
int main(int argc, char *argv[])
{
	//preWork();
	QCoreApplication a(argc, argv);

	//	char * inputName="A-large.in";
	//	fin.open(inputName);
	//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
	fin.open ( "NO2_input.txt");

	int now =clock();
	sorttime=0;
	fout.open("output.txt");
	int n;
	fin >>n;
	for (int i=0; i<n; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		work();
		fout<<endl;
	}


	fin.close();

	fout.close();
	int now2= clock();
	
	cout<<now<<endl<<now2<<endl<< now2-now<<endl;
	cout<<sorttime<<endl;

	//	return a.exec();
}


void preWork()
{


}

void work()
{
	long double D;
	int N , A;

	long double t[3000], x[3000], a[3000];
	fin>> D>> N>>A;
	for (int i=0; i<N; i++)
	{
		fin >>t[i]>>x[i];
	}
	while ( x[N-1]>=D && N>1 )
	{
		N--;
	}
	if ( x[N-1] <D )
	{
		long double p,nt;
		p = (D-x[N-1])/ (x[N]- x[N-1]);
		nt = p * (t[N]-t[N-1])+ t[N-1];
		t[N] = nt;
		x[N] =D;
		N++;
	}
	for (int i=0; i<A; i++)
	{
		fin>> a[i];
	}
	for (int i=0; i<A; i++)
	{
		long double start =0;
		for (int j=N-1; j>=0; j--)
		{
			if (start>=t[j]) break;
			long double tt = t[j]-start;
			long double travel = 0.5*a[i]*tt*tt;
			if (travel<=x[j])  continue;
			start =  t[j] - sqrt(x[j]*2/a[i]);
		}
		fout<<endl<<setprecision(15)<<sqrt(D*2/a[i]) +start;
	}
}

