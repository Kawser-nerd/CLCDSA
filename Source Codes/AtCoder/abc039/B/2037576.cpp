#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    unsigned long long x;
    cin >> x;
    
    for(unsigned int i = 1;i <= x;i++){
        if(i*i*i*i == x){
            cout << i << endl;
            return 0;
        }
    }
}