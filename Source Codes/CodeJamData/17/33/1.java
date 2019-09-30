import java.io.File;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Scanner;

public class Core2 implements Runnable {
  private static final String NAME = "core";

  private  StreamTokenizer in;

  int nextInt() throws Exception {
    in.nextToken();
    return (int) in.nval;
  }

  long nextLong() throws Exception {
    in.nextToken();
    return (long) in.nval;
  }

  double res(double[] p, int k) {
    int n = p.length;
    double[][] r = new double[n + 1][n + 1];
    r[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        if (j > 0) {
          r[i + 1][j] += p[i] * r[i][j - 1];
        }
        r[i + 1][j] += (1 - p[i]) * r[i][j];
      }
    }
    double res = 0;
    for (int i = k; i <= n; i++) {
      res += r[n][i];
    }
    return res;
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      //BufferedReader in = new BufferedReader(new FileReader(new File(NAME + ".in")));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        int n = in.nextInt();
        int k = in.nextInt();
        double U = in.nextDouble();
        double[] p = new double[n];
        for (int i = 0; i < n; i++) {
          p[i] = in.nextDouble();
        }
        Arrays.sort(p);

        double r = 0;

        for (int i = 0; i < n; i++) {
          for (int j = i; j < n; j++) {
            double d = 0;
            double[] pp = Arrays.copyOf(p, n);
            for (int kk = i; kk < j; kk++) {
              d += p[j] - p[kk];
            }
            if (d <= U) {
              double m = (U - d) / (j - i + 1);
              double dd = 0;
              for (int kk = i; kk <= j; kk++) {
                pp[kk] = Math.min(1, p[j] + m);
                dd += pp[kk] - p[kk];
              }
              r = Math.max(r, res(pp, k));
              if (dd < U && i > 0) {
                double[] ppp = Arrays.copyOf(pp, n);
                ppp[i - 1] = Math.min(1, p[i - 1] + U - dd);
                r = Math.max(r, res(ppp, k));
              }
              if (dd < U && j < n - 1) {
                double[] ppp = Arrays.copyOf(pp, n);
                ppp[j + 1] = Math.min(1, p[j + 1] + U - dd);
                r = Math.max(r, res(ppp, k));
              }
            }
          }
        }
        out.println("Case #" + test + ": " + r);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Core2()).start();
  }
}