import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * @author nik
 */
public class C {
  public static void main(String[] args) throws Exception {
    BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
    PrintWriter out = new PrintWriter("c.out");

    int T = Integer.parseInt(in.readLine());
    for (int i = 1; i <= T; i++) {
      int n = Integer.parseInt(in.readLine());
      double[] x = new double[n];
      double[] y = new double[n];
      double[] z = new double[n];
      double[] p = new double[n];
      for (int j = 0; j < n; j++) {
        StringTokenizer tz = new StringTokenizer(in.readLine());
        x[j] = Integer.parseInt(tz.nextToken());
        y[j] = Integer.parseInt(tz.nextToken());
        z[j] = Integer.parseInt(tz.nextToken());
        p[j] = Integer.parseInt(tz.nextToken());
      }

      double l = 0;
      double r = 1e8;
      while (r > l + 1e-7) {
        double pp = (l + r) / 2;
        boolean can = true;
        outer:
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            double d = Math.abs(x[k] - x[j]) + Math.abs(y[k] - y[j]) + Math.abs(z[k] - z[j]);
            if (d > pp * (p[k] + p[j])) {
              can = false;
              break outer;
            }
          }
        }
        if (can) {
          r = pp;
        }
        else {
          l = pp;
        }
      }

      double rr = (l+r)/2;
      out.printf(Locale.US, "Case #%d: %.6f\n", i, rr);
    }
    
    in.close();
    out.close();
  }
}
