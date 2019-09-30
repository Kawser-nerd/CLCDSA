#include<string>
#include<iostream>
#include<sstream>
#include<assert.h>
#include<cstdio>
#include<map>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<queue>
#include<functional>
#include<set>

using namespace std;

//=========================================================
// program:
//
string welcome = "welcome to code jam";



int solve(const string s)
{
    int n = welcome.length(), t=s.length();
    int dp[500][n];
    
    for (int j=n; j--;)
        dp[t-1][j] = 0;
    if(s[t-1]==welcome[n-1])
        dp[t-1][n-1] = 1;
        
        
    
    for (int i=s.length()-1; i--; )
    {
        for (int j=n; j--;)
        {
            if( s[i]==welcome[j] )
            {
                if(j==n-1)
                {
                    dp[i][j] = (dp[i+1][j] + 1)%10000;
                }
                else
                {
                    dp[i][j] = (dp[i+1][j] + dp[i+1][j+1])%10000;
                }
            }
            else
            {
                dp[i][j] = dp[i+1][j];
            }
        }
    }
    /*for (int i=0; i<t; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<< "("<<s.substr(i)<<","<<welcome.substr(j) << ") = "<<dp[i][j]<<endl;
        }
    }
    
    cout<<"["<<s<<"]"<<dp[0][0]<<endl;    */
    return dp[0][0];
    
}

inline void init(){}
//=========================================================
// I/O:
//
int main()
{
    init();
    int N; cin>>N;
    string line;
    getline(cin,line);
    for (int i=1;i<=N;i++)
    {
        getline(cin,line);
        cerr<<"["<<i<<" / "<<N<<"]"<<endl;
        cout<<"Case #"<<i<<": " ;
        printf("%04d", solve(line) );
        cout  << endl;
        
    }
    return 0;
}
