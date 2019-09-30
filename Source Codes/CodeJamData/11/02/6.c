#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *readFile(char *name) {

  FILE *inputFile;
  long fileLen;
  long readLen;
  char *stringFile;

  /* Open file */
  inputFile = fopen(name, "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Error opening %s: %s (%u)\n", name, strerror(errno), errno);
    return NULL;
  }
  
  /* Get length */
  fseek(inputFile, 0L, SEEK_END);
  fileLen = ftell(inputFile);
  rewind(inputFile);

  stringFile = (char *) malloc(sizeof(char) * fileLen);

  /* Read in file */
  if ((readLen = fread(stringFile, 1, fileLen, inputFile)) != fileLen) {
    fprintf(stderr, "Read %ld of %ld\n", readLen, fileLen);
    fclose(inputFile);
    return NULL;
  }

  fclose(inputFile);
  return stringFile;

}

char *lineReturn(char *file) {

  static int position = 0;
  static int start;

  start = position;

  /* Look for end of line or end of file */
  while (file[position] != '\n' && file[position] != 0) {
    position++;
  }

  /* Replace newline with null to end string */
  if (file[position] == '\n') {
    file[position] = 0;
    position++;
    return file + start;
  }

  else
    return NULL;

}

void print(char *letters, int len, int count) {
  int i;

  printf("Case #%d: [", count);
  for (i = 0; i < len; i++) {
    if (i >= 1)
      printf(", ");
    printf("%c", letters[i]);
  }
  printf("]\n");
}

void solve(char *line, int num) {

  int len1 = 0;
  int len2 = 0;
  int len3 = 0;

  int iter;
  int iter2;

  int count;

  int cur_position = 0;

  char array1[36*3];
  char array2[28*2];
  char array3[100];

  char combine1[26];
  char combine2[26];
  char opposite1[26];
  char opposite2[26];

  int pos = 0;

  while (line[cur_position] >= '0' && line[cur_position] <= '9') {
    len1 *= 10;
    len1 += line[cur_position] - '0';
    cur_position += 1;
  }
  cur_position += 1;

  count = 0;
  pos = 0;
  while(count < len1) {
    array1[pos] = line[cur_position++];
    combine1[(int)array1[pos++]-'A'] = 1;
    array1[pos] = line[cur_position++];
    combine2[(int)array1[pos++]-'A'] = 1;
    array1[pos++] = line[cur_position++];

    cur_position += 1;
    count += 1;    
  }

  while (line[cur_position] >= '0' && line[cur_position] <= '9') {
    len2 *= 10;
    len2 += line[cur_position] - '0';
    cur_position += 1;
  }
  cur_position += 1;

  count = 0;
  pos = 0;
  while(count < len2) {
    array2[pos] = line[cur_position++];
    opposite1[(int)array2[pos++]-'A'] = 1;
    array2[pos] = line[cur_position++];
    opposite2[(int)array2[pos++]-'A'] = 1;

    cur_position += 1;
    count += 1;    
  }

  while (line[cur_position] >= '0' && line[cur_position] <= '9') {
    len3 *= 10;
    len3 += line[cur_position] - '0';
    cur_position += 1;
  }
  cur_position += 1;

  count = 0;
  pos = 0;
  while(count < len3) {
    array3[pos++] = line[cur_position++];

    /* Check for combine */
    if (pos >= 2) {
      char done = 0;
      while (!done) {
	done = 1;
	if (combine1[(int)array3[pos-2]-'A'] && combine2[(int)array3[pos-1]-'A']) {
	  for (iter = 0; iter < (len1 * 3); iter += 3) {
	    if (array1[iter] == array3[pos-2] && array1[iter+1] == array3[pos-1]) {
	      pos--;
	      array3[pos-1] = array1[iter+2];
	      done = 0;
	      break;
	    }	    
	  }
	}
	
	if (combine2[(int)array3[pos-2]-'A'] && combine1[(int)array3[pos-1]-'A']) {
	  for (iter = 0; iter < (len1 * 3); iter += 3) {
	    if (array1[iter] == array3[pos-1] && array1[iter+1] == array3[pos-2]) {
	      pos--;
	      array3[pos-1] = array1[iter+2];
	      done = 0;
	      break;
	    }	    
	  }
	}
      }
    }

    /* Check for opposite */
    if (pos >= 2) {
      if (opposite1[(int)array3[pos-1]-'A']) {
	for (iter = 0; iter < (len2 * 2); iter += 2) {
	  if (array3[pos-1] == array2[iter]) {
	    for (iter2 = 0; iter2 < pos-1; iter2++) {
	      if (array3[iter2] == array2[iter+1]) {
		pos = 0;
		break;
	      }
	    }
	  }
	  if (!pos)
	    break;
	}
      }
      if (opposite2[(int)array3[pos-1]-'A'] && pos > 0) {
	for (iter = 1; iter < (len2 * 2); iter += 2) {
	  if (array3[pos-1] == array2[iter]) {
	    for (iter2 = 0; iter2 < pos-1; iter2++) {
	      if (array3[iter2] == array2[iter-1]) {
		pos = 0;
		break;
	      }
	    }
	  }
	  if (!pos)
	    break;
	}
      }
    }
      
    count += 1;    
  }
  print(array3, pos, num);
}

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr ,"Usage: <input file name>\n");
    return 1;
  }

  char *stringFile;
  char *line;
  int count = 0;

  /* Read in file */
  stringFile = readFile(argv[1]);
  if (stringFile == NULL) {
    fprintf(stderr ,"File error\n");
    return 1;
  }

  /* Go through lines */
  line = lineReturn(stringFile);
  count += 1;
  while((line = lineReturn(stringFile)) != NULL) {

    // CALL CODE HERE
    solve(line, count);
    count += 1;
  }

  free(stringFile);

  return 0;

}


  

  

  


