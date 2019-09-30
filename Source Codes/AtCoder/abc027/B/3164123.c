#include <stdio.h>

int dist[105][105];
int need[105];
int a[105];
int N;

int search(int num){

	int i;

	int pos=0;
	int size=0;
	int sum=0;

	while(1){

		size=0;
		sum=0;
		for(i=pos;i<N-1;i++){
			size++;
			sum+=a[i];
			if(dist[i][i+1]==0){
				if(sum%size==0&&sum/size==num){
					pos=i+1;
					if(pos==N-1){
						if(a[N-1]!=num){return 0;}
					}
					break;
				}
				else{return 0;}//??

			}
			if(i==N-2){
			size++;
			sum+=a[N-1];
			pos=N-1;
			}

		}
		if(pos==N-1){
			if(sum%size==0&&sum/size==num){
			break;
			}
			else{
			return 0;
			}
		}
	}
	return 1;//?????
}

int main(){


	scanf("%d",&N);

	int i;

	int sum=0;

	for(i=0;i<N;i++){
		scanf(" %d",&a[i]);
		sum+=a[i];
	}

	if(sum%N!=0){
		printf("-1\n");
		return 0;
	}

	for(i=0;i<N-1;i++){
		dist[i][i+1]=1;
	}

	for(i=0;i<N-1;i++){
		dist[i][i+1]=0;
		int res=search(sum/N);
		if(res==0){dist[i][i+1]=1;}
	}

	int ans=0;
	for(i=0;i<N-1;i++){
	ans+=dist[i][i+1];
	}
	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:56:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&a[i]);
   ^