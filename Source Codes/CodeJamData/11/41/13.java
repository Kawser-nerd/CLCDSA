import java.util.*;
import java.io.*;

public class x {
  static class Pair implements Comparable <Pair> {
    int x, y;
    Pair (int xx, int yy) {
      x = xx; y = yy;
    }
    public int compareTo (Pair z) {
      if (x != z.x) return x - z.x;
      return y - z.y;
    }
  }



  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int X = in.nextInt ();
      int S = in.nextInt ();
      int R = in.nextInt ();
      int z = in.nextInt ();
      int n = in.nextInt ();

      boolean [] U = new boolean [n];
      Pair [] e = new Pair [2 * n + 1];
      int [] w = new int [n];

      for (int i = 0; i < n; i++) {
        e[2 * i] = new Pair (in.nextInt (), i + 1);
        e[2 * i + 1] = new Pair (in.nextInt (), -(i + 1));
        w[i] = in.nextInt ();
      }
      e[2 * n] = new Pair (X, 0);

      double [] A = new double [X];

      Arrays.sort (e);

      int csp = 0, cp = 0, lpos = 0;
      double ans = 0;

      for (int i = 0; i <= X; i++) {
        if (e[cp].x == i) {
          //System.out.println (e[cp].x + " " + e[cp].y + " " + i + " " + X + " " + n);
          //ans += 1.0 * (i - lpos) / (csp + S);
          lpos = i;
          if (i == X) break;
          do {
            if (e[cp].y < 0) U[-e[cp].y - 1] = false; else U[e[cp].y - 1] = true;
            ++cp;
          } while (e[cp].x == i);
          csp = 0;
          for (int j = 0; j < n; j++)
            if (U[j] && w[j] > csp)
              csp = w[j];
        }
        A[i] = (csp + S);
      }

      Arrays.sort (A);

      double zleft = z;

      for (int i = 0; i < X; i++) {
        if (zleft >= 1 / (A[i] + (R - S))) {
          ans += 1.0 / (A[i] + R - S);
          zleft -= 1 / (A[i] + (R - S));
        } else if (zleft > 0) {
          double P = zleft * (A[i] + (R - S));
          double Q = (1 - P) / A[i];
          ans += zleft + Q;
          zleft = 0;
          //System.out.println ("here");
        } else ans += 1.0 / A[i];
      }

      System.out.println ("Case #" + tt + ": " + ans);
    }
  }
}