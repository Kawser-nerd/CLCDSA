#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctype.h>

using namespace std;
typedef long long LL;
LL s[10000]={0};
struct Zhan{
    int dui[60]={0};
    int top=-1;
}zhan[60];
int main(){
    int n;
    scanf("%d",&n);
    int j=-1;
    for (int i=0; i<n; i++) {
        int p;
        scanf("%d",&p);
        int min=10000000,mark=-1;
        for (int k=0; k<=j; k++) {
            //min ?? mark ??
            if (p<=zhan[k].dui[zhan[k].top]) {
                int m=zhan[k].dui[zhan[k].top]-p;
                if(m<min){
                    min=m;
                    mark=k;
                }
            }
        }
        if(mark==-1) {
            j++;
            mark=j;
        }
        zhan[mark].dui[++zhan[mark].top]=p; //zhan add
        
    }
    printf("%d\n",j+1);
    return 0;
}