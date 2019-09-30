#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main(){

    int N, K;
    int ans;

    cin >> N >> K;
    ans =  K * pow((K-1), (N-1)) ; 

    cout << ans << endl;
    return 0;

}