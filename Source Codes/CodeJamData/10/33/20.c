
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { false = 0, true  = 1 } bool;
typedef unsigned char uchar;
typedef unsigned long ulong;

typedef enum {
  bark_black_free   = 0x00,
  bark_white_free   = 0x01,
  bark_black_used   = 0x02,
  bark_white_used   = 0x03,
  bark_color_mask   = 0x01,
  bark_used_mask    = 0x02,
  bark_color_black  = 0x00,
  bark_color_white  = 0x01,
  bark_used_free    = 0x00,
  bark_used_used    = 0x02 
} BARK_VALUES;

typedef struct {
  uchar *bark;
  ulong width;
  ulong height;
} BARKMAP;

bool  verbose = false;

#define IS_OPPOSITE_AND_FREE(val, oppo) (((val & bark_color_mask) != (oppo & bark_color_mask)) && ((val & bark_used_mask) == bark_used_free))
#define IS_SAME_OR_USED(val, match) (((val & bark_color_mask) == (match & bark_color_mask)) || ((val & bark_used_mask) == bark_used_used))
#define IS_USED(val) ((val & bark_used_mask) == bark_used_used)
#define BARK_COLOR(val) (val & bark_color_mask)

int getn(FILE *input) {
  char  buffer[256];
  int   pos = 0;
  short c;
  
  memset(buffer, 0, 256);
  
  while ((((c = fgetc(input)) != EOF) && (c != ' ')) && c != '\n') {
    buffer[pos++] = c;
  }
  return atoi(buffer);
}

void setmap(BARKMAP *bm, ulong x, ulong y, uchar vals) {
  bm->bark[x + 0 + y * bm->width] = ((vals & 0x08) >> 3);
  bm->bark[x + 1 + y * bm->width] = ((vals & 0x04) >> 2);
  bm->bark[x + 2 + y * bm->width] = ((vals & 0x02) >> 1);
  bm->bark[x + 3 + y * bm->width] = ((vals & 0x01) >> 0);
}

void getmap(FILE *input, BARKMAP *bm) {
  int x, y;
  short c;
  char debug[2] = { 0, 0 };
  for (y = 0; y < bm->height; y++) {
    for (x = 0; x < (bm->width / 4); x++) {
      c = fgetc(input);
      if ((c >= '0') && (c <= '9')) {
        setmap(bm, x * 4, y, c - '0');
      } else if ((c >= 'A') && (c <= 'F')) {
        setmap(bm, x * 4, y, c - 'A' + 10);
      }
    }
    c = fgetc(input);
  }
}

void printmap(BARKMAP *bm) {
  int x, y;
  char output[2] = { 0, 0 };
  for (y = 0; y < bm->height; y++) {
    for (x = 0; x < bm->width; x++) {
      output[0] = (bm->bark[x + y * bm->width] & bark_color_mask)
                ? ((bm->bark[x + y * bm->width] & bark_used_mask)
                    ? 'X'
                    : 'x')
                : ((bm->bark[x + y * bm->width] & bark_used_mask)
                    ? '_'
                    : '.');
      printf(output);
    }
    printf("\n");
  }
}

bool find_square(BARKMAP *bm, ulong x, ulong y, ulong size) {
  int ix, iy;
  uchar b, bx, by;
    
  // check used flags
  for (ix = x; ix < (x + size); ix++) {
    for (iy = y; iy < (y + size); iy++) {
      if (bm->bark[ix + iy * bm->width] & bark_used_mask) return false;
    }
  }
  // check color consistency
  for (ix = x; ix < (x + size); ix++) {
    for (iy = y; iy < (y + size); iy++) {
      b = bm->bark[ix + iy * bm->width];
      if (ix > x) {
        bx = bm->bark[(ix - 1) + (iy * bm->width)];
        if (b == bx) return false;
      }
      if (iy > y) {
        by = bm->bark[ix + ((iy - 1) * bm->width)];
        if (b == by) return false;
      }
    }
  }
  // mark squares as used
  for (ix = x; ix < (x + size); ix++) {
    for (iy = y; iy < (y + size); iy++) {
      bm->bark[ix + iy * bm->width] |= bark_used_used;
    }
  }
  // success
  return true;
}

int main(int argc, char *argv[]) {  
  if ((argc < 2) || (argc > 3)) {
    printf("Input file required. Usage: %s filename [--verbose]\n", argv[0]);
    return 0;
  }
  if (argc == 3) {
    if (strcmp(argv[2], "--verbose") == 0) {
      verbose = true;
    } else {
      printf("Unknown option: %s\n", argv[2]);
    }
  }
  
  FILE *input;
  FILE *output;
  char  outfile[256]  = "";
  int   i;
  
  input = fopen(argv[1], "r");
  
  strcpy(outfile, argv[1]);
  i = (ulong)strrchr(outfile, '.') - (ulong)outfile;
  outfile[i + 1] = 'o';
  outfile[i + 2] = 'u';
  outfile[i + 3] = 't';
  output = fopen(outfile, "w");
  
  char  outdata[2048]   = "";
  char  outbuffer[1024] = "";
  int   n_cases = 0;
  
  n_cases = getn(input);
  
  // case testing here
    // variables
  BARKMAP   bm;
  int       max_size, size, ix, iy;
  ulong    *sizes;
  ulong     size_count;
  
  for (i = 0; i < n_cases; i++) {
    // read input
    bm.height = getn(input);
    bm.width  = getn(input);
    bm.bark   = malloc(bm.width * bm.height);
    getmap(input, &bm);
    if (verbose) printmap(&bm);
    
    // process data
    if (bm.height < bm.width) {
      max_size = bm.height;
    } else {
      max_size = bm.width;
    }
    sizes = malloc(max_size * sizeof(ulong));
    memset(sizes, 0, max_size * sizeof(ulong));
       
      // try biggest squares first
    for (size = max_size; size > 0; size--) {
      //if (verbose) printf("Checking size %i...\n", size);
        for (iy = 0; iy <= (bm.height - size); iy++) {
      for (ix = 0; ix <= (bm.width - size); ix++) {
          //if (verbose) printf("  %i, %i  ", ix, iy);
          if (find_square(&bm, ix, iy, size)) {
            sizes[size - 1]++;
            //if (verbose) printf("Yes\n");
          } else {
            //if (verbose) printf("No\n");
          }
          //if (verbose) printmap(&bm);
        }
      }
      if (verbose) {
        printf("Size %i:\n", size);
        printmap(&bm);
      }
    }
      // count separate sizes
    size_count = 0;
    for (size = 0; size < max_size; size++) {
      if (sizes[size]) size_count++;
    }
    
    free(bm.bark);
    
    // write output    
    sprintf(outdata, "Case #%i: %i\n", i + 1, size_count);
    for (size = max_size; size > 0; size--) {
      if (sizes[size - 1]) {
        sprintf(outbuffer, "%i %i\n", size, sizes[size - 1]);
        strcat(outdata, outbuffer);
      }
    }
    printf(outdata);
    fprintf(output, outdata);
    free(sizes);
  }
 
  fclose(input); 
  fclose(output); 
  return 0;
}
