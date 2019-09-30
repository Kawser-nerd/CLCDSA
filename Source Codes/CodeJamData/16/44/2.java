import java.io.*;
import java.util.*;

public class D {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "D-small-attempt1";

  private static void main2() throws IOException {
    int n = in.nextInt();
    int[] grid = new int[n];
    for (int i = 0; i < n; i++)
      grid[i] = Integer.parseInt(in.next(), 2);
    int[] cost = new int[1<<n];
    Arrays.fill(cost, 1 << 29);
    for (int i = 0; i < 1 << n; i++) {
      int sz = Integer.bitCount(i);
      int need = 0;
      int cmask = 0;
      int other = 0;
      for (int j = 0; j < n; j++) {
        if ((i&(1<<j)) != 0) {
          cmask |= grid[j];
          need += sz - Integer.bitCount(grid[j]);
        } else {
          other |= grid[j];
        }
      }
      int freebits = n-Integer.bitCount(other);
      int needmore = sz-Integer.bitCount(cmask);
      if ((cmask&other) == 0 && needmore >= 0 && freebits >= needmore) {
        cost[i] = need;
      }
    }
    int[] dp = new int[1<<n];
    Arrays.fill(dp, 1 << 29);
    dp[0] = 0;
    for (int j = 0; j < 1 << n; j++) {
      for (int k = 0; k < 1 << n; k++) {
        dp[k|j] = Math.min(dp[k|j], dp[k] + cost[j]);
      }
    }
    out.println(dp[(1<<n)-1]);
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
