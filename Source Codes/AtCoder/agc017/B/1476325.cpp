#include<iostream>
using namespace std;
int main()
{
    long long N,A,B,C,D,ans=0;
    cin>>N>>A>>B>>C>>D;
    for(int i=0;i<N;i++)
      if(C*i-D*(N-1-i)<= B-A&&B-A<= D*i-C*(N-1-i))ans=1;

if(ans) cout << "YES"<< endl;
else cout << "NO"<< endl;
}