import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {
  private static BigInteger solve(BigInteger n, BigInteger m) {
    if (m.equals(BigInteger.ONE)) return n;

    n = n.subtract(BigInteger.ONE);
    m = m.subtract(BigInteger.ONE);

    BigInteger x, y, sumX, sumY;
    y = n.shiftRight(1);
    x = n.subtract(y);
    sumX = sumY = BigInteger.ONE;

    for (; m.compareTo(sumX.add(sumY)) > 0;) {
      m = m.subtract(sumX.add(sumY));

      x = x.subtract(BigInteger.ONE);
      y = y.subtract(BigInteger.ONE);

      BigInteger tx, ty, tSumX = sumX, tSumY = sumY;
      tx = x.shiftRight(1);
      x = x.subtract(tx);
      ty = y.subtract(y.shiftRight(1));
      y = y.shiftRight(1);

      if (tx.equals(x)) {
        sumX = sumX.add(tSumX);
      } else {
        sumY = sumY.add(tSumX);
      }

      if (ty.equals(x)) {
        sumX = sumX.add(tSumY);
      } else {
        sumY = sumY.add(tSumY);
      }
    }

    return m.compareTo(sumX) <= 0 ? x : y;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt(); // Scanner has functions to read ints, longs, strings, chars, etc.
    for (int i = 1; i <= t; ++i) {
      BigInteger n = in.nextBigInteger();
      BigInteger m = in.nextBigInteger();
      BigInteger sum = solve(n, m);

      sum = sum.subtract(BigInteger.ONE);
      BigInteger div = sum.shiftRight(1);
      System.out.println("Case #" + i + ": " + sum.subtract(div) + " " + div);
    }
  }
}
