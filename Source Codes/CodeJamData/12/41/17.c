#include<stdio.h>
#include<string.h>
#include<math.h>
int s[10005],len[10005];
int maxL[10005];



int min(int a,int b){
    if(a<b)return a;
    return b;
}

int main()
{
    int tn,n;
    int i,j,k;
    int tar;
    int isP,isN;
    int nowL;
    int t;
    scanf("%d",&tn);
    for(k=1;k<=tn;k++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&s[i],&len[i]);
        }
        scanf("%d",&tar);

        isP = 1;

        memset(maxL,-1,sizeof(maxL));

        maxL[0] = min(s[0],len[0]);
        if(maxL[0]<s[0])isP = 0;
        /*
        printf("isP %d\n",isP);
        */

        for(i=0;i<n;i++){
            nowL = maxL[i];
            /*
            printf("i %d: %d\n",i,maxL[i]);
            */
            t = -1;
            for(j=i+1;j<n;j++){
                if(nowL>=s[j]-s[i]){
                    t = min(len[j],s[j]-s[i]);

                    if(maxL[j]==-1||maxL[j]<t)maxL[j] = t;

                }
            }
        }
        isN = 1;
        for(i=0;i<n;i++){
            if(maxL[i]!=-1&&maxL[i]+s[i]>=tar)isN = 0;
        }

        if(isP&&isN==0)printf("Case #%d: YES\n",k);
        else printf("Case #%d: NO\n",k);

    }
    return 0;
}
