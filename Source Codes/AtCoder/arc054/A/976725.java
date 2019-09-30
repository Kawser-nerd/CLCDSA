import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    double l = sc.nextDouble();
    double x = sc.nextDouble();
    double y = sc.nextDouble();
    double s = sc.nextDouble();
    double d = sc.nextDouble();
    double time = 1e200;
    if (d >= s) {
      time = Math.min(time, (d - s) / (x + y));
    } else {
      time = Math.min(time, (d + l - s) / (x + y));
    }

    if (y > x) {
      if (s >= d) {
        time = Math.min(time, (s - d) / (y - x));
      } else {
        time = Math.min(time, (s + l - d) / (y - x));
      }
    }
    System.out.printf("%.40f\n", time);
  }
}