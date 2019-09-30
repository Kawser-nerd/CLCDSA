#include<stdio.h>
#include<math.h>
#include<sys/time.h>
#define key 2500

unsigned long long seed;

unsigned long long xorshift(){
  seed=seed^(seed<<13);
  seed=seed^(seed>>7);
  seed=seed^(seed<<17);
  return seed;
}

typedef struct{
  int elem[205];
}vec;

int min(int a,int b){if(a<b){return a;}return b;}

unsigned int x=123456789,y=362436069,z=521288629,w,t;
vec pts[5050];

void gen_in(){
  int i,j,v;
  for(i=1;i<=5000;i++){
    for(j=1;j<=200;j++){
      t = x ^ (x << 11);
      x = y;
      y = z;
      z = w;
      w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
      v = (w % 100000);
      v-=50000;
      if(v>=0){v++;}
      pts[i].elem[j]=v;
    }
  }
}

double cos_simil(int a,int b){
  long long i,ab=0,as=0,bs=0,va,vb;
  double sqa,sqb,res;
  for(i=1;i<=200;i++){
    va=pts[a].elem[i];
    vb=pts[b].elem[i];
    ab+=va*vb;
    as+=va*va;
    bs+=vb*vb;
  }
  res=ab;
  sqa=sqrt(as);
  sqb=sqrt(bs);
  res/=sqa;
  res/=sqb;
  return res;
}

int main(void){
  int arr[5050],i,j,te,m,ver;
  int minv[5050];
  int res[5050][2]={0},nmb,nmv;
  double minc[5050],ncs,nmc,rc=0.0;
  struct timeval tv;
  gettimeofday(&tv, NULL);
  seed=(tv.tv_sec*1000000+tv.tv_usec);
  scanf("%u",&w);
  gen_in();
  for(i=1;i<=5000;i++){
    arr[i]=i;
    minc[i]=3.0;
  }
  for(i=5000;i>=2;i--){
    te=(xorshift()%i)+1;
    m=arr[i];
    arr[i]=arr[te];
    arr[te]=m;
  }
  for(i=1;i<=4999;i++){
    //if(i%10==0){
      //printf("Calculating %d\n",i);
    //}
    ver=min(key,5000-i);
    for(j=ver;j>=1;j--){
      te=(xorshift()%(5000-i))+1;
      m=arr[j];
      arr[j]=arr[te];
      arr[te]=m;
    }
    nmb=-1;
    nmv=-1;
    nmc=3.0;
    for(j=1;j<=ver;j++){
      ncs=cos_simil(arr[j],arr[5001-i]);
      //if(j==1){printf("[%.12lf]\n",ncs);}
      ncs=1-ncs;
      if(ncs<minc[arr[j]]){
        minc[arr[j]]=ncs;
        minv[arr[j]]=arr[5001-i];
      }
      if(minc[arr[j]]<nmc){
        nmc=minc[arr[j]];
        nmb=j;
        nmv=minv[arr[j]];
      }
    }
    rc+=nmc;
    res[i][0]=arr[nmb];
    res[i][1]=nmv;
    m=arr[nmb];
    arr[nmb]=arr[5000-i];
    arr[5000-i]=m;
  }
  //printf("<%.12lf>\n",rc);
  for(i=1;i<=4999;i++){
    printf("%d %d\n",res[i][0],res[i][1]);
    //if(i%10==0){printf("<%d>\n",i);}
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:67:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u",&w);
   ^