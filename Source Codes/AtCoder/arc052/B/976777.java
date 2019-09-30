import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int q = s.nextInt();
    double[] x = new double[n];
    double[] r = new double[n];
    double[] h = new double[n];
    for (int i = 0; i < n; i++) {
      x[i] = s.nextDouble();
      r[i] = s.nextDouble();
      h[i] = s.nextDouble();
    }
    for (int j = 0; j < q; j++) {
      double a = s.nextDouble();
      double b = s.nextDouble();
      double mass = 0.0;
      for (int i = 0; i < n; i++) {
        if (x[i] <= a && a <= x[i] + h[i] && x[i] + h[i] <= b) {
          double h1 = x[i] + h[i] - a;
          double r1 = r[i] * h1 / h[i];
          mass += Math.PI * r1 * r1 * h1 / 3.0;
        } else if (x[i] <= a && b <= x[i] + h[i]) {
          double h1 = x[i] + h[i] - a;
          double r1 = r[i] * h1 / h[i];
          double h2 = x[i] + h[i] - b;
          double r2 = r[i] * h2 / h[i];
          mass += Math.PI * (r1 * r1 * h1 - r2 * r2 * h2) / 3.0;
        } else if (a <= x[i] && x[i] <= b && b <= x[i] + h[i]) {
          double h2 = x[i] + h[i] - b;
          double r2 = r[i] * h2 / h[i];
          mass += Math.PI * (r[i] * r[i] * h[i] - r2 * r2 * h2) / 3.0;
        } else if (a <= x[i] && x[i] + h[i] <= b) {
          mass += Math.PI * r[i] * r[i] * h[i] / 3.0;
        }
      }
      System.out.printf("%.20f\n", mass);
    }
  }
}