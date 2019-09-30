import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    final Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    long c = scanner.nextLong();
    long[] x = new long[n + 1];
    long[] v = new long[n + 1];
    for (int i = 0; i < n; i++) {
      x[i + 1] = scanner.nextLong();
      v[i + 1] = scanner.nextLong();
    }
    System.out.println(solve(n + 1, c, x, v));
  }

  private static long solve(int n, long c, long[] x, long[] v) {
    long res = 0;

    long sum = 0;
    long[] rsum = new long[n];
    for (int i = 1; i < n; i++) {
      rsum[i] = rsum[i - 1];
      sum += v[i];
      if (sum - x[i] * 2 > rsum[i]) {
        rsum[i] = sum - x[i] * 2;
      }
    }
    sum = 0;
    long[] lsum = new long[n];
    for (int i = 1; i < n; i++) {
      lsum[i] = lsum[i - 1];
      sum += v[n - i];
      if (sum - (c - x[n - i]) * 2 > lsum[i]) {
        lsum[i] = sum - (c - x[n - i]) * 2;
      }
    }

    // Start at 0 and exit at right
    sum = 0;
    for (int right = 0; right < n; right++) {
      sum += v[right];
      long r = sum - x[right];
      if (r > res) res = r;
    }
    // Start at 0, go to right and then back to left, then exit there
    sum = 0;
    for (int left = n - 1; left > 0; left--) {
      sum += v[left];
      long r = sum + rsum[left - 1] - (c - x[left]);
      if (r > res) res = r;
    }

    // Start at 0 and exit at left
    sum = 0;
    for (int left = n - 1; left >= 0; left--) {
      sum += v[left];
      long r = sum - (c - x[left]);
      if (r > res) res = r;
    }
    // Start at 0, go to left and then back to right, then exit there
    sum = 0;
    for (int right = 1; right < n; right++) {
      sum += v[right];
      long r = lsum[n - right - 1] + sum - x[right];
      if (r > res) res = r;
    }

    return res;
  }
}