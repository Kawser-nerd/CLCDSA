import java.util.*;

public class Main {
  private static long split(long n, long k) {
    long sum = 0;
    while (n > 0) {
      sum += n % k;
      n /= k;
    }
    return sum;
  }

  private static long solve(long n, long s) {
    long k;
    for (k = 2; k*k <= n || k < 100; k++) {
      if (split(n, k) == s) {
        return k;
      }
    }
    while (k <= n) {
      long a = n / k;
      long b = n % k;
      if ((a + b - s) % a == 0) {
        long dk = (a + b - s) / a;
        if (dk >= 0 && b - dk*a >= 0) {
          return k + dk;
        }
      }
      k = n / a + 1;
    }
    if (n == s) {
      return n+1;
    }
    return -1;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    long nl = s.nextLong();
    long sl = s.nextLong();
    System.out.println(solve(nl, sl));
  }
}