#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    long int t = k*pow(k-1,n-1);
    cout << t <<'\n';
    return 0;
}