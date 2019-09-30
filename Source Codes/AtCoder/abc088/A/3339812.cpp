#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, a, sum=0;
    cin >> n >> a;
    sum = n- (n/500) * 500 - a;
    if(sum<=0) cout << "Yes" << endl;
    else cout << "No" << endl;
}