#include <cstdio>
#include <cstring>

int total, slen;
int hmuch[12];
char str[200];

void out_min(int len){
  while (len > total){
    printf("0");
    len--;
  }
  for (int i=1; i<=9; i++){
    for (int j=0; j<hmuch[i]; j++){
      printf("%d", i);
    }
  }
}

int is_desc(int fr){
  int i;
  for (i=fr+1; i<slen; i++){
    if (str[i] > str[i-1]) return 0;
  }
  return 1;
}



int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tn, t;
  scanf("%d\n", &tn);
  for (t=1; t<=tn; t++){
    gets(str);
    memset(hmuch, 0, sizeof(hmuch));
    total = 0;
    slen = 0;
    for (int i=0; (str[i]>='0' && str[i]<='9'); i++){
      hmuch[str[i]-'0']++;
      total += (str[i]>='1');
      slen++;
    }
    printf("Case #%d: ", t);
    if (is_desc(0)){
      int i;
      for (i=1; hmuch[i]==0; i++);
      printf("%d", i);
      hmuch[i]--;
      total--;
      out_min(slen);
    }
    else{
      int z;
      for (z=slen-2; is_desc(z); z--);
      for (int i=0; i<z; i++){
        hmuch[str[i]-'0']--;
        total--;
        printf("%c", str[i]);
      }
      int nd;
      for (nd=str[z]-'0'+1; hmuch[nd]==0; nd++);
      hmuch[nd]--;
      total--;
      printf("%d", nd);
      out_min(total+hmuch[0]);
    }
    printf("\n");
  }
  return 0;
}
