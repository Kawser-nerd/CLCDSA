import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      boolean [][] z = new boolean [101][101];
      int r = in.nextInt (), cnt = 0;
      for (int i = 0; i < r; i++) {
        int x1 = in.nextInt (), y1 = in.nextInt (), x2 = in.nextInt (), y2 = in.nextInt ();
        for (int a = x1; a <= x2; a++)
          for (int b = y1; b <= y2; b++) {
            if (!z[a][b]) ++cnt;
            z[a][b] = true;
          }
      }

      int s;
      for (s = 1;;s++) {
        for (int i = 100; i >= 1; i--)
          for (int j = 100; j >= 1; j--) {
            if (z[i - 1][j] && z[i][j - 1] && !z[i][j]) {
              z[i][j] = true;
              ++cnt;
            }
            if (!z[i - 1][j] && !z[i][j - 1] && z[i][j]) {
              z[i][j] = false;
              --cnt;
            }
          }
        if (cnt == 0) break;
      }
       
      System.out.println ("Case #" + tt + ": " + s);
    };
  };
};