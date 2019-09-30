import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;


public class Main {

  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int[][] C = sc.nextIntTable(N, 4);

    Map<Long, Integer> map = new HashMap<>();
    Map<Long, Long> rot = new HashMap<>();
    long[] hash = new long[N];
    for (int i = 0; i < N; i++) {
      long h = hash(C[i][0], C[i][1], C[i][2], C[i][3]);
      if (!map.containsKey(h)) {
        map.put(h, 0);
      }
      map.put(h, map.get(h) + 1);
      rot.put(h, rot(C[i]));
      hash[i] = h;
    }

    int[][] idx = {{0, 4, 7, 1}, {1, 7, 6, 2}, {3, 2, 6, 5}, {0, 3, 5, 4}};

    long count = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {

        loop: for (int k = 0; k < 4; k++) {
          Map<Long, Integer> tmp = new HashMap<>();
          tmp.put(hash[i], 1);
          tmp.put(hash[j], hash[i] == hash[j] ? 2 : 1);

          int[] c = {C[i][0], C[i][1], C[i][2], C[i][3], C[j][(0 + k) % 4], C[j][(1 + k) % 4],
              C[j][(2 + k) % 4], C[j][(3 + k) % 4]};


          long nc = 1;
          for (int[] v : idx) {
            long h = hash(c[v[0]], c[v[1]], c[v[2]], c[v[3]]);
            if (!tmp.containsKey(h)) tmp.put(h, 0);

            if (!map.containsKey(h) || tmp.get(h) >= map.get(h)) {
              continue loop;
            }
            nc *= (map.get(h) - tmp.get(h)) * rot.get(h);
            tmp.put(h, tmp.get(h) + 1);
          }


          count += nc;
        }
      }
    }
    System.out.println(count * 2 / 6);
  }

  private static long rot(int... C) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
      if (C[0] == C[(i + 0) % 4] && C[1] == C[(i + 1) % 4] && C[2] == C[(i + 2) % 4]
          && C[3] == C[(i + 3) % 4]) {
        ret ++;
      }
    }
    return ret;
  }

  private static long hash(int... C) {
    long min = Long.MAX_VALUE;

    for (int k = 0; k < 4; k++) {
      long ret = 0;
      for (int i = 0; i < 4; i++) {
        ret *= 1000;
        ret += C[(i + k) % 4];
      }
      min = Math.min(min, ret);
    }
    return min;
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