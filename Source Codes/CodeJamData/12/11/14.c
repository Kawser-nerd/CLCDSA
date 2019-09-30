#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(void) {
    int num;
    int i;
    int j;
    int t;
    int pass_len;
    int typed_len;
    double best;
    double temp;
    double total_correct;
    double *local_correct;
    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%d %d", &typed_len, &pass_len);
        best = pass_len + 2; // when give-up (two enter-press)

        local_correct = (double *)malloc(sizeof(double)*(typed_len+1));
        local_correct[0] = 1.0; // Initial state : no miss
        for(j = 1; j <= typed_len; ++j) {
            scanf("%lf", local_correct+j);
            local_correct[j] *= local_correct[j-1];
        }
        total_correct = local_correct[typed_len];
        temp = total_correct * (pass_len - typed_len + 1)
            + (1.0 - total_correct) * (pass_len * 2 - typed_len + 2); // when just proceed typing
        if(best > temp) {
            best = temp;
        }
        for(j = 1; j <= typed_len; ++j) {
            t = (typed_len - j) * 2 + pass_len - typed_len + 1;
            temp = t * local_correct[j] // when all correct while j-th type
                + (t + pass_len + 1) * (1 - local_correct[j]);
            if(best > temp) {
                best = temp;
            }
        }

        printf("Case #%d: %lf\n", i, best);
        free(local_correct);
    }

    return 0;
}

