#include<stdio.h>
#include<stdlib.h>
 
int sortfnc(const void *a,const void *b){
    if(*(unsigned long long int*)a == *(unsigned long long int*)b){return 0;}
    if(*(unsigned long long int*)a > *(unsigned long long int*)b){return -1;}
    return 1;
}
 
unsigned long long int nCr(unsigned long long int n,unsigned long long int r){
	unsigned long long int i,res = 1;
	for(i = 1;i <= r;i++){
		res*=(n-i+1);
		res/=i;
	}
	return res;
}
 
unsigned long long int ssearch(unsigned long long int x,unsigned long long int a[]){
	unsigned long long int i,r = 0;
	for(i = 0;i <= 63;i++){if(a[i] == x){r++;}}
	return r;
}
 
int main(void){
	unsigned long long int n,a,b,v[64]={0},i,f=0,r=0,sv,usv,nv,p,rvpc,rvpm,prr;
	scanf("%llu%llu%llu",&n,&a,&b);
	for(i = 0;i < n;i++){scanf("%llu",&v[i]);}
	qsort(v,n,sizeof(long long),sortfnc);
	i = 0;
	sv = 0;
	while(1){
		nv = v[i];
		sv+=v[i];
		if(i != 0 && v[i] == v[i-1]){usv++;}else{usv = 1;}
		if(i != 0 && v[i] != v[i-1]){f++;}
		i++;
		if(b < i){break;}
		if(a < i && f >= 1){break;}
		if(a <= i){
			if(a == i){rvpc = sv;rvpm = i;}
			p = nCr(ssearch(nv,v),usv);
			r+=p;
		}
	}
	prr = rvpc % rvpm;
	prr*=100000000000;
	prr/=rvpm;
	printf("%llu.%011llu\n%llu\n",rvpc/rvpm,prr,r);
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu%llu",&n,&a,&b);
  ^
./Main.c:28:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 0;i < n;i++){scanf("%llu",&v[i]);}
                       ^