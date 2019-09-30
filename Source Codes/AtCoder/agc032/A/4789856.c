#include <stdio.h>


void stack(int *b, int *a, int m){
    int i, j, flag;
    int new_b[100];

    if(m==1){
        if(b[0] == 1){
            a[0] = 1;
        }else{
            a[0] = -1;
        }
    }else{
        for(i=0;i<m;i++){
            if(b[i] > i+1){
                break;
            }
        }
        if(i != m){
            a[m-1] = -1;
        }else{
            flag = 0;
            for(i=0;i<m;i++){
                if(b[i] == i+1){
                    for(j=i+1;j<m;j++){
                        new_b[j-1] = b[j];
                    }
                    stack(new_b, a, m-1);
                    if(a[m-2] == -1){
                        new_b[i] = b[i];
                        continue;
                    }else{
                        a[m-1] = i+1;
                        flag = 1;
                        break;
                    }
                }else{
                    new_b[i] = b[i];
                }
            }
            if(flag == 0){
                a[m-1] = -1;
            }
        }
    }
}

int main(void)
{
    int n;
    int b[100];

    int i;
    int a[100];

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &b[i]);
    }

    stack(b, a, n);

    if(a[n-1] == -1){
        printf("%d", -1);
    }else{
        for(i=0;i<n;i++){
            printf("%d\n", a[i]);
        }
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:59:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &b[i]);
         ^