#include <iostream>
#include <math.h>
using namespace std;



int main(){
    
    int N;
    cin >> N;
    int a=0;
    int b=0;
    int s=1;
    int flag = 0;

   
    for(a=0;a<26;a++){
        for(b=0;b<16;b++){
            s = N - (4*a + 7*b);
            if(s==0){
                flag = 1;
            }
        }
    }
    if(flag == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    
    return 0;
}