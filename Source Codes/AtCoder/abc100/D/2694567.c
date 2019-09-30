#include <stdio.h>
void sort(long long* data,int l,int r);
int pivot(long long* data,int i,int j);
int partition(long long* data,int i,int j,long long x);

int main(void){
	int N,M,i,j;
	scanf("%d %d",&N,&M);
	long long data[N][3],sum[N];
	for(i=0;i<N;i++){
		scanf("%lld %lld %lld",&data[i][0],&data[i][1],&data[i][2]);
	}
	long long ans=0;
	for(j=1;j<=8;j++){
		for(i=0;i<N;i++){
			sum[i]=0;
			if(j<=4)	sum[i]+=data[i][0];
			else		sum[i]-=data[i][0];
			if(j==1 ||j==2 ||j==5 ||j==6 )	sum[i]+=data[i][1];
			else		sum[i]-=data[i][1];
			if(j==1 ||j==3 ||j==5 ||j==7 )	sum[i]+=data[i][2];
			else		sum[i]-=data[i][2];
		}
		sort(sum,0,N-1);
		
		long long tmp=0;
		for(i=0;i<M;i++){
			tmp += sum[N-i-1];
		}
		if(tmp>ans) ans=tmp;
	}
	
	printf("%lld",ans);

	return 0;
}

int pivot(long long* data,int i,int j){
	int k = i+1;
	while(k <= j && data[i]==data[k]) k++;
	if(k>j)	return -1;
	if(data[i] >= data[k]) return i;
	return k;
}

int partition(long long* data,int i,int j,long long x){
	int l = i, r = j;
	while(l <= r){
		while( l <= j && data[l] < x) l++;
		while( r >= i && data[r] >= x) r--;
		if(l > r) break;
		long long t = data[l];
		data[l] = data[r];
		data[r] = t;
		l++;r--;
	}
	return l;
}

void sort(long long* data,int i,int j){
	if(i == j) return;
	int p = pivot(data,i,j);
	if(p != -1){
		int k = partition(data,i,j,data[p]);
		sort(data,i,k-1);
		sort(data,k,j);
	}
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&data[i][0],&data[i][1],&data[i][2]);
   ^