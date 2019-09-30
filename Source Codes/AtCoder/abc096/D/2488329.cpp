#include <iostream>
#include <cmath>
#include <stdarg.h>
using namespace std;

int i=0;
bool sosuhantei(int num)
{
    if(num<2) return false;
    else if(num == 2) return true;
    else if(num%2 ==0)return false;
    
    
    for(int i=3;i<=sqrt(num);i+=1)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;

}


int main()
{
    int n;
    cin >>n;
    for(i=1;i<=55555;i++){
    if(sosuhantei(i)==true&&i%5==1){
        
        cout<<i<<" ";
        n-=1;
    }
        if(n==0)break;
    }
    cout << endl;
    return 0;
}