import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] x = new int[N];
    int[] y = new int[N];
    for (int i = 0; i < N; i++) {
      x[i] = scanner.nextInt();
      y[i] = scanner.nextInt();
    }

    long[] count = new long[3];
    double eps = 1e-9;
    for (int i = 0; i < N; i++) {
      ArrayList<Double> tlist = new ArrayList<>();
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        double t = Math.atan2(y[j] - y[i], x[j] - x[i]);
        tlist.add(t);
        tlist.add(t + 2 * Math.PI);
      }
      Collections.sort(tlist);

      for (int j = 0; j < N - 1; j++) {
        Double dt = tlist.get(j);
        int k1 = upperBound(tlist, Math.PI / 2 + dt - eps);
        int k2 = lowerBound(tlist, Math.PI / 2 + dt + eps);
        int k3 = upperBound(tlist, Math.PI + dt - eps);
        count[1] += k2 - k1 - 1;
        count[2] += k3 - k2 + 1;
      }
    }
    count[0] = (long) N * (N - 1) * (N - 2) / 6 - count[1] - count[2];
    System.out.printf("%d %d %d\n", count[0], count[1], count[2]);
  }

  private static int lowerBound(ArrayList<Double> a, double k) {
    int left = -1;
    int right = a.size();
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (Double.compare(a.get(mid), k) > 0) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  }

  private static int upperBound(ArrayList<Double> a, double k) {
    int left = -1;
    int right = a.size();
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (Double.compare(a.get(mid), k) < 0) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return left;
  }
}