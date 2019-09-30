#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 0x10
#define EXPR_BUF_SIZE (BUF_SIZE*2)

int toint(char ch)
{
  return ch - '0';
}

void print_expr(const char* buf)
{
  for(size_t i = 0; i < strlen(buf); i += 2) {
    putchar(buf[i]);
    switch(buf[i+1]) {
      case ' ':
        break;
      case '+':
        putchar('+');
        break;
      case '\0':
        putchar('\n');
        break;
    }
  }
}

long long eval_expr(const char* buf)
{
  long long tmp = 0;
  long long total = 0;
  for(size_t i = 0; i < strlen(buf); i += 2) {
    if(buf[i+1] == ' ') {
      tmp = 10 * (tmp + toint(buf[i]));
      continue;
    } else if(buf[i+1] == '+' || buf[i+1] == '\0') {
      total += tmp + toint(buf[i]);
      tmp = 0;
    } else {
      fprintf(stderr, "eval: Unknown operator found: %c\n", buf[i+1]);
      exit(1);
    }
  }
  if(tmp != 0) {
    fprintf(stderr, "Invalid expression found: %s\n", buf);
    exit(1);
  }
  //print_expr(buf);
  //printf("%lld\n", total);
  return total;
}

int next_expr(char* buf)
{
  for(size_t i = 1; i < strlen(buf); i += 2) {
    if(buf[i] == ' ') {
      buf[i] = '+';
      return 0;
    } else if(buf[i] == '+') {
      buf[i] = ' ';
      continue;
    } else {
      fprintf(stderr, "next: Unknown operator found: %c\n", buf[i]);
      exit(1);
    }
  }
  return 1;
}

int main()
{
  char buf[BUF_SIZE];
  fgets(buf, sizeof(buf), stdin);
  // delete LF
  buf[strlen(buf)-1] = '\0';

  char expr_buf[EXPR_BUF_SIZE];
  memset(expr_buf, 0, sizeof(expr_buf));
  for(size_t i = 0; i < strlen(buf); i++) {
    expr_buf[2*i] = buf[i];
    expr_buf[2*i+1] = ' ';
  }
  // delete last operator
  expr_buf[strlen(expr_buf)-1] = '\0';

  uint64_t total = eval_expr(expr_buf);
  while(!next_expr(expr_buf)) {
    total += eval_expr(expr_buf);
  }
  printf("%" PRIu64 "\n", total);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:76:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf, sizeof(buf), stdin);
   ^