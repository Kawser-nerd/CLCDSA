#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maru = 1;
const int batsu = -1;

int board[3][3];
int sums = 0;

int b[2][3];
int c[3][2];

int calc_score()
{
    int sum = 0;
    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(board[i][j] == board[i+1][j])
            {
                sum += b[i][j];
            }
            if (board[j][i] == board[j][i+1])
            {
                sum += c[j][i];
            }
        }
    }
    return sum;
}

int get_score(int n)
{
    if(n == 10)
    {
        return calc_score();
    }

    int mins = sums;
    int maxs = 0;

    int mark = (n % 2 == 1) ? maru : batsu;

    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(board[i][j] == 0)
            {
                board[i][j] = mark;
                int s = get_score(n + 1);
                mins = min(mins, s);
                maxs = max(maxs, s);
                board[i][j] = 0;
            }
        }
    }

    if (n % 2 == 1)
    {
        return maxs;
    }
    else
    {
        return mins;
    }
}

int main()
{

    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            cin >> b[i][j];
            sums += b[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> c[i][j];
            sums += c[i][j];
        }
    }

    int maxs = get_score(1);

    cout << maxs << endl;
    cout << sums - maxs << endl;

    return 0;
}