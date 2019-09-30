#include <stdio.h>

#define LEN (100001)

void get_diff(int *diff_ab)
{
    int index = 1;
    while(1){
        const char ch = getchar();
        if(ch == 'A') {
            diff_ab[index] = diff_ab[index-1] + 1;
            index++;
        } else if (ch == 'B') {
            diff_ab[index] = diff_ab[index-1] - 1;;
            index++;
        } else {
            break;
        }
    }
}

int main(void)
{
    static int diff_ab_S[LEN] = {0};
    static int diff_ab_T[LEN] = {0};

    get_diff(diff_ab_S);
    get_diff(diff_ab_T);

    int q;
    scanf("%d",&q);

    for (int i = 0; i < q; i++){
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        const int diff_diff_ab_S = diff_ab_S[b] - diff_ab_S[a - 1];
        const int diff_diff_ab_T = diff_ab_T[d] - diff_ab_T[c - 1];
        if((diff_diff_ab_S - diff_diff_ab_T) % 3 == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&q);
     ^
./Main.c:35:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d %d", &a, &b, &c, &d);
         ^