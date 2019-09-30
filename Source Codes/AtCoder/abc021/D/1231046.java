import java.util.*;

public class Main {
  public static long MOD = 1000000007;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    long k = sc.nextLong();
    // ???nHk=(n+k-1)Ck
    long p1 = 1;
    long p2 = 1;
    long p3 = 1;
    for(long i = 1; i <= n + k - 1; i++) {
      p1 = (p1 * i) % MOD;
    }
    for(long i = 1; i <= k; i++) {
      p2 = (p2 * i) % MOD;
    }
    for(long i = 1; i <= n - 1; i++) {
      p3 = (p3 * i) % MOD;
    }
    long p = (p2 * p3) % MOD;
    long inv = func(p, MOD - 2);
    System.out.println((p1 * inv) % MOD);
  }

  public static long func(long a, long x) {
    if(x == 0) return 1;
    if(x % 2 == 0) {
      long t = func(a, x / 2);
      return (t * t) % MOD;
    }
    long t = func(a, (x - 1) / 2);
    t = (t * t) % MOD;
    return (t * a) % MOD;
  }
}