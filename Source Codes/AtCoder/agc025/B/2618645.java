import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    int N = Integer.parseInt(sc.next());
    long A = Long.parseLong(sc.next());
    long B = Long.parseLong(sc.next());
    long K = Long.parseLong(sc.next());

    final long p = 998244353;

    combination nC = new combination(N, p);

    long ans = 0;
    long b = 0;
    for (int a = 0; a <= N; a++) {
      b = (K - A * a) / B;
      if (A * a > K) {
        break;
      } else if ((K - A * a) % B != 0 || b > (long) N) {
        continue;
      } else {
        ans += (nC.C(a, p) * nC.C((int) b, p)) % p;
      }
    }
    System.out.println(ans % p);
  }

  static class combination {
    public int n;
    public long nfact;
    public long reverceTable[];

    public combination(int n, long p) {
      this.n = n;
      reverceTable = new long[n + 1];
      reverceTable[0] = 1;
      nfact = 1;
      for (int i = 1; i < n + 1; i++) {
        nfact = nfact * i % p;
      }
      long sum = 1;
      long x = nfact;
      long m = p - 2;
      while (m > 0) {
        if ((m & 1) == 1) {
          sum = sum * x % p;
        }
        x = x * x % p;
        m >>= 1;
      }
      reverceTable[n] = sum;
      for (int i = n - 1; i > 0; i--) {
        reverceTable[i] = reverceTable[i + 1] * (i + 1) % p;
      }
    }

    public long C(int r, long p) {
      if (r < 0 || r > n) {
        return 0;
      } else {
        return (nfact * reverceTable[r] % p) * reverceTable[n - r] % p;
      }
    }
  }
}