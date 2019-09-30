#include <iostream>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
   long long a,b;
   cin>>a>>b;
   if((a<0&&b>0)||(a==0)||(b==0))cout<<"Zero"<<endl;
   else if(((b-a+1)%2==0)||(a>0&&b>0)) cout<<"Positive"<<endl;
   else cout<<"Negative"<<endl;
return 0;
}