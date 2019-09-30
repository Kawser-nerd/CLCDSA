import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {
  private static int N;
  private static int[] code;;
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    char[] c = sc.next().toCharArray();
    N = c.length;
    code = new int[N];
    code[0] = encode(c);
    for (int i = 1; i < N; i ++) {
      code[i] = rot(code[i - 1]);
    }
    
    int ret = dfs(code[0], 0, 1);
    System.out.println(ret);
  }
  
  private static int dfs(int now, int shift, int depth) {
    if (now == 0) {
      return depth;
    }

    if (shift == N) {
      return Integer.MAX_VALUE;
    }
    
    int min = Integer.MAX_VALUE;
    for (int i = shift + 1; i < N; i ++) {
      int v = dfs(now & code[i], i, depth + 1);
      min = Math.min(v, min);
    }
    return min;
  }

  private static int rot(int x) {
    boolean flg = (x & (1 << (N - 1))) != 0;
    return ((x << 1) & ((1 << N) - 1)) | (flg ? 1 : 0);
  }
  
  private static int encode(char[] c) {
    int x = 0;
    for (char v : c) {
      x <<= 1;
      if (v == 'x') {
        x |= 1;
      }
    }
    return x;
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