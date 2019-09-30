import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Set;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] from = new int[M];
    int[] to = new int[M];

    UnionFind uf = new UnionFind(N);
    for (int i = 0; i < M; i++) {
      from[i] = sc.nextInt() - 1;
      to[i] = sc.nextInt() - 1;
      uf.union(from[i], to[i]);
    }

    Set<Integer> roots = new HashSet<>();
    for (int i = 0; i < N; i++) {
      int root = uf.find(i);
      roots.add(root);
    }
    List<Integer> rootArray = new ArrayList<>(roots);

    int[][] g = packU(N, from, to);


    long c1 = 0;
    for (int root : rootArray) {
      if (g[root].length == 0) {
        c1 ++;
        roots.remove(root);
      }
    }

    color = new int[N];

    long ret = c1 * c1;

    long c2 = 0;
    long c3 = 0;
    for (int root : roots) {
      if (dfs(root, -1, g)) {
        c2 ++;
      } else {
        c3 ++;
      }
      ret += uf.count(root) * c1 * 2;
    }
    
    ret += c2 * c2 * 2 + c2 * c3 * 2 + c3 * c3;
    System.out.println(ret);
    
  }

  private static int[] color;
  private static boolean dfs(int now, int pre, int[][] g) {
    color[now] = pre < 0 ? 1 : -color[pre];
    for (int next : g[now]) {
      if (color[next] == 0) {
        if (!dfs(next, now, g)) {
          return false;
        }
      } else if (color[next] != -color[now]) {
        return false;
      }
    }
    return true;
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
}


class UnionFind {
  private int[] table;
  private int[] rank;
  private int[] count;

  public UnionFind(int size) {
    this.table = new int[size];
    this.rank = new int[size];
    this.count = new int[size];
    for (int i = 0; i < size; i++) {
      this.table[i] = i;
      this.rank[i] = 1;
      this.count[i] = 1;
    }
  }

  public boolean isSame(int node1, int node2) {
    return find(node1) == find(node2);
  }

  public int find(int node) {
    if (table[node] == node) {
      return node;
    } else {
      return table[node] = find(table[node]);
    }
  }

  public int count(int node) {
    return count[find(node)];
  }

  public void union(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    if (rank[root1] < rank[root2]) {
      table[root1] = root2;
      count[root2] += count[root1];
    } else if (rank[root1] > rank[root2]) {
      table[root2] = root1;
      count[root1] += count[root2];
    } else if (root1 != root2) {
      table[root2] = root1;
      count[root1] += count[root2];
      rank[root1]++;
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