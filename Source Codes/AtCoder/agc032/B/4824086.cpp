#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <chrono>
#include <vector>

using namespace std;
typedef pair<int, int> edge_pair;

int main()
{
    int N;
    cin >> N;
    vector<edge_pair> ans_pairs;
    int sum = N;
    if (N % 2 == 0)
        sum++;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i + j == sum)
                continue;
            ans_pairs.push_back(edge_pair(j, i));
        }
    }
    cout << ans_pairs.size() << endl;
    for (int i = 0; i < ans_pairs.size(); i++)
    {
        cout << ans_pairs[i].first << " " << ans_pairs[i].second << endl;
    }
    return 0;
}