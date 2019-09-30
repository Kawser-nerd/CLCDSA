import java.util.*;
import java.math.*;

public class Main {
  
  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(System.in);
    int taskCount = scan.nextInt();
    for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
      int N = scan.nextInt();
      int X = scan.nextInt();
      int Y = scan.nextInt();
      int index = 1;
      int current = 1;
      while (true) {
        int next = index * 2 + 3;
        if (current + next <= N) {
          current += next;
          index += 2;
        } else {
          break;
        }
      }
      int width = (Math.abs(X) + Math.abs(Y)) / 2;
      int exists = (index - 1) / 2;
      double res;
      if (width <= exists) {
        res = 1;
      } else if (width - 1 == exists) {
        int height = Y;
        int side = index + 1;
        int left = N - current;
        if (left == 2 * side + 1) {
          res = 1;
        } else if (X == 0) {
          res = 0;
        } else {
          double[][][] dp = new double[left + 1][side + 1][side + 1];
          dp[0][0][0] = 1;
          for (int i = 1; i <= left; i++) {
            for (int j = 0; j <= side; j++) {
              for (int k = 0; k <= side; k++) {
                if (j < side && k < side) {
                  dp[i][j + 1][k] += 0.5 * dp[i - 1][j][k];
                  dp[i][j][k + 1] += 0.5 * dp[i - 1][j][k];
                } else if (j < side) {
                  dp[i][j + 1][k] += dp[i - 1][j][k];
                } else if (k < side) {
                  dp[i][j][k + 1] += dp[i - 1][j][k];
                }
              }
            }
          }
          res = 0;
          for (int j = height + 1; j <= side; j++) {
            for (int k = 0; k <= side; k++) {
              res += dp[left][j][k];
            }
          }
        }
      } else {
        res = 0;
      }
      System.out.println(String.format("Case #%d: %f", taskIndex, res));
    }
  }
}
