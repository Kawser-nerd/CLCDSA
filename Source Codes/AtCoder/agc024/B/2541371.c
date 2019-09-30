#include <stdio.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))

int main() {
    int n;
    int a[200001],ans[200001];
    
    //input
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    
    /*My originail code O(n^2)
    int max1 = 0;
    for (int k = 1; k <= n ; k++) {
        int count1 = 0;
        int l = 0;
        int mark1 = k;
        while (l <= n-1) {
            if(a[l] == mark1){
                count1++;
                mark1++;
            }
            l++;
        }
        max1 = max(max1, count1);
    }
    */
    
    
    //sophisticated O(n)
    int max2=0;
    for(int i=0;i<=n;i++) ans[i]=0;
    for(int i=0;i<n;i++){
            ans[a[i]] = ans[a[i]-1]+1;
        max2 = max(max2, ans[a[i]]);
    }
    
    //Output
    
    printf("\n%d\n",n - max2);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^