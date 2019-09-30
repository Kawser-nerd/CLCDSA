#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int n , K , T;
char c[102][102];
int dx[] = {0 , 0 , 1 , 1 , -1};
int dy[] = {0 , 1 , 0 , 1 , 1};

bool check(int x , int y , int f , char chr)
{
    for(int i = 0 ; i < K ; i++)
        if(c[x + dx[f] * i][y + dy[f] * i] != chr)
            return false;
    return true;
}

int main()
{
    freopen("A.in" , "r" , stdin);
    freopen("A.out" , "w" , stdout);
    cin>>T;
    for(int caseID = 1 ; caseID <= T ; caseID ++)
    {
        memset(c , 0 , sizeof(c));
        cin>>n>>K;
        for(int i = 1 ; i <= n ; i++)
        {
            string t;
            cin>>t;
            int loc = 0;
            for(int j = n - 1 ; j >= 0 ; j--)
                if(t[j] == 'R')
                    c[i][++loc] = 'R';
                else if(t[j] == 'B')
                    c[i][++loc] = 'B';
        }
        bool isR = false , isB = false;
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                for(int k = 1 ; k <= 4 ; k++)
                {
                    if(check(i , j , k , 'B'))
                        isB = true;
                    if(check(i , j , k , 'R'))
                        isR = true;
                }
        cout<<"Case #"<<caseID<<": ";
        if(isR == false && isB == false)
            cout<<"Neither"<<endl;
        if(isR == true && isB == false)
            cout<<"Red"<<endl;
        if(isR == false && isB == true)
            cout<<"Blue"<<endl;
        if(isR == true && isB == true)
            cout<<"Both"<<endl;
    }
    return 0;
}
