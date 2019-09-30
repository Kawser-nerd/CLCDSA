#include <iostream>
#include <algorithm>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <cstdlib>
typedef long long ll;
#define fi first
#define se second

using namespace std;

int main(){

    int n,a,b;
    cin >>n>>a>>b;
    if((b-a)%2) cout << "Borys";
    else cout << "Alice";

    return 0;
}