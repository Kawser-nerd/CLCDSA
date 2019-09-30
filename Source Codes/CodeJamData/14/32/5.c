#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000000

char train[101][101];
int trainnum[101];
int con[101][2];
int m;
int N;
long long allfactor;

void gettrain(int p)
{
    char ch,ch0;
    while (1)
    {
        ch = getchar();
        if (ch>='a' && ch<='z')
            break;
    }
    ch0 = 0;
    trainnum[p] = 0;
    while (1)
    {
        if (ch!=ch0)
        {
                    trainnum[p]++;
        train[p][trainnum[p]-1] = ch;
        }
        ch0 = ch;
        ch = getchar();
        if (!(ch>='a' && ch<='z'))
            break;
    }
}


long long getfactorial( int n)
{
    int l1;
    long long res;

    if (n==-1)
        return 0;

    res = 1;
    for (l1=2;l1<=n;l1++)
    {
        res = res * l1;
        res = res % 1000000007;
    }

    return res;
}

int checkalphabet( char ch)
{
    int cond[101]; //0:none;1:left;2:right;3:central;4:all
    int l1,l2;
    int rep;
    int condnum[5];
    int last;

    for (l1=0;l1<N;l1++)
    {
        rep = 0;
        for (l2=0;l2<trainnum[l1];l2++)
            if (train[l1][l2] == ch)
                if ( l2==0 || train[l1][l2]!=train[l1][l2-1] )
                    if (rep==0)
                        rep = 1;
                    else
                        return 0;

        cond[l1] = 0;
        if ( train[l1][0] == ch && train[l1][trainnum[l1]-1] == ch)
            cond[l1] = 4;
        if ( train[l1][0] == ch && train[l1][trainnum[l1]-1] != ch)
            cond[l1] = 1;
        if ( train[l1][0] != ch && train[l1][trainnum[l1]-1] == ch)
            cond[l1] = 2;
        if ( train[l1][0] != ch && train[l1][trainnum[l1]-1] != ch && rep==1)
            cond[l1] = 3;
    }
    for (l1=0;l1<=4;l1++)
        condnum[l1] = 0;
    for (l1=0;l1<N;l1++)
        condnum[cond[l1]]++;
    if ( condnum[3]>1 )
        return 0;
    if ( condnum[3] == 1)
    {
        if ( condnum[1]!=0 || condnum[2] !=0 || condnum[4]!=0 )
            return 0;
        return 1;
    }
    if ( condnum[1]>1 || condnum[2]>1)
        return 0;
    last = -1;
    for (l1=0;l1<N;l1++)
        if (cond[l1] == 2)
        {
            last = l1;
            break;
        }
    for (l1=0;l1<N;l1++)
        if (cond[l1] == 4)
        {
            if (last!=-1)
            {
                con[last][1] = l1;
                con[l1][0] = last;
                last = l1;
            }
            else
                last = l1;
        }
    for (l1=0;l1<N;l1++)
        if (cond[l1] == 1)
        {
            if (last!=-1)
            {
                con[last][1] = l1;
                con[l1][0] = last;
            }
        }
    if (condnum[4]>1)
    {
        allfactor = allfactor*getfactorial(condnum[4]);
        allfactor = allfactor % 1000000007;
    }

    return 1;
}


int getgroupnum()
{
    int use[101];
    int l1, a;
    int groupnum;

    for (l1=0;l1<N;l1++)
        use[l1] = 0;

    groupnum = 0;
    for (l1=0;l1<N;l1++)
    {
        if (con[l1][0] == -1 && con[l1][1]==-1)
        {
            groupnum++;
            use[l1] = 1;
        }

        if (con[l1][0] == -1 && con[l1][1]!=-1)
        {
            a = l1;
            while (a!=-1)
            {
                if (use[a] == 1)
                    return -1;
                use[a] = 1;
                a = con[a][1];
            }
            groupnum++;
        }
    }
    for (l1=0;l1<N;l1++)
        if (use[l1]==0)
            return -1;

    return groupnum;
}


int main()
{
    int iCase, T;
    int l1,flag,res;
    long long fres;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        scanf("%d",&N);
        for (l1=0;l1<N;l1++)
            gettrain(l1);
        for (l1=0;l1<N;l1++)
        {
            con[l1][0]=-1;
            con[l1][1]=-1;
        }
        flag = 1;
        allfactor = 1;
        for (l1='a';l1<='z';l1++)
            if (!checkalphabet(l1))
            {
                flag = 0;
                break;
            }
        if (flag ==0)
        {
            printf("Case #%d: %d\n",iCase,0);
            continue;
        }
        res = getgroupnum();
        fres = allfactor;
        fres = fres * getfactorial(res);
        fres = fres % 1000000007;
        printf("Case #%d: %lld\n",iCase, fres);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
