#include<iostream>
#include<cstring>
using namespace std;
int  an[4][2]={{2, 2},{2,1},{1,1},{1,2}};//WW WS SS SW
int i,j,kind[100005],n;
char ans[100005];
int main()
{
    while(cin>>n&&(n>=3))
    {
        int flag=0;
        memset(kind,0,sizeof(kind));
        for(i=1;i<=n;i++)
        {
            cin>>ans[i];
        }

        for(j=0;j<4;j++)
        {
            kind[1]=an[j][0];
            kind[2]=an[j][1];
            for(i=2;i<=n;i++)
            {
             if(kind[i]==2)//is wolf
             {
                 if(ans[i]=='o') kind[i+1]=kind[i-1]%2+1;
                 else kind[i+1]=kind[i-1];
             }
             else if(kind[i]==1)
                 if(ans[i]=='x')  kind[i+1]=kind[i-1]%2+1;
                 else kind[i+1]=kind[i-1];
            }



            if(kind[n+1]==kind[1])
            {


                if(kind[1]==1)
                {
                    if(ans[1]=='o'&&kind[2]==kind[n]){flag++;break;}
                    if(ans[1]=='x'&&kind[2]!=kind[n]){flag++;break;}
                }
                else if(kind[1]==2)
                {
                    if(ans[1]=='x'&&kind[2]==kind[n]){flag++;break;}
                    if(ans[1]=='o'&&kind[2]!=kind[n]){flag++;break;}
                }
            }


        }

        if(flag==0)cout<<"-1"<<endl;
        else
        {


        for(i=1;i<=n;i++)
        {
            if(kind[i]==1)cout<<'S';
            else cout<<'W';
        }
            cout<<endl;
           // cout<<kind[n+1]<<endl;

        }
    }

} ./Main.cpp:31:18: warning: add explicit braces to avoid dangling else [-Wdangling-else]
                 else kind[i+1]=kind[i-1];
                 ^
1 warning generated.