#include <stdio.h>

int main() {
  char time_line[289];
  for (int i=0; i<289; i++) {
    time_line[i] = 0;
  }

  int line_count;
  scanf("%d", &line_count);
?for (int i=0; i<line_count; i++) {
    int start_time, end_time;
    scanf("%d-%d", &start_time, &end_time);
    
    int start_index, end_index;
    start_index = (start_time / 100) * 12 + (start_time % 100) / 5;
    end_index = (end_time / 100) * 12 + ((end_time + 4) % 100) / 5;

    for (int j=start_index; j<end_index; j++) {
      time_line[j] = 1;
    }
  }
  for (int i=0; i<289; i++) {
    if(time_line[i] == 1) {
      printf("%02d%02d-", (i / 12), (i % 12) * 5);
      while(time_line[i] != 0) {
        i++;
      }
      printf("%02d%02d\n", (i / 12), (i % 12) * 5);
    }
  }
} ./Main.cpp:11:1: warning: treating Unicode character as whitespace [-Wunicode-whitespace]
?for (int i=0; i<line_count; i++) {
^~
1 warning generated.