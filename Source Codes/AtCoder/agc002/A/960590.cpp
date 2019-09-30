#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    int a,b;cin>>a>>b;
    if(a<=0 && b >= 0){cout << "Zero\n";return 0;}
    if(b<0 && (b-a) % 2 == 0){cout <<"Negative\n";return 0;}
    cout<<"Positive\n";
    return 0;
}