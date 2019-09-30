#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define INF 0x3f3f3f3f
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FOR(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e4+5;

int main(){
	int A,B,C,D,E,F;
	scanf("%d%d%d%d%d%d",&A,&B,&C,&D,&E,&F);
	double lim=E/100.0,ans=-1;
	int x=0,y=0;
	//暴力枚举,注意糖水浓度为0的情况 
	for(int i=0;i*A*100<=F;i++){
		for(int j=0;i*A*100+j*B*100<=F;j++){
			for(int k=0;k*C<=1.0*F/100*E;k++){
				for(int p=0;k*C+p*D<=1.0*F/100*E;p++){
					if(i==0&&j==0&&k==0&&p==0)
						continue;
					if(i*A*100+j*B*100+k*C+p*D>F||i==0&&j==0)
						continue;
					double rate=(k*C+p*D)/(1.0*i*A*100+j*B*100);
					if(rate<=lim&&ans<rate){
						ans=rate;
						x=i*A*100+j*B*100;
						y=k*C+p*D;
					}
						
				}
			}
		}
	}
	printf("%d %d\n",x+y,y);
	return 0;
} ./Main.cpp:38:40: warning: '&&' within '||' [-Wlogical-op-parentheses]
                                        if(i*A*100+j*B*100+k*C+p*D>F||i==0&&j==0)
                                                                    ~~~~~~^~~~~~
./Main.cpp:38:40: note: place parentheses around the '&&' expression to silence this warning
                                        if(i*A*100+j*B*100+k*C+p*D>F||i==0&&j==0)
                                                                          ^
                                                                      (         )
1 warning generated.