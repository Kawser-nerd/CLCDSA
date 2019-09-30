import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static final int MOD = 1_000_000_007;

  public static void main(String[] args) {
    int N = sc.nextInt();
    long A = sc.nextLong();
    long B = sc.nextLong();
    if (A > B) {
      long t = A;
      A = B;
      B = t;
    }
    long[] S = new long[N + 1];
    S[0] = -1_000_000_000_000_000_001L;
    for (int i = 0; i < N; i++) {
      S[i + 1] = Long.parseLong(sc.next());
      if (i > 0 && S[i + 1] < S[i - 1] + A) {
        System.out.println(0);
        return;
      }
    }
    long[][] dp = new long[2][N + 1];
    dp[0][1] = 1;
    dp[1][0] = dp[1][1] = 1;
    long[] bsum = new long[N + 2];
    bsum[1] = 1;
    bsum[2] = 2;
    int limit = 0;
    int prev = 0;
    for (int i = 2; i <= N; i++) {
      while (S[prev + 1] <= S[i] - B) {
        ++prev;
      }
      if (S[i] < S[i - 1] + A) {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = prev < limit ? 0 : (bsum[prev + 1] - bsum[limit] + MOD) % MOD;
        limit = i - 1;
      } else {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        dp[1][i] = prev < limit ? 0 : (bsum[prev + 1] - bsum[limit] + MOD) % MOD;
      }
      bsum[i + 1] = (bsum[i] + dp[1][i]) % MOD;
    }
    long ans = (dp[0][N] + dp[1][N]) % MOD;
    System.out.println(ans);
  }

}