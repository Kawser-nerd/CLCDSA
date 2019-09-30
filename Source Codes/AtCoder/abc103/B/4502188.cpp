#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_NUM 100001
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    string S,T;
    cin>>S>>T;
    int N=S.size();
    int count=0;
    char temp;

    for(int i=0;i<N;i++)
    {
        temp=S[0];
        for(int j=0;j<N-1;j++)
        {
            S[j]=S[j+1];
        }
        S[N-1]=temp;
        if(S==T)
        {
            count=1;
            break;
        }
    }
    if(count)
        cout<<"Yes";
    else
        cout<<"No";

}