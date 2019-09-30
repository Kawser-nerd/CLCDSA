#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define Rg register
#define RI register int
#define RC register char
#define ed puts("") 
#define pair pair<LL,LL>
#define space putchar(' ')
using namespace std;
    
template <typename tp> inline void read(tp & x)
{	
    x=0;
    RI f=1;
    RC c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar(); }
    while(c>='0' && c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();} 
 	x*=f;
} 	
    
template <typename Tp> inline void print(Tp x)
{		
    if(x<0) x=-x,putchar('-');
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int n;
LL a[1000005];
int k;
int ans;
bool flag1,flag2;
int flag=-1;

int main()
{
	read(n);
	for(RI i=1;i<=n;++i)
		read(a[i]);

	for(RI i=1;i<=n;++i)
	{
		if(flag==-1 && !flag1 && !flag2)
		{
			++ans;
			flag=a[i];
			continue;
		}
		if(flag!=-1 && !flag1 && !flag2)
		{
			if(flag==a[i]) 
				continue;
			if(flag>a[i]) 
				flag1=1;//??? 
			else if(flag<a[i]) 
				flag2=1;//??? 
			flag=a[i];
		}
		else if(flag1)//???
		{
			if(a[i]<=flag) 
				flag=a[i];
			else 
			{
				flag=-1;
				flag1=0;
				--i;
			}
		}
		else if(flag2)//???
		{
			if(a[i]>=flag) 
				flag=a[i];
			else 
			{
				flag=-1;
				flag2=0;
				--i;
			}
		} 
	}
	print(ans);	
	return 0;
} ./Main.cpp:25:5: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
    RI f=1;
    ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
./Main.cpp:26:5: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
    RC c=getchar();
    ^
./Main.cpp:16:12: note: expanded from macro 'RC'
#define RC register char
           ^
./Main.cpp:49:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(RI i=1;i<=n;++i)
            ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
./Main.cpp:52:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(RI i=1;i<=n;++i)
            ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
4 warnings generated.