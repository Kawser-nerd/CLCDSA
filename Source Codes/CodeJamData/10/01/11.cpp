#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        int N, K;
        scanf("%d%d", &N, &K);
        
        printf("Case #%d: ", t);
        if((1 << N) - 1 == (K & ((1 << N) - 1)))
            printf("ON\n");
        else
            printf("OFF\n");

    }
    return 0;
}
