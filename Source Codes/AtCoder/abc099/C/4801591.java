import java.util.Scanner;

class Main {

  public static int min(int a, int b) {
    return a < b ? a : b;
  }

  public static int INF = Integer.MAX_VALUE / 4;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = Integer.parseInt(scanner.next());
    scanner.close();
    int[] dp = new int[100010];
    dp[0] = 0;
    for (int n = 1; n < dp.length; n++) {
      dp[n] = INF;
      int power = 1;
      while (power <= n) {
        dp[n] = min(dp[n], 1 + dp[n - power]);
        power *= 6;
      }
      power = 1;
      while (power <= n) {
        dp[n] = min(dp[n], 1 + dp[n - power]);
        power *= 9;
      }
    }
    System.out.println(dp[N]);
  }

}