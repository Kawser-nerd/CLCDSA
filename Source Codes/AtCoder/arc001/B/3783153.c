#include <stdio.h>

int main(void)
{
    int i, j, k, N;
    char ans[100];
    int a[4] = {0,0,0,0};
    int tmp;
    
    
    scanf("%d",&N);
    scanf("%s",ans);
    
    for (i=0; i<N; i++){
        if (ans[i] == '1'){
            a[0]++;
        }
        else if (ans[i] == '2'){
            a[1]++;
        }
        else if (ans[i] == '3'){
            a[2]++;
        }
        else if (ans[i] == '4'){
            a[3]++;
        }
    }
    
    for (j=0; j<3; j++){
        for (k=j+1; k<4; k++){
            if (a[k] > a[j]){
                tmp = a[j];
                a[j] = a[k];
                a[k] = tmp;
            }
        }
    }
    printf("%d %d\n",a[0], a[3]);
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",ans);
     ^