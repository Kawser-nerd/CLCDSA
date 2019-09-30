import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  public static final int MOD = 1000000007;

  @SuppressWarnings("unchecked") 
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);

    int n = scanner.nextInt();
    Pair[] aa = new Pair[n];
    for (int i = 0 ; i < n ; i ++) {
      aa[i] = new Pair(scanner.nextInt(), i);
    }

    Arrays.sort(aa, (a1, a2) -> a1.fst - a2.fst);

    int res = 0;
    for (int i = 0 ; i < n ; i ++) {
      if (Math.abs(aa[i].snd - i) % 2 != 0) {
        res ++;
      }
    }

    System.out.println(res / 2);
  }

  public static void main(String[] args) {
    Main main = new Main();
    main.run();
  }

  public static class Pair {

    public int fst;
    public int snd;

    public Pair(int fst, int snd) {
      this.fst = fst;
      this.snd = snd;
    }

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