import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  @SuppressWarnings("unchecked") 
  public void run() {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();

    int[][] costs = new int[n][n];
    for (int i = 0 ; i < n ; i ++) {
      for (int j = 0 ; j < n ; j ++) {
        costs[i][j] = scanner.nextInt();
      }
    }

    if (!warshallFloyd(n, costs)) {
      System.out.println(-1);
      return;
    }

    long res = 0;
    for (int i = 0 ; i < n ; i ++) {
      for (int j = i + 1 ; j < n ; j ++) {
        boolean needed = true;
        for (int k = 0 ; k < n ; k ++) {
          if (k == i || k == j) {
            continue;
          }
          if (costs[i][j] >= costs[i][k] + costs[k][j]) {
            needed = false;
            break;
          }
        }
        if (needed) {
          res += costs[i][j];
        }
      }
    }

    System.out.println(res);
  }

  public boolean warshallFloyd(int n, int[][] costs) {
    int[][] dd = new int[n][n];
    for (int i = 0 ; i < n ; i ++) {
      for (int j = 0 ; j < n ; j ++) {
        dd[i][j] = costs[i][j];
      }
    }
    for (int k = 0 ; k < n ; k ++) {
      for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
          if (dd[i][k] < Integer.MAX_VALUE && dd[k][j] < Integer.MAX_VALUE && dd[i][j] > dd[i][k] + dd[k][j]) {
            dd[i][j] = dd[i][k] + dd[k][j];
            return false;
          }
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
 
    private boolean isPrintableChar(int codePoint) {
      return codePoint >= 33 && codePoint <= 126;
    }
 
  }
 
}