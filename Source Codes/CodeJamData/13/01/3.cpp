#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        string s[4];
        for(int i=0; i<4; i++)cin>>s[i];
        int win = 0;
        for(int i=0; i<4; i++)
        {
            bool Owin = true, Xwin = true;
            bool o2 = true, x2 = true;
            for(int j=0; j<4; j++)
            {
                if(s[i][j]!='T' && s[i][j]!='O')Owin = false;
                if(s[i][j]!='T' && s[i][j]!='X')Xwin = false;
                
                if(s[j][i]!='T' && s[j][i]!='O')o2 = false;
                if(s[j][i]!='T' && s[j][i]!='X')x2 = false;
            }
            if(Owin)win = 1;
            if(Xwin)win = 2;
            if(o2)win = 1;
            if(x2)win = 2;
            //if(Owin)cout<<i<<"O"<<endl;
            //if(Xwin)cout<<i<<"X"<<endl;
        }
        bool o3 = true, x3 = true, o4 = true, x4 = true;
        for(int i=0; i<4; i++)
        {
            if(s[i][i]!='T' && s[i][i]!='O')o3=false;
            if(s[i][i]!='T' && s[i][i]!='X')x3=false;            
            if(s[i][3-i]!='T' && s[i][3-i]!='O')o4=false;
            if(s[i][3-i]!='T' && s[i][3-i]!='X')x4=false;
        }
        if(o3||o4)win=1;
        if(x3||x4)win=2;

        bool anyp = false;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(s[i][j]=='.')anyp = true;
            }
        }
        cout<<"Case #"<<t<<": ";
        if(win==1)cout<<"O won"<<endl;
        else if(win==2)cout<<"X won"<<endl;
        else if(anyp)cout<<"Game has not completed"<<endl;
        else cout<<"Draw"<<endl;
    }

    return 0;
}
