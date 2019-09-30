#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUF_SIZE 0x100
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

uint16_t buf[BUF_SIZE];

int can_be_group(int selector, int num_node)
{
  for(int i = 0; i < num_node; i++) {
    if(selector & (1 << i)) {
      if((selector & buf[i]) != selector) {
        return 0;
      }
    }
  }
  return 1;
}

int count_bits(uint16_t ch)
{
  int cnt = 0;
  for(int i = 0; i < 16; i++) {
    if(ch & (1 << i)) {
      cnt++;
    }
  }
  return cnt;
}

char bit_char(uint16_t ch, int i)
{
  if(ch & (1 << i)) {
    return '1';
  } else {
    return '0';
  }
}

void print_in_bits(uint16_t ch)
{
  for(int i = 0; i < 16; i++) {
    putchar(bit_char(ch, i));
  }
  putchar('\n');
}

void debug_print(const uint16_t* array, size_t size)
{
  for(size_t i = 0; i < size; i++) {
    print_in_bits(array[i]);
  }
}

int main()
{
  int num_node, num_edge;
  scanf("%d%d", &num_node, &num_edge);

  memset(buf, 0, sizeof(buf));
  for(int i = 0; i < num_node; i++) {
    buf[i] = 1 << i;
  }

  for(int i = 0; i < num_edge; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    buf[a-1] |= 1 << (b-1);
    buf[b-1] |= 1 << (a-1);
  }

  int result = 0;
  for(int i = 1; i < (1 << num_node); i++) {
    if(can_be_group(i, num_node)) {
      result = max(result, count_bits(i));
    }
  }

  //debug_print(buf, num_node);
  printf("%d\n", result);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:62:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &num_node, &num_edge);
   ^
./Main.c:71:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^