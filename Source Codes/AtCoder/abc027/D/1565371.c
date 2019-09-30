#include <stdio.h>
#include <stdlib.h>

/* ????? */
int int_sort( const void * a , const void * b ) {
  /* ???void*???????????int??cast?? */
  if( abs(*( int * )a) <abs( *( int * )b) ) {
    return 1;
  }
  else
  if(abs( *( int * )a) == abs(*( int * )b) ) {
    return 0;
  }
  return -1;
}

int main(void){
    char nisizaki[114514];
    scanf("%s",nisizaki);
    int emu=0;
    int plus=0;
    int minus=0;
    for(int i=0;nisizaki[i]=='M'||nisizaki[i]=='+'||nisizaki[i]=='-';i++){
        if(nisizaki[i]=='M')emu++;
        if(nisizaki[i]=='+')plus++;
        if(nisizaki[i]=='-')minus++;
    }
    long long int score=0;
    int left=emu/2;
    int right=emu/2;
    int po[emu];
    int kariplus=0;
    int kariminus=0;
    int k=0;
        for(int i=0;nisizaki[i]=='M'||nisizaki[i]=='+'||nisizaki[i]=='-';i++){
        if(nisizaki[i]=='M'){po[k]=kariplus-kariminus;k++;}
        if(nisizaki[i]=='+')kariplus++;
        if(nisizaki[i]=='-')kariminus++;
        }
  qsort(( void * )po , emu , sizeof( po[0] ), int_sort );
    for(int i=0;i<emu;i++){
            if(left==0){right--;score+=(long long int)po[i];}
            else if(right==0){left--;score-=(long long int)po[i];}
            else if(po[i]>0){right--;score+=(long long int)po[i];}
            else if(po[i]<0){left--;score-=(long long int)po[i];}
    }
    printf("%lld\n",score);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",nisizaki);
     ^