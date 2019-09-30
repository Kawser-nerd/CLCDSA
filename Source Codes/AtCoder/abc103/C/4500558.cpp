#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 3010;
int a[maxn];
int main()
{
    int n; scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        sum += (t-1);
    }
    printf("%d\n", sum);
    return 0;
}