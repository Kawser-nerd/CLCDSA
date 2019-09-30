import java.util.*;

public class Main {
  static long mod = 1000000007;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    HashMap<Integer, Integer> p = new HashMap<>();
    for (int i = 2; i * i <= M; i++) {
      while (M % i == 0) {
        if (p.containsKey(i)) {
          p.put(i, p.get(i) + 1);
        } else {
          p.put(i, 1);
        }
        M /= i;
      }
    }
    if (M != 1) {
      if (p.containsKey(M)) {
        p.put(M, p.get(M) + 1);
      } else {
        p.put(M, 1);
      }
    }
    long ans = 1;
    for (Integer b : p.values()) {
      ans *= calcComb(b + (N - 1), b);
      ans %= mod;
    }
    System.out.println(ans);
  }

  // ??????
  public static long calcPow(long b, long n) {
    if (n == 0) {
      return 1;
    }
    if (n % 2 == 0) {
      long tmp = calcPow(b, n / 2);
      tmp %= mod;
      return tmp * tmp % mod;
    } else {
      b %= mod;
      long tmp = calcPow(b, n - 1);
      tmp %= mod;
      return b * tmp % mod;
    }
  }

  // ?????
  public static long calcInv(long n) {
    // a^{-1}=a^{p-2}(mod p)
    return calcPow(n, mod - 2) % mod;
  }

  // ??????
  public static long calcComb(long n, long r) {
    long divA = 1; // nPr???
    long divB = 1; // r!^{-1}???
    for (int i = 0; i < r; i++) {
      divA *= n - i;
      divA %= mod;
    }
    for (int i = 0; i < r; i++) {
      divB *= r - i;
      divB %= mod;
    }
    divB = calcInv(divB);
    divB %= mod;
    return divA * divB % mod;
  }
}