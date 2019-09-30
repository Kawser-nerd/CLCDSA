#include <iostream>
#include <string>
using namespace std;
string S;
void solve()
{
    int i,j,len=S.length(),ans=0;
    i=len/2;
    while(i--)
    {
        string tmp1,tmp2;
        for (j=0;j<i;j++)
            tmp1.push_back(S[j]);
        for (j=i;j<2*i;j++)
            tmp2.push_back(S[j]);
        if (tmp1==tmp2) {ans=2*i;break;}
    }
    cout<<ans<<endl;
}
int main()
{
    while(cin>>S)
        solve();
}