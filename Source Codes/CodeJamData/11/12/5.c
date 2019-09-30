#include <stdio.h>
#include <string.h>

int N, caseN;
int i, j, k, l, mm;
char dict[10000][11];
char word[11];
int score, maxScore, maxScoreStr;
int chcount[26], exist[26];
int n, m;
int len[10000];
char s[27];
int valid[10000];
int count;
int guessed[26];

int main() {
  scanf("%d", &N);
  for (caseN = 1; caseN <= N; caseN++) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) scanf("%s", dict[i]);
    for (i = 0; i < n; i++) len[i] = strlen(dict[i]);

    printf("Case #%d:", caseN);

    while (m--) {
      scanf("%s", s);

      maxScore = -1;

      for (i = 0; i < n; i++) {
        score = 0;

        for (j = 0; j < n; j++) valid[j] = 1;
        memset(chcount, 0, sizeof(chcount));

        memset(guessed, 0, sizeof(guessed));

        for (j = 0; j < n; j++)
          if (len[i] != len[j]) valid[j] = 0;
          else {
            for (k = 0; k < len[j]; k++)
              chcount[dict[j][k]-'a']++;
          }

        memset(exist, 0, sizeof(exist));
        count = 0;
        for (j = 0; j < len[i]; j++) {
          if (exist[dict[i][j]-'a'] == 0) {
            exist[dict[i][j]-'a'] = 1;
            count++;
          }
        }

        for (j = 0; j < len[i]; j++)
          word[j] = '-';

        word[len[i]] = '\0';

        for (j = 0; j < 26 && count > 0; j++) {
          guessed[s[j]-'a'] = 1;

          if (chcount[s[j]-'a']) {
            if (!exist[s[j]-'a']) {
              score++;
            } 
            else {
              count--;
              for (k = 0; k < len[i]; k++)
                if (dict[i][k] == s[j])
                  word[k] = dict[i][k];
            }

            for (k = 0; k < n; k++) {
              if (!valid[k]) continue;

              for (l = 0; l < len[i]; l++)
                if (word[l] != '-' && dict[k][l] != word[l]) {
                  valid[k] = 0;
                  for (mm = 0; mm < len[k]; mm++) chcount[dict[k][mm]-'a']--;
                  break;
                }
            }

            for (k = 0; k < n; k++) {
              if (!valid[k]) continue;

              for (l = 0; l < len[k]; l++)
                if (guessed[dict[k][l]-'a'] && word[l] != dict[k][l]) {
                  valid[k] = 0;
                  for (mm = 0; mm < len[k]; mm++) chcount[dict[k][mm]-'a']--;
                  break;
                }
            }
          }
        }

        if (score > maxScore) {
          maxScore = score;
          maxScoreStr = i;
        }
      }

      printf(" %s", dict[maxScoreStr]);
    }
    printf("\n");
  }
  return 0;
}
