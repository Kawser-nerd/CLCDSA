#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> prime;

bool is_prime(int a)
{
    if(a == 2) return true;
    for(int i = 2; i * i <= a; i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    for(int i = 2; i <= 55555; i++)
    {
        if(is_prime(i) && i % 5 == 1)
            prime.push_back(i);
    }
    int N; cin >> N;

    for(int i = 0; i < N; i++)
    {
        cout << prime[i] << " ";
    }

    return 0;
}