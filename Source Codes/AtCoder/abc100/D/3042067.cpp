#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[1001][4];
bool cmp(long long p,long long q) {
    return p > q;
}
int main() {
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for (i = 0;i < n;i ++) {
        for (j = 0;j < 3;j ++)
            cin>>a[i][j];
    }
    long long ans = -1;
    for (i = 0;i < 8;i ++) {
        long long f[100010];
        for (j = 0;j < n;j ++) {
            long long sum = 0;
            for (k = 0;k < 3;k ++) {
                if(i >> k & 1)sum += a[j][k];
                else sum -= a[j][k];
            }
            f[j] = sum;
        }
        sort(f,f + n,cmp);
        long long s = 0;
        for (j = 0;j < m;j ++)s += f[j];
        ans = max(s,ans);
    }
    cout<<ans;
    return 0;
}