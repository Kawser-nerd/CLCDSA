import java.util.Arrays;
import java.util.Scanner;

class Main {

  public static void reverse(int[] A) {
    for (int i = 0; i < A.length / 2; i++) {
      int tmp = A[i];
      A[i] = A[A.length - i - 1];
      A[A.length - i - 1] = tmp;
    }
  }

  private static final int[] num = { 999999, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

  private static final int INF = Integer.MAX_VALUE / 4;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = Integer.parseInt(scanner.next());
    int M = Integer.parseInt(scanner.next());
    int[] A = new int[M];
    for (int i = 0; i < M; i++) {
      A[i] = Integer.parseInt(scanner.next());
    }
    Arrays.sort(A);
    reverse(A);
    int[] dp = new int[10010];
    Arrays.fill(dp, -INF);
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < M; j++) {
        if (i - num[A[j]] >= 0) {
          dp[i] = Math.max(dp[i], dp[i - num[A[j]]] + 1);
        }
      }
    }
    String ans = "";
    int goal = dp[N];
    for (int k = 0; k < goal; k++) {
      for (int i = 0; i < M; i++) {
        if (N - num[A[i]] >= 0 && dp[N] != 0 && dp[N - num[A[i]]] == dp[N] - 1) {
          ans += A[i];
          N -= num[A[i]];
          break;
        }
      }
    }
    System.out.println(ans);
  }

}