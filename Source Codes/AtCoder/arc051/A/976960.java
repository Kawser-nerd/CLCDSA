import java.util.*;
import java.math.*;

public class Main {
  private static boolean blueVisible(double x, double y, double x1, double y1, double r) {
    double dx = x - x1;
    double dy = y - y1;
    return dx*dx + dy*dy > r*r;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    double x1 = s.nextDouble();
    double y1 = s.nextDouble();
    double r = s.nextDouble();
    double x2 = s.nextDouble();
    double y2 = s.nextDouble();
    double x3 = s.nextDouble();
    double y3 = s.nextDouble();
    System.out.println(
        (x1 + r > x3 ||
         x1 - r < x2 ||
         y1 + r > y3 ||
         y1 - r < y2) ? "YES" : "NO");
    System.out.println(
       (blueVisible(x2, y2, x1, y1, r) ||
        blueVisible(x2, y3, x1, y1, r) ||
        blueVisible(x3, y3, x1, y1, r) ||
        blueVisible(x3, y2, x1, y1, r)) ? "YES" : "NO");
  }
}