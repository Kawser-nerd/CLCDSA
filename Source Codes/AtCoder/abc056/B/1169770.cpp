#include<iostream>
using namespace std;
#define loop(i,a,b) for(int i=a;i<(int)b;i++)
int main() 
{
    long long int w,a,b;
    cin>>w>>a>>b;
    cout<<max(0LL,max(b-a-w,a-b-w));
	return 0;
}