#include<iostream>
#include<cmath>
using namespace std;

const long long F = (2e5) * (1e9);

int main()
{
    long long n;
	cin >> n;
	long long* a = new long long[n];
	long long* sum = new long long[n];
    cin >> a[0];
    sum[0] = a[0];
    long long tot = a[0];
    for(int i = 1;i < n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        tot += a[i];
    }
    long long Min = F;
    for(int i = 0;i < n - 1;i++)
    {
        if(Min > abs(2 * sum[i] - tot))
            Min = abs(2 * sum[i] - tot);
    }
    cout << Min << endl;
    return 0;
}