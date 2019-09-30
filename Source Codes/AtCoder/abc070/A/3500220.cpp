#include <iostream>
using namespace std;
int main() {
 int n;
 while(cin >> n)
{
int a, b;
a = n % 10;
b = n /100;
if(a==b) {
 cout << "Yes" << endl;
 }
 else { 
     cout << "No" << endl;
}
}
 return 0;
 }