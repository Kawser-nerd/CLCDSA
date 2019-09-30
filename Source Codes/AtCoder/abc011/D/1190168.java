import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int D = sc.nextInt();
    int X = sc.nextInt();
    int Y = sc.nextInt();
    double ans = 0;
    if(X % D == 0 && Y % D == 0) {
      X /= D;
      Y /= D;
      // dp[i][j]?iCj / 2^i???
      double[][] dp = new double[1001][1001];
      for(int i = 0; i < 1001; i++) {
        dp[i][0] = 1 / (double)Math.pow(2, i);
        dp[i][i] = 1 / (double)Math.pow(2, i);
        for(int j = 1; j < i; j++) {
          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) / (double)2;
        }
      }
      // ??????????k??????
      for(int k = 0; k <= N; k++) {
        // N???????????????????k?????
        double prob1 = dp[N][k];
        if((k + Y) % 2 == 0 && (N - k + X) % 2 == 0 && (k + Y) >= 0 && (k - Y) >= 0 && (N - k + X) >= 0 && (N - k - X) >= 0) {
          // ????????
          int up = (k + Y) / 2;
          // ????????
          int right = (N - k + X) / 2;
          double prob2 = dp[k][up];
          double prob3 = dp[N - k][right];
          ans += (prob1 * prob2 * prob3);
        }
      }
    }
    System.out.println(ans);
  }
}