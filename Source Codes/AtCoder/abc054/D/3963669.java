import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int Ma = scanner.nextInt();
    int Mb = scanner.nextInt();
    int[] a = new int[N + 1];
    int[] b = new int[N + 1];
    int[] c = new int[N + 1];

    for (int i = 1; i <= N; i++) {
      a[i] = scanner.nextInt();
      b[i] = scanner.nextInt();
      c[i] = scanner.nextInt();
    }

    int INF = 1_000_000;
    int M = 400;
    int[][][] dp = new int[N + 1][M + 1][M + 1];
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= M; j++)
        for (int k = 0; k <= M; k++) dp[i][j][k] = INF;
    for (int i = 0; i <= N; i++) dp[i][0][0] = 0;

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        for (int k = 1; k <= M; k++) {
          dp[i][j][k] = dp[i - 1][j][k];
          if(j >= a[i] && k >= b[i]) {
            dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j - a[i]][k - b[i]] + c[i]);
          }
        }
      }
    }

    //for (int i = 1; i <= N; i++) {
    //  System.out.printf("N = %d\n", i);
    //  for (int j = 1; j <= M; j++) {
    //    for (int k = 1; k <= M; k++) {
    //      if (dp[i][j][k] >= INF) System.out.print("? ");
    //      else System.out.printf("%d ", dp[i][j][k]);
    //    }
    //    System.out.println();
    //  }
    //}

    int min = INF;
    for (int i = 1; i <= M; i++)
      for (int j = 1; j <= M; j++)
        if (Ma * j == Mb * i) min = Math.min(min, dp[N][i][j]);

    if (min >= INF) {
      System.out.println(-1);
    } else {
      System.out.println(min);
    }
  }
}