import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  @SuppressWarnings("unchecked") 
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);

    int n = scanner.nextInt();
    int[] aa = new int[n];
    int[] bb = new int[n];
    int[] cc = new int[n];
    int[] dd = new int[n];
    for (int i = 0 ; i < n ; i ++) {
      aa[i] = scanner.nextInt();
      bb[i] = scanner.nextInt();
    }
    for (int i = 0 ; i < n ; i ++) {
      cc[i] = scanner.nextInt();
      dd[i] = scanner.nextInt();
    }

    List<Integer>[] paths = new List[n];
    for (int i = 0 ; i < n ; i ++) {
      paths[i] = new ArrayList();
      for (int j = 0 ; j < n ; j ++) {
        if (aa[i] < cc[j] &&  bb[i] < dd[j]) {
          paths[i].add(j);
        }
      }
    }

    int res = 0;
    int[] parts = maxBipartiteMatching(n, n, paths);
    for (int b = 0 ; b < n ; b ++) {
      if (parts[b] >= 0) {
        res ++;
      }
    }
    System.out.println(res);
  }

  public int[] maxBipartiteMatching(int an, int bn, List<Integer>[] paths) {
    int[] parts = new int[bn];
    Arrays.fill(parts, -1);
    for (int a = 0 ; a < an ; a ++) {
      boolean[] visited = new boolean[bn];
      search(a, paths, parts, visited);
    }
    return parts;
  }

  private boolean search(int a, List<Integer>[] paths, int[] parts, boolean[] visited) {
    for (int b : paths[a]) {
      if (visited[b]) {
        continue;
      }
      visited[b] = true;
      if (parts[b] == -1 || search(parts[b], paths, parts, visited)) {
        parts[b] = a;
        return true;
      }
    }
    return false;
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