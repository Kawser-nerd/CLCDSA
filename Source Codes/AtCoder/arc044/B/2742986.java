import java.io.*;
import java.util.*;


public class Main implements Runnable {

  public static final int MOD = 1000000007;

  @SuppressWarnings("unchecked")
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);
    
    int n = scanner.nextInt();
    int[] aa = new int[n];
    long[] nums = new long[n];
    for (int i = 0 ; i < n ; i ++) {
      aa[i] = scanner.nextInt();
      nums[aa[i]] ++;
      if (i != 0 && aa[i] == 0) {
        System.out.println(0);
        return;
      }
    }
    if (aa[0] != 0) {
      System.out.println(0);
      return;
    }
    
    long res = 1;
    for (int i = 1 ; i < n ; i ++) {
      if (nums[i] > 0) {
        res *= pow(pow(2, nums[i - 1]) - 1, nums[i]);
        res %= MOD;
        res *= pow(2, (nums[i] * (nums[i] - 1)) / 2);
        res %= MOD;
      }
      // System.out.println(res);
    }
    
    System.out.println(res);
  }

  public long div(long a, long b) {
    return a * pow(b, MOD - 2) % MOD;
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
 
    private boolean isPrintableChar(int codePoint) {
      return codePoint >= 33 && codePoint <= 126;
    }
 
  }
 
}