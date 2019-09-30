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

int n,c,k;
int temp;
LL ans;
LL t[1000005];
int s[1000005];
bool vis[1000005];
bool flag=1;
LL kk;

int main()
{
	read(n),read(c),read(k);
	for(RI i=1;i<=n;++i)
		read(t[i]);
	stable_sort(t+1,t+n+1);
	for(RI i=1;i<=n;++i)
	{
//		int kk=t[i]+k;
//		ans++;
//		temp=c-1;
//		int flag=i;
//		for(RI j=flag+1;j<=n;++j)
//		{
//			if(t[j]<=kk && t[j]+k>=kk)
//			{
//				temp--;
//				if(temp==0)
//					break;	
//			}	
//		}	
//		int hh=c-temp;//??????
//		i+=hh-1;
		if(flag)
        {
            ++ans,++temp;
            kk=t[i]+k;
            flag=0;
        }
        else if(t[i]<=kk) 
			++temp;
        else if(t[i]>kk)
        {
            flag=true;
			temp=0;
            --i;
        }
        if(temp==c) 
        {
            flag=true;
			temp=0;
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
./Main.cpp:51:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(RI i=1;i<=n;++i)
            ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
./Main.cpp:54:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(RI i=1;i<=n;++i)
            ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
4 warnings generated.