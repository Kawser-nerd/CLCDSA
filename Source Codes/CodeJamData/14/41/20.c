#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    int *A = (int*)a;
    int *B = (int*)b;
    return *B-*A;
}

int main(){
    int T,N;
    scanf("%d",&T);
    int i,j,k;
    int max;
    int files[10002] = {0};
    for(i = 0; i < T; i++){
        scanf("%d",&N);
	scanf("%d",&max);
	for(j = 0; j < N; j++)
	    scanf("%d",&files[j]);
	qsort(files, N, sizeof(int), compare);
 	int first = 0, last = N-1;
	int cnt = 0;
	int h = 0;
	while(first <= last){
	    if(first == last){
	        cnt++;
		break;
	    }
	        h += files[first];
	        if(h+files[last] <= max){
	            last--;
	        }
		cnt++;
		h = 0;
		first++;
	}
        printf("Case #%d: %d\n",i+1,cnt);
    }
    return 0;
}
