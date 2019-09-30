import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    long K = scanner.nextLong();
    int[] digits = new int[41];
    int t = 0;
    while (K > 0) {
      if (K % 2 == 1) digits[t] = 1;
      K /= 2;
      t++;
    }

    int[] numOnes = new int[41];
    for (int i = 0; i < N; i++) {
      long a = scanner.nextLong();
      int j = 0;
      while (a > 0) {
        if (a % 2 == 1) numOnes[j]++;
        a /= 2;
        j++;
      }
    }

    long[][] dp = new long[42][2];
    for (int i = 40; i >= 0; i--) {
      long d = 1L << i;
      int ones = numOnes[i];
      int zeros = N - ones;
      if (digits[i] == 0) {
        dp[i][0] = dp[i + 1][0] + d * ones;
        if (dp[i + 1][1] > 0) dp[i][1] = dp[i + 1][1] + d * Math.max(ones, zeros);
      } else {
        dp[i][0] = dp[i + 1][0] + d * zeros;
        dp[i][1] = dp[i + 1][0] + d * ones;
        if (dp[i + 1][1] > 0) dp[i][1] = Math.max(dp[i][1], dp[i + 1][1] + d * Math.max(ones, zeros));
      }
    }
    System.out.println(Math.max(dp[0][0], dp[0][1]));
  }
}