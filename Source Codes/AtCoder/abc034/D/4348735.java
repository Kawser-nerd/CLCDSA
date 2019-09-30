import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int K = scanner.nextInt();

    int[] w = new int[N];
    int[] p = new int[N];
    for (int i = 0; i < N; i++) {
      w[i] = scanner.nextInt();
      p[i] = scanner.nextInt();
    }

    double[] s = new double[N];
    double left = 0.d, right = 100.d;
    while (Math.abs(right - left) > 1e-9) {
      double mid = (left + right) / 2;
      for (int i = 0; i < N; i++) s[i] = w[i] * (p[i] - mid);
      Arrays.sort(s);
      double r = 0.d;
      for (int i = N - K; i < N; i++) r += s[i];

      if (Double.compare(r, 0.d) > 0) {
        left = mid;
      } else {
        right = mid;
      }
    }
    System.out.println(right);
  }
}