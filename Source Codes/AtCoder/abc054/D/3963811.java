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
    int[][] dp1 = new int[M + 1][M + 1];
    int[][] dp2 = new int[M + 1][M + 1];
    for (int i = 0; i <= M; i++) for (int j = 0; j <= M; j++) dp1[i][j] = INF;
    dp1[0][0] = 0;
    for (int j = 0; j <= M; j++) System.arraycopy(dp1[j], 0, dp2[j], 0, M + 1);

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        for (int k = 1; k <= M; k++) {
          if(j >= a[i] && k >= b[i]) {
            dp2[j][k] = Math.min(dp2[j][k], dp1[j - a[i]][k - b[i]] + c[i]);
          }
        }
      }
      for (int j = 0; j <= M; j++) System.arraycopy(dp2[j], 0, dp1[j], 0, M + 1);
    }

    //for (int i = 1; i <= M; i++) {
    //  for (int j = 1; j <= M; j++) {
    //    if (dp2[i][j] >= INF) System.out.print("? ");
    //    else System.out.printf("%d ", dp2[i][j]);
    //  }
    //  System.out.println();
    //}

    int min = INF;
    for (int i = 1; i <= M; i++)
      for (int j = 1; j <= M; j++)
        if (Ma * j == Mb * i) min = Math.min(min, dp2[i][j]);

    if (min >= INF) {
      System.out.println(-1);
    } else {
      System.out.println(min);
    }
  }
}