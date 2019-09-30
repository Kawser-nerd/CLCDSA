import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.function.BiFunction;
import java.util.function.Function;

public class Main {
  Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    new Main().run();
  }


  double f(double x) {
    return x + p / Math.pow(2.0, x / 1.5);
  }

  double f_(double x) {
    return 1.0 - p * Math.log(2) / 1.5 * Math.pow(2.0, -x / 1.5);
  }

  double p;

  void run() {
    p = sc.nextDouble();

    double left = 0;
    double right = p;
    while (right - left > 1e-9) {
      double mid = (left + right) / 2.0;
      double v = f_(mid);
      if (v > 0) {
        right = mid;
      } else {
        left = mid;
      }
    }

    System.out.println(f(right));
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

    BIT(int n, BiFunction<T, T, T> bif, T defaultValue) {
      this.n = n;
      bit = new ArrayList<>(n + 1);
      for (int i = 0; i < n + 1; ++i) {
        bit.add(defaultValue);
      }
      this.bif = bif;
    }

    void update(int i, T v) {
      for (int x = i; x <= n; x += x & -x) {
        bit.set(x, bif.apply(bit.get(x), v));
      }
    }

    T reduce(int i, T defaultValue) {
      T ret = defaultValue;
      for (int x = i; x > 0; x -= x & -x) {
        ret = bif.apply(ret, bit.get(x));
      }
      return ret;
    }
  }

  long MOD = 1_000_000_007;

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
}