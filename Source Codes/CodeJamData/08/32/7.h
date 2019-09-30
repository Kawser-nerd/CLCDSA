#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

typedef long long int64;
#define mysize(X) ((int)X.size())
#define myfor(i,c,d) for( int i=(c); i<=(d); ++i )
#define myforv(i,V) for( int i=0; i<mysize(V); ++i )

#define pause system("pause")

#define gettime _record_time=clock()
#define outtime printf("time used: %.3lf\n",(double)(clock()-_record_time)/CLOCKS_PER_SEC)
clock_t _record_time;

int toInt(string s) { istringstream sin(s); int t; sin>>t; return t;}
int64 toInt64(string s) { istringstream sin(s); int64 t; sin>>t; return t;}
string toString(int v ){ ostringstream sout; sout<<v; return sout.str();}
string toString(int64 v){ ostringstream sout; sout<<v; return sout.str();}

template<class T>void checkmin( T&a, const T&b ){if(b<a)a=b;}
template<class T>void checkmax( T&a, const T&b ){if(b>a)a=b;}

bool eoln( istream &fin = cin )
{ 	return fin.peek()=='\n' || fin.peek()==EOF;  	}

bool seekeof( istream &fin = cin )
{
	int t;  while( (t=fin.peek())!=EOF && t<=' ' ) fin.get();
	return t==EOF ;
}

bool seekeoln( istream &fin = cin )
{
	int t;  while( (t=fin.peek())!=EOF && t!='\n' && t<=' ' ) fin.get();
	return t==EOF || t=='\n' ;
}

//#include "E:\codes\标准模块\计算几何\Computational Geometry.h"

