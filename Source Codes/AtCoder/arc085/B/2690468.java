import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  @SuppressWarnings("unchecked") 
  public void run() {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int z = scanner.nextInt();
    int w = scanner.nextInt();

    long[] aa = new long[n];
    for (int i = 0 ; i < n ; i ++) {
      aa[i] = scanner.nextInt();
    }

    if (n <= 1) {
      long res = Math.abs(w - aa[0]);
      System.out.println(res);
      return;
    }

    long[] xMins = new long[n - 1];
    long[] yMaxs = new long[n - 1];

    xMins[n - 2] = Math.abs(aa[n - 1] - aa[n - 2]);
    yMaxs[n - 2] = Math.abs(aa[n - 1] - aa[n - 2]);

    for (int i = n - 3 ; i >= 0 ; i --) {
      long x = Math.max(yMaxs[i + 1], Math.abs(aa[i] - aa[n - 1]));
      xMins[i] = Math.min(x, xMins[i + 1]);
      long y = Math.min(xMins[i + 1], Math.abs(aa[i] - aa[n - 1]));
      yMaxs[i] = Math.max(y, yMaxs[i + 1]);
    }

    long res = Math.max(yMaxs[0], Math.abs(w - aa[n - 1]));
    System.out.println(res);
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
 
    private boolean isPrintableChar(int codePoint) {
      return codePoint >= 33 && codePoint <= 126;
    }
 
  }
 
}