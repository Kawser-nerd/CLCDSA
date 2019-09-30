#include <iostream>
#include <cstring>
using namespace std;
char a[100009];
unsigned long long dp1[100009];
unsigned long long dp3[100009];
unsigned long long dp2[100009];
unsigned long long sum=0;
unsigned long long wenhao=1;
#define mood(x)  ((x)%1000000007) 
int main()
{
	ios::sync_with_stdio(false);
	cin>>(a+1);
	int len=strlen(a+1);
	
	for(int i=1;i<=len;i++)
	{	dp1[i]=dp1[i-1];
		dp2[i]=dp2[i-1];
		dp3[i]=dp3[i-1];
		if(a[i]=='A')
		{
			dp1[i]+=wenhao;
			dp1[i]=mood(dp1[i]);
		}
		else if(a[i]=='B')
		{
			dp2[i]=mood((mood(dp1[i-1])+mood(dp2[i])));
		}
		else if(a[i]=='C')
		{
			dp3[i]=mood((mood(dp2[i-1])+mood(dp3[i])));
		}
		else if(a[i]=='?')
		{   
		 
			
			dp1[i]=mood(dp1[i-1]*3+wenhao);
			dp2[i]=mood(dp2[i-1]*3+dp1[i-1]);
			dp3[i]=mood(dp3[i-1]*3+dp2[i-1]);
			wenhao*=3;
			wenhao=mood(wenhao);
		}
		
	}
	cout<<mood(dp3[len])<<endl;

	return 0;
}