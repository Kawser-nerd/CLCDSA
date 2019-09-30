import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  int[] DX = new int[]{-1, 1, 0, 0};
  int[] DY = new int[]{0, 0, -1, 1};

  @SuppressWarnings("unchecked") 
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);

    int n = scanner.nextInt();
    String s = scanner.next();

    boolean[] bb = new boolean[n];
    for (int i = 0 ; i < n ; i ++) {
      bb[i] = !((s.charAt((i + 1) % n) == 'o') ^ (s.charAt((i + 2) % n) == 'o'));
    }

    int[] ress = new int[n];
    boolean pos = false;
    if (n % 3 == 0) {
      outer: for (int k0 = 0 ; k0 <= 1 ; k0 ++) {
        for (int k1 = 0 ; k1 <= 1 ; k1 ++) {
          for (int k2 = 0 ; k2 <= 1 ; k2 ++) {
            ress[0] = k0;
            ress[1] = k1;
            ress[2] = k2;
            for (int i = 3 ; i < n ; i ++) {
              ress[i] = (bb[i - 3]) ? ress[i - 3] : 1 - ress[i - 3];
            }
            if (check(n, ress, s)) {
              pos = true;
              break outer;
            }
          }
        }
      }
    } else {
      for (int k = 0 ; k <= 1 ; k ++) {
        ress[0] = k;
        for (int i = 3 ; i != 0 ; i = (i + 3) % n) {
          ress[i] = (bb[(i - 3 + n) % n]) ? ress[(i - 3 + n) % n] : 1 - ress[(i - 3 + n) % n];
        }
        if (check(n, ress, s)) {
          pos = true;
          break;
        }
      }
    }

    if (pos) {
      StringBuilder output = new StringBuilder();
      for (int i = 0 ; i < n ; i ++) {
        output.append((ress[i] == 0) ? 'S' : 'W');
      }
      System.out.println(output);
    } else {
      System.out.println(-1);
    }
  }

  public boolean check(int n, int[] ress, String s) {
    for (int i = 0 ; i < n ; i ++) {
      if (ress[i] == 0) {
        if ((s.charAt(i) == 'o' && ress[(i - 1 + n) % n] != ress[(i + 1) % n]) || (s.charAt(i) == 'x' && ress[(i - 1 + n) % n] == ress[(i + 1) % n])) {
          return false;
        }
      } else {
        if ((s.charAt(i) == 'o' && ress[(i - 1 + n) % n] == ress[(i + 1) % n]) || (s.charAt(i) == 'x' && ress[(i - 1 + n) % n] != ress[(i + 1) % n])) {
          return false;
        }
      }
    }
    return true;
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