#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main(void){
    // Your code here!
    long long int a,b,x;
    cin >> x >> a >> b;
    if(abs(x-a) > abs(x-b)) cout << 'B' << endl;
    else cout << 'A' << endl;
    
    
    
    
    
    return 0;
}