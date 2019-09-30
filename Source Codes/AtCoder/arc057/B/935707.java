import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiFunction;

public class Main {
  Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    new Main().run();
  }

  void run() {
    int n = ni();
    int k = ni();
    int sum = 0;
    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
      a[i] = ni();
      sum += a[i];
    }
    if (sum == k) {
      System.out.println(1);
    } else {
      int[][] dp = new int[n + 1][n + 1];
      for (int i = 0; i <= n; ++i) {
        Arrays.fill(dp[i], Integer.MAX_VALUE);
      }
      dp[0][0] = 0;
      long s = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
          if (dp[i][j] == Integer.MAX_VALUE) {
            continue;
          }
          // 0??
          dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j]);
          // ?????????
          // ????????/???????? < ???????v/????????
          // u/s < v/ns
          // \frac{u*ns}{s*ns} < \frac{s*v}{s*ns}
          // u*ns < s*v
          // v > u*ns/s
          // v = (u * ns) / s + 1
          long u = dp[i][j];
          long ns = s + a[i];
          long v;
          if (s == 0) {
            // ???1???????????????
            v = 1;
          } else {
            v = (u * ns) / s + 1;
          }
          // ?????????????????????
          // ??if??????AC?????????
          if (v - u <= a[i]) {
            dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], (int) v);
          }
        }
        s += a[i];
      }
      for (int i = n; 0 <= i; --i) {
        if (dp[n][i] <= k) {
          System.out.println(i);
          break;
        }
      }
    }
  }

  int ni() {
    return Integer.parseInt(sc.next());
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }

  class BIT<T> {
    int n;
    ArrayList<T> bit;
    BiFunction<T, T, T> bif;

    BIT(int n, BiFunction<T, T, T> bif, T defaultValue) {
      this.n = n;
      bit = new ArrayList<>(n + 1);
      for (int i = 0; i < n + 1; ++i) {
        bit.add(defaultValue);
      }
      this.bif = bif;
    }

    void update(int i, T v) {
      for (int x = i; x <= n; x += x & -x) {
        bit.set(x, bif.apply(bit.get(x), v));
      }
    }

    T reduce(int i, T defaultValue) {
      T ret = defaultValue;
      for (int x = i; x > 0; x -= x & -x) {
        ret = bif.apply(ret, bit.get(x));
      }
      return ret;
    }
  }

  long MOD = 1_000_000_007;

  long pow(long a, long r) {
    long sum = 1;
    while (r > 0) {
      if ((r & 1) == 1) {
        sum *= a;
        sum %= MOD;
      }
      a *= a;
      a %= MOD;
      r >>= 1;
    }
    return sum;
  }

  long C(int n, int r) {
    long sum = 1;
    for (int i = n; 0 < i; --i) {
      sum *= i;
      sum %= MOD;
    }
    long s = 1;
    for (int i = r; 0 < i; --i) {
      s *= i;
      s %= MOD;
    }
    sum *= pow(s, MOD - 2);
    sum %= MOD;

    long t = 1;
    for (int i = n - r; 0 < i; --i) {
      t *= i;
      t %= MOD;
    }
    sum *= pow(t, MOD - 2);
    sum %= MOD;

    return sum;
  }
}