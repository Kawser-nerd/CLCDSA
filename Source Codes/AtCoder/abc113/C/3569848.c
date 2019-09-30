#include<stdio.h>
#include<stdlib.h>

struct city{
  int num,pref,year;
  char nums[13];
};

int comp1(const void *p1,const void *p2){
  struct city n1=*(const struct city *)p1;
  struct city n2=*(const struct city *)p2;

  return (n1.pref!=n2.pref) ? (n1.pref-n2.pref) : (n1.year-n2.year) ;
}

int comp2(const void *p1,const void *p2){
  struct city n1=*(const struct city *)p1;
  struct city n2=*(const struct city *)p2;

  return n1.num-n2.num;
}

int main(void){
  int N,M;
  int i,j,k=1;
  
  scanf("%d%d",&N,&M);
  struct city *cities;
  cities=(struct city *)calloc(M,sizeof(struct city));

  for(i=0;i<M;i++){
    cities[i].num=i;
    scanf("%d%d",&cities[i].pref,&cities[i].year);
  }

  qsort(cities,M,sizeof(struct city),comp1);
  
  int p;
  for(i=0,p=-1;i<M;i++){
    if(p!=cities[i].pref){
      p=cities[i].pref;
      k=1;
    }
    sprintf(cities[i].nums,"%06d%06d",cities[i].pref,k);
    ++k;
  }

  qsort(cities,M,sizeof(struct city),comp2);

  for(i=0;i<M;i++) printf("%s\n",cities[i].nums);
  
  free(cities);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&cities[i].pref,&cities[i].year);
     ^