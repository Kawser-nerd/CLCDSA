#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int solve(int a, int b, int c){
    vector<int> arr(3);
    int ans = 0;
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    sort(arr.begin(), arr.end());
    if(arr[0] % 2 == arr[1] % 2 && arr[1] % 2 == arr[2] % 2){
        ans += (arr[2] - arr[1]) / 2 + (arr[2] - arr[0]) / 2;
    }
    else if(arr[0] % 2 == arr[1] % 2 && arr[0] % 2 != arr[2] % 2){
        ans += (arr[2] - arr[1]) / 2 + (arr[2] - arr[0]) / 2 + 1;
    }
    else {
        ans += (arr[2] - arr[1]) / 2 + (arr[2] - arr[0]) / 2 + 2;
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}