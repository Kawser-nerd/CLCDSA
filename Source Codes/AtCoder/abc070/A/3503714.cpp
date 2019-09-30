#include<iostream>
using namespace std;
int main(){
int a;
while(cin>>a&&a<=999&&a>=100)
if(a/100==a%10)
cout << "Yes" <<endl;
else
cout << "No" <<endl;
return 0;
}