#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int num,t;
    cin >> num;
    for(int i=1;i<=num;i++)
        for(int j=0; j<=8 ;j++)
        if(i==pow(2,j))
            t=i;
    cout << t << endl;

return 0;

}