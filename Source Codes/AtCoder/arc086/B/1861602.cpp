#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline long long	read()//?????????? 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
#include<map>
#include<cmath>
const long long N=100005,oo=1e18;
long long a[N],b[N],c[N],tot,n,mmax,mmin,pos;
int main(){
	n=read();
    for(long long i=1;i<=n;i++){
    	c[i]=b[i]=a[i]=read();
	}
	a[0]=b[0]=-oo; tot=0;
	for(long long i=1;i<=n&&tot<=2*n;){
		mmax=-oo; if(b[i]>=b[i-1]){i++; continue;}
		for(long long j=1;j<=n;j++){
			if(b[j]>mmax){
				mmax=b[j]; pos=j;
			}
		}
		b[i]+=mmax; if(b[i]>=b[i-1])i++; tot++;
	}
	if(tot<=2*n){
		cout<<tot<<endl;
		for(long long i=1;i<=n;){if(a[i]>=a[i-1]){i++; continue;} mmax=-oo;
		for(long long j=1;j<=n;j++){
			if(a[j]>mmax){
				mmax=a[j]; pos=j;
			}
		}
		cout<<pos<<" "<<i<<endl;
		a[i]+=mmax; if(a[i]>=a[i-1])i++;}
		return 0;
	}
	tot=0;
	a[n+1]=c[n+1]=oo;
	for(long long i=n;i;){
		mmin=oo; if(c[i]<=c[i+1]){i--; continue;}
		for(long long j=1;j<=n;j++){
			if(c[j]<mmin){
				mmin=c[j]; pos=j;
			}
		}
		c[i]+=mmin; if(c[i]<=c[i+1])i--;tot++;
	}
	cout<<tot<<endl;
	for(long long i=n;i;tot++){
		mmin=oo; if(a[i]<=a[i+1]){i--; continue;}
		for(long long j=1;j<=n;j++){
			if(a[j]<mmin){
				mmin=a[j]; pos=j;
			}
		}
		cout<<pos<<" "<<i<<endl;
		a[i]+=mmin; if(a[i]<=a[i+1])i--;
	}
}