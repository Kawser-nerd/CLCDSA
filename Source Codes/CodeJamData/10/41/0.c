#include <stdio.h>

int i, T, k;
int x[51][51];
int c1, c2, d1, d2;
int add_amount, left, right, top, bottom;
int valid;

int check(int c1, int c2, int d1, int d2){
  if (d1 < 0) return 1;
  if (d1 >= k) return 1;
  if (d2 < 0) return 1;
  if (d2 >= k) return 1;
  return (x[c1][c2] == x[d1][d2]) ? 1 : 0;
}

int main(){
  scanf("%d", &T);
  for (i = 1; i <= T; ++i){
    printf("Case #%d: ", i);
    scanf("%d", &k);
    c1 = 0;
    c2 = 0;
    while (c1 + c2 < (2 * k - 1)){
      scanf("%d", &x[c1][c2]);
      if ((c1 + c2 + 1 < k)){
	if (c2 == 0){
	  c2 = c1 + 1; c1 = 0;
	} else {
	  ++c1; --c2;
	}
      } else {
	if (c1 == k - 1){
	  c1 = c2 + 1; c2 = k - 1;
	} else {
	  ++c1; --c2;
	}
      }
    }
    if (0){
    printf("\n");
    for (c1 = 0; c1 < k; ++c1){
      for (c2 = 0; c2 < k; ++c2)
	printf("%d", x[c1][c2]);
      printf("\n");
    }
    }
    valid = 0;
    for (add_amount = 0; !valid && (add_amount <= (2 * k - 2)); ++add_amount){
      for (left = 0; !valid && (left <= add_amount); ++left){
	right = add_amount - left;
	// WLOG left, right, top or bottom = 0, methinks...
	for (top = 0; !valid && (top <= add_amount); ++top){
	  bottom = add_amount - top;
	  if ((left != 0) && (right != 0) && (bottom != 0) && (top != 0))
	    continue;
	  valid = 1;
	  for (c1 = 0; valid && (c1 < k); ++c1){
	    for (c2 = 0; valid && (c2 < k); ++c2){
	      valid = check(c1, c2, (c2 + top) - left, (c1 + left) - top)
		* check(c1, c2, (k-1) + add_amount - c1 - (2 * left),
			 (k-1) + add_amount - c2 - (2 * top))
		* check(c1, c2, (k-1) + add_amount - c2 - top - left,
			 (k-1) + add_amount - c1 - top - left);
	    }
	  }
	}
      }
      if (0 && valid){
	--top; --left;
	for (c1 = 0; c1 < top; ++c1){
	  for (c2 = 0; c2 < (k + add_amount); ++c2){
	    printf(".");
	  }
	  printf("\n");
	}
	for (c1 = 0; c1 < k; ++c1){
	  for (c2 = 0; c2 < left; ++c2)
	    printf(".");
	  for (c2 = 0; c2 < k; ++c2)
	    printf("%d", x[c1][c2]);
	  for (c2 = 0; c2 < right; ++c2)
	    printf(".");
	  printf("\n");
	}
	for (c1 = 0; c1 < bottom; ++c1){
	  for (c2 = 0; c2 < (k + add_amount); ++c2){
	    printf(".");
	  }
	  printf("\n");
	}
      }
      if (valid)
	printf("%d\n", (2*k+add_amount)*add_amount);
    }
  }
}
