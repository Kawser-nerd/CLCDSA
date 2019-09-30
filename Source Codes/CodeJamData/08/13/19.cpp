#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string.h>
#include <math.h>




FILE *Fin = fopen("C-large.in","r");
//FILE *Fin = stdin;
ofstream Fou("c1.out");
//#define Fou cout

int n,m;
int n1[1000], n2[1000];

		int ans[100];
	int mod2[1000];

int get2(int n)
{
	if (n==0) return 1;
	if (n==1) return 4;
	int tmp = get2(n>>1);
	tmp *= tmp;
	if (n&1) tmp*=4;
	tmp %= 1000;
	return tmp;
}

int get(int n)
{
	if (n==1) return 6;
	if (n==0) return 2;
	if (n==2)
		 n = 2;
	int i,j;
	for (i=0; ((long long)1<<i)<=n; i++);
	i--;
	if ((1<<i)==n) return ans[i];
	int tmp = get(n-(1<<i)) * ans[i] - get2(n-(1<<i)) * get((1<<i) - (n-(1<<i)));
	tmp%=1000;
	if (tmp<0) tmp += 1000;
	return tmp;
}

int main()
{
	int i,j,k,caseN,t;
	fscanf(Fin,"%d",&caseN);

	mod2[0] = 4;
	for (i=1; i<=1000; i++)
		mod2[i] = mod2[i-1]*mod2[i-1] % 1000;
		
		ans[0] = 6;
		for (i=1; ((long long)1<<i)<=2000000000; i++)
		{
			ans[i] = ans[i-1]*ans[i-1] % 1000;
			ans[i] -= 2*mod2[i-1];
			ans[i]%=1000;
			if (ans[i]<0) ans[i]+=1000;
		}
	
	for (t=0; t<caseN; t++)
	{
		Fou<<"Case #"<<t+1<<": ";
		fscanf(Fin,"%d",&n);

		int all = get(n) % 1000;
		all--;
		if (all<0) all+= 1000;
		if (all>=100) Fou<<all<<endl;
		else if (all>=10) Fou<<'0'<<all<<endl;
		else Fou<<"00"<<all<<endl;
	}
	return 0;
}

