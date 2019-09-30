#include <stdio.h>
#include <string.h>
#include <math.h>

int     num_testcases;
int     length;
int     num_unique_letters;
char    line[64];

int     nums[10];
int     letters[26];

char    assign[256];

long long answer;

int
main(int argc, char* argv[])
{
    FILE       *fp;
    int         num_testcases;
    int         i, j;
    long long   min;

    fp = fopen(argv[1], "r");

    fscanf(fp, "%d\n", &num_testcases);

    for (i = 0; i < num_testcases; i++) {
        fgets(line, 64, fp);

        length = strlen(line) - 1;
        num_unique_letters = 0;
        answer = 0;
        min = 0;

        memset(nums, 0, sizeof(int) * 10);
        memset(letters, 0, sizeof(int) * 26);
        memset(assign, '?', sizeof(char) * 256);

        for (j = 0; j < length; j++) {
            if (line[j] >= '0' && line[j] <= '9') {
                if (nums[line[j] - '0'] == 0) {
                    num_unique_letters++;
                    nums[line[j] - '0'] = 1;
                }
            } else if (line[j] >= 'a' && line[j] <= 'z') {
                if (letters[line[j] - 'a'] == 0) {
                    num_unique_letters++;
                    letters[line[j] - 'a'] = 1;
                }
            }
        }
   
        if (num_unique_letters == 1) {
            /* no unary */
            num_unique_letters = 2;
        }

        assign[line[0]] = 1;
        answer = powl(num_unique_letters, length - 1);

        for (j = 1; j < length; j++) {
            if (min == 1) min++;

            if (assign[line[j]] == '?') {
                assign[line[j]] = min;
                answer += (min * powl(num_unique_letters, length - j - 1));
                min++;
            } else {
                answer += ((long long)assign[line[j]] * powl(num_unique_letters, length - j - 1));
            }            
        }

        printf("Case #%d: %lld\n", i + 1, answer);
    }
    fclose(fp);

    return 0;
}
