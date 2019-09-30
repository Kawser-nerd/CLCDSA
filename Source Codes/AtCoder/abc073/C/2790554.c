#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int sort(const void *a, const void *b){
    return *(int*)a-*(int*)b ;
}



int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    bool s[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        s[i]=true;
    }
    qsort (a,n,sizeof(int),sort);  
    
    int ans=0;
    for (int i=0; i<n; i++){
        if (a[i]==a[i+1] && s[i]==true){
            s[i]=false;
            s[i+1]=false;
        }
    }
    
    for (int i=0; i<n; i++){
        if (s[i]==true){
            ans++;
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^