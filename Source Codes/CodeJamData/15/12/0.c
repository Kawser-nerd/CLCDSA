#include<stdio.h>
typedef long long LL;

LL barber[1000];

LL finishcount(int x,LL mid){
  int a;
  LL finishcnt=0;
  for(a=0;a<x;a++){
    finishcnt+=mid/barber[a];
  }
  return finishcnt;
}

int main(int argc,char*argv[]){
  int a,d,e,n,x;
  scanf("%d",&e);
  for(d=1;d<=e;d++){
    scanf("%d%d",&x,&n);
    for(a=0;a<x;a++)scanf("%I64d",barber+a);
    n--;
    int ans;
    if(n<x){
      ans=n;
      goto answer;
    }
    LL lo=0;
    LL hi=100001*(LL)1000000001;

    while(lo+1!=hi){
      LL mid=(lo+hi)/2;
      LL finishcnt=finishcount(x,mid);
      if(finishcnt+x<=n)lo=mid;
      else hi=mid;
    }

    LL fincnt=finishcount(x,lo);
    //printf(" %d %d\n",(int)lo,(int)fincnt);
    LL enqcnt=fincnt+x;
    if(enqcnt>n)puts("error1");
    ans=-1;
    for(a=0;a<x;a++){
      if(hi%barber[a]==0){
        enqcnt++;
        if(enqcnt==n+1){
          ans=a;
          break;
        }
      }
    }
    //if(fincnt<n)puts("error3");
    if(ans<0)puts("error2");
    answer:
    printf("Case #%d: %d\n",d,ans+1);
  }
  return 0;
}
