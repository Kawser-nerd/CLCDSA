#include <iostream>


using namespace std;

int main()
{
    int a,b,c,j=0,k=0;
    cin>>a>>b>>c;
    j=b-a;
    k=c-b;
    if(j==k)
    {
        cout<<"YES";
    }
    else
        {
            cout<<"NO";
        }
        return 0;
}