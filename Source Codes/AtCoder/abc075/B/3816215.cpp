#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> S(H, vector<int>(W, 0));
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            char sij;
            cin >> sij;
            if('#' == sij)
                S[i][j] = -1;
        }
    }
#define INCB(sij) {if(sij != -1) sij++;}
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            if(S[i][j] == -1)
            {
                if(i-1 > -1 && j-1 > -1)
                    INCB(S[i-1][j-1]);
                if(i-1 > -1)
                    INCB(S[i-1][j]);
                if(i-1 > -1 && j+1 < W)
                    INCB(S[i-1][j+1]);

                if(j-1 > -1)
                    INCB(S[i][j-1]);
                if(j+1 < W)
                    INCB(S[i][j+1]);

                if(i+1 < H && j-1 > -1)
                    INCB(S[i+1][j-1]);
                if(i+1 < H)
                    INCB(S[i+1][j]);
                if(i+1 < H && j+1 < W)
                    INCB(S[i+1][j+1]);
            }
        }
    }
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            if(S[i][j] == -1) cout << '#';
            else cout << S[i][j];
        }
        cout << endl;
    }

    return 0;
}