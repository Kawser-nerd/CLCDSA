#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int map[1000000];

int main(void) {
    for(int i=0; i<105000; i++)
        map[i] = 0xFFFF;

    for(long long int i=1; i<100000; i++)
        for(long long int j=i; i*j<=100000; j++)
            if(i*j<=100000) map[i*j] = min(map[i*j], (int)abs(j-i));

    int n;
    scanf("%d",&n);
    int ans=0xFFFF;
    for(int r=0; r<=n; r++)
        ans = min(ans, r+map[n-r]);

    printf("%d\n",ans);

    return 0;
}