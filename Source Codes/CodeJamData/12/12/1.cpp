#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

int a[1000], b[1000];

#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

void solve(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", a+i, b+i);
    }
    int current[1000]={0};
    int stars=0;
    int tries=0;
    while(stars<2*N)
    {
        bool found = false;
        for(int i=0; i<N; i++)
        {
            if(current[i]==0 && b[i]<=stars)
            {
                current[i]=2;
                stars+=2;
                tries++;
                found=true;
                break;
            }
        }
        if(found)
            continue;
        for(int i=0; i<N; i++)
        {
            if(current[i]==1 && b[i]<=stars)
            {
                current[i]=2;
                stars++;
                tries++;
                found=true;
                break;
            }
        }
        if(found)
            continue;
        int good = -1;
        for(int i=0; i<N; i++)
        {
            if(current[i]==0 && a[i]<=stars && (good==-1 || b[i]>b[good]))
            {
                good=i;
            }
        }
        if(good!=-1)
        {
            current[good]=1;
            stars++;
            tries++;
            continue;
        }
        printf("Too Bad\n");
        return;
    }
    printf("%d\n", tries);
    assert(tries>=N && tries<=2*N);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
