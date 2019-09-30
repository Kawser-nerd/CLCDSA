import java.util.HashMap;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    final int M = 1_000_000_007;
    int N = scanner.nextInt();
    int[] c = new int[N];
    for (int i = 0; i < N; i++) c[i] = scanner.nextInt();
    HashMap<Integer, Integer> lastPos = new HashMap<>();
    long[] dp = new long[N + 1];
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
      dp[i] = dp[i - 1];
      int color = c[i - 1];
      if (lastPos.containsKey(color) && lastPos.get(color) < i - 1) {
        dp[i] += dp[lastPos.get(color)];
        if (dp[i] >= M) dp[i] -= M;
      }
      lastPos.put(color, i);
    }
    System.out.println(dp[N]);
  }
}