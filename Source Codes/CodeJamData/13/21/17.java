import java.util.*;
import java.math.*;

public class Main {
  
  static long[][] dp;
  
  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(System.in);
    int taskCount = scan.nextInt();
    dp = new long[101][201];
    for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
      int A = scan.nextInt();
      int N = scan.nextInt();
      int[] arr = new int[N];
      for (int i = 0; i < N; i++) {
        arr[i] = scan.nextInt();
      }
      Arrays.sort(arr);
      for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 200; j++) {
          dp[i][j] = -1;
        }
      }
      dp[0][0] = A;
      for (int i = 1; i <= N; i++) {
        long current = arr[i - 1];
        for (int j = 0; j <= 200; j++) {
          if (dp[i - 1][j] == -1) {
            continue;
          }
          dp[i][j + 1] = Math.max(dp[i][j + 1], dp[i - 1][j]);
          if (dp[i - 1][j] <= 1) {
            continue;
          }
          long temp = dp[i - 1][j];
          int add = 0;
          while (temp <= current) {
            temp += temp - 1;
            add++;
          }
          dp[i][j + add] = Math.max(dp[i][j + add], temp + current);
        }
      }
      int res = -1;
      for (int i = 0; i <= 200; i++) {
        if (dp[N][i] >= 0) {
          res = i;
          break;
        }
      }
      System.out.println(String.format("Case #%d: %d", taskIndex, res));
    }
  }
}
