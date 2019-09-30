#include <iostream>
using namespace std;
int main(){
    int num,a,c;
    cin >> num;
    a=num%10;
    c=num/100;
    if(a==c)
    cout <<"Yes"<< endl;
    else
    cout <<"No" << endl;

return 0;

}