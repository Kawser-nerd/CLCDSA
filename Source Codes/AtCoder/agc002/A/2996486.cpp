#include<cstdio>
using namespace std;

int main()
{
    int a, b;
    long long m = 1;
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++)
    {
        if(i == 0)
        {
            m = 0;
            break;
        }
        else if(i < 0)
            m = -m;

    }
    if(m == 0)
        printf("Zero");
    else if(m < 0)
        printf("Negative");
    else
        printf("Positive");
    return 0;
}