import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int W = scanner.nextInt();
    int[] v = new int[N];
    int[] w = new int[N];
    int maxv = 0;
    int maxw = 0;
    for (int i = 0; i < N; i++) {
      v[i] = scanner.nextInt();
      w[i] = scanner.nextInt();
      maxv = Math.max(maxv, v[i]);
      maxw = Math.max(maxw, w[i]);
    }

    if (N <= 30) {
      System.out.println(solveN(N, W, v, w));
    } else if (maxv <= 1000) {
      System.out.println(solveV(N, W, v, w));
    } else {
      System.out.println(solveW(N, W, v, w));
    }
  }

  private static long solveN(int N, int W, int[] v, int[] w) {
    long[][] a = new long[1 << (N / 2)][2];
    long[][] b = new long[1 << (N - N / 2)][2];
    for (int i = 1; i < 1 << (N / 2); i++) {
      int j = msb(i) - 1;
      a[i][0] = a[i ^ (1 << j)][0] + w[j];
      a[i][1] = a[i ^ (1 << j)][1] + v[j];
    }
    for (int i = 1; i < 1 << (N - N / 2); i++) {
      int j = msb(i) - 1;
      b[i][0] = b[i ^ (1 << j)][0] + w[j + N / 2];
      b[i][1] = b[i ^ (1 << j)][1] + v[j + N / 2];
    }

    Arrays.sort(b, Comparator.comparingLong(t -> t[0]));
    for (int i = 1; i < 1 << (N - N / 2); i++) {
      b[i][1] = Math.max(b[i][1], b[i - 1][1]);
    }

    long max = 0;
    for (int i = 0; i < 1 << (N / 2); i++) {
      long aw = a[i][0];
      long av = a[i][1];
      int left = -1;
      int right = b.length;
      while (right - left > 1) {
        int mid = (left + right) / 2;
        if (b[mid][0] <= W - aw) {
          left = mid;
        } else {
          right = mid;
        }
      }
      if (left >= 0) max = Math.max(max, av + b[left][1]);
    }
    return max;
  }

  private static int msb(int n) {
    int i = 0;
    while (n > 0) {
      n /= 2;
      i++;
    }
    return i;
  }

  private static long solveV(int N, int W, int[] v, int[] w) {
    int MAX_V = 1000 * N;
    long INF = 10_000_000_000L;
    long[][] dp = new long[N + 1][MAX_V + 1];
    for (int i = 1; i <= MAX_V; i++) dp[0][i] = INF;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= MAX_V; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= v[i - 1]) {
          dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
        }
      }
    }
    for (int i = MAX_V; i >= 0; i--) {
      if (dp[N][i] <= W) return i;
    }
    throw new IllegalStateException();
  }

  private static long solveW(int N, int W, int[] v, int[] w) {
    int MAX_W = Math.min(W, 1000 * N);
    long[][] dp = new long[N + 1][MAX_W + 1];
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= MAX_W; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= w[i - 1]) {
          dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
      }
    }
    long max = 0;
    for (int i = 0; i <= MAX_W; i++) {
      max = Math.max(max, dp[N][i]);
    }
    return max;
  }
}