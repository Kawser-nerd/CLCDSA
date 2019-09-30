//#pragma GCC optimize(2)
#include<cstdio>
#define L 1<<23
#define C (c=*A++)
#define ENS //__attribute__((optimize("-O2")))
#define NES //__attribute__((optimize("-O2"))) __inline__ __attribute__((always_inline))
#define N 1000001

int MAPLE,n,l[N],r[N],cnt,last,wt,ss[19];char fl[L],*A=fl,s[N],t[N];bool fg=true;
NES void read(int&x){char c;for(x=0;'0'>C||c>'9';);while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,C;}NES void print(int x){if(!x)putchar(48);else{for(wt=0;x;ss[++wt]=x%10,x/=10);for(;wt;putchar(ss[wt--]+48));}}
ENS int main()
{int i,j;char c;
	for(fl[fread(fl,1,L,stdin)]=EOF,read(n);'a'>C||c>'z';);for(i=1;i<=n;s[i]=c,C,i++);while('a'>C||c>'z');for(i=1;i<=n;t[i]=c,C,i++);
	for(last=i=n,j=n+1;i;fg&=s[i]==t[i],i--)
		if(t[i]!=t[i-1])
		{if((--j)>i)j=i;
			for(;j&&s[j]!=t[i];j--);if(!j)return puts("-1"),0;
			l[++cnt]=j,r[cnt]=last,last=i-1;
		}if(fg)return puts("0"),0;for(l[0]=n+1,i=1;i<=cnt;i++)for(;l[i-MAPLE]<r[i]+MAPLE;MAPLE++);print(MAPLE);
} ./Main.cpp:10:51: warning: for loop has empty body [-Wempty-body]
NES void read(int&x){char c;for(x=0;'0'>C||c>'9';);while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,C;}NES void print(int x){if(!x)putchar(48);else{for(wt=0;x;ss[++wt]=x%10,x/=10);for(;wt;putchar(ss[wt--]+48));}}
                                                  ^
./Main.cpp:10:51: note: put the semicolon on a separate line to silence this warning
./Main.cpp:10:173: warning: for loop has empty body [-Wempty-body]
NES void read(int&x){char c;for(x=0;'0'>C||c>'9';);while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,C;}NES void print(int x){if(!x)putchar(48);else{for(wt=0;x;ss[++wt]=x%10,x/=10);for(;wt;putchar(ss[wt--]+48));}}
                                                                                                                                                                            ^
./Main.cpp:10:173: note: put the semicolon on a separate line to silence this warning
./Main.cpp:17:27: warning: for loop has empty body [-Wempty-body]
                ...