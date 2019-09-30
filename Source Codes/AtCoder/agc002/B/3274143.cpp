#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int box[100005];
int cand[100005];

int N, M;

int main()
{
    cin >> N >> M;

    cand[0] = 1;

    fill(box, box + N, 1);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        box[x]--;
        box[y]++;

        if (cand[x] == 1)
        {
            cand[y] = 1;
        }

        if (box[x] == 0)
        {
            cand[x] = 0;
        }
    }

    cout << accumulate(cand, cand + N, 0) << endl;

    return 0;
}