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
int L,D,N;
string words[5000];


int solve( const string pat)
{
    int masks[15];
    int j=0;
    for (int i=0;i<L; i++)
    {
        if(pat[j]=='(')
        {
            masks[i]=0;
            j++;
            while(pat[j]!=')')
            {
                masks[i] |= (1<<( pat[j]-'a' ) );
                j++;
            }
        }
        else masks[i] = (1<<( pat[j]-'a' ) );
        j++;
    }
    int c=0;
    for (int i=0;i<D; i++)
    {
        bool good= true;
        for (int j=0; (j<L) && good; j++)
        {
            good = ( ( masks[j]&( 1<<(words[i][j]-'a' ) ) ) != 0 );
        }
        if(good) c++;
    }
    
    return c;
}



inline void init(){}
//=========================================================
// I/O:
//
int main()
{
    init();
    cin>>L>>D>>N;
    for (int i=0; i<D; i++)
        cin>>words[i];
    
    
    
    for (int i=1;i<=N;i++)
    {
        cerr<<"["<<i<<" / "<<N<<"]"<<endl;
        string pat;
        cin>>pat;
        cout<<"Case #"<<i<<": " <<solve(pat)  << endl;
        
        
        
    }
    return 0;
}
