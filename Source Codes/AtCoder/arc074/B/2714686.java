import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  @SuppressWarnings("unchecked") 
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);
  
    int n = scanner.nextInt();
    
    int[] aa = new int[3 * n];
    for (int i = 0 ; i < 3 * n ; i ++) {
      aa[i] = scanner.nextInt();
    }

    PriorityQueue<Integer> lefts = new PriorityQueue<>();
    PriorityQueue<Integer> rights = new PriorityQueue<>((a1, a2) -> a2 - a1);

    long l = 0;
    long r = 0;
    for (int i = 0 ; i < n ; i ++) {
      lefts.add(aa[i]);
      l += aa[i];
    }
    for (int i = 2 * n ; i < 3 * n ; i ++) {
      rights.add(aa[i]);
      r += aa[i];
    }

    long[] ll = new long[n + 1];
    long[] rr = new long[n + 1];
    ll[0] = l;
    rr[n] = r;
    for (int i = 1 ; i <= n ; i ++) {
      lefts.add(aa[n + i - 1]);
      int a = lefts.poll();
      l += aa[n + i - 1] - a;
      ll[i] = l;
    }
    for (int i = n - 1 ; i >= 0 ; i --) {
      rights.add(aa[n + i]);
      int a = rights.poll();
      r += aa[n + i] - a;
      rr[i] = r;
    }

    long max = Long.MIN_VALUE;
    for (int i = 0 ; i <= n ; i ++) {
      if (ll[i] - rr[i] > max) {
        max = ll[i] - rr[i];
      }
    }
    System.out.println(max);
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