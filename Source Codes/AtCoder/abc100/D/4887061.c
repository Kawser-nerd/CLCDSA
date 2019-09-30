#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a,const void *b){
	long long t=*(long long*)a-*(long long*)b;
	if(t>0)return -1;
	if(t<0)return 1;
	return 0;
}

#define N 1000

int main(){
	int n,m,i;
	long long xyz[N][3],ans=0,kot[N],tmp=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%lld %lld %lld",&xyz[i][0],&xyz[i][1],&xyz[i][2]);
	
	for(i=0;i<n;i++)kot[i]=xyz[i][0]+xyz[i][1]+xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	for(i=0;i<n;i++)kot[i]=-xyz[i][0]+xyz[i][1]+xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	for(i=0;i<n;i++)kot[i]=xyz[i][0]-xyz[i][1]+xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	for(i=0;i<n;i++)kot[i]=-xyz[i][0]-xyz[i][1]+xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	for(i=0;i<n;i++)kot[i]=xyz[i][0]+xyz[i][1]-xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	for(i=0;i<n;i++)kot[i]=-xyz[i][0]+xyz[i][1]-xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	for(i=0;i<n;i++)kot[i]=xyz[i][0]-xyz[i][1]-xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	for(i=0;i<n;i++)kot[i]=-xyz[i][0]-xyz[i][1]-xyz[i][2];
	qsort(kot,n,sizeof(long long),compare_int);
	for(i=0;i<m;i++)tmp+=kot[i];
	if(ans<tmp)ans=tmp;tmp=0;
	
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:17:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%lld %lld %lld",&xyz[i][0],&xyz[i][1],&xyz[i][2]);
                  ^