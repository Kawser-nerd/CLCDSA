import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int[] graph = new int[N];
    for (int i = 0; i < M; i++) {
      int x = scanner.nextInt() - 1;
      int y = scanner.nextInt() - 1;
      graph[y] ^= (1 << x);
    }

    long[] dp = new long[1 << N];
    dp[0] = 1;
    for (int i = 1; i < (1 << N); i++) {
      for (int j = 0; j < N; j++) {
        if (((i >> j) & 1) == 1 && ((i ^ (1 << j)) & graph[j]) == 0) dp[i] += dp[i ^ (1 << j)];
      }
    }
    System.out.println(dp[(1 << N) - 1]);
  }
}