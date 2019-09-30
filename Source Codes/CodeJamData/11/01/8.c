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

int calculate_time(int *array, int length) {

  int o_pos = 1;
  int o_tot = 0;
  int o_diff = 0;
  int o_but = 0;

  int b_pos = 1;
  int b_tot = 0;
  int b_diff = 0;
  int b_but = 0;

  int total_time = 0;
  int position = 0;

  int o_array[length];
  int b_array[length];

  while(position < length) {
    if (array[position] == 'O') {
      position++;
      o_array[o_tot++] = array[position];
      position++;
    }
    else {
      position++;
      b_array[b_tot++] = array[position];
      position++;
    }
  }

  position = 0;

  if (o_tot > 0)
    o_diff = o_array[o_but] - 1;
  else 
    o_diff = 1000;
  if (b_tot > 0)
    b_diff = b_array[o_but] - 1;
  else 
    b_diff = 1000;

  while(position < length) {

    if (array[position] == 'O' && o_diff <= 0) {
      b_diff -= 1;
      total_time += 1;
      o_pos = o_array[o_but];
      if (++o_but != o_tot) {
	if (o_pos >= o_array[o_but])
	  o_diff = o_pos - o_array[o_but];
	else
	  o_diff = o_array[o_but] - o_pos;
      }
      position += 2;
    }
    else if (array[position] == 'B' && b_diff <= 0) {
      o_diff -= 1;
      total_time += 1;
      b_pos = b_array[b_but];
      if (++b_but != b_tot) {
	if (b_pos >= b_array[b_but])
	  b_diff = b_pos - b_array[b_but];
	else
	  b_diff = b_array[b_but] - b_pos;
      }
      position += 2;
    }
    else if (array[position] == 'O') {
      total_time += o_diff;
      b_diff -= o_diff;
      o_diff = 0;
    }
    else if (array[position] == 'B') {
      total_time += b_diff;
      o_diff -= b_diff;
      b_diff = 0;
    }

  }

  return total_time;
}

int line2Array(char *line) {

  int len = 0;
  int cur_position = 0;
  int *array;
  int cur_value = 0;
  int count = 0;
  int time = 0;

  while (line[cur_position] >= '0' && line[cur_position] <= '9') {
    len *= 10;
    len += line[cur_position] - '0';
    cur_position += 1;
  }

  len *= 2;

  cur_position += 1;

  array = (int *) malloc(sizeof(int) * len);

  while(count < len) {
    cur_value = 0;
    while((line[cur_position] >= '0' && line[cur_position] <= '9') || line[cur_position] == 'O' || line[cur_position] == 'B') {
      if (line[cur_position] == 'O' || line[cur_position] == 'B') {
	cur_value = line[cur_position++];
	break;
      }
      cur_value = cur_value * 10;
      cur_value = cur_value + line[cur_position] - '0';
      cur_position += 1;
    }
    array[count] = cur_value;
    count += 1;
    cur_position += 1;
  }

  time = calculate_time(array, len);
  free(array);

  return time;
}

void time_count(char *line, int number) {

  int time;
  time = line2Array(line);
  printf("Case #%d: %d\n", number, time);

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

    time_count(line, count);


    count += 1;
  }
  free(stringFile);

  return 0;

}


  

  

  


