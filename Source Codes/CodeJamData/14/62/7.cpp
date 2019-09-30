#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
typedef double D;
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define R(i,n) for(int i=0;i<(n);i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define make(a) scanf("%d",&a)
template<typename A> void ma(A &a, A b){if(a<b)a=b;}
template<typename A> void mi(A &a, A b){if(a>b)a=b;}
int n,t[16],wyn,sil[10];
void licz(int nr,int il){
	//printf("%d %d\n  ",nr,il);
	//R(i,1<<n)printf("%d ",t[i]);
	//puts("");
	if(nr==n){
		R(i,1<<n)if(t[i]!=i)return;
		//printf("il %d\n",il);
		wyn+=sil[il];
		return;
	}
	int dl = 1<<nr;
	//printf("%d\n",dl);
	licz(nr+1,il);
	R(i,(1<<(n-nr)))R(j,(1<<(n-nr)))if(i<j){
		R(k,dl)swap(t[i*dl+k],t[j*dl+k]);
		//printf("%d ??\n",dl);
		licz(nr+1,il+1);
		R(k,dl)swap(t[i*dl+k],t[j*dl+k]);
	}
}
void test(){
	static int tes=0;tes++;
	printf("Case #%d: ",tes);
	make(n);wyn = 0;
	sil[0] = 1;
	F(i,1,n+2)sil[i] = sil[i-1] * i;
	R(i,1<<n){
		make(t[i]);t[i]--;
	}
	licz(0,0);
	printf("%d\n",wyn);//exit(0);
}
main(){
	int _;make(_);while(_--)test();
}