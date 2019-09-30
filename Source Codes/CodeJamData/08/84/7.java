import java.util.*;
import java.math.*;

public class x {
  static final int mod = 30031;

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int tn = in.nextInt ();
    for (int tt = 1; tt <= tn; tt++) {
      int n = in.nextInt ();
      int k = in.nextInt ();
      int p = in.nextInt ();

      int Z = 1 << p;

      int [][] D = new int [2][Z];

      D[k & 1][(1 << k) - 1] = 1;

      int Z1 = Z >> 1;

      for (int i = k; i < n; i++) {

        for (int j = 0; j < Z; j++)
          D[(i + 1) & 1][j] = 0;

        for (int j = 0; j < Z1; j++) {
          for (int a = 0; a < p; a++)
            if ((j & (1 << a)) != 0) {
              int l = j & (~ (1 << a));
              l = (l << 1) + 1;
              D[(i + 1) & 1][l] += D[i & 1][j];
              if (D[(i + 1) & 1][l] >= mod)
                D[(i + 1) & 1][l] -= mod;
            };
        };

        for (int j = Z1; j < Z; j++) {
          int l = ((j << 1) & (Z - 1)) + 1;
          D[(i + 1) & 1][l] += D[i & 1][j];
          if (D[(i + 1) & 1][l] >= mod)
            D[(i + 1) & 1][l] -= mod;
        };
      };

      System.out.println ("Case #" + tt + ": " + (D[n & 1][(1 << k) - 1] % mod));



    };
  };
};
