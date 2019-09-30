#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

#define MAX 201

int num_unique_chest_types;
int unique_chests[MAX];

int key_sources[MAX][MAX];

int num_chests_per_type[MAX];
int num_keys_per_type[MAX];

int chest_type[MAX];
int num_keys_per_chest[MAX];
int chest_keys[MAX][MAX];

int is_chest_open[MAX];
int current_key_count[MAX];
int closed_chest_count[MAX];
int sequence[MAX];


void reset() {
  num_unique_chest_types = 0;
  memset(num_chests_per_type,0,sizeof(int)*MAX);
  memset(num_keys_per_type,0,sizeof(int)*MAX);
  ////////////////////
  memset(current_key_count,0,sizeof(int)*MAX);
  memset(sequence,0,sizeof(int)*MAX);
  memset(is_chest_open,0,sizeof(int)*MAX);
  memset(closed_chest_count,0,sizeof(int)*MAX);
}

int can_open_chest(int c) {
  return ((is_chest_open[c]==0) && current_key_count[chest_type[c]]);
}

void open_chest(int c) {
  int i;
  if (c > 0) {
    assert(is_chest_open[c] == 0);
    is_chest_open[c] = 1;
    current_key_count[chest_type[c]]--;
    closed_chest_count[chest_type[c]]--;
  }
  for (i=1; i <= num_keys_per_chest[c]; i++) {
    current_key_count[chest_keys[c][i]]++;
  }
}

void close_chest(int c) {
  int i;
  assert(is_chest_open[c] == 1);
  is_chest_open[c] = 0;
  current_key_count[chest_type[c]]++;
  closed_chest_count[chest_type[c]]++;
  for (i=1; i <= num_keys_per_chest[c]; i++) {
    current_key_count[chest_keys[c][i]]--;
  }
}

int kshistory[MAX];
int kscount;
int key_search_recurse(int k) {
  int i,s;
  for (i=0; i < kscount; i++) {
    if (k==kshistory[i]) {
      return 0;
    }
  }
  kshistory[kscount] = k;
  kscount++;
  for (i=0; i < num_keys_per_type[k]; i++) {
    s = key_sources[k][i];
    if (can_open_chest(s)) {
      return 1;
    }
    if (!is_chest_open[s]) {
      if (key_search_recurse(chest_type[s])) {
        return 1;
      }
    }
  }
  return 0;
}
int key_search(int k) {
  kscount = 0;
  return key_search_recurse(k);
}


int main(void) {

  int T,t;
  int K;
  int N,n;
  int pos;
  int i;
  int val;
  int c;
  int impossible;
  int deadend;
  
  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");
  
  fscanf(in,"%d\n",&T);

  for (t=1; t <= T; t++) {
    reset();
    fscanf(in,"%d\n",&K);
    fscanf(in,"%d\n",&N);
    for (n=0; n <= N; n++) {
      if (n > 0) {
        fscanf(in,"%d\n",&val);
        chest_type[n] = val;
        if (num_chests_per_type[val]==0) {
          unique_chests[num_unique_chest_types] = val;
          num_unique_chest_types++;
        }
        num_chests_per_type[val]++;
        closed_chest_count[val]++;
      }
      if (n==0) {
        num_keys_per_chest[0] = K; // chest[0] stores the inital (free) keys
      } else {
        fscanf(in,"%d\n",&num_keys_per_chest[n]);
      }
      for (i=1; i <= num_keys_per_chest[n]; i++) {
        fscanf(in,"%d\n",&val);
        chest_keys[n][i] = val;
        key_sources[val][num_keys_per_type[val]] = n;
        num_keys_per_type[val]++;
      }
    }

    open_chest(0);

    //check for simple impossible
    impossible = 0;
    for (i=0; i< num_unique_chest_types; i++) {
      c = unique_chests[i];
      if (num_keys_per_type[c] < num_chests_per_type[c]) {
        impossible = 1;
        break;
      }
      if (current_key_count[c] == 0) {
        if (key_search(c)==0) {
          impossible = 1;
          break;
        }
      }
    }

    if (!impossible) {
      pos = 0;
      while (pos < N) {
        // next possible chest
        sequence[pos] += 1;
        c = sequence[pos];

        if (c > N) { // dead end -- backtrack
          if (pos==0) {
            impossible = 1;
            break;
          }
          pos--;
          close_chest(sequence[pos]);
        } else if (can_open_chest(c)) {
          open_chest(c);
          deadend = 0;
          if (closed_chest_count[chest_type[c]] && (current_key_count[chest_type[c]]==0)) { // dead end?
            if (key_search(chest_type[c])==0) {
              deadend = 1;
            }
          }
          if (deadend) {
            close_chest(c);
          } else {
            pos++;
            sequence[pos] = 0;
          }
        }
      }
    }
    if (impossible) {
      fprintf(out,"Case #%d: IMPOSSIBLE\n", t);
    } else {
      assert(pos == N);
      fprintf(out,"Case #%d:", t);
      for (n=0; n < N; n++) {
        fprintf(out," %d",sequence[n]);
      }
      fprintf(out,"\n");
    }
    fflush(out);
  }
  fclose(in);
  fclose(out);
}
