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

LL x,y;
LL tempa,tempb;
const LL inf=0x3f3f3f3f;
LL Ans1,Ans2,Ans3,Ans4;
LL Ans;

inline LL Min(LL a,LL b)
{
	if(a<b)
		return a;
	return b;
}

inline LL ans1()//y?x+a??
{
	LL c=tempb-tempa;
	if(c>0)
		return c;
	else 
		return inf;	
} 


inline LL ans2()//y?x-a??
{
	LL c=tempb-tempa;
	if(c<0)
	{
		LL hh=-c+2;
		return hh;
	}
	else
		return inf;
} 
	
inline LL ans3()//y?-x+a?? ???B??a?A 
{
	LL c=y+x;
	if(c>=0)	
	{
		LL hh=c+1;	
		return hh;
	}
	return inf;
}	
	
inline LL ans4()//y?-x-a?? ??a?A ??1?B 
{
	LL c=y+x;
	if(c<=0)
	{
		LL hh=-c+1;
		return hh; 
	}
	return inf; 
}	

	
int main()
{
	read(x);
	read(y);
	tempa=x;
	tempb=y;
	Ans1=ans1();
	Ans2=ans2();
	Ans3=ans3();
	Ans4=ans4();
	Ans=Min(Ans1,Ans2);
	Ans=Min(Ans,Ans3);
	Ans=Min(Ans,Ans4);
	printf("%lld",Ans);
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
2 warnings generated.