import java.util.*;
import java.io.*;

public class Main {

  private static void solve() {
    int n = nextInt();
    long k = nextLong();

    int[] cnt = new int[64];

    long[] a = new long[n];
    long ans = 0;
    for (int i = 0; i < n; i++) {
      a[i] = nextLong();
      ans ^= a[i];

      for (int j = 0; j < 64; j++) {
        if ((a[i] & (1L << j)) != 0) {
          cnt[j]++;
        }
      }
    }

    long ans2 = 0;
    for (int i = 0; i < n; i++) {
      ans2 += a[i] ^ k;
    }

    ans = Math.max(ans, ans2);

    for (int i = 0; i < 64; i++) {
      if ((k & (1L << i)) != 0) {
        long xor = 0;
        for (int j = i + 1; j < 64; j++) {
          if ((k & (1L << j)) != 0) {
            xor |= (1L << j);
          }
        }

        for (int j = 0; j < i; j++) {
          if (cnt[j] < n - cnt[j]) {
            xor |= (1L << j);
          }
        }

        long temp = 0;
        for (int j = 0; j < n; j++) {
          temp += (a[j] ^ xor);
        }

        if (ans < temp) {
          ans = temp;
        }
      }
    }

    System.out.println(ans);
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