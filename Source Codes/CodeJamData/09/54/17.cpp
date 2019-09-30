#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1000000007;

long long pow10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
vector<long long> palin;
long long rev(long long foo)
{
    long long ans=0;
    while(foo)
    {
        ans = 10*ans + (foo%10);
        foo/=10;
    }
    return ans;
}
int main()
{
    palin.push_back(0);
    
    for(int d=1;d<=13;d++)
    {
        if(d%2==0)
        {
            for(int i=pow10[d/2-1];i<pow10[d/2];i++)
                palin.push_back(pow10[d/2]*i+rev(i));
        }
        else
        {
            for(int i=pow10[d/2];i<pow10[d/2+1];i++)
                palin.push_back(pow10[d/2]*i+rev(i/10));
        }
    }
//    cout << palin[palin.size()-2] << endl;
//    cout << palin[palin.size()-1] << endl;
    palin.push_back(10000000000001);
//    cout << palin[palin.size()-1] << endl;
    int n;
    cin >> n;
    for(int test = 1;test <= n; test++)
    {

        long long l,r;
        cin >> l >> r;
        r++;
        long long P[2];
        P[0]=P[1] = 0;
        for(int i=0;palin[i]<r;i++)
        {
            if(palin[i]<l && palin[i+1]>=l)
            {
                if(palin[i+1]<r)
                P[i%2]+=palin[i+1]-l+1;
                else
                    P[i%2] += r-l+1;
            }
            else if(palin[i+1]>=r)
            {
                P[i%2] += r-palin[i];
            }
            else if(palin[i]>=l)
            {
                P[i%2] += palin[i+1]-palin[i];
            }
        }
//        cout << P[0] << ' ' << P[1] << endl;
        long long ans=0;
//        cout << l << ' ' << (r-1) << "----" << P[0] << ' ' << P[1] << endl;
        P[0] %= mod;
        P[1] %= mod;
        if(P[0]%2==0)
            ans += P[0]/2*(P[0]-1);
        else
            ans += (P[0]-1)/2 * P[0];
        if(P[1]%2==0)
            ans += P[1]/2*(P[1]-1);
        else
            ans += (P[1]-1)/2 * P[1];

        ans %= mod;

        cout << "Case #" << test << ": " << ans << endl;
    }
}
