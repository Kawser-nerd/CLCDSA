import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int H = sc.nextInt();
    int[][] p = sc.nextIntTable(N, 4);
    
    UnionFind uf = new UnionFind(2000);
    int[] left = new int[2000];
    int[] right = new int[2000];

    boolean[] node = new boolean[2000];
    for (int i = 0; i < N; i ++) {
      int A = p[i][0];
      int B = p[i][1];
      int C = p[i][2];
      int D = p[i][3];

      int X = C == 0 ? A + 1000 : C;
      int Y = D == 0 ? B : D + 1000;
      
      uf.union(X, Y);
      left[X] ++;
      right[Y] ++;
      node[X] = node[Y] = true;
    }
    
    for (int i = 1; i < 1000; i ++) {
      // C > 0, D == 0
      if (left[i] > right[i]) { 
        System.out.println("NO");
        return;
      } else if (left[i] < right[i]) {
        uf.union(0, i);
      }
    }
    
    for (int i = 1000; i < 2000; i ++) {
      // C == 0, D > 0
      if (left[i] < right[i]) {
        System.out.println("NO");
        return;
      } else if (left[i] > right[i]) {
        uf.union(0, i);
      }
    }
    
    int root = uf.find(0);
    for (int i = 0; i < 2000; i ++) {
      if (node[i] && root != uf.find(i)) {
        System.out.println("NO");
        return;
      }
    }
    System.out.println("YES");
  }
  

}

class UnionFind {
  private int[] table;
  private int[] rank;
  
  public UnionFind(int size) {
      this.table = new int[size];
      this.rank = new int[size];
      for (int i = 0; i < size; i ++) {
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
          rank[root1] ++;
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