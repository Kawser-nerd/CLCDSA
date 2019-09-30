import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    int MX = (int) 1e6 + 1;

    boolean [] F = new boolean [MX];
    long [] P = new long [MX];
    int pc = 0;

    for (int i = 2; i < MX; i++)
      if (!F[i]) {
        P[pc++] = i;
        for (int j = i + i; j < MX; j += i)
          F[j] = true;
      }
    P[pc++] = MX + 1; 


    for (int tt = 1; tt <= t; tt++) {
      long n = in.nextLong ();
      long ans = (n == 1) ? 0 : 1;
      for (int i = 0; P[i] * P[i] <= n; i++) {
        long cp = P[i], v = cp;
        while (v * cp <= n) {
          v *= cp;
          ++ans;
          //System.out.println (v + " " + ans + " " + cp);
        }
      }

      System.out.println ("Case #" + tt + ": " + ans);
    }
  }
}