import java.util.Scanner;

public class Main {
  
  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    
    int H = Integer.parseInt(sc.next());
    int W = Integer.parseInt(sc.next());
    int A = Integer.parseInt(sc.next());
    int B = Integer.parseInt(sc.next());
    final long mod = 1000000007;
    combination c = new combination(H + W, mod);
    int x = B + 1;
    int y = H - A;
    long ans = 0;
    while (1 <= x && x <= W && 1 <= y && y <= H) {
      ans = (ans + c.C(x - 1 + y - 1, x - 1) * c.C(W - x + H - y, W - x) % mod) % mod;
      x++;
      y--;
    }
    System.out.println(ans);
  }
  
  static class combination {
    public int n;
    public long p;
    public long factTable[];
    public long reverceTable[];
    
    public combination(int n, long p) {
      this.n = n;
      this.p = p;
      factTable = new long[n + 1];
      factTable[0] = 1;
      for (int i = 1; i <= n; i++) {
        factTable[i] = factTable[i - 1] * i % p;
      }
      reverceTable = new long[n + 1];
      reverceTable[0] = 1;
      reverceTable[n] = 1;
      long x = factTable[n];
      long m = p - 2;
      while (m > 0) {
        if ((m & 1) == 1) {
          reverceTable[n] = reverceTable[n] * x % p;
        }
        x = x * x % p;
        m >>= 1;
      }
      for (int i = n - 1; i > 0; i--) {
        reverceTable[i] = reverceTable[i + 1] * (i + 1) % p;
      }
    }
    
    public long C(int n, int r) {
      if (r < 0 || n < r) {
        return 0;
      } else {
        return (factTable[n] * reverceTable[r] % p) * reverceTable[n - r] % p;
      }
    }
  }
  
}