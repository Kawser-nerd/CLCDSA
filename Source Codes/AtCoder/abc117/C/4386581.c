#include <stdio.h>
#include <math.h>

int swap(int *a, int *b){
  int x = a[0];
  a[0] = b[0];
  b[0] = x;
}

void quick_a(int *s, int m){
  int i, j, k=1, p=1;
  int a = s[0];
  for(; k<m; k++){
    if(a < s[k]){
      a = s[k];
      p = k;
      break;
    }else if(a > s[k]){
      p = k-1;
      break;
    }else if(k+1==m){
      break;
    }
  }
  if(k<m-1){
    i = p;
    j = m-1;
    do{
      while(s[i]< a && i!=j){
        i++;
      }
      if(i==j)    {break; }
      while(s[j]>=a && i!=j){
        j--;
      }
      if(i==j)    {break; }
      if(s[i]>s[j]){
        swap(&s[i], &s[j]);
      }
    }while(i+1!=j);
    quick_a(&s[0],   j);
    quick_a(&s[j], m-j);
  }else if(p==k-1 && s[0]>s[k]){
    swap(&s[0], &s[k]);
  }
}

void quick_d(int *s, int m){
  int i, j, k=1, p=1;
  int a = s[0];
  for(; k<m; k++){
    if(a > s[k]){
      a = s[k];
      p = k;
      break;
    }else if(a < s[k]){
      p = k-1;
      break;
    }else if(k+1==m){
      break;
    }
  }
  if(k<m-1){
    i = p;
    j = m-1;
    do{
      while(s[i]> a && i!=j){
        i++;
      }
      if(i==j)    {break; }
      while(s[j]<=a && i!=j){
        j--;
      }
      if(i==j)    {break; }
      if(s[i]<s[j]){
        swap(&s[i], &s[j]);
      }
    }while(i+1!=j);
    quick_d(&s[0],   j);
    quick_d(&s[j], m-j);
  }else if(p==k-1 && s[0]<s[k]){
    swap(&s[0], &s[k]);
  }
}

int main(void){
  int n, m, i, j;
  scanf("%d %d", &n, &m);
  int x[m];
  for(i=0; i<m; i++){
    scanf("%d", &x[i]);
  }

  if(n>=m){
    printf("0\n");
  }else{
    quick_a(&x[0], m);
    int s[m-1];
    for(i=0; i<m-1; i++){
      s[i] = x[i+1]-x[i];
    }
    quick_d(&s[0], m-1);
    int sum = 0;
    for(i=0; i<n-1; i++){
      sum += s[i];
    }
    printf("%d", x[m-1]-x[0]-sum);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:88:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:91:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x[i]);
     ^