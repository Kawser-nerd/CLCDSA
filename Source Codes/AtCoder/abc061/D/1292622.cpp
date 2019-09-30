#include<iostream>  
#include<vector>  
#include<algorithm>  
  
using namespace std;  
typedef long long ll;  
const int maxn = 2000 + 5;  
const ll oo = 0x3f3f3f3f3f3f3f3f;  
int N, M;  
ll d1, d2;  
  
int main()  
{  
    while (cin >> N >> M)  
    {  
        vector<int>a(M);  
        vector<int>b(M);  
        vector<ll>c(M);  
        for (int i = 0; i < M; i++)  
        {  
            cin >> a[i] >> b[i] >> c[i];  
            a[i]--, b[i]--;  
        }  
        vector<ll>d(N, -oo);  
        d[0] = 0LL;  
        for (int i = 0; i < 2 * N; i++)  
        {  
            for (int j = 0; j < M; j++)  
            {  
                d[b[j]] = max(d[b[j]], d[a[j]] + c[j]);  
            }  
            if (i == N - 1)  
                d1 = d[N - 1];  
            if (i == 2 * N - 1)  
                d2 = d[N - 1];  
        }  
        if (d1 == d2)  
            cout << d1 << endl;  
        else  
            cout << "inf" << endl;  
    }  
    return 0;  
}