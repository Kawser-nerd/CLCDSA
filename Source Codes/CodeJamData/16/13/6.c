#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

int bff[1001];

int in_circle[1001];
int chain[1001];
int amax_chain[1001];
int cpos[1001];
int is_chain_end[1001];

int main(void) {

  int max_is_link, k, f, curpos, i, t, T, n, N, max_circle, len, max, valid, max_chain, total_chain;

  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");

  fscanf(in,"%d",&T);
  
  for (t=1; t <= T; t++) {
    fscanf(in,"%d",&N);
    for (n=1; n <= N; ++n) {
      fscanf(in,"%d",bff + n);
      in_circle[n] = 0;
      is_chain_end[n] = 0;
    }
    // check for circles
    valid = N;
    max_circle = 0;
    for (n=1; n <= N; ++n) {
      if (in_circle[n]) continue;
      for (i=1; i <= N; ++i) {
        cpos[i] = 0;
      }
      curpos = 1;
      chain[1] = n;
      cpos[n] = 1;
      while (1) {
        f = bff[chain[curpos]];
        if (in_circle[f]) {
          for (i=1; i <= curpos; ++i) {
            valid--;
            assert(in_circle[chain[i]] == 0);
            in_circle[chain[i]] = 1;
          }
          break;
        }
        if (cpos[f] == 0) {
          curpos++;
          chain[curpos] = f;
          cpos[f] = curpos;
        } else if (cpos[f] == curpos - 1) {
          // chain (not a circle)
          break;
        } else {
          len = curpos - cpos[f] + 1;
          if (len > max_circle) max_circle = len;
          for (i=1; i <= curpos; ++i) {
            valid--;
            assert(in_circle[chain[i]] == 0);
            in_circle[chain[i]] = 1;
          }
          break;
        }
      }
    }
    total_chain = 0;
    while (valid) {
      max_chain = 0;
      max_is_link = 0;
      for (n=1; n <= N; ++n) {
        if (in_circle[n] || is_chain_end[n]) continue;
        for (i=1; i <= N; ++i) {
          cpos[i] = 0;
        }
        curpos = 1;
        chain[1] = n;
        cpos[n] = 1;
        while (1) {
          f = bff[chain[curpos]];
          if (in_circle[f]) {
            for (i=1; i <= curpos; ++i) {
              valid--;
              assert(in_circle[chain[i]] == 0);
              in_circle[chain[i]] = 1;
            }
            break;
          }
          if (is_chain_end[f]) {
            if (curpos > max_chain) {
              max_chain = curpos;
              for (i=1; i <= curpos; ++i) {
                amax_chain[i] = chain[i];
              }
            }
            max_is_link = 1;
            break;
          }
          if (cpos[f] == 0) {
            curpos++;
            chain[curpos] = f;
            cpos[f] = curpos;
          } else if (cpos[f] == curpos - 1) {
            if (curpos > max_chain) {
              max_chain = curpos;
              for (i=1; i <= curpos; ++i) {
                amax_chain[i] = chain[i];
              }
            }
            max_is_link = 0;
            break;
          } else {
            assert(0);
          }
        }
      }
      if (max_chain == 0) break;
      total_chain += max_chain;
      if (max_is_link == 0) {
        for (i=1; i <= max_chain; ++i) {
          valid--;
          assert(in_circle[amax_chain[i]] == 0);
          if (i == 1 || i == max_chain) {
            is_chain_end[amax_chain[i]] = 1;
          } else {
            in_circle[amax_chain[i]] = 1;
          }
        }
      } else {
        for (i=1; i <= max_chain; ++i) {
          valid--;
          assert(in_circle[amax_chain[i]] == 0);
          if (i == 1) {
            is_chain_end[amax_chain[i]] = 1;
          } else {
            in_circle[amax_chain[i]] = 1;
          }
        }
        is_chain_end[bff[amax_chain[max_chain]]] = 0;
      }
    }
    if (total_chain > max_circle) {
      max = total_chain;
    } else {
      max = max_circle;
    }
    fprintf(out, "Case #%d: %d\n", t, max);
  }

  fclose(in);
  fclose(out);
}