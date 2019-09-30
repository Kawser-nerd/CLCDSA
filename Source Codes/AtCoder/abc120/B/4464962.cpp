#include <iostream>
using namespace std;
int main(void){
    int a,b,k;
    int count=0;
    cin >>a>>b>>k;
    
    for(int i=100;i>=1;i--){
        if(a%i==0&&b%i==0){
            count++;
            if(count==k){
                cout<<i<<endl;
                return 0;
            }
        }
    }
}