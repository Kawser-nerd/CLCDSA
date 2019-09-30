#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, x, num_kouryo = 0;
    int *just_candies, *kouryo, *just_candies_kouryo;
    int loop, loop_kouryo = 0;

    scanf("%d %d", &N, &x);
    //printf("N = %d, x = %d\n", N, x);
    just_candies = (int *)malloc(N * sizeof(int));
    kouryo = (int *)malloc(N * sizeof(int));

    for(loop = 0; loop < N; loop++){
        scanf("%d", &just_candies[loop]);
        if(just_candies[loop] <= x){
            kouryo[loop] = 1;
            num_kouryo++;
        }else{
            kouryo[loop] = 0;
        }
    }
    //printf("num_kouryo = %d\n", num_kouryo);

    just_candies_kouryo = (int *)malloc(num_kouryo * sizeof(int));

    for(loop = 0; loop < N; loop++){
        if(loop_kouryo == num_kouryo){
            break;
        }else{
            if(kouryo[loop]){
                just_candies_kouryo[loop_kouryo] = just_candies[loop];
                loop_kouryo++;
            }
        }
    }

    /*for(loop = 0; loop < num_kouryo; loop++){
        if(loop == 0) printf("just_candies_kouryo: ");
        printf("%d%c", just_candies_kouryo[loop], (loop == num_kouryo-1)? '\n' : ' ');
    }*/

    int tmp, flag_swap = 1;
    int ans = 0;

    if(num_kouryo > 0){
        while(flag_swap == 1){
            flag_swap = 0;
            for(loop = 0; loop < num_kouryo-1; loop++){
                    if(just_candies_kouryo[loop] > just_candies_kouryo[loop+1]){
                        tmp = just_candies_kouryo[loop];
                        just_candies_kouryo[loop] = just_candies_kouryo[loop+1];
                        just_candies_kouryo[loop+1] = tmp;
                        flag_swap = 1;
                }
            }
        }

        /*for(loop = 0; loop < num_kouryo; loop++){
            if(loop == 0){
                printf("just_candies_kouryo swapped: ");
            }
            printf("%d%c", just_candies_kouryo[loop], (loop == num_kouryo-1)? '\n' : ' ');
        }*/

        for(loop = 0; loop < num_kouryo; loop++){
            if(x < just_candies_kouryo[loop]){
                //printf("loop = %d: x = %d < %d = just_candies_kouryo[%d]\n", loop, x, just_candies_kouryo[loop], loop);
                break;
            }else{
                //printf("loop = %d: current x = ", loop);
                x -= just_candies_kouryo[loop];
                ans++;
            }
            //printf("%d, ans = %d\n", x, ans);
        }
        printf("%d\n", (loop == num_kouryo && x > 0)? ans-1 : ans);
    }else{
        printf("0\n");
    }

    free(just_candies);
    free(kouryo);
    free(just_candies_kouryo);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &x);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &just_candies[loop]);
         ^