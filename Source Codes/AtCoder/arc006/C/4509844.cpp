#include <cstdio>
const int maxn=100;
int main(){
	int i,j,trunk,count=0,N;
	int p[maxn]={0};
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&trunk);
		for(j=0;j<N;j++){
			if(trunk<=p[j]){
				p[j]=trunk;
				break;
			}
			if(p[j]==0){
				p[j]=trunk;
				count++;
				break;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}