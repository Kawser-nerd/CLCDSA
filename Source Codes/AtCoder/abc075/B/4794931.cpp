#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
    string mass[50];
    int h,w;
    int x[8] = {-1,-1,-1,0,0,1,1,1};
    int y[8] = {-1,0,1,-1,1,-1,0,1};
    cin >> h >> w;
    for(int i = 0;i < h;i++)
    {
        cin >> mass[i];
    }

    for(int i = 0;i < h;i++)
    {
        for(int j = 0;j < w;j++)
        {
            if(mass[i][j] == '#'){continue;}
            
            int num = 0;
            for(int d = 0;d < 8;d++)
            {
                int ni = i + x[d];
                int nj = j + y[d];
                if(ni < 0 || h <= ni){continue;}
                if(nj < 0 || w <= nj){continue;}
                if(mass[ni][nj] == '#'){num++;}
            }
            mass[i][j] = char(num + '0');
        }
    }
    for(int i = 0;i < h;i++){cout << mass[i] << endl;}
    return 0;
}