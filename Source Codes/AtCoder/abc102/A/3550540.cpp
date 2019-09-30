#include <iostream>
 
using namespace std;
 
int main(){
    
    int n; cin >> n;
    if(n%2 == 0){
        cout << n;
    }
    else{
        cout << 2*n;       
        
    }
    return 0;
}