#include<stdio.h>
#include<stdlib.h>

int main(){

    int T;
    scanf("%d",&T);
    int i;
    for(i = 0; i < T; i++){
        int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
    	if(N == 1 || N == 2 || M == 1 || M == 2 || K <= 4){
	    printf("Case #%d: %d\n",i+1,K);
	}
	else{
	    
 	    if(K < 8){
	        printf("Case #%d: %d\n",i+1,K-1);
	        continue;
	    }
	    else if(K == 8){
	        printf("Case #%d: %d\n",i+1,K-2);
	        continue;
	    }
	    int max = (M-2)*(N-2);
	    int ans = (K-8)/2+2;
	    if(ans < max){
	        ans = K-ans;
	    }
	    else{
	        ans = K-max;
	    }
	    printf("Case #%d: %d\n",i+1,ans);
	}
    }
    return 0;

}
