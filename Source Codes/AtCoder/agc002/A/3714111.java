import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    if (a > 0 && b > 0) {
      System.out.println("Positive");
    }
    if (a == 0 || b == 0 || (a < 0 && b > 0)) {
      System.out.println("Zero");
    }
    if (a < 0 && b < 0) {
      if (Math.abs(a - b) % 2 == 1) {
        System.out.println("Positive");
      } else {
        System.out.println("Negative");
      }
    }
  }
}