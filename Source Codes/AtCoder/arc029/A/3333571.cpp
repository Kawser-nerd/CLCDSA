#include <stdio.h>
int n, h, i, j, x;
int t[4];
int main() {
    // insert code here...
    scanf("%d",&n);
    scanf("%d",&t[0]);
    if(n >1)scanf("%d",&t[1]);
    if(n >2)scanf("%d",&t[2]);
    if(n == 4)scanf("%d",&t[3]);
    for(h = 0;h < n;h++){
        for(j = h;j > 0;j--){
            if(t[j] < t[j-1]){
                x = t[j];
                t[j] = t[j-1];
                t[j-1] = x;
            }
        }
    }
    if(n == 1 || n==2) printf("%d", t[n-1]);
    else if(n == 3){
        if(t[2] >=t[1]+t[0])
        printf("%d", t[2]);
        else printf("%d", t[1]+t[0]);
    }
    else{
        if(t[3] >= t[2]+t[1]+t[0]) printf("%d", t[3]);
        else if(t[3] > t[2]+t[1]){
            printf("%d",t[2]+t[1]+t[0]);
        }else if(t[3]+t[0] > t[2]+t[1]){
            printf("%d",t[3]+t[0]);
        }else{
            printf("%d",t[2]+t[1]);
        }
    }
    printf("\n");
    return 0;
}