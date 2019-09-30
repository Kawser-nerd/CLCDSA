/**
 * Created at 18:10 on 2019/03/07
 */

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

  static FastScanner sc = new FastScanner();

  static long MOD = 1000000007;
  static BigInteger bigMOD = new BigInteger("1000000007");
  static Integer[] p = new Integer[31624];

  static long startTime;

  static BigInteger ans = BigInteger.ONE;

  public static void main(String[] args) {

    long N = sc.nextInt();
    long M = sc.nextInt();

    startTime = System.currentTimeMillis();

    for (int i=0; i<p.length; i++) {
      p[i] = 0;
    }

    for (int i=2; N != 1 && i<p.length; i++) {
      if (M % i == 0) {
        M /= i;
        p[i]++;
        i--;
      }
    }

    //????????????????????????????????
    if (M != 1) p[0] = 1;

    Arrays.sort(p, Comparator.reverseOrder());

    for (int i=0; i<p.length; i++) {
      if (p[i] == 0) break;
      ans = (H(p[i], N).multiply(ans)).mod(bigMOD);
    }

    System.out.println(ans);

    //System.out.println("(" + (System.currentTimeMillis() - startTime) + "ms)");

  }

  static BigInteger H(long n, long r) {
    return C(n+r-1, r-1);
  }

  static BigInteger C(long n, long r) {
    if (r > n/2) return C(n, n-r);
    return P(n, r).divide(P(r, r));
  }

  static BigInteger P(long n, long r) {
    if (r < 0 || r > n) return BigInteger.ZERO;
    if (r == 0) return BigInteger.ONE;
    return new BigInteger(Long.toString(n)).multiply(P(n-1, r-1));
  }

  static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    public long nextLong() {
      if (!hasNext()) throw new NoSuchElementException();
      long n = 0;
      boolean minus = false;
      int b = readByte();
      if (b == '-') {
        minus = true;
        b = readByte();
      }
      if (b < '0' || '9' < b) {
        throw new NumberFormatException();
      }
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10;
          n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
          return minus ? -n : n;
        } else {
          throw new NumberFormatException();
        }
        b = readByte();
      }
    }

    public int nextInt() {
      return (int) nextLong();
    }
  }

}