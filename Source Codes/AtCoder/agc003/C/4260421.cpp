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
LL ans;
LL b[100005];
struct qwq
{
	int num;
	int val;
	bool flag;
}a[100005];

inline bool cmp(qwq x,qwq y)
{
	return x.val<y.val;
}
//qwq
int main()
{
	read(n);
	for(RI i=1;i<=n;++i)
		read(a[i].val),a[i].num=i;
	stable_sort(a+1,a+n+1,cmp);
	for(RI i=1;i<=n;++i)
	{
		int k=i;
		int kk=a[i].val;
//		while(k<=n)
//		{
//			if(a[i].num==k)
//			{
//				a[i].flag=1;	
//				break;
//			}
//			k+=2;
//		}
		int h=i%2;
		int hh=a[i].num%2;
		if(h==hh) a[i].flag=1;
		if(a[i].flag) continue;
//		k=i;
//		while(k>=1)
//		{
//			if(a[i].num==k)
//			{
//				a[i].flag=1;
//				break;
//			}
//			k-=2;
//		}
	}
	for(RI i=1;i<=n;++i)
	{
		if(a[i].flag) continue;
		ans++;
	}
	if(ans==0)
	{
		print(0);
		return 0;
	}
	print(ans/2);
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
./Main.cpp:57:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(RI i=1;i<=n;++i)
            ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
./Main.cpp:60:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(RI i=1;i<=n;++i)
            ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
./Main.cpp:88:6: warning: 'register' stor...