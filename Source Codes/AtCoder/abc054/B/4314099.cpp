#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int m, n;
    char nn[55][55];
    char mm[55][55];
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>nn[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin>>mm[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n-m; i++){
        if(ans == 1)break;
        for(int j = 0; j < n-m; j++){
            if(nn[i][j] == mm[0][0]){
                int flag = 1;
                for(int k = 0; k < m; k++){
                    if(flag == 0)break;
                    for(int l = 0; l < m; l++){
                        if(nn[i+k][j+l] != mm[k][l]){
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag == 0)continue;
                else ans = 1;
                break;
            }
            else continue;
        }
    }
    if(n == m){
        int flag = 1;
        for(int i = 0; i < n; i++){
            if(flag == 0)break;
            for(int j = 0; j < m; j++){
                if(nn[i][j] != mm[i][j]){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1)ans = 1;
        else ans = 0;
    }
    if(ans == 1)cout<<"Yes";
    else cout<<"No";


    return 0;
}