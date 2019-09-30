using namespace std;
#include<iostream>
#include<string>

int main()
{
    int N;
    cin>>N;
    char S[N];
    int x=0,max=0;
    for(int j=0;j<N;j++)
    cin>>S[j];
    for(int i=0;i<N;i++)
    {
        if(S[i]=='I')
        x++;
        else
        x--;

        if(x>=max)
        max=x;

    }
    cout<<max;
    return 0;
} ./Main.cpp:3:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.