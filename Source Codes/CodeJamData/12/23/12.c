#include <stdio.h>
#include <assert.h>

unsigned int sum_masked(unsigned int arr[20], unsigned int mask) {
  unsigned int sum = 0;
  unsigned int i;
  for(i=0; i < 20; ++i) {
    sum += arr[i] * ((mask >> i) & 0x1);
  }
  return sum;
}

void print_masked(unsigned int arr[20], unsigned int mask) {
  unsigned int i;
  for(i=0; i < 20; ++i) {
    if(((mask >> i) & 0x1)) {
      printf("%u ",arr[i]);
    }
  }
  printf("\n");
  
}

void solve_array(int i, unsigned int arr[20]) {
  unsigned int bit_mask,bit_mask2;
  unsigned int top_sum;
  printf("Case #%d:\n",i);
  for(bit_mask = 1; bit_mask < (1<<21); bit_mask++) {
    top_sum = sum_masked(arr,bit_mask);
    for(bit_mask2 = bit_mask + 1; bit_mask2 < (1<<21); bit_mask2++) {
      if(top_sum == sum_masked(arr,bit_mask2 & (~bit_mask))) {
	print_masked(arr,bit_mask);
	print_masked(arr,bit_mask2 & (~bit_mask));
	return;
      }
    }
  }
  printf("impossible");
}

int main() {
  int num_cases;
  unsigned int arr[20];
  unsigned int num_elements;
  int i,j;
  scanf("%d",&num_cases);
  for(i=0;i<num_cases;++i) {
    scanf("%u",&num_elements);
    assert(num_elements == 20);
    for(j=0;j<20;++j) {
      scanf("%u",&arr[j]);
    }
    solve_array(i+1,arr);
  }
  return 0;
}
