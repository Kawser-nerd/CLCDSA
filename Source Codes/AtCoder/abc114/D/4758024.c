#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000


bool prime_judge(int a){
  if((int)sqrt(a)<2){
    return true;
  }
  else{
    int flag=1;
    srep(i,2,(int)sqrt(a)+1){
      if(a%i==0){
        flag=0;
        break;
      }
    }
    if(flag==1){
      return true;
    }
    else{
      return false;
    }
  }
}

//N!???????a???
int prime_number(int a, int N){
  int temp=a;
  int count=0;
  while(temp<=N){
    count+=N/temp;
    temp=temp*a;
  }
  return count;
}


int main(){
  char buf[1024];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  int *prime=(int *)malloc(sizeof(int)*N);
  int element=0;
  srep(i,2,N+1){
    bool temp=prime_judge(i);
    if(temp==true){
      prime[element]=i;
      element++;
    }
    else{
      ;
    }
  }

  int *prime_n=(int *)malloc(sizeof(int)*N);
  rep(i,element){
    prime_n[i]=prime_number(prime[i], N);
  }

  // rep(i,element){
  //   printf("prime[%d] = %d\n", i, prime[i]);
  // }
  // rep(i,element){
  //   printf("prime_n[%d] = %d\n", i, prime_n[i]);
  // }


  int count=0;
  if(prime_n[0]>=74){
    count++;
  }

  int ncount_2=0;
  int ncount_4=0;
  int ncount_14=0;
  int ncount_24=0;
  rep(i,element){
    if(prime_n[i]>=2){
      ncount_2++;
    }
    if(prime_n[i]>=4){
      ncount_4++;
    }
    if(prime_n[i]>=14){
      ncount_14++;
    }
    if (prime_n[i]>=24){
      ncount_24++;
    }
  }

  // printf("ncount_2 = %d\n", ncount_2);
  // printf("ncount_4 = %d\n", ncount_4);
  // printf("ncount_14 = %d\n", ncount_14);
  // printf("ncount_24 = %d\n", ncount_24);

  count+=ncount_24*(ncount_2-1);
  count+=ncount_14*(ncount_4-1);
  if(ncount_4>1){
    count+=ncount_4*(ncount_4-1)*(ncount_2-2)/2;
  }

  printf("%d\n", count);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:55:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^