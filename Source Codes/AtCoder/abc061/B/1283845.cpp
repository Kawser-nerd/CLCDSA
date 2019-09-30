#include<iostream>
using namespace std;
int main()
{
	int a[51];
	int b[51];
	int c[51]={};
	int n,m,x,y,i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	cin>>a[i]>>b[i];
		
		
		for(i=0;i<m;i++)	
	{
     		x=a[i];
     		c[x-1]++;
     		y=b[i];
     		c[y-1]++;
     		}
     		for(i=0;i<n;i++)
     		cout<<c[i]<<'\n';
     		
     		return 0;
     		}