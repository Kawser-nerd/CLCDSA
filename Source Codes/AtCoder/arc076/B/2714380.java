import java.io.*;
import java.util.*;
 
 
public class Main implements Runnable {

  @SuppressWarnings("unchecked") 
  public void run() {
    BetterScanner scanner = new BetterScanner(System.in);
  
    int n = scanner.nextInt();
    Town[] towns = new Town[n];
    for (int i = 0 ; i < n ; i ++) {
      int x = scanner.nextInt();
      int y = scanner.nextInt();
      towns[i] = new Town(i, x, y);
    }

    Dist[] dists = new Dist[2 * n - 2];

    Arrays.sort(towns, (t1, t2) -> t1.x - t2.x);
    for (int i = 0 ; i < n - 1 ; i ++) {
      dists[i] = new Dist(towns[i + 1].ind, towns[i].ind, towns[i + 1].x - towns[i].x);
    }
    Arrays.sort(towns, (t1, t2) -> t1.y - t2.y);
    for (int i = 0 ; i < n - 1 ; i ++) {
      dists[i + n - 1] = new Dist(towns[i + 1].ind, towns[i].ind, towns[i + 1].y - towns[i].y);
    }

    Arrays.sort(dists, (d1, d2) -> d1.d - d2.d);

    UnionFind u = new UnionFind(n);
    long res = 0;
    for (int i = 0 ; i < 2 * n - 2 ; i ++) {
      Dist dist = dists[i];
      if (!u.isConnected(dist.fst, dist.snd)) {
        u.unite(dist.fst, dist.snd);
        res += dist.d;
      }
    }
    System.out.println(res);
  }

  public class Town {
    public int ind;
    public int x;
    public int y;
    public Town(int ind, int x, int y) {
      this.ind = ind;
      this.x = x;
      this.y = y;
    }
  }
 
  public class Dist {
    public int fst;
    public int snd;
    public int d;
    public Dist(int fst, int snd, int d) {
      this.fst = fst;
      this.snd = snd;
      this.d = d;
    }
  }

  public static class UnionFind {
    
    private int[] parents;
    private int[] ranks;

    public UnionFind(int max) {
      parents = new int[max];
      ranks = new int[max];
      for (int i = 0 ; i < max; i ++) {
        parents[i] = i;
      }
    }

    public int find(int i) {
      int parent = parents[i];
      if (i == parent) {
        return i;
      } else {
        parents[i] = find(parent);
        return parents[i];
      }
    }

    public void unite(int i, int j) {
      int iRoot = find(i);
      int jRoot = find(j);
      if (iRoot != jRoot) {
        if (ranks[iRoot] > ranks[jRoot]) {
          parents[jRoot] = iRoot;
        } else if (ranks[jRoot] > ranks[iRoot]) {
          parents[iRoot] = jRoot;
        } else {
          parents[jRoot] = iRoot;
          ranks[iRoot] ++;
        }
      }
    }

    public boolean isConnected(int i, int j) {
      return find(i) == find(j);
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