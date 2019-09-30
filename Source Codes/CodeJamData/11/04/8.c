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

int outOfPosition(char *line, int width) {

  int cur_value = 0;
  int cur_position = 0;
  int count = 0;
  int outs = 0;

  while(count < width) {
    cur_value = 0;
    while(line[cur_position] >= '0' && line[cur_position] <= '9') {
      cur_value = cur_value * 10;
      cur_value = cur_value + line[cur_position] - '0';
      cur_position += 1;
    }
    if (cur_value != (count + 1))
      outs++;
    count += 1;
    cur_position += 1;
  }

  return outs;

}

void solver(char *line, int number, int length) {

  int outs;
  float hits = 0.0;
  outs = outOfPosition(line, length);

  hits = (float) outs;
  
  printf("Case #%d: %.6f\n", number, hits);
  
}

int get_len(char *line) {
  int cur_value = 0;
  int cur_position = 0;
  while(line[cur_position] >= '0' && line[cur_position] <= '9') {
    cur_value = cur_value * 10;
    cur_value = cur_value + line[cur_position] - '0';
    cur_position += 1;
  }
  return cur_value;
}




int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr ,"Usage: <input file name>\n");
    return 1;
  }

  char *stringFile;
  char *line;
  int count = 0;
  int length;

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
    length = get_len(line);
    line = lineReturn(stringFile);
    solver(line, count, length);
    count += 1;
  }
  free(stringFile);

  return 0;

}


  

  

  


