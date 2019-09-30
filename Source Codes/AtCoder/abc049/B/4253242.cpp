#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int h, w;
    char m[105][105];
    cin>>h>>w;
    for(int i = 0; i < h; i++){
            getchar();
        for(int j = 0; j < w; j++){
            scanf("%c", &m[i][j]);
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            printf("%c", m[i][j]);
        }
        cout<<endl;
        for(int j = 0; j < w; j++){
            printf("%c", m[i][j]);
        }
        cout<<endl;
    }



    return 0;
}