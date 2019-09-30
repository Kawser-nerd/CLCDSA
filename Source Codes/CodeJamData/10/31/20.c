#include <stdio.h>
#include <stdlib.h>

int solve(int* a_wires, int* b_wires, int no) {
  int crosses = 0;
  int i,j;
  for(i=0;i<no;i++) {
    for(j=i+1;j<no;j++) {
      if (a_wires[i] > a_wires[j]) {
        if (b_wires[i] < b_wires[j]) {
          crosses++;
        }
      } else {
        if (b_wires[i] > b_wires[j]) {
          crosses++;
        }
      }
    }
  }
  return crosses;
}

int main() {
  int testcase;
  int wire_no;
  int i;

  while(scanf("%d\n", &testcase) == 1) {
    testcase = 1;
    while(scanf("%d\n", &wire_no) == 1) {
      int * a_wires = malloc(sizeof(int) * wire_no);
      int * b_wires = malloc(sizeof(int) * wire_no);
      for (i=0;i<wire_no;i++) {
        scanf("%d %d\n", &(a_wires[i]), &(b_wires[i]));
      }
      printf("Case #%d: %d\n", testcase, solve(a_wires,b_wires, wire_no));
      free(a_wires);
      free(b_wires);
      testcase++;
    }
  }
  return 0;
}
