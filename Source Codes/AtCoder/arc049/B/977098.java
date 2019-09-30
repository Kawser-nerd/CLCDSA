import java.util.*;
import java.math.*;

public class Main {
  private static double solve(int n, double[] p, double[] c) {
    double maxt = 0.0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (p[i] > p[j]) {
          // p[i] > x > p[j]
          // c[i](p[i] - x) = c[j](x - p[j])
          // x(c[i] + c[j]) = c[i]p[i] + c[j]p[j]
          // x = (c[i]p[i] + c[j]p[j]) / (c[i] + c[j])
          double x = (c[i]*p[i] + c[j]*p[j]) / (c[i] + c[j]);
          double t = c[i]*(p[i] - x);
          maxt = Math.max(maxt, t);
        }
      }
    }
    return maxt;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    double[] x = new double[n];
    double[] y = new double[n];
    double[] c = new double[n];
    for (int i = 0; i < n; i++) {
      x[i] = s.nextDouble();
      y[i] = s.nextDouble();
      c[i] = s.nextDouble();
    }
    System.out.println(Math.max(solve(n, x, c), solve(n, y, c)));
  }
}