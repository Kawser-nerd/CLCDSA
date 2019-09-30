import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long Q = sc.nextLong();
    long H = sc.nextLong();
    long S = sc.nextLong();
    long D = sc.nextLong();
    long N = sc.nextLong();
    long min1l = Math.min(Math.min(4 * Q, 2 * H), S);
    long min2l = Math.min(Math.min(8 * Q, 4 * H), Math.min(2 * S, D));
    long ans = 0;
    if (N % 2 == 1) {
      ans = (N - 1) / 2 * min2l + min1l;
    } else {
      ans = N / 2 * min2l;
    }
    System.out.println(ans);
  }
}