import java.io.*;
import java.util.*;

public class B {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "B-large";

  private static void main2() throws IOException {
    int n = in.nextInt(), k = in.nextInt();
    double[] p = new double[n];
    for (int i = 0; i < n; i++) p[i] = Double.parseDouble(in.next());
    Arrays.sort(p);
    double max = 0;
    for (int q = 0; q <= k; q++) {
      double[] x = new double[k];
      for (int i = 0; i < q; i++) x[i] = p[i];
      for (int i = q; i < k; i++) x[i] = p[n-(i-q)-1];
      double[] dp = new double[4*k];
      int r = 2*k;
      dp[r] = 1;
      for (int i = 0; i < k; i++) {
        double[] next = new double[4*k];
        for (int j = 0; j < 4*k; j++) {
          if (j > 0) next[j-1] += dp[j] * (1-x[i]);
          if (j+1 < 4*k) next[j+1] += dp[j] * x[i];
        }
        dp = next;
      }
      max = Math.max(max, dp[r]);
    }
    out.printf("%.10f\n", max);
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ": ");
      main2();
    }

    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
