import java.util.*;
import java.io.*;

public class Main {

  private static void solve() {
    int n = nextInt();
    long x = nextLong();

    long[] l = new long[n + 1];
    long[] p = new long[n + 1];

    l[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
      l[i] = 2 * l[i - 1] + 3;
      p[i] = 2 * p[i - 1] + 1;
    }

    System.out.println(get(n, x, l, p));
  }

  private static long get(int n, long x, long[] l, long[] p) {
    if (n == 0) {
      return 1;
    }

    if (x == 1) {
      return 0;
    }

    x--;

    if (x <= l[n - 1]) {
      return get(n - 1, x, l, p);
    }

    x -= l[n - 1];

    if (x == 1) {
      return p[n - 1] + 1;
    }

    x--;

    if (x == l[n - 1] + 1) {
      x--;
    }
    
    return p[n - 1] + 1 + get(n - 1, x, l, p);
  }

  private static void run() {
    br = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out);

    solve();

    out.close();
  }

  private static StringTokenizer st;
  private static BufferedReader br;
  private static PrintWriter out;

  private static String next() {
    while (st == null || !st.hasMoreElements()) {
      String s;
      try {
        s = br.readLine();
      } catch (IOException e) {
        return null;
      }
      st = new StringTokenizer(s);
    }
    return st.nextToken();
  }

  private static int nextInt() {
    return Integer.parseInt(next());
  }

  private static long nextLong() {
    return Long.parseLong(next());
  }

  public static void main(String[] args) {
    run();
  }
}