#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a,const void *b){
	return *(long long*)a-*(long long*)b;
}

long long ru2(int n){
	int i;
	long long r=1;
	for(i=0;i<n;i++)r=r*2;
	return r;
}

struct num{
	long long a;
	int no;
};

int main(){
	int i,j,k,n,ans=0,c=0;
	long long a[200000],r2[41];
	for(i=0;i<=40;i++)r2[i]=ru2(i);
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	qsort(a,n,sizeof(long long),compare_int);
	struct num at[200000];
	at[0].a=a[0];
	at[0].no=1;
	for(i=1;i<n;i++){
		if(at[c].a!=a[i]){
			at[++c].a=a[i];
			at[c].no=1;
		}else at[c].no++;
	}
	//printf("%d\n\n",c);
	//for(i=0;i<n;i++)printf("%d",a[i]);
	//for(i=0;i<=c;i++)printf("%d\n",at[i].no);
	for(i=c;i>=0;i--){
		for(j=0;j<=40;j++){
			if(at[i].a<r2[j]&&r2[j]<=2*at[i].a){
				int lb=-1,ub=c;
				while(ub-lb>1){
					int mid=(ub+lb)/2;
					if(at[mid].a>=(r2[j]-at[i].a))ub=mid;
					else lb=mid;
				}
				if(at[i].a+at[ub].a==r2[j]){
					if((i!=ub&&at[i].no>0&&at[ub].no>0)){
						int tmp=(at[i].no<at[ub].no?at[i].no:at[ub].no);
						at[i].no-=tmp;
						at[ub].no-=tmp;
						ans+=tmp;
					}else if((i==ub&&at[i].no>1)){
						int tmp=at[i].no/2;
						at[i].no=at[i].no%2;
						ans+=tmp;
					}
				}
			}
		}
	}
	//for(i=0;i<=c;i++)printf("%d\n",at[i].no);
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:25:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%lld",&a[i]);
                  ^