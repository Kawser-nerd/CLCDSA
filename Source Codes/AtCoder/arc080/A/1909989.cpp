#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main ()
{
	int n,a,b1=0,b2=0;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf ("%d",&a);
		if (a%2==1) b1++;
		if (a%4==0) b2++;
	}
	if ((b2>=b1)||(b2+1==b1 && b2+b1==n)) 
		printf ("Yes\n");
	else printf ("No\n");
	return 0;
}