#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 255
#define STEPS_UNIT 1000
#define MAX_KEYS 400

typedef struct {
  unsigned int open_chest;
  unsigned int num_having_keys;
  unsigned int *having_keys;
  unsigned int num_rest_chests;
  unsigned int *rest_chests;
} step_t;

typedef struct {
  unsigned int match_key;
  unsigned int num_contain_keys;
  unsigned int *contain_keys;
} chest_t;

void solver(unsigned int num_start_keys, unsigned int num_chests, unsigned int *keys, chest_t *chests);
int check_keys(unsigned int num_having_keys, unsigned int *having_keys, unsigned int num_rest_chests, unsigned int *rest_chests, chest_t *chests);
unsigned int try_next_step(unsigned int num_chests, chest_t *chests, unsigned int max_steps, unsigned int current_steps, step_t *steps);
step_t *realloc_steps(unsigned int *max_steps, step_t *steps);
void dump_problem(unsigned int num_start_keys, unsigned int num_chests, unsigned int *keys, chest_t *chests);

int main (int argc, char **argv)
{
  setvbuf(stdout, NULL, _IONBF, 0);
  if (argc != 2) {
    fprintf(stderr, "Input open is needed.\n");
    exit(EXIT_FAILURE);
  }
  FILE *fp;
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open problem file.\n");
    exit(EXIT_FAILURE);
  }
  unsigned int n = 0;
  int rtn;
  rtn = fscanf(fp, "%d", &n);

  unsigned int i, j, k;
  unsigned int keys[MAX_KEYS];
  unsigned int num_keys, num_chests;
  chest_t *chests;
  for (i = 1; i <= n; i++) {
    rtn = fscanf(fp, "%d %d", &num_keys, &num_chests);
    chests = (chest_t *)malloc(sizeof(chest_t) * (num_chests + 1));
    for (j = 0; j < num_keys; j++) {
      rtn = fscanf(fp, "%d", &keys[j]);
    }
    for (j = 1; j <= num_chests; j++) {
      rtn = fscanf(fp, "%d %d", &chests[j].match_key, &chests[j].num_contain_keys);
      chests[j].contain_keys = (unsigned int *)malloc(sizeof(unsigned int) * chests[j].num_contain_keys);
      for (k = 0; k < chests[j].num_contain_keys; k++) {
        rtn = fscanf(fp, "%d", &chests[j].contain_keys[k]);
      }
    }
    printf("Case #%d:", i);
    solver(num_keys, num_chests, keys, chests);
    for (j = 1; j <= num_chests; j++) {
      free(chests[j].contain_keys);
    }
    free(chests);
  }
  fclose(fp);
  return EXIT_SUCCESS;
}

void solver(unsigned int num_start_keys, unsigned int num_chests, unsigned int *keys, chest_t *chests)
{
  unsigned int max_steps = 0;
  unsigned int current_steps = 0;
  unsigned int i;
  step_t *steps = NULL;
  steps = (step_t *)malloc(sizeof(step_t) * (num_chests + 1));
//  steps = realloc_steps(&max_steps, steps);
  steps[0].open_chest = 0;
  steps[0].num_having_keys = num_start_keys;
  steps[0].having_keys = (unsigned int *)malloc(sizeof(unsigned int) * num_start_keys);
  for (i = 0; i < num_start_keys; i++) {
    steps[0].having_keys[i] = keys[i];
  }
  steps[0].num_rest_chests = num_chests;
  steps[0].rest_chests = (unsigned int *)malloc(sizeof(unsigned int) * num_chests);
  for (i = 1; i <= num_chests; i++) {
    steps[0].rest_chests[i - 1] = i;
  }
  current_steps++;
  if (check_keys(steps[0].num_having_keys, steps[0].having_keys, steps[0].num_rest_chests, steps[0].rest_chests, chests) == 0) {
      printf(" IMPOSSIBLE\n");
  } else {
    current_steps = try_next_step(num_chests, chests, max_steps, current_steps, steps);
    if (current_steps == 0) {
      printf(" IMPOSSIBLE\n");
    }
  }
  for (i = 0; i < current_steps; i++) {
    free(steps[i].having_keys);
    free(steps[i].rest_chests);
  }
  free(steps);
  return;
}
unsigned int try_next_step(unsigned int num_chests, chest_t *chests, unsigned int max_steps, unsigned int current_steps, step_t *steps)
{
  unsigned int i, j, k;
  unsigned int rtn;
//  if (current_steps == max_steps) {
//    steps = realloc_steps(&max_steps, steps);
//  }
  for (i = 0; i < steps[current_steps - 1].num_rest_chests; i++) {
    for (j = 0; j < steps[current_steps - 1].num_having_keys; j++) {
      if (chests[steps[current_steps - 1].rest_chests[i]].match_key == steps[current_steps - 1].having_keys[j]) {
        steps[current_steps].open_chest = steps[current_steps - 1].rest_chests[i];
        steps[current_steps].num_having_keys = steps[current_steps - 1].num_having_keys - 1 + chests[steps[current_steps].open_chest].num_contain_keys;
        steps[current_steps].having_keys = (unsigned int *)malloc(sizeof(unsigned int) * steps[current_steps].num_having_keys);
        for (k = 0; k < steps[current_steps - 1].num_having_keys; k++) {
          if (k < j) {
            steps[current_steps].having_keys[k] = steps[current_steps - 1].having_keys[k];
          } else if (k > j) {
            steps[current_steps].having_keys[k - 1] = steps[current_steps - 1].having_keys[k];
          }
        }
        for (k = steps[current_steps - 1].num_having_keys - 1; k < steps[current_steps].num_having_keys; k++) {
          steps[current_steps].having_keys[k] = chests[steps[current_steps].open_chest].contain_keys[k - steps[current_steps - 1].num_having_keys + 1];
        }
        steps[current_steps].num_rest_chests = steps[current_steps - 1].num_rest_chests - 1;
        steps[current_steps].rest_chests = (unsigned int *)malloc(sizeof(unsigned int) * steps[current_steps].num_rest_chests);
        for (k = 0; k < steps[current_steps - 1].num_rest_chests; k++) {
          if (k < i) {
            steps[current_steps].rest_chests[k] = steps[current_steps - 1].rest_chests[k];
          } else if (k > i) {
            steps[current_steps].rest_chests[k - 1] = steps[current_steps - 1].rest_chests[k];
          }
        }
        if (steps[current_steps].num_rest_chests == 0) {
          for (k = 1; k <= current_steps; k++) {
            printf(" %u", steps[k].open_chest);
          }
          printf("\n");
          return ++current_steps;
        }
        if (check_keys(steps[current_steps].num_having_keys, steps[current_steps].having_keys, steps[current_steps].num_rest_chests, steps[current_steps].rest_chests, chests) == 0) {
          free(steps[current_steps].having_keys);
          free(steps[current_steps].rest_chests);
        } else {
          current_steps++;
          rtn = try_next_step(num_chests, chests, max_steps, current_steps, steps);
          if (rtn > 0) {
            return rtn;
          } else {
            current_steps--;
            free(steps[current_steps].having_keys);
            free(steps[current_steps].rest_chests);
          }
        }
      }
    }
  }
  return 0;
}

