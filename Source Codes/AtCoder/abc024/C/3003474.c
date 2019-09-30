#include <stdio.h>

int main(void){
    int n,d,k;
    scanf("%d%d%d",&n,&d,&k);
    int l[10005],r[10005];
    int s[105],t[105];
    for(int i=0; i<d; i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    int temp;
    for(int i=0; i<k; i++){
        scanf("%d%d",&s[i],&t[i]);
    }
    int count;
    for(int i=0; i<k; i++){
        count=0;
        for(int j=0; j<d; j++){
            count++;
            if(s[i]<t[i]){
                if(l[j]<=s[i] && s[i]<r[j]){
                    s[i]=r[j];
                    if(s[i]>=t[i]){
                        printf("%d\n",count);
                        break;
                    }
                }
            }
            if(t[i]<s[i]){
                if(s[i]<=r[j] && l[j]<s[i]){
                    s[i]=l[j];
                    if(t[i]>=s[i]){
                        printf("%d\n",count);
                        break;
                    }
                }
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&d,&k);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&l[i],&r[i]);
         ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&s[i],&t[i]);
         ^