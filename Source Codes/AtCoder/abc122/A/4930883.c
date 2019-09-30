#include <stdio.h>

int main(){
  char input_data, output_data[128];
  output_data['A'] = 'T';
  output_data['G'] = 'C';
  output_data['C'] = 'G';
  output_data['T'] = 'A';

  scanf("%c", &input_data);

  printf("%c\n", output_data[input_data]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", &input_data);
   ^