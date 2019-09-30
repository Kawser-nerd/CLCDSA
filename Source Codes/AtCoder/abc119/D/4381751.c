#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>

#define true 1
#define false 0

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)


//2??????

//???????? min, max??????????? n
int binary(long *array, int N, long k){
  int lb=0;
  int ub=N;
  //????????????????????
  while(ub-lb>1){
    int mid=(ub+lb)/2;
    if(k>=array[mid]){
      lb=mid;
    }
    else{
      ub=mid;
    }
  }
  //??????ub-lb==1
  //a[lb] <= k <= a[ub]???
  return lb;
}

long min(long a, long b){
  if(a>=b){
    return b;
  }
  else{
    return a;
  }
}


long shortest(long s, long t, long x){
  if(s-x>=0){
    if(t-x>=0){
      if(s>=t){
        return s-x;
      }
      else{
        return t-x;
      }
    }
    else{
      if(s-x>=x-t){
        return x-t+(s-t);
      }
      else{
        return s-x+(s-t);
      }
    }
  }
  else{
    if(t-x>=0){
      if(t-x>=x-s){
        return x-s+(t-s);
      }
      else{
        return t-x+(t-s);
      }
    }
    else{
      if(s>=t){
        return x-t;
      }
      else{
        return x-s;
      }
    }
  }
}


int main(){
  char buf[1024];
  int A, B, Q;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d %d", &A, &B, &Q);

  long *s=(long *)malloc(sizeof(long)*A);
  long *t=(long *)malloc(sizeof(long)*B);
  long *x=(long *)malloc(sizeof(long)*Q);

  rep(i,A){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%ld", &s[i]);
  }
  rep(i,B){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%ld", &t[i]);
  }
  rep(i,Q){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%ld", &x[i]);
  }


  rep(i,Q){
    int lbs=binary(s, A, x[i]);
    int lbt=binary(t, B, x[i]);
    long answer=10000000000;
    //printf("lbs = %d, lbt = %d\n", lbs, lbt);

    if(lbs==A-1){
      if(lbt==B-1){
        answer=shortest(s[lbs], t[lbt], x[i]);
        printf("%ld\n", answer);
      }
      else{
        rep(k,2){
          long temp=shortest(s[lbs], t[lbt+k], x[i]);
          answer=min(answer, temp);
        }
        printf("%ld\n", answer);
      }
    }
    else{
      if(lbt==B-1){
        rep(j,2){
          long temp=shortest(s[lbs+j], t[lbt], x[i]);
          answer=min(answer, temp);
        }
        printf("%ld\n", answer);
      }
      else{
        rep(j,2){
          rep(k,2){
            long temp=shortest(s[lbs+j], t[lbt+k], x[i]);
            answer=min(answer, temp);
          }
        }
        printf("%ld\n", answer);
      }
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:94:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:102:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^
./Main.c:106:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^
./Main.c:110:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^