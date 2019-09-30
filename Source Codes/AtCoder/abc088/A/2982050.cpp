#include <iostream>
using namespace std;
int main(void){
    int n,a;
    cin >> n >> a;
    n = n % 500;
    if(n <= a) cout << "Yes";
    else cout<< "No";
}