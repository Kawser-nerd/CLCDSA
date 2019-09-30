#include<stdio.h>

#define BUF_LENGTH 102

char buf1[BUF_LENGTH];
char buf2[BUF_LENGTH];

char table[256];

void learn(char *input, char *output)
{
  while (*input)
      table[*output++] = *input++;
}

void train(char *inputFile, char *outputFile)
{
  FILE *input = 0, *output = 0;

  input = fopen(inputFile, "r");
  output = fopen(outputFile, "r");

  while (fgets(buf1, BUF_LENGTH, input))
    {
      fgets(buf2, BUF_LENGTH, output);
      learn(buf1, buf2);
    }

  fclose(input);
  fclose(output);
}

char *translate(char *googlerese, char *english)
{
  char *result = english;
  while (*googlerese)
    *english++ = table[*googlerese++];
  *english = 0;
  return result;
}

void test()
{
  int i;
  for (i = 'a'; i <= 'z'; i++)
    if (!table[i])
      fprintf(stderr, "error: character %c is undefined\n", i);
}

void run()
{
  int T, t;

  scanf("%d\n", &T);

  for (t = 1; t <= T; t++)
    if (fgets(buf1, BUF_LENGTH, stdin))
      printf("Case #%d: %s", t, translate(buf1, buf2));
    else
      break;
}

/*
 * usage: main <training_input> <training_output>
 *
 * trains the program using the sample input and output (also an additional 'q' -> 'z' rule which can be discovered by running the program with training I/O followed by running the program with swapped I/O data.
 *
 * the program then reads input from stdin in the described format and output translation to stdout.
 */
int main(int argc, char **argv)
{
  if (argc == 3)
    {
      train(argv[1], argv[2]);
      test();
      run();
    }
  else
    fprintf(stderr, "usage: q1 <training_input> <training_output>\n");

  return 0;
}
