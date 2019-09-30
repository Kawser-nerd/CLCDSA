import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] from = new int[M];
    int[] to = new int[M];

    for (int i = 0; i < M; i++) {
      from[i] = sc.nextInt() - 1;
      to[i] = sc.nextInt() - 1;
    }

    int Q = sc.nextInt();
    int[][] query = sc.nextIntTable(Q, 3);
    for (int i = 0; i < Q; i++) {
      query[i][0]--;
    }

    int[][] g = packU(N, from, to);
    int[] color = new int[N];
    int[] len = new int[N];
    Arrays.fill(len, -1);
    for (int i = Q - 1; i >= 0; i--) {
      dij(query[i][0], color, query[i][2], len, query[i][1], g);
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < N; i++) {
      sb.append(color[i]);
      sb.append("\n");
    }
    System.out.print(sb);
  }


  public static int[][] packU(int n, int[] from, int[] to) {
    int[][] g = new int[n][];
    int[] p = new int[n];
    for (int f : from)
      p[f]++;
    for (int t : to)
      p[t]++;
    for (int i = 0; i < n; i++)
      g[i] = new int[p[i]];
    for (int i = 0; i < from.length; i++) {
      g[from[i]][--p[from[i]]] = to[i];
      g[to[i]][--p[to[i]]] = from[i];
    }
    return g;
  }


  private static ArrayDeque<int[]> queue = new ArrayDeque<>();
  private static void dij(int now, int[] color, int nowColor, int[] len, int d, int[][] g) {
    queue.add(new int[] {now, d});

    while (queue.size() > 0) {
      int[] v = queue.poll();
      
      if (len[v[0]] < 0) {
        color[v[0]] = nowColor;
      }

      if (len[v[0]] >= v[1]) {
        continue;
      }
      
      len[v[0]] = v[1];
      
      if (v[1] == 0) {
        continue;
      }

      for (int u : g[v[0]]) {
        if (len[u] >= v[1] - 1) {
          continue;
        }
        queue.add(new int[] {u, v[1] - 1});
      }
    }
  }
}



class FastScanner {
  public static String debug = null;

  private final InputStream in = System.in;
  private int ptr = 0;
  private int buflen = 0;
  private byte[] buffer = new byte[1024];
  private boolean eos = false;

  private boolean hasNextByte() {
    if (ptr < buflen) {
      return true;
    } else {
      ptr = 0;
      try {
        if (debug != null) {
          buflen = debug.length();
          buffer = debug.getBytes();
          debug = "";
          eos = true;
        } else {
          buflen = in.read(buffer);
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
      if (buflen < 0) {
        eos = true;
        return false;
      } else if (buflen == 0) {
        return false;
      }
    }
    return true;
  }

  private int readByte() {
    if (hasNextByte())
      return buffer[ptr++];
    else
      return -1;
  }

  private static boolean isPrintableChar(int c) {
    return 33 <= c && c <= 126;
  }

  private void skipUnprintable() {
    while (hasNextByte() && !isPrintableChar(buffer[ptr]))
      ptr++;
  }

  public boolean isEOS() {
    return this.eos;
  }

  public boolean hasNext() {
    skipUnprintable();
    return hasNextByte();
  }

  public String next() {
    if (!hasNext())
      throw new NoSuchElementException();
    StringBuilder sb = new StringBuilder();
    int b = readByte();
    while (isPrintableChar(b)) {
      sb.appendCodePoint(b);
      b = readByte();
    }
    return sb.toString();
  }

  public long nextLong() {
    if (!hasNext())
      throw new NoSuchElementException();
    long n = 0;
    boolean minus = false;
    int b = readByte();
    if (b == '-') {
      minus = true;
      b = readByte();
    }
    if (b < '0' || '9' < b) {
      throw new NumberFormatException();
    }
    while (true) {
      if ('0' <= b && b <= '9') {
        n *= 10;
        n += b - '0';
      } else if (b == -1 || !isPrintableChar(b)) {
        return minus ? -n : n;
      } else {
        throw new NumberFormatException();
      }
      b = readByte();
    }
  }

  public int nextInt() {
    return (int) nextLong();
  }

  public long[] nextLongList(int n) {
    return nextLongTable(1, n)[0];
  }

  public int[] nextIntList(int n) {
    return nextIntTable(1, n)[0];
  }

  public long[][] nextLongTable(int n, int m) {
    long[][] ret = new long[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ret[i][j] = nextLong();
      }
    }
    return ret;
  }

  public int[][] nextIntTable(int n, int m) {
    int[][] ret = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ret[i][j] = nextInt();
      }
    }
    return ret;
  }
}