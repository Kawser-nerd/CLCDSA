#include <cstdio>
int N,count=0;
void dfs(long long,unsigned char);
int main(void)
{
    scanf("%d",&N);
    dfs(0,0);
    printf("%d\n",count);
    return 0;
}
void dfs(long long nextNum,unsigned char flag357)
{
    if(nextNum<=N)
    {
        if(flag357==07)    // 07 is BIN 111
            count++;
        dfs(nextNum*10+3,flag357|01); // BIN 001
        dfs(nextNum*10+5,flag357|02); // BIN 010
        dfs(nextNum*10+7,flag357|04); // BIN 100
    }
}