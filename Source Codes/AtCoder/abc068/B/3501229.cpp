#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int c,n;
    int fun(int);
    while(cin >> n){
    c=fun(n);
    cout << c << endl;
    }
return 0;
}

    int fun(int n){

        int sum1=0;
        int temp,sum2=1;

        int j;
        for(int i=2;i<=n;i++){
            int j=i;
            int cou=0;
            if(j%2!=0)
                continue;
            else{
            while(j%2==0){
            cou++;
            j=j/2;
            }
            }
            if(cou>sum1){
                sum1=cou;
                sum2=i;
            }
        }
     return sum2;
    }