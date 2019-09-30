import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int X = sc.nextInt();
    int Y = sc.nextInt();
    int money = 0;

    if (A + B < 2 * C) {
      money = A * X + B * Y;
    } else {
      if (X > Y) {
        money = Math.min(C * Y * 2 + A * (X - Y), C * X * 2);
      } else {
        money = Math.min(C * X * 2 + B * (Y - X), C * Y * 2);
      }
    }

    System.out.println(money);
  }
}