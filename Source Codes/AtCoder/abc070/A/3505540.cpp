#include <iostream>
using namespace std;
int main(){
int i;
while(cin >> i&&i>=100&&i<=999)
if(i/100==i%10)
cout << "Yes" << endl;
else 
cout << "No" << endl;
return 0;
}