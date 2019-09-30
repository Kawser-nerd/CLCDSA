#include <iostream>
using namespace std;

long a=1,b=0;

void calc(long cnt){
    if(cnt){
        cnt--;
        long pa,pb;
        pb=a; pa=pb+b;
        b=pb; a=pa;
        calc(cnt);
    }else{
        return;
    }
}

int main(void){
    long K;
    cin>>K;
    calc(K+1);
    cout<<a<<" "<<b<<endl;
}