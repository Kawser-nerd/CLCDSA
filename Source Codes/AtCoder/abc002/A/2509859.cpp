#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b;
    int max=0;
    
    cin >>a>>b;
    
    if(a<b){
        max=b;
    }else{
        max=a;
    }
    
    cout <<max<<endl;
}