#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll a[100010];
int main(){
	int n,l;
	scanf("%d%d",&n,&l);
	rep(i,0,n)scanf("%d",a+i);
	int index=0;
	rep(i,1,n)if(a[i-1]+a[i]>=l)index=i;
	if(index){
		puts("Possible");
		rep(i,1,index)printf("%d\n",i);
		for(int i=n-1;i>index;i--)printf("%d\n",i);
		printf("%d\n",index);
	}else{
		puts("Impossible");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:18: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  rep(i,0,n)scanf("%d",a+i);
                  ^
./Main.c:15:24: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   rep(i,1,index)printf("%d\n",i);
                        ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&l);
  ^
./Main.c:10:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%d",a+i);
            ^