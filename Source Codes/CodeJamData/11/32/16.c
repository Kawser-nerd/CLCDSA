/*
 * Hirakendu Das, 20 May 2011, for Google Code Jam contest.
 * Problem X: XXX.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "helper_funcs.h"

#define VERBOSE_LEVEL_DEFAULT 1

#define max(x,y) ((x) > (y) ? (x) : (y))
#define abs(x) ((x) > 0? (x) : (-(x)))
#define min(x,y) ((x) < (y) ? (x) : (y))

int main(int argc, char *argv[])
{
  int i, temp_i;
  FILE *input_file_ptr, *output_file_ptr;
  int verbose_level = VERBOSE_LEVEL_DEFAULT;
  char *input_file_name_default = "input.txt";
  char *input_file_name = NULL;
  char *output_file_name_default = "output.txt";
  char *output_file_name = NULL;
  int num_cases, case_id;
  
  long l, t, n, c, dist_b4_boost, sum_dist, nn, j, fast_dist, tot_time;
  int a[2000], d[2000], rd[2000];
  
  
  /* Parse commandline arguments. */
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
      input_file_name = argv[++i];
    } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
      output_file_name = argv[++i];
    } else if (strcmp(argv[i], "-v") == 0) {
      verbose_level = atoi(argv[++i]);
    } else {
      printf("Error parsing arguments!\n");
      printf("Usage: template.bin -i <input_file_name> -o <output_file_name>");
      printf("  -v <verbose_level>\n");
      return 0;
    }
  }
  if (input_file_name == NULL) {
    input_file_name = input_file_name_default;
  }
  if (output_file_name == NULL) {
    output_file_name = output_file_name_default;
  }
  
  /* Parse input file and run the algorithm. */
  input_file_ptr = fopen(input_file_name, "r");
  if (input_file_ptr == NULL) {
    printf("Error opening input file.\n");
    return 0;
  }
  output_file_ptr = fopen(output_file_name, "w");
  if (input_file_ptr == NULL) {
    printf("Error opening output file.\n");
    return 0;
  }
  temp_i = fscanf(input_file_ptr, "%d", &num_cases);
  if (verbose_level >= 2) {
    printf("  Number of test cases: %d\n", num_cases);
  }
  for (case_id = 1; case_id <= num_cases; case_id++) {
    if (verbose_level >= 1) {
      printf("  Case #%d: ", case_id);
    }
    /* A particular test case. */
    /* Get the input. */
    temp_i = fscanf(input_file_ptr, "%ld %ld %ld %ld", &l, &t, &n, &c);
    for (i = 0; i < c; i++) {
      temp_i = fscanf(input_file_ptr, "%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
      d[i] = a[i % c];
    }
    if (verbose_level >= 3) {
      printf("d = ");
      for (i = 0; i < n; i++) {
	printf(" %d", d[i]);
      }
      printf("\n");
    }
    /* 2. The algorithm and printing output. */
    dist_b4_boost = 0.5 * t;
    sum_dist = 0;
    for (i = 0; i < n; i++) {
      sum_dist += d[i];
      if (sum_dist > dist_b4_boost) {
	break;
      }
    }
    nn = n - i;
    rd[0] = sum_dist - dist_b4_boost;
    j = 1;
    for (i = i + 1; i < n; i++) {
      rd[j] = d[i];
      j++;
    }
    merge_sort_i(rd, nn);
    if (verbose_level >= 3) {
      printf(" rd = ");
      for (i = 0; i < nn; i++) {
	printf(" %d", rd[i]);
      }
      printf("\n");
    }
    fast_dist = 0;
    for (i = 0; i < min(l,nn); i++) {
      fast_dist += rd[i];
    }
    printf("fast_dist = %ld\n", fast_dist);
    sum_dist = 0;
    for (i = 0; i < n; i++) {
      sum_dist += d[i];
    }
    printf("sum_dist = %ld\n", sum_dist);
    tot_time = sum_dist * 2 - fast_dist;
    printf("tot_time = %ld\n", tot_time);
    if (verbose_level >= 1) {
      printf("\n");
    }
    fprintf(output_file_ptr, "Case #%d: %ld\n", case_id, tot_time);
  }  /* End of case_id loop. */
  fclose(input_file_ptr);
  fclose(output_file_ptr);
  
  return 0;
}
