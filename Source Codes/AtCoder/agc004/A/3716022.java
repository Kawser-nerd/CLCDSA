import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long A = sc.nextLong();
    long B = sc.nextLong();
    long C = sc.nextLong();
    long ans1 = Math.abs((A / 2 - (A - A / 2)) * B * C);
    long ans2 = Math.abs(A * (B / 2 - (B - B / 2)) * C);
    long ans3 = Math.abs(A * B * (C / 2 - (C - C / 2)));
    long ans = Math.min(Math.min(ans1, ans2), ans3);
    System.out.println(ans);
  }
}