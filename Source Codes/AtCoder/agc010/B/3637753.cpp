#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

long long N;
vector<long long> A;

int main()
{
    cin >> N;
    long long sum = 0;
    
    for (int i = 0; i <= N - 1; i++)
    {
        long long a;
        cin >> a;
        sum += a;
        A.push_back(a);
    }
    long long NN = (N * (N + 1)) / 2;
    if (sum % NN != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    long long p = (long long)(sum / NN);
    bool f = true;
    long long cnt = 0;
    for (int i = 0; i < N; i++)
    {
        long long hoge = p - (A[(i+1)%N]-A[i]);
        if(hoge % N != 0 || hoge < 0)
        {
            f = false;
            break;
        }
        else
        {
            cnt += hoge / N;
        }
    }

    if(cnt != p)
    {
        f = false;
    }

    if (f == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}