#include <stdio.h>
#include <stdlib.h>

long long int arr[100];

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    long long int c, d ,v ,ans, count;
    scanf("%d", &test);
    for(int t = 1; t <= test; t++){
        scanf("%lld%lld%lld", &c, &d, &v);
        for(int i = 0; i < d; i++){
            scanf("%lld", &arr[i]);
            //printf("%lld ", arr[i]);
        }
        ans = 0; count = 1;
        for(int i = 0; i < d; i){
            if(count < arr[i]){
                ans++;
                count *= (c+1);
                //printf("a%lld ", count);
            }else{
                count += (arr[i++] * c);
                //printf("b%lld ", count);
            }
        }
        while(count <= v){
            ans++;
            count *= (c+1);
            //printf("c%lld ", count);
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
