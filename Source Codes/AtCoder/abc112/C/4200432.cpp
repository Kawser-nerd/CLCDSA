#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
struct coo{
	int x;
	int y;
	int h;
}c[110];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i].x;
		cin>>c[i].y;
		cin>>c[i].h;
	}
	int ch;
	int p=0;
	while(c[p].h==0) p++;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			int ch=c[p].h+abs(i-c[p].x)+abs(j-c[p].y);
			int f=0;
			for(int k=0;k<n;k++)
			{
				int hh=ch-abs(i-c[k].x)-abs(j-c[k].y);
				if(hh<0) hh=0;
				if(hh!=c[k].h)
				{
					f=1;
					break;
				}
			}
			if(!f)
			{
				cout<<i<<' '<<j<<' '<<ch<<endl; return 0;
			} 
		}
	}
}