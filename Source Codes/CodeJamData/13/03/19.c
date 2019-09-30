#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 105
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

bool isPalindrome(long long int n){
    char str[25];
    sprintf(str, "%lld", n);

    int i = 0, j = strlen(str) - 1;
    while (i < j){
        if (str[i] != str[j]) return false;
        i++, j--;
    }
    return true;
}

int main(){
    int t, line, n = 0;
    long long int a = 1, b = 1000000000000000ll, ar[1010];

    int i, counter = 0;

    for (i = 1; ;i++){
        long long int x = i;
        long long int y = (x * x);
        if (y > b) break;

        if (y >= a){
            if (isPalindrome(x) && isPalindrome(y)) ar[n++] = y;
        }
    }

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        counter = 0;
        scanf("%lld %lld", &a, &b);
        for (i = 0; i < n; i++){
            if (ar[i] >= a && ar[i] <= b) counter++;
        }

        printf("Case #%d: %d\n", line, counter);
    }

    return 0;
}
