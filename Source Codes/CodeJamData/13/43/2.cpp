#include <cstdio>
using namespace std;
const int NMax=2000;
int N,A[NMax],B[NMax];
int smaller[NMax][NMax];
int degree[NMax],label[NMax],used[NMax];
void work(){
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",A+i);
	for (int i=0;i<N;i++)
		scanf("%d",B+i);
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			smaller[i][j]=0;
	for (int i=0;i<N;i++){
		int tlast=-1;
		for (int j=0;j<i;j++){
			if (A[j]+1>A[i])
				smaller[i][j]=1;
			if (A[j]+1==A[i])
				tlast=j;
		}
		if (tlast!=-1)
			smaller[tlast][i]=1;
	}
	for (int i=N-1;i>=0;i--){
		int tlast=-1;
		for (int j=N-1;j>i;j--){
			if (B[j]+1>B[i])
				smaller[i][j]=1;
			if (B[j]+1==B[i])
				tlast=j;
		}
		if (tlast!=-1)
			smaller[tlast][i]=1;
	}
	for (int i=0;i<N;i++)
		degree[i]=0;
	for (int i=0;i<N;i++)
		used[i]=0;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			if (smaller[i][j])
				degree[j]+=1;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (!used[j] && degree[j]==0){
				label[j]=i;
				for (int k=0;k<N;k++)
					if (smaller[j][k])
						degree[k]-=1;
				used[j]=1;
				break;
			}
		}
	}
	for (int i=0;i<N;i++)
		printf(" %d",label[i]+1);
	puts("");
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int Case=0;Case<T;Case++){
		printf("Case #%d:",Case+1);
		work();
	}
	return 0;
}

