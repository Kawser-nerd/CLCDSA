import java.util.*;
import java.math.*;

public class Main {
  private static double f(double x, double p) {
    return x + p / Math.pow(2, x / 1.5);
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    double p = s.nextDouble();
    double xmax = p;
//    System.out.println(xmax);
    double xmin = 0.0;
    for (int i = 0; i < 512; i++) {
//      System.out.printf("%f %f\n", xmin, xmax);
      double xmid1 = (xmax - xmin)/3.0 + xmin;
      double xmid2 = 2.0*(xmax - xmin)/3.0 + xmin;
      if (f(xmid1, p) < f(xmid2, p)) {
        xmax = xmid2;
      } else {
        xmin = xmid1;
      }
    }
    System.out.printf("%.20f\n", f(xmax, p));
  }
}