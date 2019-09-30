import java.awt.geom.Point2D;
import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.function.Supplier;

public class Main {
  final static int INF = 1 << 28;
  final static long MOD = 1_000_000_007;
  final static double GOLDEN_RATIO = (1.0 + Math.sqrt(5)) / 2.0;
  Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    new Main().run();
  }

  void run() {
    int n = ni();
    ArrayList<Pair<Integer, Integer>> list = new ArrayList<>();
    for (int i = 0; i < n; ++i) {
      int x = ni();
      int y = ni();
      Pair<Integer, Integer> p = new Pair<>(x, y);
      list.add(p);
    }
    for (int i = 0; i < n; ++i) {
      Pair<Integer, Integer> p = list.get(i);
      if (p.f > p.s) {
        Integer tmp = p.f;
        p.f = p.s;
        p.s = tmp;
      }
    }
    Collections.sort(list);
    debug(list);
//    int max = list.get(list.size() - 1).s;
//    int min = list.get(0).f;
    int max = list.stream().mapToInt(p -> Math.max(p.f, p.s)).max().orElse(-1);
    int min = list.stream().mapToInt(p -> Math.min(p.f, p.s)).min().orElse(-1);
    long ans = Long.MAX_VALUE;
//    int max2 = list.get(list.size() - 1).f;
    int max2 = list.stream().max(Comparator.comparingInt(a -> a.f)).orElse(new Pair<>(-1, -1 )).f;
    int min2 = list.stream().min(Comparator.comparingInt(a -> a.s)).orElse(new Pair<>(-1, -1)).s;
    // case 1 (maxr - MIN) * (MAX - minb)
    ans = Math.min(ans, (long) (max2 - min) * (max - min2));
    // case 2 (MAX - MIN) * (maxb - minb)
    for (int i = 0; i < n; ++i) {
      Pair<Integer, Integer> p = list.get(i);
      ans = Math.min(ans, (long) (max - min) * (max2 - Math.min(p.f, min2)));
      max2 = Math.max(max2, p.s);
    }
    System.out.println(ans);
  }

  int ni() {
    return Integer.parseInt(sc.next());
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }

  /**
   * ??????????
   *
   * @return a ? b ??????
   */
  long gcd(long a, long b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

  /**
   * ????????????
   *
   * @return mx + ny = gcd(m, n)??????(x, y)???
   */
  Pair<Long, Long> gcd_ex(long m, long n) {
    long[][] mat = _gcd_ex(m, n);
    return new Pair<>(mat[0][0], mat[0][1]);
  }

  long[][] _gcd_ex(long m, long n) {
    if (n == 0) {
      return new long[][]{{1, 0}, {0, 1}};
    }
    long k = m / n;
    long[][] K = new long[][]{{0, 1}, {1, -k}};
    long[][] r = _gcd_ex(n, m % n);
    long[][] dst = new long[2][2];
    for (int y = 0; y < 2; ++y)
      for (int x = 0; x < 2; ++x)
        for (int i = 0; i < 2; ++i)
          dst[y][x] += r[y][i] * K[i][x];
    return dst;
  }

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
   * http://alexbowe.com/popcount-permutations/
   * bit?????????????????????????
   * ex)
   * <pre>
   * for (int i = 0; i < 25; ++i) {
   *   int bits = (1 << i) - 1;
   *   long m = C(25, num);
   *   for (j = 0; j < m; ++j) {
   *     ...(25?????i?bit??????)
   *     if (bits != 0)
   *       bits = next_perm(bits);
   *   }
   * }
   * </pre>
   *
   * @param v ???bit?
   * @return ??bit?
   */
  int next_perm(int v) {
    int t = (v | (v - 1)) + 1;
    return t | ((((t & -t) / (v & -v)) >> 1) - 1);
  }

  /**
   * from http://gihyo.jp/dev/serial/01/geometry part 6
   */
  static class Line {
    double a;
    double b;
    double c;

    /**
     * ??????????????????
     *
     * @param a x???
     * @param b y???
     * @param c ???
     */
    Line(double a, double b, double c) {
      this.a = a;
      this.b = b;
      this.c = c;
    }

    /**
     * 2?(x1, y1), (x2, y2)??????????
     *
     * @param x1 1???x??
     * @param y1 1???y??
     * @param x2 2???x??
     * @param y2 2???y??
     * @return ??
     */
    static Line fromPoints(double x1, double y1, double x2, double y2) {
      double dx = x2 - x1;
      double dy = y2 - y1;
      return new Line(dy, -dx, dx * y1 - dy * x1);
    }

    /**
     * ??????????????
     *
     * @param l ??
     * @return ???2?????????null
     */
    Point2D getIntersectionPoint(Line l) {
      double d = a * l.b - l.a * b;
      if (d == 0.0) {
        return null;
      }
      double x = (b * l.c - l.b * c) / d;
      double y = (l.a * c - a * l.c) / d;
      return new Point2D.Double(x, y);
    }

    @Override
    public String toString() {
      return "a = " + a + ", b = " + b + ", c = " + c;
    }
  }

  /**
   * from http://gihyo.jp/dev/serial/01/geometry part 6
   */
  static public class LineSegment {
    double x1;
    double y1;
    double x2;
    double y2;

    LineSegment(double x1, double y1, double x2, double y2) {
      this.x1 = x1;
      this.y1 = y1;
      this.x2 = x2;
      this.y2 = y2;
    }

    Line toLine() {
      return Line.fromPoints(x1, y1, x2, y2);
    }

    boolean intersects(Line l) {
      double t1 = l.a * x1 + l.b * y1 + l.c;
      double t2 = l.a * x2 + l.b * y2 + l.c;
      return t1 * t2 <= 0;
    }

    boolean intersects(LineSegment s) {
      return bothSides(s) && s.bothSides(this);
    }

    // s????????????????????
    private boolean bothSides(LineSegment s) {
      double ccw1 = GeomUtils.ccw(x1, y1, s.x1, s.y1, x2, y2);
      double ccw2 = GeomUtils.ccw(x1, y1, s.x2, s.y2, x2, y2);
      if (ccw1 == 0 && ccw2 == 0) { // s??????????????
        // s?????1?????????????????s??????????????
        // true???
        return internal(s.x1, s.y1) || internal(s.x2, s.y2);
      } else { // ???????
        // CCW???????????true???
        return ccw1 * ccw2 <= 0;
      }
    }

    // (x, y)???????????????????
    private boolean internal(double x, double y) {
      // (x, y)??????????????????????????????
      return GeomUtils.dot(x1 - x, y1 - y, x2 - x, y2 - y) <= 0;
    }

    public Point2D getIntersectionPoint(Line l) {
      if (!intersects(l)) {
        return null; // ????????null???
      }
      return l.getIntersectionPoint(toLine());
    }

    public Point2D getIntersectionPoint(LineSegment s) {
      if (!intersects(s)) {
        return null; // ????????null???
      }
      return s.toLine().getIntersectionPoint(toLine());
    }

    @Override
    public String toString() {
      return "(" + x1 + ", " + y1 + ") - (" + x2 + ", " + y2 + ")";
    }
  }

  /**
   * from http://gihyo.jp/dev/serial/01/geometry part 6
   */
  static class GeomUtils {
    static double cross(double x1, double y1, double x2, double y2) {
      return x1 * y2 - x2 * y1;
    }

    static double dot(double x1, double y1, double x2, double y2) {
      return x1 * x2 + y1 * y2;
    }

    // (x1, y1) -> (x2, y2) -> (x3, y3) ????????????????????
    // ?????????????????????????
    static double ccw(double x1, double y1, double x2, double y2,
                      double x3, double y3) {
      return cross(x2 - x1, y2 - y1, x3 - x2, y3 - y2);
    }

    static double ccw(Point2D p1, Point2D p2, Point2D p3) {
      return ccw(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY());
    }
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

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
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

  static class Pair<F extends Comparable<F>, S extends Comparable<S>> implements Comparable<Pair<F, S>> {
    F f;
    S s;

    Pair() {
    }

    Pair(F f, S s) {
      this.f = f;
      this.s = s;
    }

    Pair(Pair<F, S> p) {
      f = p.f;
      s = p.s;
    }

    @Override
    public int compareTo(Pair<F, S> p) {
      if (f.compareTo(p.f) != 0) {
        return f.compareTo(p.f);
      }
      return s.compareTo(p.s);
    }

    @Override
    public int hashCode() {
      return f.hashCode() ^ s.hashCode();
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || this.f == null || this.s == null) {
        return false;
      }
      if (this.getClass() != o.getClass()) {
        return false;
      }
      Pair p = (Pair) o;
      return this.f.equals(p.f) && this.s.equals(p.s);
    }

    @Override
    public String toString() {
      return "{" + f.toString() + ", " + s.toString() + "}";
    }
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
    void set(int i, T v) {
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

  class SegmentTree<T> {
    int n;
    ArrayList<T> dat;
    BiFunction<T, T, T> bif;
    Supplier<T> sup;

    /**
     * 0-indexed ?Segment Tree?????
     *
     * @param n_  ????
     * @param bif ???????
     * @param sup ???
     */
    SegmentTree(int n_, BiFunction<T, T, T> bif, Supplier<T> sup) {
      n = 1;
      while (n < n_) n *= 2;

      dat = new ArrayList<>(2 * n - 1);
      for (int i = 0; i < 2 * n - 1; ++i) {
        dat.add(sup.get());
      }
      this.bif = bif;
      this.sup = sup;
    }

    /**
     * k??????v?????
     *
     * @param k index
     * @param v ????
     */
    void set(int k, T v) {
      k += n - 1;
      dat.set(k, v);
      while (k > 0) {
        k = (k - 1) / 2;
        dat.set(k, bif.apply(dat.get(k * 2 + 1), dat.get(k * 2 + 2)));
      }
    }

    /**
     * ????
     *
     * @param l ???
     * @param r ???
     * @return [l, r)????bif??????????
     */
    T reduce(int l, int r) {
      return _reduce(l, r, 0, 0, n);
    }

    T _reduce(int a, int b, int k, int l, int r) {
      if (r <= a || b <= l) return sup.get();
      if (a <= l && r <= b) return dat.get(k);
      T vl = _reduce(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = _reduce(a, b, k * 2 + 2, (l + r) / 2, r);
      return bif.apply(vl, vr);
    }
  }
}