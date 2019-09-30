import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int M = sc.nextInt();


    Map<Integer, List<int[]>> colorMap = new HashMap<>();
    for (int i = 0; i < M; i++) {
      int l = sc.nextInt();
      int r = sc.nextInt();
      int x = sc.nextInt();
      if (!colorMap.containsKey(r)) {
        colorMap.put(r, new ArrayList<>());
      }
      colorMap.get(r).add(new int[]{l, r, x, r - l});
    }
    int[][][] color = new int[N + 1][0][];
    for (Map.Entry<Integer, List<int[]>> entry : colorMap.entrySet()) {
      int key = entry.getKey();
      List<int[]> value = entry.getValue();
      color[key] = new int[value.size()][];
      int ptr = 0;
      for (int[] v : value) {
        color[key][ptr ++] = v;
      }
    }
    
    int mod = 1_000_000_007;

    int[][][] dp = new int[2][N + 2][N + 2];
    dp[0][0][0] = 1;
    for (int max = 0; max <= N; max ++) {
      int from = max % 2;
      int to = (max + 1) % 2;
      for (int[] v : dp[to]) Arrays.fill(v, 0);

      for (int med = 0; med == 0 || med < max; med ++) {
        for (int min = 0; min == 0 || min < med; min ++) {

          for (int[] v : color[max]) {
            if (v[2] == 1) {
              if (max - med <= v[3]) {
                dp[from][med][min] = 0;
              }
            } else if (v[2] == 2) {
              if (max - med > v[3] || max - min <= v[3]) {
                dp[from][med][min] = 0;
              }
            } else {
              if (max - min > v[3]) {
                dp[from][med][min] = 0;
              }
            }
          }
          
          if (max == 0 && min == 0 && med == 0) {
            dp[to][0][0] = 1;
          } else {
            dp[to][med][min] = (dp[to][med][min] + dp[from][med][min]) % mod;
            dp[to][max][min] = (dp[to][max][min] + dp[from][med][min]) % mod;
            dp[to][max][med] = (dp[to][max][med] + dp[from][med][min]) % mod;
          }
        }
      }
    }
    
    int ret = 0;
    for (int i = 0; i <= N; i ++) {
      for (int j = 0; j <= N; j ++) {
        ret = (ret + dp[(N + 1) % 2][i][j]) % mod;
      }
    }
    System.out.println(ret);
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