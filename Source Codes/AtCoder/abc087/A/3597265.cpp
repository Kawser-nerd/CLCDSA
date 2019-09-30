#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <climits>
#include <functional>
#include <map>
#include <stack>
#include <cstdlib>
#define endl '\n'
#define ll long long
#define NCONS 100001

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int X, A, B; cin >> X >> A >> B;
    X -= A;
    cout << X % B << endl;
    
    
    return 0;
}