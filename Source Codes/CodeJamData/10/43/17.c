#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doTestCase();

int main(){
	int i,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		printf("Case #%d: ",i);
		//fprintf(stderr,"Case #%d\n",i);
		doTestCase();
	}
	return 0;
}

// Defines and prototypes
#define MAXSIZE 100

// Functions
void doTestCase(){
	int n,k,i,j,t,r;
	int arr[MAXSIZE][MAXSIZE];
	for (i=0;i<MAXSIZE;i++) 
		for (j=0;j<MAXSIZE;j++) 
			arr[i][j]=0;
	
	scanf("%d",&n);
	int pos[n][4];
	int addpos[MAXSIZE*MAXSIZE][2];
	
	t=0;
	for (k=0;k<n;k++){
		scanf("%d %d %d %d",&pos[k][0],&pos[k][1],&pos[k][2],&pos[k][3]);
		//t+=(pos[k][2]-pos[k][0]+1)*(pos[k][3]-pos[k][1]+1);
		for (i=pos[k][0]-1;i<=pos[k][2]-1;i++){
			for (j=pos[k][1]-1;j<=pos[k][3]-1;j++){
				if (arr[i][j]==0){
					arr[i][j]=-1;
					t++;
				}
			}
		}
	}
	
	r=1;
	while (t>0){
		k=0;
		for (i=0;i<MAXSIZE;i++){
			for (j=0;j<MAXSIZE;j++){
				if (arr[i][j]==-1){
					if (((i==0) || ((arr[i-1][j]>=0) && (arr[i-1][j]<r))) && 
						((j==0) || ((arr[i][j-1]>=0) && (arr[i][j-1]<r)))){
						arr[i][j]=r;
						t--;
					}
				}
				else {
					if (((i!=0) && ((arr[i-1][j]==-1) || (arr[i-1][j]==r))) && 
						((j!=0) && ((arr[i][j-1]==-1) || (arr[i][j-1]==r)))){
						addpos[k][0]=i;
						addpos[k][1]=j;
						k++;
						t++;
					}
				}
			}
		}
		
		for (i=0;i<k;i++){
			arr[addpos[i][0]][addpos[i][1]]=-1;
		}
		r++;
	}	
	printf("%d\n",r-1);
}

		/*for (k=0;k<n;k++){
			if (arr[pos[k][0]][pos[k][1]]==1){
				if (((pos[k][0]==0) || (arr[pos[k][0]-1][pos[k][1]]==0)) && 
				    ((pos[k][1]==0) || (arr[pos[k][0]][pos[k][1]-1]==0))){
					arr[pos[k][0]][pos[k][1]]=2;
					tpos[r][0]=pos[k][0];
					tpos[r][1]=pos[k][1];
					r++;
				}
				else{
					i=0;
					while (arr[pos[k][0]+i][pos[k][1]==0) */
