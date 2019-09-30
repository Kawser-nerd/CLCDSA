import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.function.Supplier;

public class Main {
  void run() {
    int ex = ni();
    int ey = ni();
    int r = ni();
    int[][] dx = new int[4][2];
    for (int i = 0; i < 2; ++i) {
      dx[i][0] = ni();
      dx[i][1] = ni();
    }
    dx[2][0] = dx[1][0];
    dx[2][1] = dx[0][1];
    dx[3][0] = dx[0][0];
    dx[3][1] = dx[1][1];
    int[][] e = new int[4][2];
    e[0][0] = ex;
    e[0][1] = ey - r;
    e[1][0] = ex;
    e[1][1] = ey + r;
    e[2][0] = ex - r;
    e[2][1] = ey;
    e[3][0] = ex + r;
    e[3][1] = ey;
    boolean rf = true;
    for (int i = 0; i < 4; ++i) {
      rf &= dx[0][0] <= e[i][0] && e[i][0] <= dx[1][0]
          && dx[0][1] <= e[i][1] && e[i][1] <= dx[1][1];
    }
    if (rf) {
      System.out.println("NO");
    } else {
      System.out.println("YES");
    }
    boolean df = true;
    for (int i = 0; i < 4; ++i) {
      int nx = ex - dx[i][0];
      int ny = ey - dx[i][1];
      df &= nx * nx + ny * ny <= r * r;
    }
    if (df) {
      System.out.println("NO");
    } else {
      System.out.println("YES");
    }
  }

  Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    new Main().run();
  }

  int ni() {
    return Integer.parseInt(sc.next());
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }

  class BIT<T> {
    int n;
    ArrayList<T> bit;
    BiFunction<T, T, T> bif;

    /**
     * 1-indexed ?Binary Indexed Tree?????
     *
     * @param n   ??
     * @param bif ???????
     * @param sup ???
     */
    BIT(int n, BiFunction<T, T, T> bif, Supplier<T> sup) {
      this.n = n;
      bit = new ArrayList<>(n + 1);
      for (int i = 0; i < n + 1; ++i) {
        bit.add(sup.get());
      }
      this.bif = bif;
    }

    /**
     * i??????v?????
     *
     * @param i index
     * @param v ????
     */
    void update(int i, T v) {
      for (int x = i; x <= n; x += x & -x) {
        bit.set(x, bif.apply(bit.get(x), v));
      }
    }

    /**
     * ????
     *
     * @param defaultValue ???
     * @param i            index
     * @return [1, i]??f???????
     */
    T reduce(T defaultValue, int i) {
      T ret = defaultValue;
      for (int x = i; x > 0; x -= x & -x) {
        ret = bif.apply(ret, bit.get(x));
      }
      return ret;
    }
  }

  long MOD = 1_000_000_007;

  /**
   * ????2????????????
   *
   * @return a^r (mod 1,000,000,007)
   */
  long pow(long a, long r) {
    long sum = 1;
    while (r > 0) {
      if ((r & 1) == 1) {
        sum *= a;
        sum %= MOD;
      }
      a *= a;
      a %= MOD;
      r >>= 1;
    }
    return sum;
  }

  /**
   * ?????
   * O(n)
   *
   * @return {}_nC_r
   */
  long C(int n, int r) {
    long sum = 1;
    for (int i = n; 0 < i; --i) {
      sum *= i;
      sum %= MOD;
    }
    long s = 1;
    for (int i = r; 0 < i; --i) {
      s *= i;
      s %= MOD;
    }
    sum *= pow(s, MOD - 2);
    sum %= MOD;

    long t = 1;
    for (int i = n - r; 0 < i; --i) {
      t *= i;
      t %= MOD;
    }
    sum *= pow(t, MOD - 2);
    sum %= MOD;

    return sum;
  }

  double GOLDEN_RATIO = (1.0 + Math.sqrt(5)) / 2.0;

  /**
   * ??????
   *
   * @param left  ??
   * @param right ??
   * @param f     ??????
   * @param comp  ???????????????Comparator.comparingDouble(Double::doubleValue)
   *              ???????????????Comparator.comparingDouble(Double::doubleValue).reversed()
   * @return ?????x
   */
  double goldenSectionSearch(double left, double right, Function<Double, Double> f, Comparator<Double> comp) {
    double c1 = divideInternally(left, right, 1, GOLDEN_RATIO);
    double c2 = divideInternally(left, right, GOLDEN_RATIO, 1);
    double d1 = f.apply(c1);
    double d2 = f.apply(c2);
    while (right - left > 1e-9) {
      if (comp.compare(d1, d2) > 0) {
        right = c2;
        c2 = c1;
        d2 = d1;
        c1 = divideInternally(left, right, 1, GOLDEN_RATIO);
        d1 = f.apply(c1);
      } else {
        left = c1;
        c1 = c2;
        d1 = d2;
        c2 = divideInternally(left, right, GOLDEN_RATIO, 1);
        d2 = f.apply(c2);
      }
    }
    return right;
  }

  /**
   * [a,b]?m:n?????????
   */
  double divideInternally(double a, double b, double m, double n) {
    return (n * a + m * b) / (m + n);
  }

  /**
   * http://qiita.com/p_shiki37/items/65c18f88f4d24b2c528b
   */
  static class FastScanner {
    private final InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    public FastScanner(InputStream in) {
      this.in = in;
    }

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    public long nextLong() {
      if (!hasNext()) throw new NoSuchElementException();
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
  }
}