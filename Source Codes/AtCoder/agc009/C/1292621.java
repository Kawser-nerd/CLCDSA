import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
 
public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    long A = sc.nextLong();
    long B = sc.nextLong();
    long[] S = new long[N + 1];
    System.arraycopy(sc.nextLongList(N), 0, S, 1, N);
    S[0] = -Integer.MAX_VALUE;
 
    if (A > B) {
      long tmp = A;
      A = B;
      B = tmp;
    }
 
    for (int i = 3; i <= N; i++) {
      if (S[i] - S[i - 2] < A) {
        System.out.println(0);
        return;
      }
    }
 
    // i???????? Y????j?? j <= i
    long mod = 1000000000 + 7;

    long[][] dp = new long[2][N + 1];
    long[] sum = new long[N + 2];
    sum[1] = 1;
    sum[2] = 2;

    dp[0][1] = 1;
    dp[1][0] = dp[1][1] = 1;

    int ptr1 = 0;
    int ptr2 = 0;
 
    for (int i = 2; i <= N; i++) {
      while (S[i] - S[ptr2 + 1] >= B) {
        ptr2 ++;
      }

      // S[i - 1]-> Y S[i]->X
      if (S[i] - S[i - 1] < A) {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = ptr2 < ptr1 ? 0 : (sum[ptr2 + 1] - sum[ptr1] + mod) % mod;
        ptr1 = i - 1;
      } else {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
        dp[1][i] = ptr2 < ptr1 ? 0 : (sum[ptr2 + 1] - sum[ptr1] + mod) % mod;
      }

      // S[i] -> Y
      sum[i + 1] = (sum[i] + dp[1][i]) % mod;
    }
 
    long ret = (dp[0][N] + dp[1][N]) % mod;
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