int main(){
  
  int a, b, c;
  int cnt_5 = 0, cnt_7 = 0;
  
  scanf("%d%d%d", &a, &b, &c);

  if(a == 5){
    cnt_5++;
  }if(a == 7){
    cnt_7++;
  }if(b == 5){
    cnt_5++;
  }if(b == 7){
    cnt_7++;
  }if(c == 5){
    cnt_5++;
  }if(c == 7){
    cnt_7++;
  }

  if(cnt_5 == 2 && cnt_7 == 1){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d", &a, &b, &c);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:23:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("YES\n");
     ^
./Main.c:23:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:23:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:25:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("NO\n");
     ^
./Main.c:25:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’