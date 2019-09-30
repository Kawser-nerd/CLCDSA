import java.io.*;
import static java.lang.Integer.*;

public class C {
  public static long add(long a, long b) {
    if (a == -1 || b == -1) { return -1; }
    return a + b;
  }
  public static long min(long a, long b) {
    if (a == -1) { return b; }
    if (b == -1) { return a; }
    return Math.min(a, b);
  }
  public static void main(String[] args) throws Throwable {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = parseInt(br.readLine());

    for (int t = 0; t++ < T; ) {
      String[] line = br.readLine().split(" ");
      int N = parseInt(line[0]);
      int Q = parseInt(line[1]);

      long[] E = new long[N];
      long[] S = new long[N];
      for (int n = 0; n < N; ++n) {
        line = br.readLine().split(" ");
        E[n] = parseInt(line[0]);
        S[n] = parseInt(line[1]);
      }

      long[][] D = new long[N][N];
      for (int n = 0; n < N; ++n) {
        line = br.readLine().split(" ");
        for (int m = 0; m < N; ++m) {
          D[n][m] = parseInt(line[m]);
        }
      }

      for (int k = 0; k < N; ++k)
      for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        D[i][j] = min(D[i][j], add(D[i][k], D[k][j]));

      double[][] X = new double[N][N];
      for (int n = 0; n < N; ++n) 
      for (int m = 0; m < N; ++m)
        X[n][m] = (D[n][m] == -1 || D[n][m] > E[n]) ? Double.POSITIVE_INFINITY : ((double) D[n][m]) / S[n];

      for (int k = 0; k < N; ++k)
      for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        X[i][j] = Math.min(X[i][j], X[i][k] + X[k][j]);

      System.out.print(String.format("Case #%d:", t));
      for (int q = 0; q < Q; ++q) {
        line = br.readLine().split(" ");
        int n = parseInt(line[0]) - 1;
        int m = parseInt(line[1]) - 1;
        System.out.print(String.format(" %.8f", X[n][m]));
      }
      System.out.println();
    }
  }
}
