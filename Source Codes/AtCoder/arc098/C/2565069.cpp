#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>

typedef std::pair<int,int> pii;

int n,k,q;

int a[2005];
bool rem[2005];

pii bottoms[2005];

std::vector<int> choices;
std::vector<int> subseq;
int lo;

int ans=0x3f3f3f3f;

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d%d%d",&n,&k,&q);
    for (int i=0; i<n; i++) {
        scanf("%d",a+i);
        bottoms[i]={a[i],i};
    }
    std::sort(bottoms,bottoms+n);
    rem[n]=1;
    for (int i=0; i<n; i++) {
        // do current position
        choices.clear();
        lo=0;
        for (int j=0; j<=n; j++) {
            if (rem[j]) {
                if (j-lo>=k) {
                    subseq.clear();
                    for (int kk=lo; kk<j; kk++) {
                        subseq.push_back(a[kk]);
                    }
                    std::sort(subseq.begin(),subseq.end());
                    for (int kk=0; kk<=(j-lo)-k; kk++) choices.push_back(subseq[kk]);
                }
                lo=j+1;
            }
        }
        if (choices.size()<q) break;
        std::sort(choices.begin(),choices.end());
        if (ans>choices[q-1]-choices[0]) {
            ans=choices[q-1]-choices[0];
        }
        // remove next bottom element
        rem[bottoms[i].second]=1;
    }
    printf("%d\n",ans);
}