import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    long X = scanner.nextLong();
    int[] x = new int[N];
    for (int i = 0; i < N; i++) {
      x[i] = scanner.nextInt();
    }
    reverse(x);

    long sum = 0;
    long[] xcum = new long[N + 1];
    for (int i = 0; i < N; i++) {
      sum += x[i];
      xcum[i + 1] = sum;
    }

    long min = Long.MAX_VALUE;
    for (int k = 1; k <= N; k++) {
      long e = compute(xcum, k, N);
      if (e < 0) continue;
      e += k * X;
      e += N * X;
      if (min > e) min = e;
    }
    System.out.println(min);
  }

  private static long compute(long[] xcum, int k, int N) {
    long e = 0;
    long co = 5;
    for (int i = 0; i < (N - 1) / k + 1; i++) {
      if (i > 1) co += 2;
      e += co * (xcum[Math.min(k * (i + 1), xcum.length - 1)] - xcum[k * i]);
      if (e < 0) return -1;
    }
    return e;
  }

  private static void reverse(int[] x) {
    int left = 0;
    int right = x.length - 1;
    while (left < right) {
      int tmp = x[left];
      x[left] = x[right];
      x[right] = tmp;
      left++;
      right--;
    }
  }
}