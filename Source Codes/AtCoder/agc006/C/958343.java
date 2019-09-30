import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.function.Supplier;

public class Main {
  void run() {
    int n = ni();
    long[] x = new long[n + 1];
    for (int i = 1; i <= n; ++i) {
      x[i] = ni();
    }
    int m = ni();
    long k = sc.nextLong();
    int[] a = new int[m];
    for (int i = 0; i < m; ++i) {
      a[i] = ni();
    }

    long[] d = new long[n];
    for (int i = 1; i <= n - 1; ++i) {
      d[i] = x[i + 1] - x[i];
    }
    int[] tikanD = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
      tikanD[i] = i;
    }
    for (int i = 0; i < m; ++i) {
      int left = a[i] - 1;
      int right = a[i];
      int tmp = tikanD[left];
      tikanD[left] = tikanD[right];
      tikanD[right] = tmp;
    }
    tikanD = pow_tikan(tikanD, k);
    long[] d_ = new long[n];
    for (int i = 1; i <= n - 1; ++i) {
      d_[i] = d[tikanD[i]];
    }
    d = d_;
    long ite = x[1];
    System.out.println(ite);
    for (int i = 1; i <= n - 1; ++i) {
      ite += d[i];
      System.out.println(ite);
    }
  }

  int[] tikan(int[] a, int[] b) {
    int[] res = new int[a.length];
    for (int i = 0; i < a.length; ++i) {
      res[i] = i;
    }
    for (int i = 0; i < a.length; ++i) {
      res[i] = b[a[res[i]]];
    }
    return res;
  }

  int[] pow_tikan(int[] d, long k) {
    int[] res = new int[d.length];
    for (int i = 0; i < d.length; ++i) {
      res[i] = i;
    }
    int[] v = d.clone();
    while (k > 0) {
      if (k % 2 == 1) {
        res = tikan(res, v);
      }
      v = tikan(v, v);
      k /= 2;
    }
    return res;
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