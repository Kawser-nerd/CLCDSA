import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] digits = new int[9];
    int numDigits = 0;
    while (N > 0) {
      digits[numDigits] = N % 10;
      numDigits++;
      N /= 10;
    }

    long[][][] dp = new long[numDigits + 1][10][2];
    dp[0][0][0] = 1;
    for (int i = 1; i <= numDigits; i++) {
      int d = digits[numDigits - i];

      for (int j = 0; j <= 9; j++) {
        dp[i][j][1] = dp[i - 1][j][1] * 9;
        if (j > 0) dp[i][j][1] += dp[i - 1][j - 1][1];
        if (d == 0) {
          dp[i][j][0] = dp[i - 1][j][0];
        } else if (d == 1) {
          dp[i][j][1] += dp[i - 1][j][0];
          if (j > 0) dp[i][j][0] = dp[i - 1][j - 1][0];
        } else {
          dp[i][j][1] += dp[i - 1][j][0] * (d - 1);
          if (j > 0) dp[i][j][1] += dp[i - 1][j - 1][0];
          dp[i][j][0] = dp[i - 1][j][0];
        }
      }
    }

    int res = 0;
    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 2; j++) {
        res += dp[numDigits][i][j] * i;
      }
    }
    System.out.println(res);
  }
}