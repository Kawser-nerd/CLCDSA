import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {
 
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);

    int n = scanner.nextInt();
    long c = scanner.nextLong();
    long[] xx = new long[n];
    long[] vv = new long[n];
    long[] rxx = new long[n];
    long[] rvv = new long[n];

    for (int i = 0 ; i < n ; i ++) {
      xx[i] = scanner.nextLong();
      vv[i] = scanner.nextLong();
      rxx[n - i - 1] = c - xx[i];
      rvv[n - i - 1] = vv[i];
    }

    long a = calc(xx, vv, n, c);
    long b = calc(rxx, rvv, n, c);

    if (a > b) {
      System.out.println(a);
    } else {
      System.out.println(b);
    }
  }

  private long calc(long[] xx, long[] vv, int n, long c) {
    long max;
    long cur;
    long[] maxs = new long[n + 1];

    max = 0;
    cur = 0;
    for (int j = n - 1 ; j >= 0 ; j --) {
      long px = (j == n - 1) ? c : xx[j + 1];
      cur += vv[j] - (px - xx[j]);
      if (cur > max) {
        max = cur;
      }
      maxs[j] = max;
    }

    max = 0;
    cur = 0;
    for (int i = 0 ; i < n ; i ++) {
      long px = (i == 0) ? 0 : xx[i - 1];
      cur += vv[i] - (xx[i] - px);
      long s = cur - xx[i] + maxs[i + 1];
      if (s > max) {
        max = s;
      }
      if (cur > max) {
        max = cur;
      }
    }
    return max;
  }

  public static void main(String[] args) {
    Main main = new Main();
    main.run();
  }
 
  // scanner slightly faster than usual ones
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
 
    private boolean isPrintableChar(int codePoint) {
      return codePoint >= 33 && codePoint <= 126;
    }
 
  }
 
}