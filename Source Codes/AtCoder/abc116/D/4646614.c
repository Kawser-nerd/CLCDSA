#include <stdio.h>
#include <stdlib.h>
#define ll long long int

typedef struct{
	ll t;
	ll d;
}data;

int compare(const void *a, const void *b){return (((data*)b)->d - ((data*)a)->d);}

int main(void){
	int n,k,i;
	scanf("%d %d",&n,&k);
	data neta[n];
	ll ans=0,sum=0;
	for(i=0;i<n;i++)scanf("%lld %lld",&neta[i].t,&neta[i].d);
	int used[100001]={0},sushiTypes=0,stack[100000],top=0;
	qsort(neta, n, sizeof(data), compare);
	
	for(i=0;i<k;i++){
		sum += neta[i].d;
		if(used[neta[i].t]){//????????????????????
			stack[top]=neta[i].d;
			top++;
		}else{
			used[neta[i].t] = 1;
			sushiTypes++;
		}
	}
	ans = sum+(ll)sushiTypes*sushiTypes;
	for(i=k;i<n && top>0;i++){//????????k???? and ???????
		if(used[neta[i].t])continue;//??????????????
		used[neta[i].t] = 1;
		top--;//???????d????????top??d????????????
		sum += neta[i].d -stack[top];
		sushiTypes++;
		ans = sum+(ll)sushiTypes*sushiTypes>ans?sum+(ll)sushiTypes*sushiTypes:ans;
	}
	
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&k);
  ^
./Main.c:17:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%lld %lld",&neta[i].t,&neta[i].d);
                  ^