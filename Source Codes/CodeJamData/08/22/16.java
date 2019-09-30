import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author nik
 */
public class B {
  public static void main(String[] args) throws Exception {
    BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
    PrintWriter out = new PrintWriter("b.out");

    int[] pr = new int[100000];
    int np = 0;
    boolean [] er = new boolean[1000000 + 3];
    for (int i = 2; i < er.length; i++) {
      if (er[i]) {
        continue;
      }
      pr[np++] = i;
      for (int j = 2*i; j < er.length; j += i) {
        er[j] = true;
      }
    }

    int C = Integer.parseInt(in.readLine());
    for (int i = 1; i <= C; i++) {
      StringTokenizer tz = new StringTokenizer(in.readLine());
      long A = Long.parseLong(tz.nextToken());
      long B = Long.parseLong(tz.nextToken());
      long P = Long.parseLong(tz.nextToken());
      int n = (int) (B - A + 1);

      int[] a = new int[n];
      int[] sz = new int[n];
      Arrays.fill(a, -1);
      Arrays.fill(sz, 1);
      int tt1, tt2;
      for (int j = 0; j < np; j++) {
        if (pr[j] < P) continue;
        int cp = pr[j];
        if (A + ((long) cp) > B) break;

        long t0 = (A / cp) * cp;
        if (t0 < A) t0 += cp;
        if (t0+cp > B) continue;
        int z0 = (int) (t0 - A);
        int w0 = z0;
        while (a[w0] != -1) w0 = a[w0];
        tt1 = z0;
        while (tt1 != w0) {
          tt2 = a[tt1];
          a[tt1] = w0;
          tt1 = tt2;
        }

        int z1 = z0 + cp;
        while (z1 < n) {
          int w1 = z1;
          while (a[w1] != -1) w1 = a[w1];
          tt1 = z1;
          while (tt1 != w1) {
            tt2 = a[tt1];
            a[tt1] = w1;
            tt1 = tt2;
          }

          if (w1 != w0) {
            if (sz[w0] > sz[w1]) {
              sz[w0] += sz[w1];
              a[w1] = w0;
            }
            else {
              sz[w1] += sz[w0];
              a[w0] = w1;
              w0 = w1;
            }
          }

          z1 += cp;
        }
      }

      int r = 0;
      for (int e : a) {
        if (e == -1) {
          r++;
        }
      }

      out.println("Case #" + i + ": " + r);
      if (i % 5 == 0) {
        System.out.print(".");
      }
    }

    in.close();
    out.close();
  }
}
