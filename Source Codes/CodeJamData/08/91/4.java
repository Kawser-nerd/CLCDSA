import java.util.*;
import java.io.*;

public class x {

  static class Pt implements Comparable <Pt> {
    int x, y, z;
    Pt (int xx, int yy, int zz) {
      x = xx; y = yy; z = zz;
    };
    public int compareTo (Pt a) {
      if (y != a.y) return y - a.y;
      if (x != a.x) return x - a.x;
      if (z != a.z) return z - a.z;
      return 0;
    };
  };



  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    PrintWriter out = new PrintWriter (System.out);

    int tcnt = in.nextInt ();

    for (int i = 1; i <= tcnt; i++) {
      int n = in.nextInt ();
      Pt [] p = new Pt[n];
      for (int j = 0; j < n; j++) {
        int a = in.nextInt ();
        int b = in.nextInt ();
        int c = in.nextInt ();
        p[j] = new Pt (a, b, c);
      };

      Arrays.sort (p);

      int mx = 0;
        

      for (int x = 0; x <= 10000; x++) {
        int [] T = new int [10002];
        for (int j = 0; j < n; j++) {
          if (p[j].x <= x) {
            int z = 10000 - p[j].y - x;
            for (int k = 1 + p[j].z; k <= 10001; k += k & -k)
              T[k]++;
            if (z >= 0) {
              int sum = 0;
              for (int k = 1 + Math.max (0, z); k > 0; k -= k & -k)
                sum += T[k];
              mx = Math.max (mx, sum);
            };
            //System.out.println (x + " " + j + " " + p[j].y + " " + z);
          };
        };
      };


      out.println ("Case #" + i + ": " + mx);
    };

    out.close ();
  };
};