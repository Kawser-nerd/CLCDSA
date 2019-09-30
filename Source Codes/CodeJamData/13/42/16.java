import java.math.*;
import java.util.*;

public class B {
  static BigInteger bin(int n) {
    return BigInteger.ONE.shiftLeft(n);
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int re = in.nextInt();
    for (int ri = 1; ri <= re; ++ri) {
      int n = in.nextInt();
      BigInteger m = in.nextBigInteger().subtract(BigInteger.ONE);

      int cnt = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (m.testBit(i)) {
          ++cnt;
        } else {
          break;
        }
      }
      BigInteger lo = null;
      if (cnt < n) {
        lo = bin(cnt + 1).subtract(BigInteger.ONE).subtract(BigInteger.ONE);
      } else {
        lo = bin(n).subtract(BigInteger.ONE);
      }

      int len = m.add(BigInteger.ONE).bitLength();
      BigInteger hi = BigInteger.ONE;
      for (int i = 1; i < len; ++i) {
        hi = hi.add(bin(n - i));
      }
      hi = hi.subtract(BigInteger.ONE);

      System.out.printf("Case #%d: %s %s\n", ri, lo, hi);
    }
  }
}

