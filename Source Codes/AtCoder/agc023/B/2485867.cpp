#include <iostream>
using namespace std;
const int N = 502;
int n; char a[N][N];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);

    int res=0;
    for(int d=0;d<n;d++) {
        int ok=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][(j+d)%n]!=a[j][(i+d)%n]) ok=0;
        if(ok) res+=n;
    }
    cout<<res<<endl;
}