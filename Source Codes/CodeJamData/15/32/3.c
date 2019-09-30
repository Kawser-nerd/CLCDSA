#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

char kStr[10];
char lStr[10];
char sStr[10];
int arr[10];

bool match(int start, int len){
    bool res = true;
    for(int i = 0; i < len; i++){
        if(lStr[i] != sStr[i + start]){
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test, k, l, s,ans, max;
    scanf("%d", &test);
    for(int t = 1; t <= test; t++){
        ans = 0;
        max = 0;
        int temp = 0;
        scanf("%d%d%d", &k, &l, &s);
        scanf("%s", kStr);
        scanf("%s", lStr);
        //printf("%s%s", kStr, lStr);
        int loop = 1;
        for(int i = 0; i < s; i++){
            loop *= k;
        }
        for(int i = 0; i < s; i++){
            arr[i] = 0;
            sStr[i] = kStr[0];
        }
        for(int i = 0; i < loop; i++){
            for(int j = (s - 1); j >= 0; j--){
                    arr[j] = (arr[j] + 1) % k;
                    sStr[j] = kStr[arr[j]];
                    if(arr[j]){
                        break;
                    }
            }
            temp = 0;
            for(int j = 0; j <= (s - l); j++){
                if(match(j, l)){
                    ans++;
                    temp++;
                }
            }
            if(max < temp){
                max = temp;
            }
        }
        double res = (double)(max);
        res -= (double)((double)(ans) / (double)(loop));
        printf("Case #%d: %f\n", t, res);
    }
    return 0;
}
