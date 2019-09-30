import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  public static final int MOD = 1000000007;

  @SuppressWarnings("unchecked") 
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);

    int n = scanner.nextInt();
    int m = scanner.nextInt();

    long[] xx = scanner.nextLongArray(n);
    long[] yy = scanner.nextLongArray(m);

    long left = 0;
    for (int i = 1 ; i < m ; i ++) {
      long a = n - 1;
      a *= i;
      a %= MOD;
      a *= m - i;
      a %= MOD;
      a *= xx[1] - xx[0];
      a %= MOD;
      a *= yy[i] - yy[i - 1];
      a %= MOD;
      left += a;
      left %= MOD;
    }

    long res = left;
    long prev = left;
    for (int i = 2 ; i < n ; i ++) {
      prev *= i;
      prev %= MOD;
      prev *= pow(i - 1, MOD - 2);
      prev %= MOD;
      prev *= n - i;
      prev %= MOD;
      prev *= pow(n - i + 1, MOD - 2);
      prev %= MOD;
      prev *= xx[i] - xx[i - 1];
      prev %= MOD;
      prev *= pow(xx[i - 1] - xx[i - 2], MOD - 2);
      prev %= MOD;
      res += prev;
      res %= MOD;
    }

    System.out.println(res);
  }

  public long pow(long a, long b) {
    if (b == 0) {
      return 1;
    } else if (b % 2 == 0) {
      long d = pow(a, b / 2);
      return (d * d) % MOD;
    } else {
      long d = pow(a, b - 1);
      return (a * d) % MOD;
    }
  }

  public static void main(String[] args) {
    Main main = new Main();
    main.run();
  }
 
  public static class BetterScanner {
 
    private InputStream stream;
    private byte[] buffer = new byte[1024];
    private int pointer = 0;
    private int bufferLength = 0;
 
    public BetterScanner(InputStream stream) {
      this.stream = stream;
    }
 
    private boolean updateBuffer() {
      if (pointer >= bufferLength) {
        pointer = 0;
        try {
          bufferLength = stream.read(buffer);
        } catch (IOException exception) {
          exception.printStackTrace();
        }
        return bufferLength > 0;
      } else {
        return true;
      }
    }
 
    private int read() {
      if (updateBuffer()) {
        return buffer[pointer ++];
      } else {
        return -1;
      }
    }
 
    public boolean hasNext() {
      skipUnprintable();
      return updateBuffer();
    }
 
    private void skipUnprintable() { 
      while (updateBuffer() && !isPrintableChar(buffer[pointer])) {
        pointer ++;
      }
    }
 
    public String next() {
      if (hasNext()) {
        StringBuilder builder = new StringBuilder();
        int codePoint = read();
        while (isPrintableChar(codePoint)) {
          builder.appendCodePoint(codePoint);
          codePoint = read();
        }
        return builder.toString();
      } else {
        throw new NoSuchElementException();
      }
    }
 
    public long nextLong() {
      if (hasNext()) {
        long number = 0;
        boolean minus = false;
        int codePoint = read();
        if (codePoint == '-') {
          minus = true;
          codePoint = read();
        }
        if (codePoint >= '0' && codePoint <= '9') {
          while (true) {
            if (codePoint >= '0' && codePoint <= '9') {
              number *= 10;
              number += codePoint - '0';
            } else if (codePoint < 0 || !isPrintableChar(codePoint)) {
              return (minus) ? -number : number;
            } else {
              throw new NumberFormatException();
            }
            codePoint = read();
          }
        } else {
          throw new NumberFormatException();
        }
      } else {
        throw new NoSuchElementException();
      }
    }
 
    public int nextInt() {
      long number = nextLong();
      if (number >= Integer.MIN_VALUE && number <= Integer.MAX_VALUE) {
        return (int)number;
      } else {
        throw new NumberFormatException();
      }
    }

    public long[] nextLongArray(int n) {
      long[] array = new long[n];
      for (int i = 0 ; i < n ; i ++) {
        array[i] = nextLong();
      }
      return array;
    }

    public int[] nextIntArray(int n) {
      int[] array = new int[n];
      for (int i = 0 ; i < n ; i ++) {
        array[i] = nextInt();
      }
      return array;
    }
 
    private boolean isPrintableChar(int codePoint) {
      return codePoint >= 33 && codePoint <= 126;
    }
 
  }
 
}