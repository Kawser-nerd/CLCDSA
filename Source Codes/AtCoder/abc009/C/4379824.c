#include<stdio.h>
#include<string.h>

char S[101];

int check(char *T, int N, int n, int m, int K){
  int i, len = 0, count[26] = {0}, count1[26] ={0}, sum = 0;
  char s[101], t[101];
  strcpy(t, T);
  if(S[n] != t[m]){
    K--;
  }
  for (i = m; i < N; i++){
    t[i] = t[i + 1];
  }
  for (i = n + 1; i <= N; i++){
    s[i - n - 1] = S[i];
  }
  
  while(s[len]){
    if(s[len] == 'a'){
      count[0]++;
    } else if(s[len] == 'b'){
      count[1]++;
    } else if(s[len] == 'c'){
      count[2]++;
    } else if(s[len] == 'd'){
      count[3]++;
    } else if(s[len] == 'e'){
      count[4]++;
    } else if(s[len] == 'f'){
      count[5]++;
    } else if(s[len] == 'g'){
      count[6]++;
    } else if(s[len] == 'h'){
      count[7]++;
    } else if(s[len] == 'i'){
      count[8]++;
    } else if(s[len] == 'j'){
      count[9]++;
    } else if(s[len] == 'k'){
      count[10]++;
    } else if(s[len] == 'l'){
      count[11]++;
    } else if(s[len] == 'm'){
      count[12]++;
    } else if(s[len] == 'n'){
      count[13]++;
    } else if(s[len] == 'o'){
      count[14]++;
    } else if(s[len] == 'p'){
      count[15]++;
    } else if(s[len] == 'q'){
      count[16]++;
    } else if(s[len] == 'r'){
      count[17]++;
    } else if(s[len] == 's'){
      count[18]++;
    } else if(s[len] == 't'){
      count[19]++;
    } else if(s[len] == 'u'){
      count[20]++;
    } else if(s[len] == 'v'){
      count[21]++;
    } else if(s[len] == 'w'){
      count[22]++;
    } else if(s[len] == 'x'){
      count[23]++;
    } else if(s[len] == 'y'){
      count[24]++;
    } else if(s[len] == 'z'){
      count[25]++;
    }
    len++;
  }
    
  len = 0;
    
  while(t[len]){
    if(t[len] == 'a'){
      count1[0]++;
    } else if(t[len] == 'b'){
      count1[1]++;
    } else if(t[len] == 'c'){
      count1[2]++;
    } else if(t[len] == 'd'){
      count1[3]++;
    } else if(t[len] == 'e'){
      count1[4]++;
    } else if(t[len] == 'f'){
      count1[5]++;
    } else if(t[len] == 'g'){
      count1[6]++;
    } else if(t[len] == 'h'){
      count1[7]++;
    } else if(t[len] == 'i'){
      count1[8]++;
    } else if(t[len] == 'j'){
      count1[9]++;
    } else if(t[len] == 'k'){
      count1[10]++;
    } else if(t[len] == 'l'){
      count1[11]++;
    } else if(t[len] == 'm'){
      count1[12]++;
    } else if(t[len] == 'n'){
      count1[13]++;
    } else if(t[len] == 'o'){
      count1[14]++;
    } else if(t[len] == 'p'){
      count1[15]++;
    } else if(t[len] == 'q'){
      count1[16]++;
    } else if(t[len] == 'r'){
      count1[17]++;
    } else if(t[len] == 's'){
      count1[18]++;
    } else if(t[len] == 't'){
      count1[19]++;
    } else if(t[len] == 'u'){
      count1[20]++;
    } else if(t[len] == 'v'){
      count1[21]++;
    } else if(t[len] == 'w'){
      count1[22]++;
    } else if(t[len] == 'x'){
      count1[23]++;
    } else if(t[len] == 'y'){
      count1[24]++;
    } else if(t[len] == 'z'){
      count1[25]++;
    }
    len++;
  }
  
  for (i = 0; i < 26; i++){
    if(count[i] < count1[i]){
      sum += count[i];
    } else {
      sum += count1[i];
    }
  }
  sum = N - n - 1 - sum;
  
  return K - sum;
}
  
 
int main(){
  int N, K, i, j, k;
  char T[101], t[101], u;
  
  scanf("%d %d", &N, &K);
  scanf("%s", S);
  
  strcpy(t, S);
  
  for (i = 1; i < N; i++){
    u = t[i];
    for (j = i - 1; j >= 0; j--){
      if(u < t[j]){
        t[j + 1] = t[j];
        if(j == 0){
          t[0] = u;
        }
      } else {
        t[j + 1] = u;
        break;
      }
    }
  }
  
  for (i = 0; i < N; i++){
    for (j = 0; j < N - i; j++){
      if(check(t, N, i, j, K) >= 0){
        if(S[i] != t[j]){
          K--;
        }
        T[i] = t[j];
        for (k = j; k < N; k++){
          t[k] = t[k + 1];
        }
        break;
      }
    }
  }
  T[i] = '\0';
  
  printf("%s\n", T);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:153:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^
./Main.c:154:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^