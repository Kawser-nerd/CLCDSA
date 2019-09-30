#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        int buf[N];
        for(int i = 0; i<N; i++)
        {
            scanf("%d",&buf[i]);
        }
        sort(buf,buf+N);
        int ptr = 0;
        int res = 0;
        //?????????????
        while(ptr<N)
        {

            int lastNumber = buf[ptr];
            int countSum = 0;
            while(buf[ptr]==lastNumber&&ptr<N)
            {
                ptr++;
                countSum++;
            }
            res+=countSum%2;
        }
        printf("%d\n",res);
    }
    return 0;
}