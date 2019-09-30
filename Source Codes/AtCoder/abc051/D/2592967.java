import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {
 
  public static final int MOD = 1000000007;

  public void run() {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int m = scanner.nextInt();

    List<Integer>[] paths = new List[n];
    List<Integer>[] costs = new List[n];
    boolean[][] used = new boolean[n][n];
    for (int i = 0 ; i < n ; i ++) {
      paths[i] = new ArrayList();
      costs[i] = new ArrayList();
    }
    for (int i = 0 ; i < m ; i ++) {
      int a = scanner.nextInt() - 1;
      int b = scanner.nextInt() - 1;
      int c = scanner.nextInt();
      paths[a].add(b);
      costs[a].add(c);
      paths[b].add(a);
      costs[b].add(c);
      used[a][b] = true;
      used[b][a] = true;
    }

    for (int i = 0 ; i < n ; i ++) {
      dijkstra(n, paths, costs, used, i);
    }

    int res = 0;
    for (int i = 0 ; i < n ; i ++) {
      for (int j = 0 ; j < n ; j ++) {
        if (used[i][j]) {
          res ++;
        }
      }
    }

    System.out.println(res / 2);
  }

  public void dijkstra(int n, List<Integer>[] paths, List<Integer>[] costs, boolean[][] used, int first) {
    int[] dd = new int[n];
    int[] prevs = new int[n];
    for (int i = 0 ; i < n ; i ++) {
      dd[i] = (i == first) ? 0 : Integer.MAX_VALUE;
      prevs[i] = -1;
    }
    Queue<Integer> queue = new PriorityQueue<Integer>((n1, n2) -> dd[n1.intValue()] - dd[n2.intValue()]);
    for (int i = 0 ; i < n ; i ++) {
      queue.offer(i);
    }
    while (!queue.isEmpty()) {
      int c = queue.poll();
      for (int j = 0 ; j < paths[c].size() ; j ++) {
        int b = paths[c].get(j);
        int cost = costs[c].get(j);
        if (dd[b] > dd[c] + cost) {
          dd[b] = dd[c] + cost;
          prevs[b] = c;
          if (queue.remove(b)) {
            queue.offer(b);
          }
        }
      }
    }
    for (int end = 0 ; end < n ; end ++) {
      int c = end;
      while (c != first) {
        int nc = prevs[c];
        used[c][nc] = false;
        used[nc][c] = false;
        c = nc;
      }
    }
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
 
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.