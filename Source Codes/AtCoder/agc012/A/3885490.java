import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] a = new long[3 * N];
    for (int i = 0; i < 3 * N; i++) {
      a[i] = sc.nextLong();
    }
    Arrays.sort(a);
    long ans = 0L;
    for (int i = 1; i <= N; i++) {
      ans += a[3 * N - 2 * i];
    }
    System.out.println(ans);
  }
}