import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Sample implements Runnable {
  private static final String NAME = "ticket";
  private static final long mod = 1000002013;

  private long dist(long n, long d, long num) {
    long v = n * (n + 1) - (n - d) * (n - d + 1);
    v = v / 2;
    return ((v % mod) * num) % mod;
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        long n = in.nextLong();
        int m = in.nextInt();

        P[] t = new P[2 * m];
        int cur = 0;

        long r = 0;

        for (int i = 0; i < m; i++) {
          int o = in.nextInt();
          int e = in.nextInt();
          int p = in.nextInt();
          t[cur++] = new P(o, p, 0);
          t[cur++] = new P(e, p, 1);

          r = r + dist(n, e - o, p);
          if (r >= mod) r = r - mod;
        }

        Arrays.sort(t);

        Stack<P> s = new Stack<P>();

        long res = 0;
        for (int i = 0; i < t.length; i++) {
          P p = t[i];
          if (p.in == 0) {
            s.add(p);
          } else {
            long k = p.num;
            while (k != 0) {
              P ss = s.pop();
              long num = Math.min(ss.num, k);

              res = res + dist(n, p.d - ss.d, num);
              if (res >= mod) res = res - mod;

              k -= num;
              if (num < ss.num) {
                s.add(new P(ss.d, ss.num - num, ss.in));
              }
            }
          }
        }

        res = r - res;
        if (res < 0) res = res + mod;
        out.println("Case #" + test + ": " + res);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Sample()).start();
  }

  private class P implements Comparable<P> {
    long d;
    long num;
    int in;

    private P(long d, long num, int in) {
      this.d = d;
      this.num = num;
      this.in = in;
    }

    @Override
    public int compareTo(P p) {
      if (d < p.d) return - 1;
      if (d > p.d) return 1;
      return in - p.in;
    }
  }
}
