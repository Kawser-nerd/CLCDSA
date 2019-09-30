#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[10010];
int num[10010];
int sum[10010];
char letter[100][10]={
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
// "THREE",
void clear(int x)
{
    int n=sum[x];
    int m=strlen(letter[x]);
    for (int i=0;i<m;i++)
    {
        num[letter[x][i]]-=n;
    }
}
void work(int idx)
{
    printf("Case #%d: ",idx);
    scanf("%s",s+1);
    memset(num,0,sizeof(num));
    int n=strlen(s+1);
    for (int i=1;i<=n;i++)
    {
        num[s[i]]++;
    }
    sum[4]=num['U'];
    clear(4);
    sum[0]=num['Z'];
    clear(0);
    sum[2]=num['W'];
    clear(2);
    sum[6]=num['X'];
    clear(6);
    sum[7]=num['S'];
    clear(7);
    sum[5]=num['F'];
    clear(5);
    sum[1]=num['O'];
    clear(1);
    sum[8]=num['G'];
    clear(8);
    sum[9]=num['I'];
    clear(9);
    sum[3]=num['H'];
    clear(3);
    for (int i=0;i<=9;i++)
    {
        for (int j=1;j<=sum[i];j++)
        printf("%c",'0'+i);
    }
    printf("\n");
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    work(i);
    return 0;
}
