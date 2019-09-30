#include <iostream>
 #include <cstdio> 
#include <cstring> 
using namespace std;
 int main(){
 char a[50],b[50],c[100]; 
while(cin>>a>>b){ 
int i,j; c[0]=a[0]; 
for(i=1,j=0;i<=100;i++)
{
 if(i%2!=0)
 {c[i]=b[j];j++;} 
else c[i]=a[j]; 
} 
cout<<c<<endl; 
}
 return 0;
 }