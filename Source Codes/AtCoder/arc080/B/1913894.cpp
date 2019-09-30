#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int s[20000],p[150][150];

int main ()
{ 
	int h,w,n,o=1,q=0,a; 
	scanf ("%d%d%d",&h,&w,&n); 
	for (int i=1;i<=n;i++)
		scanf ("%d",&s[i]);
	for (int i=1;i<=h;i++) 
	{  
		for (int j=1;j<=w;j++)
		{
			if (i%2)
				p[i][j]=o;
			else
				p[i][w-j+1]=o;
			s[o]--;
			if (s[o]==0) o++;
		} 
	}
	for (int i=1;i<=h;i++)
	{
		for (int j=1;j<=w;j++)
			printf ("%d ",p[i][j]);
		printf ("\n");
	}
	return 0;
}