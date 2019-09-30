#include <iostream>
using namespace std;
int main(){
int a, b, c;
cin >> a >> b >> c;
int x[3];
if(a >= b && a >= c){
x[0] = a;
if(b >= c){
x[1] = b;
x[2] = c;
} else {
x[1] = c;
x[2] = b;
}
} else if(b >= a && b >= c){
x[0] = b;
if(a >= c){
x[1] = a;
x[2] = c;
} else {
x[1] = c;
x[2] = a;
}
} else if(c >= a && c >= b){
x[0] = c;
if(a >= b){
x[1] = a;
x[2] = b;
} else {
x[1] = b;
x[2] = a;
}
}
int sum = x[0] * 10 + x[1] + x[2];
cout << sum << endl;
}