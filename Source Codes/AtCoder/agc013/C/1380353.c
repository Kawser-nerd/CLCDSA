#include <stdio.h>
#define FOR(i,a,n) for(i=a;i<n;i++)

int binary_lower(int a[],int n,int k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(a[mid]<k) left=mid;
		else right=mid;
	}
	return right;
}
int binary_upper(int a[],int n,int k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(a[mid]<=k) left=mid;
		else right=mid;
	}
	return left;
}
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int pos[100000];
int x[100000],w[100000];
int main(void)
{
	int n,l,t,cnt=0,a,s,k,d,i;
	scanf("%d%d%d",&n,&l,&t);
	FOR(i,0,n){
		scanf("%d%d",&x[i],&w[i]);
		if(w[i]==1) pos[i]=(x[i]+t%l)%l;
		else pos[i]=(x[i]-t%l+l)%l;
	}
	a=pos[0];
	qsort(pos,n,sizeof(int),comp);
	if(w[0]==1){
		FOR(i,0,n){
			d=x[i]-x[0];
			if(w[i]==2&&d<2*t){
				cnt+=1+(2*t-d-1)/l;
				cnt%=n;
			}
		}
		k=cnt%n;
		s=binary_lower(pos,n,a);
	}
	else{
		FOR(i,0,n){
			d=l-x[i]+x[0];
			if(w[i]==1&&d<2*t){
				cnt+=1+(2*t-d-1)/l;
				cnt%=n;
			}
		}
		k=(n-cnt)%n;
		s=binary_upper(pos,n,a);
	}
	d=(s-k+n)%n;
	FOR(i,0,n) printf("%d\n",pos[(d+i)%n]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
  qsort(pos,n,sizeof(int),comp);
  ^
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&l,&t);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x[i],&w[i]);
   ^