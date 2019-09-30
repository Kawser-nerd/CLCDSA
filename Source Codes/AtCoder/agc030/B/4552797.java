import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int L = scanner.nextInt();
    int N = scanner.nextInt();
    int[] x = new int[N];
    int[] y = new int[N];
    for (int i = 0; i < N; i++) {
      x[i] = scanner.nextInt();
      y[N - i - 1] = L - x[i];
    }
    long[] x2 = new long[N + 1];
    long[] y2 = new long[N + 1];
    for (int i = 1; i <= N; i++) x2[i] = x2[i - 1] + x[i - 1] * 2L;
    for (int i = 1; i <= N; i++) y2[i] = y2[i - 1] + y[i - 1] * 2L;

    long max = x[N - 1];
    for (int n = N - 1; n > 0; n--) {
      int m = N - n;
      max = Math.max(max, Math.max(
          x2[n - 1] - x2[Math.max(n - m - 1, 0)] + y2[m] - y2[Math.max(m - n, 0)] + x[n - 1],
          x2[n] - x2[Math.max(n - m, 0)] + y2[m - 1] - y2[Math.max(m - n - 1, 0)] + y[m - 1]
      ));
    }
    max = Math.max(max, y[N - 1]);
    System.out.println(max);
  }
}