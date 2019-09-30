#include <cstdio>
#include <cstring>
using namespace std;

int gs[1024];
int pass[1024] = {};
long long int cost[1024];
int now = 1;
int pos = 0;
int R, K, N;
long long go()
{
    long long int total = 0;
    while(now <= R)
    {
        if(pass[pos])
            break;

        cost[pos] = total;
        pass[pos] = now;

        int start = pos;
        long long int alc = 0;
        while(alc + gs[pos] <= K)
        {
            alc += gs[pos];
            pos = (pos + 1) % N;
            if(pos == start)
                break;
        }

        total += alc;
        now++;
    }

    return total;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
        scanf("%d%d%d", &R, &K, &N);
        for(int i = 0; i < N; i++)
            scanf("%d", gs + i);
    

        memset(pass, 0, sizeof(pass));
        memset(cost, 0, sizeof(cost));
        now = 1;
        pos = 0;
        long long ans = go();
       
        if(now > R)
            printf("%lld\n", ans);
        else
        {
            int d = now - pass[pos];   
            memset(pass, 0, sizeof(pass));

            //printf("%d %d %lld %lld\n", now, d, ans, cost[pos]);
            ans += (R - now + 1) / d * (ans - cost[pos]);

            now += (R - now + 1) / d * d;
            ans += go();
            printf("%lld\n", ans);
        }
    }
    return 0;
}
