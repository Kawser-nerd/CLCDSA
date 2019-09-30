import java.util.*;
import java.io.*;

public class xx {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();


    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt (), m = in.nextInt (), a = in.nextInt ();

      int x1, y1, x2, y2;

      if (a > n * m) System.out.println ("Case #" + tt + ": IMPOSSIBLE"); else {
        y1 = 1;
        x2 = - a % n;
        if (x2 < 0) x2 += n;
        x1 = n;
        y2 = (a + x2 * y1) / n;
        System.out.println ("Case #" + tt + ": 0 0 " + x1 + " " + y1 + " " + x2 + " " + y2);
      };
    };
  };
};