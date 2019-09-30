#include <assert.h>
#include <stdio.h>
#include <string.h>

const int maxl = 2010;

int main () {
  int t, tn;
  assert (scanf ("%d ", &tn) == 1);
  for (t = 1; t <= tn; t++) {
    char s[maxl + 1];
    int cnt[256], i, ans[10];
    memset (ans, 0, sizeof (ans));
    memset (cnt, 0, sizeof (cnt));
    assert (fgets (s, maxl, stdin));
    for (i = 0; s[i]; i++)
      cnt[(int)s[i]]++;
    // ZERO
    ans[0] = cnt['Z'];
    cnt['Z'] -= ans[0];
    cnt['E'] -= ans[0];
    cnt['R'] -= ans[0];
    cnt['O'] -= ans[0];
    // TWO
    ans[2] = cnt['W'];
    cnt['T'] -= ans[2];
    cnt['W'] -= ans[2];
    cnt['O'] -= ans[2];
    // FOUR
    ans[4] = cnt['U'];
    cnt['F'] -= ans[4];
    cnt['O'] -= ans[4];
    cnt['U'] -= ans[4];
    cnt['R'] -= ans[4];
    // SIX
    ans[6] = cnt['X'];
    cnt['S'] -= ans[6];
    cnt['I'] -= ans[6];
    cnt['X'] -= ans[6];
    // EIGHT
    ans[8] = cnt['G'];
    cnt['E'] -= ans[8];
    cnt['I'] -= ans[8];
    cnt['G'] -= ans[8];
    cnt['H'] -= ans[8];
    cnt['T'] -= ans[8];
    // ONE
    ans[1] = cnt['O'];
    cnt['O'] -= ans[1];
    cnt['N'] -= ans[1];
    cnt['E'] -= ans[1];
    // THREE
    ans[3] = cnt['T'];
    cnt['T'] -= ans[3];
    cnt['H'] -= ans[3];
    cnt['R'] -= ans[3];
    cnt['E'] -= ans[3];
    cnt['E'] -= ans[3];
    // FIVE
    ans[5] = cnt['F'];
    cnt['F'] -= ans[5];
    cnt['I'] -= ans[5];
    cnt['V'] -= ans[5];
    cnt['E'] -= ans[5];
    // SEVEN
    ans[7] = cnt['S'];
    cnt['S'] -= ans[7];
    cnt['E'] -= ans[7];
    cnt['V'] -= ans[7];
    cnt['E'] -= ans[7];
    cnt['N'] -= ans[7];
    // NINE
    ans[9] = cnt['I'];
    cnt['N'] -= ans[9];
    cnt['I'] -= ans[9];
    cnt['N'] -= ans[9];
    cnt['E'] -= ans[9];
    /*
    for (i = 0; i < 10; i++)
      fprintf (stderr, "ans[i=%d] = %d\n", i, ans[i]);
    for (i = 'A'; i <= 'Z'; i++)
      fprintf (stderr, "cnt[%c] = %d\n", i, cnt[i]);
     */
    for (i = 'A'; i <= 'Z'; i++) {
      assert (cnt[i] == 0);
    }
    printf ("Case #%d: ", t);
    for (i = 0; i < 10; i++) {
      assert (0 <= ans[i]);
      while (ans[i] --> 0)
        putc ('0' + i, stdout);
    }
    puts ("");
  }
  return 0;
}
