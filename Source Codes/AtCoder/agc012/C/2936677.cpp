#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n;
struct node{
	int lst,nxt,c;
}a[233];
int len,h1,t1,h2,t2,nw,er[40],l;
void addh1(){
	a[++len].c=nw;
	a[len].nxt=h1;
	a[h1].lst=len;
	h1=len;
}
void addh2(){
	a[++len].c=nw;
	a[len].nxt=h2;
	a[h2].lst=len;
	h2=len;
}
void addt2(){
	a[++len].c=nw;
	a[len].lst=t2;
	a[t2].nxt=len;
	t2=len;
}
int main(){
	scanf("%lld",&n);
	++n;
	h1=t1=1;h2=t2=2;
	a[1].c=1;a[2].c=1;
	nw=1;len=2;
	for(;n;n/=2)
		er[++l]=n&1ll;
	if(er[l-1]){
		++nw;
		addh1();
		addt2();
	}
	for(l=l-2;l;--l){
		++nw;
		addh1();
		addh2();
		if(er[l]){
			++nw;
			addh1();
			addt2();
		}
	}
	printf("%d\n",len);
	for(int i=h1;i;i=a[i].nxt)
		printf("%d ",a[i].c);
	for(int i=h2;i;i=a[i].nxt)
		printf("%d ",a[i].c);
	return 0;
}