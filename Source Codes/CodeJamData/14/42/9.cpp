#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int N, A[1005];
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", A+i);
        int ans=0;
        int *begin=A, *end=A+N;
        while(begin!=end)
        {
            int *pos = min_element(begin, end);
            ans+=min(pos-begin, end-pos-1);
            copy_backward(pos+1, end, end-1);
            end--;
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
