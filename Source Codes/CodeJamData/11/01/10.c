/* 09:46, 10:10 - */
#include <stdio.h>

int pos[2]; /* blue, orange */
int timeline[2];

char robotarr[100];
int butarr[100];

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int
main () {
  int ntest, testno;
  int nitem;
  int i;
  int curritem;

  scanf ("%d", &ntest);
  for (testno = 1; testno <= ntest; testno++) {
    scanf ("%d", &nitem);
    for (i = 0; i < nitem; i++) {
      char buf[2];
      scanf ("%s%d", buf, &butarr[i]);
      robotarr[i] = buf[0];
    }

/*
    for (i = 0; i < nitem; i++) {
      printf ("%c%d", robotarr[i], butarr[i]);
    }
    printf ("]\n");
*/

    pos[0] = pos[1] = 1;
    timeline[0] = timeline[1] = 0;
    curritem = 0;

    while (curritem < nitem) {
      int actor = (robotarr[curritem] == 'B');
      int initdiff = abs (pos[ actor ] - butarr[curritem]);
    
      // calculate start time
      int start = timeline[1 - actor] - initdiff;
      if (start < timeline[actor]) {
        start = timeline[actor];
      }

      int cost = 0;
      // update timeline, pos, & curritem
      while (1) {
        // account for curritem
        cost += abs (pos[actor] - butarr[curritem]) + 1;
	pos[actor] = butarr[curritem];
	curritem++;

	if (curritem >= nitem || (robotarr[curritem] == 'B') != actor) {
	  timeline[actor] = start + cost;
	  break;
	}
      }
    }

    // print
    printf ("Case #%d: %d\n", testno, MAX (timeline[0], timeline[1]));
  }

  return 0;
}