step_t *realloc_steps(unsigned int *max_steps, step_t *steps)
{
  step_t *dummy;
  dummy = (step_t *)realloc(steps, sizeof(step_t) * (*max_steps + STEPS_UNIT));
  if (dummy == NULL) {
    fprintf(stderr, "Failed to realloc(steps: %u, size: %zu)\n", *max_steps + STEPS_UNIT, sizeof(step_t) * (*max_steps + STEPS_UNIT));
    exit(EXIT_FAILURE);
  }
  fprintf(stderr,"Succeeded realloc(steps: %u, size: %zu)\n", *max_steps + STEPS_UNIT, sizeof(step_t) * (*max_steps + STEPS_UNIT));
  steps = dummy;
  return steps;
}

int check_keys(unsigned int num_having_keys, unsigned int *having_keys, unsigned int num_rest_chests, unsigned int *rest_chests, chest_t *chests)
{
  unsigned int cnt_keys[MAX_KEYS];
  unsigned int max_key_idx = 0;

  unsigned int i, j;
  for (i = 0; i < MAX_KEYS; i++) {
    cnt_keys[i] = 0;
  }
  for (i = 0; i < num_having_keys; i++) {
    cnt_keys[having_keys[i]]++;
    if (max_key_idx < having_keys[i]) {
      max_key_idx = having_keys[i];
    }
  }
  for (i = 0; i < num_rest_chests; i++) {
    for (j = 0; j < chests[rest_chests[i]].num_contain_keys; j++) {
      cnt_keys[chests[rest_chests[i]].contain_keys[j]]++;
      if (max_key_idx < chests[rest_chests[i]].contain_keys[j]) {
        max_key_idx = chests[rest_chests[i]].contain_keys[j];
      }
    }
    if (max_key_idx < chests[rest_chests[i]].match_key) {
      max_key_idx = chests[rest_chests[i]].match_key;
    }
  }
  for (i = 0; i < num_rest_chests; i++) {
    if (cnt_keys[chests[rest_chests[i]].match_key] == 0) {
      return 0;
    }
    cnt_keys[chests[rest_chests[i]].match_key]--;
  }
  for (i = 1; i <= max_key_idx; i++) {
    cnt_keys[i] = 0;
  }
  for (i = 0; i < num_having_keys; i++) {
    cnt_keys[having_keys[i]]++;
  }
  for (i = 1; i <= max_key_idx; i++) {
    if (cnt_keys[i] == 0) {
      for (j = 0; j < num_rest_chests; j++) {
        if (chests[rest_chests[j]].match_key == i) {
          unsigned int k, l;
          unsigned int flag = 1;
          for (k = 0; k < num_rest_chests; k++) {
            if (j == k) continue;
            for (l = 0; l < chests[rest_chests[k]].num_contain_keys; l++) {
              if (chests[rest_chests[k]].contain_keys[l] == i) {
                flag = 0;
                break;
              }
            }
          }
          if (flag) return 0;
        }
      }
    }
  }
  return 1;
}

void dump_problem(unsigned int num_start_keys, unsigned int num_chests, unsigned int *keys, chest_t *chests)
{
  unsigned int i, j;
  printf("start keys:");
  for (i = 0; i < num_start_keys; i++) {
    printf(" %u", keys[i]);
  }
  printf("\n");
  for (i = 1; i <= num_chests; i++) {
    printf("#%u chest: match_key: %u\n", i, chests[i].match_key);
    printf("#%u chest: contain_keys:", i);
    for (j = 0; j < chests[i].num_contain_keys; j++) {
      printf(" %u", chests[i].contain_keys[j]);
    }
    printf("\n");
  }
}
