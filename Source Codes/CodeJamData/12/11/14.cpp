#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
double pi[101000];
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int a,b,i,j;
        scanf("%d%d",&a,&b);
        double ans=1e40;
        for(i=0;i<a;i++)scanf("%lf",&pi[i]);
        double na;
        na=1+b+1;//case 3
        if(ans>na)ans=na;
        double ac=1;
        for(i=0;i<=a;i++){
            na=(a-i)+(b-i)+1+(1-ac)*(b+1);
            if(ans>na)ans=na;
            ac*=pi[i];
        }
        printf("Case #%d: %.10lf\n",cas++,ans);
    }
}

