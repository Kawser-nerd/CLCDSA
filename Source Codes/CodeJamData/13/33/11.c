#include<stdio.h>

int main(void){
  int t,num,i,j,k,cases,restatk,flg;
  struct tribe{
    int d,n,w,e,s,dd,dp,ds;
  }tr[10];
  unsigned int height[511],nextH[511],*wall,*next,suc;
  wall=height+255;
  next=nextH+255;
  
  scanf("%d",&t);
  for(cases=1;cases<=t;cases++){
    suc=restatk=0;
    for(i=0;i<511;i++) height[i]=nextH[i]=0;
    scanf("%d",&num);
    for(i=0;i<num;i++){
      scanf("%d%d%d%d%d%d%d%d",&tr[i].d,&tr[i].n,&tr[i].w,&tr[i].e,&tr[i].s,&tr[i].dd,&tr[i].dp,&tr[i].ds);
      restatk+=tr[i].n;
    }

    for(i=0;i<=676060 && restatk>0;i++){
      //printf("i=%d,restatk=%d\n",i,restatk);
      //for(j=0;j<20;j++) printf("%d%c",wall[j],(j==19)?'\n':' ');
      for(j=0;j<num;j++){
	if(tr[j].d!=i || tr[j].n==0) continue;
	//printf(" now %d-th tribe atack!\n",j);
	flg=0;
	for(k=tr[j].w;k<tr[j].e;k++){
	  if(wall[k]<tr[j].s){
	    if(next[k]<tr[j].s) next[k]=tr[j].s;
	    flg=1;
	  }
	}
	if(flg==1){
	  suc++;
	  for(k=tr[j].w;k<tr[j].e;k++) if(next[k]<tr[j].s) next[k]=tr[j].s;
	  //printf("  %d-th tr %d-th atk success\n",j,tr[j].n);
	}
	restatk--;
	tr[j].n--;
	tr[j].d+=tr[j].dd;
	tr[j].s+=tr[j].ds;
	tr[j].w+=tr[j].dp;
	tr[j].e+=tr[j].dp;
      }
      //puts("end atack!");
      for(j=0;j<511;j++){
	if(height[j]<nextH[j]) height[j]=nextH[j];
	nextH[j]=0;
      }
    }
    if(restatk>0) fprintf(stderr,"there is restatk=%d\n",restatk);
    printf("Case #%d: %d\n",cases,suc);
  }
  return 0;
}
