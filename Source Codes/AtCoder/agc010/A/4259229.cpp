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
LL buk[5];

int main()
{
	read(n);
	for(RI i=1;i<=n;++i)
	{
		read(a[i]);
		if(a[i]%2==0)//a[i]???
		{
			buk[2]++;	
		} 
		else
			buk[1]++;
	}
	if(buk[2]%2==0 && buk[1]%2==0)//???????? ???????
	{
		printf("YES");
		return 0;
	} 
	if(buk[2]%2==0 && buk[1]%2==1)//???????? ???????
	{
		printf("NO");
		return 0;	
	} 
	if(buk[2]%2==1 && buk[1]%2==0)//???????? ???????
	{
		printf("YES");
		return 0;
	} 
	if(buk[2]%2==1 && buk[1]%2==1)//???????? ???????
	{
		printf("NO");
		return 0;	
	} 
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
./Main.cpp:46:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(RI i=1;i<=n;++i)
            ^
./Main.cpp:15:12: note: expanded from macro 'RI'
#define RI register int
           ^
3 warnings generated.