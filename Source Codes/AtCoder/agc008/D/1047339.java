import java.io.*;
import java.util.*;

public class Main {
  private static boolean debug = false;
  private static boolean elapsed = false;

  private static PrintWriter _err = new PrintWriter(System.err);

  private int N;
  private int[] x;

  private void solve(Scanner sc, PrintWriter out) {
    N = sc.nextInt();
    x = new int[N];
    int[] a = new int[N * N];
    int[] cnt = new int[N];
    List<Pair<Integer>> list = new ArrayList<>();
    for (int i = 0; i < N; ++i) {
      x[i] = sc.nextInt() - 1;

      if (a[x[i]] > 0) {
        out.println("No");
        return;
      }
      a[x[i]] = i + 1;
      ++cnt[i];

      Pair<Integer> p = new Pair<>(x[i], i);
      list.add(p);
    }
    Collections.sort(list);
    int[] y = new int[N];
    for (int i = 0; i < N; ++i) {
      Pair<Integer> p = list.get(i);
      y[i] = p.b;
    }
    Collections.reverse(list);
    int[] z = new int[N];
    for (int i = 0; i < N; ++i) {
      Pair<Integer> p = list.get(i);
      z[i] = p.b;
    }

    for (int i = 0; i < N; ++i) {
//_err.println("1:[" + i + "][" + y[i] + "][" + z[i] + "] " + Arrays.toString(a));
      for (int j = 0; j < x[y[i]]; ++j) {
        if (cnt[y[i]] >= y[i] + 1) {
          break;
        }
        if (a[j] == 0) {
          a[j] = y[i] + 1;
          ++cnt[y[i]];
        }
      }
      if (cnt[y[i]] != y[i] + 1) {
        out.println("No");
        return;
      }
//_err.println("2:[" + i + "][" + y[i] + "][" + z[i] + "] " + Arrays.toString(a));
    }
    for (int i = 0; i < N; ++i) {
//_err.println("3:[" + i + "][" + y[i] + "][" + z[i] + "] " + Arrays.toString(a));
      for (int j = N * N - 1; j > x[z[i]]; --j) {
        if (cnt[z[i]] >= N) {
          break;
        }
        if (a[j] == 0) {
          a[j] = z[i] + 1;
          ++cnt[z[i]];
        }
      }
      if (cnt[z[i]] != N) {
        out.println("No");
        return;
      }
//_err.println("4:[" + i + "][" + y[i] + "][" + z[i] + "] " + Arrays.toString(a));
    }
    for (int i = 0; i < N * N; ++i) {
      if (a[i] == 0) {
        out.println("No");
        return;
      }
    }
    out.println("Yes");
    for (int i = 0; i < a.length; ++i) {
      if (i > 0) {
        out.print(" ");
      }
      out.print(a[i]);
    }
    out.println();
  }
  private long C(long n, long r) {
    long res = 1;
    for (long i = n; i > n - r; --i) {
      res *= i;
    }
    for (long i = r; i > 1; --i) {
      res /= i;
    }
    return res;
  }
  private long P(long n, long r) {
    long res = 1;
    for (long i = n; i > n - r; --i) {
      res *= i;
    }
    return res;
  }
  private static class Pair<T extends Comparable<T>> implements Comparable<Pair<T>> {
    T a;
    T b;
    public Pair(T a, T b) {
      this.a = a;
      this.b = b;
    }
    @Override
    public int compareTo(Pair<T> that) {
      if (this == that) {
        return 0;
      }
      if (this.a != null && that.a == null) {
        return 1;
      } else if (this.a == null && that.a != null) {
        return -1;
      }
      if (this.b != null && that.b == null) {
        return 1;
      } else if (this.b == null && that.b != null) {
        return -1;
      }
      int r = 0;
      if (this.a != null && that.a != null) {
        r = this.a.compareTo(that.a);
        if (r != 0) {
          return r;
        }
      }
      if (this.b != null && that.b != null) {
        r = this.b.compareTo(that.b);
        if (r != 0) {
          return r;
        }
      }
      return r;
    }
    @Override
    public boolean equals(Object o) {
      if (o instanceof Pair) {
        Pair that = (Pair)o;
        boolean res = (this.a == null && this.a == that.a || this.a != null && this.a.equals(that.a));
        res = res && (this.b == null && this.b == that.b || this.b != null && this.b.equals(that.b));
        return res;
      }
      return false;
    }
    @Override
    public int hashCode() {
      int hashCode = 17;
      hashCode = hashCode * 31 + (a != null ? a.hashCode() : 0);
      hashCode = hashCode * 31 + (b != null ? b.hashCode() : 0);
      return hashCode;
    }
    @Override
    public String toString() {
      return "[" + a + ", " + b + "]";
    }
  }
  /*
   * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
   * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
   */
  public static void main(String[] args) {
    long S = System.currentTimeMillis();

    Scanner sc = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    new Main().solve(sc, out);
    out.flush();

    long G = System.currentTimeMillis();
    if (elapsed) {
      _err.println((G - S) + "ms");
    }
    _err.flush();
  }
}