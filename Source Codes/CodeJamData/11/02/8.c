/* 10:50, 11:05 - */
#include <stdio.h>
#include <string.h>

char combmat[26][26];
char oppomat[26][26];

char arriveseq[101];

char elemlist[102];
int pos;

int 
main () {
  int ntest, testno;
  int ncomb;
  int noppo;
  int seqlen;
  int i, j;
  char buf[10];

  scanf ("%d", &ntest);
  for (testno = 1; testno <= ntest; testno++) {
    scanf ("%d", &ncomb);
    // comb
    memset (combmat, 0, sizeof (combmat));
    for (i = 0; i < ncomb; i++) {
      scanf ("%s", buf);
      // input this comb
      int r = buf[0] - 'A';
      int c = buf[1] - 'A';
      combmat[r][c] = combmat[c][r] = buf[2];
    }

    scanf ("%d", &noppo);
    memset (oppomat, 0, sizeof (oppomat));
    // oppo
    for (i = 0; i < noppo; i++) {
      scanf ("%s", buf);
      int r = buf[0] - 'A';
      int c = buf[1] - 'A';
      oppomat[r][c] = oppomat[c][r] = 1;
    }

    scanf ("%d", &seqlen);
    scanf ("%s", arriveseq);

    pos = 0;
    elemlist[pos++] = '$';
    for (i = 0; i < seqlen; i++) { // action
      char elem = arriveseq[i];
      char last = elemlist[pos - 1];
      char res;
      if (res = combmat[elem - 'A'][last - 'A']) {
        elemlist[pos - 1] = res;
      } else {
        int clear = 0;
        for (j = 1; j < pos; j++) {
	  last = elemlist[j];
	  if (oppomat[elem - 'A'][last - 'A']) {
	    pos = 1;
	    clear = 1;
	    break;
	  }
	}

	if (!clear) {
	  elemlist[pos++] = elem;
	}
      }
    }

    printf ("Case #%d: [", testno);
    for (i = 1; i < pos; i++) {
      printf ("%c", elemlist[i]);
      if (i != pos - 1) {
        printf (", ");
      }
    }
    printf ("]\n");
  }

  return 0;
}
