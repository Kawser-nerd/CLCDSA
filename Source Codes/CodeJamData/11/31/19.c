/*
 * Hirakendu Das, 20 May 2011, for Google Code Jam contest.
 * Problem X: XXX.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define VERBOSE_LEVEL_DEFAULT 1

#define max(x,y) ((x) > (y) ? (x) : (y))
#define abs(x) ((x) > 0? (x) : (-(x)))

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
  
  char grid[100][100], ch;
  int possible_flag, r, c, j;
  
  
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
    temp_i = fscanf(input_file_ptr, "%d %d", &r, &c);
    temp_i = fscanf(input_file_ptr, "%c", &ch);
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
	temp_i = fscanf(input_file_ptr, "%c", &grid[i][j]);
      }
      temp_i = fscanf(input_file_ptr, "%c", &ch);
    }
    if (verbose_level >= 3) {
      printf("    input:\n");
      for (i = 0; i < r; i++) {
	for (j = 0; j < c; j++) {
	   printf("%c", grid[i][j]);
	}
	printf("\n");
      }
    }
    /* 2. The algorithm and printing output. */
    possible_flag = 1;
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
	if (grid[i][j] == '#') {
	  if (((i + 1) < r) && ((j + 1) < c) && (grid[i + 1][j] == '#') && \
	    (grid[i][j + 1] == '#') && (grid[i + 1][j + 1] == '#')) {
	    grid[i][j] = grid[i + 1][j + 1] = '/';
	    grid[i + 1][j] = grid[i][j + 1] = '\\';
	  } else {
	    possible_flag = 0;
	    break;
	  }
	}
      }
      if (possible_flag == 0) {
	break;
      }
    }
    if (verbose_level >= 3) {
      printf("    input:\n");
      for (i = 0; i < r; i++) {
	for (j = 0; j < c; j++) {
	  printf("%c", grid[i][j]);
	}
	printf("\n");
      }
    }
    if (verbose_level >= 1) {
      if (possible_flag == 0) {
        printf("Impossible\n");
      } else {
	for (i = 0; i < r; i++) {
	  for (j = 0; j < c; j++) {
	    printf("%c", grid[i][j]);
	  }
	  printf("\n");
	}
      }
    }
    if (verbose_level >= 1) {
      printf("\n");
    }
    fprintf(output_file_ptr, "Case #%d:\n", case_id);
    if (possible_flag == 0) {
      fprintf(output_file_ptr, "Impossible\n");
    } else {
      for (i = 0; i < r; i++) {
	for (j = 0; j < c; j++) {
	  fprintf(output_file_ptr, "%c", grid[i][j]);
	}
	fprintf(output_file_ptr, "\n");
      }
    }
  }  /* End of case_id loop. */
  fclose(input_file_ptr);
  fclose(output_file_ptr);
  
  return 0;
}
