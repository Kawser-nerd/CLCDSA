#include <iostream>
using namespace std;
int main(){
    int a,b,k;
    cin >>a>>b>>k;
    for(int i=a;i<=b;i++){
        if (i-a<k || b-i<k){
            cout<<i<<endl;
        }
    }

}