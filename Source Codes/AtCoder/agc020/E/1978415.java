import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static long MOD = 998244353;
  static HashMap<Long, Long> memo = new HashMap<>();

  public static void main(String[] args) {
    char[] s = sc.next().toCharArray();
    int N = s.length;
    boolean[] S = new boolean[N];
    for (int i = 0; i < N; i++) {
      S[i] = s[i] == '1';
    }
    System.out.println(solve(S));
  }

  static long solve(boolean[] s) {
    int N = s.length;
    long key = 0;
    if (N < 50) {
      key |= (long)N << 55;
      for (int i = 0; i < N; i++) {
        if (s[i]) key |= (1L << i);
      }
      if (memo.containsKey(key)) return memo.get(key);
    }
    long[][] count = new long[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        boolean[] cs = new boolean[j - i + 1];
        for (int k = i; k <= j; k++) {
          cs[k - i] = s[k];
        }
        count[i][j] = count(cs);
      }
    }
//    for (int i = 0; i < N; i++) {
//      for (int j = i + 1; j < N; j++) {
//        System.err.println("i:" + i + " j:" + j + " " + count[i][j]);
//      }
//    }
//    System.err.println("");
    long[] dp = new long[N + 1];
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
      dp[i] %= MOD;
      if (s[i]) {
        dp[i + 1] += dp[i] * 2;
      } else {
        dp[i + 1] += dp[i];
      }
      for (int j = i; j < N; j++) {
        dp[j + 1] += dp[i] * count[i][j] % MOD;
      }
//      System.err.println(Arrays.toString(dp));
    }
    dp[N] %= MOD;
    if (N < 50) {
      memo.put(key, dp[N]);
    }
    return dp[N];
  }

  static long count(boolean[] s) {
    long ret = 0;
    for (int i = 2; i <= s.length; i++) {
      if (s.length % i != 0) continue;
      boolean[] sub = new boolean[s.length / i];
      Arrays.fill(sub, true);
      for (int j = 0; j < s.length; j++) {
        sub[j % sub.length] &= s[j];
      }
      ret += solve(sub);
      if (ret >= MOD) ret -= MOD;
    }
    return ret;
  }
}