import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.BitSet;
import java.util.NoSuchElementException;


public class Main {
  private static final int INF = Integer.MAX_VALUE / 3;
  
  // node 0:S 1-H:b H+1-H+W:r H+W+1:T
  private static int[] from = new int[30000];
  private static int[] to = new int[30000];
  private static int[] w = new int[30000];
  private static int ptr = 0;

  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int H = sc.nextInt();
    int W = sc.nextInt();
    char[][] map = new char[H][];
    for (int i = 0; i < H; i ++) {
      map[i] = sc.next().toCharArray();
    }
    

    for (int i = 0; i < H; i ++) {
      for (int j = 0; j < W; j ++) {
        char c = map[i][j];
        if (c == 'S') {
          input(0, i + 1, INF);
          input(0, H + j + 1, INF);
        } else if (c == 'T') {
          input(i + 1, H + W + 1, INF);
          input(H + j + 1, H + W + 1, INF);
        }
        if (c != '.') {
          input(i + 1, H + j + 1, 1);
          input(H + j + 1, i + 1, 1);
        }
      }
    }
    int n = H + W + 2;
    from = Arrays.copyOf(from, ptr);
    to = Arrays.copyOf(to, ptr);
    w = Arrays.copyOf(w, ptr);
    int[][][] g = packWD(n, from, to, w);
    
    int ret = maximumFlowFF(g, 0, n - 1, INF);
    System.out.println(ret >= INF ? -1 : ret);
  }
  
  private static void input(int a, int b, int c) {
    from[ptr] = a;
    to[ptr] = b;
    w[ptr] = c;
    ptr ++;
  }

  public static int maximumFlowFF(int[][][] cap, int source, int sink, int lim)
  {
      int n = cap.length;
      int[][] f = new int[n][n];
      int ret = 0;
      while(lim > 0){
          int[] path = new int[n+1];
          int[] next = new int[n+1];
          BitSet visited = new BitSet();
          Arrays.fill(next, -1);
          path[0] = source;
          visited.set(source);
          int pp = 1;
          
          outer:
          while(pp > 0){
              int prev = path[pp-1];
              visited.set(prev);
              while(++next[pp-1] < cap[prev].length){
                  int i = cap[prev][next[pp-1]][0];
                  if((cap[prev][next[pp-1]][1] - f[prev][i] > 0 || f[i][prev] > 0) && !visited.get(i)){
                      path[pp] = i;
                      next[pp] = -1;
                      pp++;
                      if(i == sink){
                          break outer;
                      }
                      continue outer;
                  }
              }
              pp--;
          }
          if(pp <= 0)break;
          
          int mincap = lim;
          for(int i = 0;i < pp - 1;i++){
              mincap = Math.min(mincap, cap[path[i]][next[i]][1] - f[path[i]][path[i+1]] > 0 ? cap[path[i]][next[i]][1] - f[path[i]][path[i+1]] : f[path[i+1]][path[i]]);
          }
          ret += mincap;
          lim -= mincap;
          for(int i = 0;i < pp - 1;i++){
              f[path[i]][path[i+1]] += mincap;
              f[path[i+1]][path[i]] -= mincap;
          }
          if(mincap == 0)throw new AssertionError(lim);
      }
      
      return ret;
  }
  
  public static int[][][] packWD(int n, int[] from, int[] to, int[] w){ return packWD(n, from, to, w, from.length); }
  public static int[][][] packWD(int n, int[] from, int[] to, int[] w, int sup)
  {
      int[][][] g = new int[n][][];
      int[] p = new int[n];
      for(int i = 0;i < sup;i++)p[from[i]]++;
      for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
      for(int i = 0;i < sup;i++){
          --p[from[i]];
          g[from[i]][p[from[i]]][0] = to[i];
          g[from[i]][p[from[i]]][1] = w[i];
      }
      return g;
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