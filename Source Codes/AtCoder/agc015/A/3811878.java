import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long A = sc.nextLong();
    long B = sc.nextLong();
    long min = A * (N - 1) + B;
    long max = B * (N - 1) + A;
    long ans = Math.max(0, max - min + 1);
    System.out.println(ans);
  }
}