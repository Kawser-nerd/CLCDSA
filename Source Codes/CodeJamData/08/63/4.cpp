#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <assert.h>
using namespace std;
typedef long long int llint;
#define N 30
#define EPS 1e-10
#define INF 1e10
#define LOW(x) ((((x)^((x)-1))&x))
#define Debug(x) cout<<#x<<"=\""<<x<<"\""<<endl;
#define Hline() do{cout<<"-------------------------------"<<endl;}while(0)
const int two[]={1,1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,
1<<11,1<<12,1<<13,1<<14,1<<15,1<<16,1<<17,1<<18,1<<19,1<<20,
1<<21,1<<22,1<<23,1<<24,1<<25,1<<26,1<<27,1<<28,1<<29,1<<30};
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
const char dname[]="NWSE";
//const char dname[]="URDL";
const double PI=acos(-1.0);
//*****************************************//
double Euclid_dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
template<class T>
string convert(vector<T> vv)
{
	ostringstream re;
	for(int i=0;i<vv.size();i++)
	{
		if(i)re<<" ";
		re<<vv[i];
	}
	return re.str();
}
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
template<class T>
vector<T> parse(const string& ss,const char* cut)
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}
#define M 10000
double value[M];
double ans[6][M];
int calAll(double p,int m)
{
	int top=0;
	value[top++]=0.0;
	value[top++]=1.0;
	for(int i=1;i<=32;i++)
	for(int j=1;j<i;j++)
	{
		if(__gcd(i,j)>1)continue;
		value[top++]=1.0*j/i;
	}
	sort(value,value+top);
	//cout<<"top="<<top<<endl;
	top--;
	for(int i=0;i<top;i++)
	{
		if(value[i]>=0.5)
			ans[1][i]=p;
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<top;j++)
		{
			double x=(value[j]+value[j+1])/2;
			double res=ans[i-1][j];
			for(int k=j;k>=0;k--)
			{
				double y=x-value[k];
				if(x+y>=1.0)res=max(res,p+(1.0-p)*ans[i-1][k]);
				else
				{
					int ind=(int)(lower_bound(value,value+top+1,x+y)-value);
					assert(ind<=top&&ans>0);
					res=max(res,(1.0-p)*ans[i-1][k]+p*ans[i-1][ind-1]);
				}
			}
			ans[i][j]=res;
			//if(x>2.0/3.0)cout<<x<<" "<<i<<" "<<res<<endl;
		}
	}
	return top+1;
}
const int mil=1000000;
int main()
{
	int ca=1,t;
	for(cin>>t;t--;)
	{
		int x,m;
		double p;
		cin>>m>>p>>x;
		printf("Case #%d: ",ca++);
		if((x<<m)<mil)
		{
			printf("%.7lf\n",0.0);
			continue;
		}
		if(x>=mil)
		{
			printf("%.7lf\n",1.0);
			continue;
		}
		const int top=calAll(p,m);
		double xx=1.0*x/mil;
		int ind=(int)(lower_bound(value,value+top,xx)-value);
		assert(ind);
		if(value[ind]>xx)ind--;
		printf("%.7lf\n",ans[m][ind]);
	}
	return 0;
}
