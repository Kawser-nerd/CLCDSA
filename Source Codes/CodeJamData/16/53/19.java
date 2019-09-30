import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Scanner;

public class Rebel implements Runnable {
  private static final String NAME = "rebel";

  private  StreamTokenizer in;

  int nextInt() throws Exception {
    in.nextToken();
    return (int) in.nval;
  }

  long nextLong() throws Exception {
    in.nextToken();
    return (long) in.nval;
  }

  double[][] d;

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        //put solution here
        int n = in.nextInt();
        in.nextInt(); // read S
        d = new double[n][n];
        int[] x = new int[n];
        int[] y = new int[n];
        int[] z = new int[n];
        for (int i = 0; i < n; i++) {
          x[i] = in.nextInt();
          y[i] = in.nextInt();
          z[i] = in.nextInt();
          for (int j = 0; j < 3; j++) {
            in.nextInt();
          }
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            int xx = x[i] - x[j];
            int yy = y[i] - y[j];
            int zz = z[i] - z[j];
            d[i][j] = Math.sqrt(xx * xx + yy * yy + zz * zz);
          }
        }
        double l = 0;
        double r = 1e10;
        while (r - l > 1e-5) {
          double m = (l + r) / 2;
          if (find(m)) {
            r = m;
          } else {
            l = m;
          }
        }
        out.println("Case #" + test + ": " + r);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  private boolean find(double m) {
    b = new boolean[d.length];
    g(0, m);
    return b[1];
  }

  boolean[] b;

  private void g(int v, double m) {
    b[v] = true;
    for (int i = 0; i < d.length; i++) {
      if (!b[i] && d[v][i] < m) {
        g(i, m);
      }
    }
  }

  public static void main(String[] args) {
    new Thread(new Rebel()).start();
  }
}
