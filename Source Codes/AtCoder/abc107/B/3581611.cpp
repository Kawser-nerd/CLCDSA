#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int H, W;

    cin >> H >> W;

    vector<vector<char> > v(H);
    vector<bool> row_print(H, false);
    vector<bool> col_print(W, false);

    for(int i = 0; i < H; ++i)
    {
        v[i].resize(W);
        for(int j = 0; j < W; ++j)
        {
            cin >> v[i][j];
            if('#' == v[i][j])
            {
                row_print[i] = true;
                col_print[j] = true;
            }
        }
    }

    for(int i = 0; i < H; ++i)
    {
        if(!row_print[i]) continue;
        for(int j = 0; j < W; ++j)
        {
            if(!col_print[j]) continue;
            cout <<  v[i][j];
        }
        cout << endl;
    }

    return 0;
}