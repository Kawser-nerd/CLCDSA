import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();

    int[][] p1 = new int[N][3];
    for (int i = 0; i < N; i ++) {
      p1[i][2] = i;
      p1[i][0] = sc.nextInt();
      p1[i][1] = sc.nextInt();
    }

    int[][] p2 = Arrays.copyOf(p1, N);
    Arrays.sort(p1, (a, b) -> a[0] - b[0]);
    Arrays.sort(p2, (a, b) -> a[1] - b[1]);
    
    
    int[] from = new int[(N - 1) * 2];
    int[] to = new int[(N  - 1) * 2];
    int[] w = new int[(N - 1) * 2];
    for (int i = 0; i < N - 1; i ++) {
      from[i] = p1[i][2];
      to[i] = p1[i + 1][2];
      w[i] = Math.min(Math.abs(p1[i][0] - p1[i + 1][0]), Math.abs(p1[i][1] - p1[i + 1][1]));
      
      from[i + (N - 1)] = p2[i][2];
      to[i + (N - 1)] = p2[i + 1][2];
      w[i + (N - 1)] = Math.min(Math.abs(p2[i][0] - p2[i + 1][0]), Math.abs(p2[i][1] - p2[i + 1][1]));
    }

    int ans = kruskal(from, to, w, N)[1];
    System.out.println(ans);
  }

  public static int[] kruskal(int[] one, int[] other, int[] w, int n)
  {
      DisjointSet ds = new DisjointSet(n);
      int p = one.length;
      long[] ord = new long[p];
      for(int i = 0;i < p;i++)ord[i] = (long)w[i]<<32 | i;
      Arrays.sort(ord);
      
      int d = 0;
      for(int i = 0;i < ord.length;i++){
          int cur = (int)ord[i];
          if(!ds.equiv(one[cur], other[cur])){
              ds.union(one[cur], other[cur]);
              d += w[cur];
          }
      }
      
      return new int[]{ds.count(), d};
  }
}

class DisjointSet {
  public int[] upper;
  
  public DisjointSet(int n)
  {
      upper = new int[n];
      Arrays.fill(upper, -1);
  }
  
  public DisjointSet(DisjointSet ds)
  {
      this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
  }       
  
  public int root(int x)
  {
      return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
  }
  
  public boolean equiv(int x, int y)
  {
      return root(x) == root(y);
  }
  
  public boolean union(int x, int y)
  {
      x = root(x);
      y = root(y);
      if(x != y) {
          if(upper[y] < upper[x]) {
              int d = x; x = y; y = d;
          }
          upper[x] += upper[y];
          upper[y] = x;
      }
      return x == y;
  }
  
  public int count()
  {
      int ct = 0;
      for(int u : upper){
          if(u < 0)ct++;
      }
      return ct;
  }
  
  public int[][] toBucket()
  {
      int n = upper.length;
      int[][] ret = new int[n][];
      int[] rp = new int[n];
      for(int i = 0;i < n;i++){
          if(upper[i] < 0)ret[i] = new int[-upper[i]];
      }
      for(int i = 0;i < n;i++){
          int r = root(i);
          ret[r][rp[r]++] = i;
      }
      return ret;
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