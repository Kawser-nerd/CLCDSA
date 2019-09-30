import java.util.*;

public class z {
  public static void main (String args []) {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int i = 1; i <= t; i++) {
      int n = in.nextInt ();
      int m = in.nextInt ();

      boolean [][] F = new boolean [m][n];
      int [] q = new int [m];
      int [] c = new int [m];


      int [] Qu = new int [m];
      int qh = 0, qt = 0;

      Arrays.fill (q, -1);

      for (int j = 0; j < m; j++) {
        int s = in.nextInt ();
        for (int k = 0; k < s; k++) {
          int x = in.nextInt ();
          int y = in.nextInt ();
          if (y == 1) q[j] = x - 1; else F[j][x - 1] = true;
        };
        for (int k = 0; k < n; k++)
          if (F[j][k]) ++c[j];

        if (c[j] == 0) {
          Qu[qt] = j;
          ++qt;
        };
      };

      boolean ok = true;

      boolean [] B = new boolean [n];

      while (qh < qt) {
        int v = Qu[qh];
        ++qh;
        if (q[v] < 0) {
          ok = false;
          break;
        };
        if (!B[q[v]]) {
          for (int j = 0; j < m; j++)
            if (F[j][q[v]]) {
              --c[j];
              if (c[j] == 0) {
                Qu[qt] = j;
                ++qt;
              };
            };
          B[q[v]] = true;
        };
      };



      if (!ok) {
        System.out.println ("Case #" + i + ": IMPOSSIBLE");

      } else {
        System.out.print ("Case #" + i + ":");
        for (int j = 0; j < n; j++)
          if (B[j]) System.out.print (" 1"); else System.out.print (" 0");
        System.out.println ();
      };
    };
  };
};