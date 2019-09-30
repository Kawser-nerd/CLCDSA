import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Prizes implements Runnable {
  private static final String NAME = "prize";

  BigInteger[] pow;
  BigInteger two = new BigInteger("2");

  private BigInteger next(BigInteger p) {
    return p.add(BigInteger.ONE).multiply(two).subtract(BigInteger.ONE);
  }
  private BigInteger gar(int n, BigInteger p) {
    if (n == 1) {
      return p;
    }

    if (p.compareTo(pow[n - 1]) < 0) return BigInteger.ZERO;

    BigInteger prev = gar(n - 1, p.subtract(pow[n - 1]));
    if (prev.equals(pow[n - 1].subtract(BigInteger.ONE))) return pow[n].subtract(BigInteger.ONE);
    return next(prev.add(BigInteger.ONE)).subtract(BigInteger.ONE);
  }

  private BigInteger possible(int n, BigInteger p) {
    if (n == 1) {
      return BigInteger.ONE.subtract(p);
    }

    if (p.compareTo(pow[n - 1]) < 0) {
      BigInteger prev = possible(n - 1, p);
      return next(prev);
    } else {
      BigInteger prev = possible(n - 1, p.subtract(pow[n - 1]));
      return prev.min(BigInteger.ONE);
    }
  }


  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      pow = new BigInteger[52];
      pow[0] = BigInteger.ONE;
      for (int i = 1; i <= 51; i++) {
        pow[i] = pow[i - 1].multiply(two);
      }

      for (int test = 1; test <= tests; test++) {
        int n = in.nextInt();
        String s = in.next();

        BigInteger p = new BigInteger(s).subtract(BigInteger.ONE);

        out.println("Case #" + test + ": " + gar(n, p) + " " + pow[n].subtract(BigInteger.ONE).subtract(possible(n, p)));
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Prizes()).start();
  }

  private class P implements Comparable<P> {
    long d;
    long num;
    int in;

    private P(long d, long num, int in) {
      this.d = d;
      this.num = num;
      this.in = in;
    }

    @Override
    public int compareTo(P p) {
      if (d < p.d) return - 1;
      if (d > p.d) return 1;
      return in - p.in;
    }
  }
}
