import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static final long MOD = 1_000_000_007;

  public static void main(String[] args) {
    long N = sc.nextInt();
    long K = sc.nextInt();
    if (N == 1) {
      System.out.println(K);
      return;
    }
    ArrayList<Long> divisor = new ArrayList<>();
    for (long i = 2; i * i <= N; i++) {
      if (N % i != 0) continue;
      divisor.add(i);
      if (i * i != N) {
        divisor.add(N / i);
      }
    }
    divisor.add(N);
    Collections.sort(divisor);
    HashMap<Long, Long> map = new HashMap<>();
    map.put(1L, K);
    for (long d : divisor) {
      long add = pow(K, (d + 1) / 2) - K;
      for (long i = 2; i * i <= d; i++) {
        if (d % i != 0) continue;
        add += MOD - map.get(i);
        if (i * i != d) add += MOD - map.get(d / i);
      }
      map.put(d, add % MOD);
    }
    long ans = 0;
    for (long k : map.keySet()) {
      ans += (k % 2 == 0 ? k / 2 : k) * map.get(k);
    }
    System.out.println(ans % MOD);
  }

  static long pow(long base, long p) {
    if (p == 0) return 1;
    if (p == 1) return base;
    long ret = pow(base, p / 2);
    ret = ret * ret % MOD;
    if (p % 2 == 1) {
      ret = ret * base % MOD;
    }
    return ret;
  }

}