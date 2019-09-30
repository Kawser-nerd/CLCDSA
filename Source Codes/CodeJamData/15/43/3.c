#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[1001000];
#define D (2500)
#define Z (D/32+1)
struct word{
  char s[12];
}di[D];
int ndi;
struct sentence{
  unsigned m[Z];
  int wcount;
  int word10[12];
}sen[25];

int lookup(char*z){
  int a;
  for(a=0;a<ndi;a++){
    if(strcmp(di[a].s,z)==0)return a;
  }
  strcpy(di[a].s,z);
  ndi++;
  if(ndi>=D)exit(-1);
  return ndi-1;
}

void initsentence(struct sentence*t){
  int a;
  for(a=0;a<Z;a++)t->m[a]=0;
}

void getsentence(struct sentence*t){
  gets(str);
  char*z=str;
  t->wcount=0;
  initsentence(t);
  while(1){
    char w[100];
    while(*z==' ')z++;
    if(sscanf(z,"%s",w)!=1)break;
    z+=strlen(w);
    int b;
    b=lookup(w);
    t->m[b/32]|=(1<<(b%32));
    if(t->wcount<12){
      t->word10[t->wcount]=b;
      t->wcount++;
    }
  }
}

void orsentence(struct sentence*t,const struct sentence*u){
  int a;
  if(u->wcount<12){
    for(a=0;a<u->wcount;a++){
      int b=u->word10[a];
      t->m[b/32]|=(1<<(b%32));
    }
    return;
  }
  for(a=0;a<ndi/32+1;a++){
    t->m[a]|=u->m[a];
  }
}
void andsentence(struct sentence*t,const struct sentence*u){
  int a;
  for(a=0;a<ndi/32+1;a++){
    t->m[a]&=u->m[a];
  }
}

int main(int argc,char*argv[]){
  int ncase,nc;
  scanf("%d",&ncase);
  for(nc=1;nc<=ncase;nc++){
    int n;
    scanf("%d",&n);
    gets(str);
    ndi=0;
    int a;
    for(a=0;a<n;a++){
      getsentence(sen+a);
    }
    struct sentence eng,fre;
    int b;
    int ans=ndi;
    for(b=1;b<(1<<n);b+=4){
      initsentence(&eng);
      initsentence(&fre);
      for(a=0;a<n;a++){
        if(((b>>a)&1)){
          orsentence(&eng,sen+a);
        }
        else{
          orsentence(&fre,sen+a);
        }
      }
      int ans2=0;
      andsentence(&fre,&eng);
      for(a=0;a<ndi;a++){
        ans2+=((fre.m[a/32]>>(a%32))&1);
      }
      if(ans2<ans)ans=ans2;
    }
    printf("Case #%d: %d\n",nc,ans);
  }
  return 0;
}

