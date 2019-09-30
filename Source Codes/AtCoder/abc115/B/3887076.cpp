#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    int P[N];
    for(int i=0;i<N;i++){
        cin >> P[i];
    }
    sort(P, P+N);
    reverse(P,P+N);
    P[0] = P[0]/2;
    int sum = std::accumulate(P, P + N, 0);
    cout << sum <<endl;
}