import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  private final int MOD = (int) (1e9 + 7);

  private void solve(Scanner in, PrintWriter out) {
    int N = in.nextInt();
    int M = in.nextInt();
    char[] S = in.next().toCharArray();
    int[] right = new int[N];
    Arrays.fill(right, -1);
    for (int i = 0; i < M; i++) {
      int l = in.nextInt() - 1;
      int r = in.nextInt() - 1;
      if (right[l] < r) right[l] = r;
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
      max = Math.max(max, i);
      max = Math.max(max, right[i]);
      right[i] = max;
    }

    int[] sum = new int[N];
    for (int i = 0; i < N; i++) sum[i] = S[i] - '0';
    for (int i = 0; i < N - 1; i++) sum[i + 1] += sum[i];

    long[][] dp = new long[N + 1][N + 1];
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
      for (int usedOne = 0; usedOne < N; usedOne++) {
        int r = right[i];
        int restOne = sum[r] - usedOne;
        if (restOne < 0) continue;

        if (restOne > 0)
          dp[i + 1][usedOne + 1] = (dp[i + 1][usedOne + 1] + dp[i][usedOne]) % MOD;

        if (r - i + 1 != restOne)
          dp[i + 1][usedOne] = (dp[i + 1][usedOne] + dp[i][usedOne]) % MOD;
      }
    }
    out.println(dp[N][sum[N - 1]]);
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    new Main().solve(in, out);
    in.close();
    out.close();
  }
}