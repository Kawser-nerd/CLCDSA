#include <iostream>
 #include <string>
 #include <algorithm>
 using namespace std;


 int main(){
     int a, b, c, d;
     cin >> a >> b >> c >> d;

     const int lower = max(a, c);
     const int upper = min(b, d);

     cout << max(0, upper-lower) << endl;

     return 0;
 }