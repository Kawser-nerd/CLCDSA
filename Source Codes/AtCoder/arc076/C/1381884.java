import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.NoSuchElementException;


public class Main {
  private static int R;
  private static int C;
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    R = sc.nextInt();
    C = sc.nextInt();
    int N = sc.nextInt();

    List<long[]> list = new ArrayList<>();
    for (int i = 0; i < N; i ++) {
      int[] p = sc.nextIntList(4);
      
      long a = f(p[0], p[1]);
      long b = f(p[2], p[3]);
      if (a >= 0 && b >= 0) {
        if (a > b) {
          long tmp = a;
          a = b;
          b = tmp;
        }

        list.add(new long[]{0, i, a});
        list.add(new long[]{1, i, b});
      }
    }
    
    Collections.sort(list, (a, b) -> Long.compare(a[2], b[2]));
    
    
    ArrayDeque<Long> queue = new ArrayDeque<>();
    for (long[] v : list) {
      if (v[0] == 0) {
        queue.push(v[1]);
      } else {
        long now = queue.poll();
        if (now != v[1]) {
          System.out.println("NO");
          return;
        }
      }
    }
    System.out.println("YES");
  }
  
  private static long INF = Integer.MAX_VALUE;
  private static long f(int x, int y) {
    long ret;
    if (x == 0) {
      ret = y; 
    } else if (y == C) {
      ret = x + INF * 10L;
    } else if (x == R) {
      ret = -y + INF * 20L;
    } else if (y == 0) {
      ret = -x + INF * 30L;
    } else {
      ret = -1;
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