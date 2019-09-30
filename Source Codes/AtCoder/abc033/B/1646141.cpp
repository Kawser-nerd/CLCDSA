#include <cstdio>
#include <cstring>

int main(){
  
  int n;
  int p[1000];
  char s[1000][30];

  int sum = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s %d", s[i], &p[i]);
    sum += p[i];
  }

  char name[31] = "atcoder";
  for(int i = 0; i < n; i++){
    if(p[i] > sum / 2){
      strcpy(name, s[i]);
    }
  }

  printf("%s\n", name);

  return 0;
}