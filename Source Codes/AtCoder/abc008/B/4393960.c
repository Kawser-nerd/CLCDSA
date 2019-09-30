#include <stdio.h>
#include <string.h>
int main(void){
    // Your code here!
    int n,i,j,m=-1;
    char a[100][100];
    int b[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
        b[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(strcmp(a[i],a[j])==0)
                b[i]++;
        }
    }
    for(i=0;i<n;i++){
        if(m<b[i]){
            m = b[i];
            j = i;
        }
    }
    printf("%s\n",a[j]);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",a[i]);
         ^