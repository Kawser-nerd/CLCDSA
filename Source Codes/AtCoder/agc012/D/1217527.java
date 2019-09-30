import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int X = sc.nextInt();
    int Y = sc.nextInt();

    int[][] b = sc.nextIntTable(N, 2);
    for (int i = 0; i < N; i++) {
      b[i][0]--;
    }

    UnionFind uf = new UnionFind(N);

    int[] mins = new int[N];
    int[] argmins = new int[N];
    Arrays.fill(mins, Integer.MAX_VALUE);
    Arrays.fill(argmins, -1);
    for (int i = 0; i < N; i++) {
      if (b[i][1] < mins[b[i][0]]) {
        mins[b[i][0]] = b[i][1];
        argmins[b[i][0]] = i;
      }
    }

    Ranking rs = new Ranking(2);
    for (int i = 0; i < N; i++) {
      rs.query(mins[i], argmins[i]);
    }

    for (int i = 0; i < N; i++) {
      if (b[i][1] + mins[b[i][0]] <= X) {
        uf.union(i, argmins[b[i][0]]);
      }
      if (mins[b[i][0]] == rs.min[0]) {
        if (b[i][1] + rs.min[1] <= Y) {
          if (rs.argmin[1] != -1) {
            uf.union(rs.argmin[1], i);
          }
        }
      } else {
        if (b[i][1] + rs.min[0] <= Y) {
          uf.union(rs.argmin[0], i);
        }
      }
    }


    int[] roots = new int[N];
    for (int i = 0; i < N; i++) {
      roots[i] = uf.find(i);
    }

    int mod = 1000000000 + 7;

    int[][] bucket = makeBuckets(roots, N);
    int[][] fif = enumFIF(500000, mod);

    long ret = 1;
    for (int[] v : bucket) {
      Map<Integer, Integer> map = new HashMap<>();
      for (int u : v) {
        int key = b[u][0];
        if (!map.containsKey(key)) {
          map.put(key, 0);
        }
        map.put(key, map.get(key) + 1);
      }

      ret *= fif[0][v.length];
      ret %= mod;
      for (int x : map.values()) {
        ret *= fif[1][x];
        ret %= mod;
      }
    }

    System.out.println(ret);
  }

  public static int[][] enumFIF(int n, int mod) {
    int[] f = new int[n + 1];
    int[] invf = new int[n + 1];
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
      f[i] = (int) ((long) f[i - 1] * i % mod);
    }
    long a = f[n];
    long b = mod;
    long p = 1, q = 0;
    while (b > 0) {
      long c = a / b;
      long d;
      d = a;
      a = b;
      b = d % b;
      d = p;
      p = q;
      q = d - c * q;
    }
    invf[n] = (int) (p < 0 ? p + mod : p);
    for (int i = n - 1; i >= 0; i--) {
      invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
    }
    return new int[][] {f, invf};
  }

  public static int[][] makeBuckets(int[] a, int sup) {
    int n = a.length;
    int[][] bucket = new int[sup + 1][];
    int[] bp = new int[sup + 1];
    for (int i = 0; i < n; i++)
      bp[a[i]]++;
    for (int i = 0; i <= sup; i++)
      bucket[i] = new int[bp[i]];
    for (int i = n - 1; i >= 0; i--)
      bucket[a[i]][--bp[a[i]]] = i;
    return bucket;
  }
}


class Ranking {
  public long[] min;
  public int[] argmin;
  public int K;

  public Ranking(int K) {
    this.K = K;
    min = new long[K];
    Arrays.fill(min, Long.MAX_VALUE);
    argmin = new int[K];
    Arrays.fill(argmin, -1);
  }

  public void query(long v, int ind) {
    // if(v >= min[K-1])return;
    for (int i = 0; i < K; i++) {
      if (v < min[i]) {
        for (int j = K - 2; j >= i; j--) {
          min[j + 1] = min[j];
          argmin[j + 1] = argmin[j];
        }
        min[i] = v;
        argmin[i] = ind;
        break;
      }
    }
  }
}


class UnionFind {
  private int[] table;
  private int[] rank;

  public UnionFind(int size) {
    this.table = new int[size];
    this.rank = new int[size];
    for (int i = 0; i < size; i++) {
      this.table[i] = i;
      this.rank[i] = 1;
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

  public void union(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    if (rank[root1] < rank[root2]) {
      table[root1] = root2;
    } else if (rank[root1] > rank[root2]) {
      table[root2] = root1;
    } else if (root1 != root2) {
      table[root2] = root1;
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