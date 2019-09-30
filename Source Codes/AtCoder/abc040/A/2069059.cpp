#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,x;
    
    scanf("%d %d",&n, &x);
    
    printf("%d",(n-x)<x-1?n-x : x-1);
    
}