import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  @SuppressWarnings("unchecked") 
  public void run() {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int m = scanner.nextInt();
    List<Integer>[] paths = new List[n];
    for (int i = 0 ; i < n ; i ++) {
      paths[i] = new ArrayList();
    }
    for (int i = 0 ; i < m ; i ++) {
      int a = scanner.nextInt() - 1;
      int b = scanner.nextInt() - 1;
      paths[a].add(b);
      paths[b].add(a);
    }
    int q = scanner.nextInt();
    int[] vv = new int[q];
    int[] dd = new int[q];
    int[] cc = new int[q];
    for (int i = 0 ; i < q ; i ++) {
      vv[i] = scanner.nextInt() - 1;
      dd[i] = scanner.nextInt();
      cc[i] = scanner.nextInt();
    }

    int[][] dp = new int[11][n];
    for (int d = 0 ; d <= 10 ; d ++) {
      for (int v = 0 ; v < n ; v ++) {
        dp[d][v] = -1;
      }
    }
    for (int i = 0 ; i < q ; i ++) {
      dp[dd[i]][vv[i]] = i;
    }

    for (int d = 9 ; d >= 0 ; d --) {
      for (int v = 0 ; v < n ; v ++) {
        dp[d][v] = Math.max(dp[d][v], dp[d + 1][v]);
        for (int u : paths[v]) {
          dp[d][u] = Math.max(dp[d][u], dp[d + 1][v]);
        }
      }
    }

    StringBuilder output = new StringBuilder();
    for (int v = 0 ; v < n ; v ++) {
      output.append((dp[0][v] >= 0) ? cc[dp[0][v]] : 0);
      output.append("\n");
    }

    System.out.println(output);
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