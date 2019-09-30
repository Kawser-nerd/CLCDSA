import java.util.Scanner;

public class Main {
  static final long M = 998244353L;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    long K = scanner.nextLong();

    System.out.println(solve(N, A, B, K));
  }

  private static long solve(int N, long A, long B, long K) {
    if (A > B) return solve(N, B, A, K);

    long[] C = chooseForN(N, M);

    long res = 0;
    for (int i = 0; i <= Math.min(N, K / B); i++) {
      if ((K - B * i) % A == 0) {
        long j = (K - B * i) / A;
        if (j > N) continue;
        res += C[i] * C[(int) j] % M;
        res %= M;
      }
    }
    return res;
  }

  private static long[] chooseForN(int n, long mod) {
    long[] C = new long[n + 1];
    long[] fact = new long[n + 1];
    long[] factinv = new long[n + 1];

    fact[0] = 1;
    for (int i = 0; i < n; i++) fact[i + 1] = fact[i] * (n - i) % mod;
    factinv[0] = 1;
    for (int i = 1; i <= n; i++) factinv[i] = factinv[i - 1] * inverse(i, mod) % mod;

    for (int i = 0; i <= n; i++) C[i] = fact[i] * factinv[i] % mod;

    return C;
  }

  private static long inverse(long a, long mod) {
    return modpow(a, mod - 2, mod);
  }

  private static long modpow(long a, long n, long mod) {
    long res = 1;
    while (n > 0) {
      if (n % 2 == 1) res = (res * a) % mod;
      a = (a * a) % mod;
      n >>= 1;
    }
    return res % mod;
  }
}