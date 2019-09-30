#include <iostream>

using namespace std;

int main(void)
{
    int W, H, N;
    cin >> W >> H >> N;

    int xmin = 0;
    int ymin = 0;
    int xmax = W;
    int ymax = H;
    for(int i = 0; i < N; ++i)
    {
        int xi, yi, ai;
        cin >> xi >> yi >> ai;
        switch(ai)
        {
            case 1:
                xmin = max(xmin, xi);
                break;
            case 2:
                xmax = min(xmax, xi);
                break;
            case 3:
                ymin = max(ymin, yi);
                break;
            case 4:
                ymax = min(ymax, yi);
                break;
        }
    }

    int ans = 0;
    if(xmin < xmax && ymin < ymax)
    {
        ans = (xmax - xmin) * (ymax - ymin);
    }
    cout << ans << endl;
    return 0;
}