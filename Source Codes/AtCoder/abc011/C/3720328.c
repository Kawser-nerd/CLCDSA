#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int NG[3];
    int num = 0;    //??
    int i;
    
    scanf("%d%*c", &N);
    for(i = 0; i < 3; i++){
        scanf("%d%*c", &NG[i]);
        if(NG[i] == N) N = -1;
    }
    while(num <= 100 && N > 0){
        if(N >= 3){
            //3????NG
            if(N - 3 == NG[0] || N - 3 == NG[1] || N - 3 == NG[2]){
                //2????NG
                if(N - 2 == NG[0] || N - 2 == NG[1] || N - 2 == NG[2]){
                    //1????NG
                    if(N - 1 == NG[0] || N - 1 == NG[1] || N - 1 == NG[2]){
                        N = -1;
                        break;
                    }else{
                        N--;
                        num++;
                    }
                }else{
                    N -= 2;
                    num++;
                }
            }else{
                N -= 3;
                num++;
            }
        }else if(N >= 2){
            N -= 2;
            num++;
        }else if(N >= 1){
            N--;
            num++;
        }else{
            break;
        }
    }
    if(N == 0 && num <= 100){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%*c", &N);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%*c", &NG[i]);
         ^