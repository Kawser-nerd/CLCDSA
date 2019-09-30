#include <iostream>
using namespace std;
int main(){
int n;
while(cin >> n)
 { int s = 0,m = 1, l;
for(int i = 2; i <= n; i++)
 { int j = i; l = 0;
 if(j % 2 != 0)
continue;
else
{
while(j%2==0)
{ l++; j/=2; }
}
 if(l>s) { s = l; m = i; }
 }
cout << m << endl; }
return 0;
}