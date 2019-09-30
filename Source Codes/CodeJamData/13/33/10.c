#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void exchange(int* arr,int p,int r){
	int temp = arr[p];
	arr[p] = arr[r];
	arr[r] = temp;
}
 
int partition(int* arr,int p,int r){
	int x = arr[r];
	int i=p-1;
	int j=0;
	for(j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			exchange(arr,i,j);
		}
	}
	exchange(arr,i+1,r);
	return i+1;
}
 
void quickSort(int* arr,int p,int r){
	int q =0;
	if(p<r){
		q = partition(arr,p,r);
		quickSort(arr,p,q-1);
		quickSort(arr,q+1,r);
	}
}

typedef struct{
	int d;
	int num;
	int w;
	int e;
	int s;
	int dd;
	int dp;
	int ds;
}tribe;

static tribe allTribes[10];
static int wall[2000];

void zeroWall(){
	int i =0;
	for(i=0;i<2000;i++){
		wall[i]=0;
	}
}

int findDay(int n){
	int i =0,j;
	int min = 100000000;
	int ans = 0;
	int k =0;
	for(i=0;i<n;i++){
		if(allTribes[i].d < min && allTribes[i].num >0){
			min = allTribes[i].d;
		}
	}
	ans  = 0;
	for(i=0;i<n;i++){
		if(allTribes[i].d == min && allTribes[i].num >0){
			for(j=allTribes[i].w*2;j<=allTribes[i].e*2;j++){
				if(wall[(j+500)] < allTribes[i].s){
					ans++;
					goto o;
				}
			}
			o:
				k=0;
				
		}
	}
	for(i=0;i<n;i++){
		if(allTribes[i].d == min && allTribes[i].num >0 ){
			for(j=allTribes[i].w*2;j<=allTribes[i].e*2;j++){
				if(wall[j+500] < allTribes[i].s){
					wall[j+500] = allTribes[i].s;
				}
			}
			allTribes[i].d += allTribes[i].dd;
			allTribes[i].e += allTribes[i].dp;
			allTribes[i].w += allTribes[i].dp;
			allTribes[i].s += allTribes[i].ds;
			allTribes[i].num--;
		}
	}
	return ans;
	
}

int allFinish(int n){
		int i =0,j;
	int min = -1;
	int ans = 0;
	for(i=0;i<n;i++){	
		if(allTribes[i].num >0){
			return 0;
		}
	}
	return 1;
}

int main(void) {
	FILE* inp = fopen("inp.txt","r");
	FILE* out = fopen("out.txt","w");

	int test = 0,i,caseCount;

	int ans = 0;
	int n;
	int d;
	int w,e,s;
	int dd,dp,ds;
	fscanf(inp,"%d",&test);
	for(caseCount =1;caseCount<=test;caseCount++){
		zeroWall();
		fscanf(inp,"%d",&n);
		ans = 0;
		for(i=0;i<n;i++){
			fscanf(inp,"%d %d %d %d %d %d %d %d",
			&(allTribes[i].d),&(allTribes[i].num),&(allTribes[i].w),&(allTribes[i].e),&(allTribes[i].s),
			&(allTribes[i].dd),&(allTribes[i].dp),&(allTribes[i].ds));
		}
		while(allFinish(n)== 0){
		
		ans += findDay(n);
		}
		print:
		fprintf(out,"Case #%d: %d\n",caseCount,ans);
	}
	
	return 0;
}
