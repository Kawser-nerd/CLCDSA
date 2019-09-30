#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<min(a,b)+min(c,d)<<'\n';
    return 0;
}