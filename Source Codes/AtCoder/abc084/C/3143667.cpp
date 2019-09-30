#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

ll c[505]; //??????????
ll s[505]; //???????????
ll f[505];  //?????f??????
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%ld%ld%ld",&c[i],&s[i],&f[i]);
    for(int i=1;i<=n;i++){
        ll time=0;
        for(int j=i;j<n;j++){
            if(time<s[j])   //??????????
                time=s[j];
            if(time%f[j]!=0)    //????????
                time=time+f[j]-time%f[j];
            time+=c[j];
        }
        printf("%ld\n",time);
    }
    return 0;
} ./Main.cpp:18:27: warning: format specifies type 'long *' but the argument has type 'll *' (aka 'long long *') [-Wformat]
        scanf("%ld%ld%ld",&c[i],&s[i],&f[i]);
               ~~~        ^~~~~
               %lld
./Main.cpp:18:33: warning: format specifies type 'long *' but the argument has type 'll *' (aka 'long long *') [-Wformat]
        scanf("%ld%ld%ld",&c[i],&s[i],&f[i]);
                  ~~~           ^~~~~
                  %lld
./Main.cpp:18:39: warning: format specifies type 'long *' but the argument has type 'll *' (aka 'long long *') [-Wformat]
        scanf("%ld%ld%ld",&c[i],&s[i],&f[i]);
                     ~~~              ^~~~~
                     %lld
./Main.cpp:28:24: warning: format specifies type 'long' but the argument has type 'll' (aka 'long long') [-Wformat]
        printf("%ld\n",time);
                ~~~    ^~~~
                %lld
4 warnings generated.