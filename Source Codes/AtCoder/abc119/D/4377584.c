#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int search(long long s[], int len, long long target)
{
    int upper, lower, middle;
    upper = len + 1;
    lower = 0;

    while (1) {
        middle = (upper + lower) / 2;
        if (s[middle] < target && target < s[middle + 1]) {break;}
        if (s[middle] < target) {lower = middle;} else {upper = middle;}
    }
    //    printf("%d %d %d, %lld %lld %lld\n", upper, lower, middle, s[middle], target, s[middle + 1]);

    return middle;
}

long long solve(int a, int b, long long s[], long long t[], long long x)
{
    int s_ptr, t_ptr;
    long long s_minus, s_plus;
    long long t_minus, t_plus;
    long long ans;
    long long distance;

    ans = LLONG_MAX;

    //search
    //for (s_ptr = 0; s[s_ptr] < x; s_ptr++) {/* NOP */}
    //for (t_ptr = 0; t[t_ptr] < x; t_ptr++) {/* NOP */}
    s_ptr = search(s, a, x) + 1;
    t_ptr = search(t, b, x) + 1;
    s_minus = s[s_ptr - 1];
    t_minus = t[t_ptr - 1];
    s_plus = s[s_ptr];
    t_plus = t[t_ptr];

    // ????
    distance = (s_minus < t_minus)?(x - s_minus):(x - t_minus);
    ans = (ans < distance)?(ans):(distance);

    // ????
    distance = (s_plus < t_plus)?(t_plus - x):(s_plus - x);
    ans = (ans < distance)?(ans):(distance);

    // ??????????
    if (s_minus < t_minus) {
        distance = (x - t_minus) + (s_plus - t_minus);
    } else {
        distance = (x - s_minus) + (t_plus - s_minus);
    }
    ans = (ans < distance)?(ans):(distance);

    // ??????
    if (s_plus < t_plus) {
        distance = (s_plus - x) + (s_plus - t_minus);
    } else {
        distance = (t_plus - x) + (t_plus - s_minus);
    }
    ans = (ans < distance)?(ans):(distance);

    return ans;
}

int main(int argc, char *argv[])
{
    int a, b, q;
    long long s[100002], t[100002], x[100000];
    int i;
    int ans;

    scanf("%d %d %d", &a, &b, &q);

    for (i = 1; i <= a; i++) { //shrine
        scanf("%lld", &s[i]);
    }
    s[0] = LLONG_MIN / 4;
    s[i] = LLONG_MAX / 4;
    
    for (i = 1; i <= b; i++) { //temple
        scanf("%lld", &t[i]);
    }
    t[0] = LLONG_MIN / 4;
    t[i] = LLONG_MAX / 4;

    for (i = 0; i < q; i++) { //start pos
        scanf("%lld", &x[i]);
    }

    for (i = 0; i < q; i++) {
        printf("%lld\n", solve(a, b, s, t, x[i]));
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:78:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &a, &b, &q);
     ^
./Main.c:81:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &s[i]);
         ^
./Main.c:87:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &t[i]);
         ^
./Main.c:93:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &x[i]);
         ^