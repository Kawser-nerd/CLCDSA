#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

const int INF = 100100100;

int N = 55555;
int arr[1000000];
vector<int> p;

void eratosthenes()
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = 1;
    }
    for (int i = 2; i < sqrt(N); i++)
    {
        if (arr[i])
        {
            for (int j = 0; i * (j + 2) < N; j++)
            {
                arr[i * (j + 2)] = 0;
            }
        }
    }
}

int GetRandom(int min, int max)
{
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

vector<int> ans;

int main()
{
    int n;

    cin >> n;

    p.clear();
    eratosthenes();

    for (int i = 2; i < N; i++)
    {
        if(arr[i] && i % 5 == 1)
        {
            p.push_back(i);
        }
    }

    for (int i = 0; i < n;i++)
    {
        if(i == n - 1)
        {
            cout << p[i] << endl;
        }
        else
        {
            cout << p[i] << " ";
        }
    }

    return 0;
}