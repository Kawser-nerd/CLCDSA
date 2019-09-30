import java.util.*; import java.math.*; import java.awt.Point;
import static java.util.Arrays.*; import static java.util.Collections.*;
import static java.lang.Math.*; import static java.lang.System.*;
class Main extends Lib {
  long[] fromLeft(int n, long[] a) {
    long[] r = new long[n+1];
    PriorityQueue<Long> q = new PriorityQueue<>();
    long s = 0;
    for (int i=0; i<n; i++) {
      q.add(a[i]);
      s += a[i];
    }
    r[0] = s;
    for (int i=n; i<2*n; i++) {
      q.add(a[i]);
      s += a[i];
      s -= q.poll();
      r[i-n+1] = s;
    }
    return r;
  }
  long[] fromRight(int n, long[] a) {
    long[] r = new long[n+1];
    PriorityQueue<Long> q = new PriorityQueue<>(Collections.reverseOrder());
    long s = 0;
    for (int i=0; i<n; i++) {
      q.add(a[3*n - i - 1]);
      s += a[3*n - i - 1];
    }
    r[n] = s;
    for (int i=0; i<n ; i++) {
      int j = 2 * n - 1 - i;
      q.add(a[j]);
      s += a[j];
      s -= q.poll();
      r[n-i-1] = s;
    }
    return r;
  }
  long solve(int n, long[] a) {
    //    println(Arrays.toString(fromLeft(n, a)));
    //    println(Arrays.toString(fromRight(n, a)));
    long[] p = fromLeft(n, a);
    long[] q = fromRight(n, a);
    long max = p[0] - q[0];
    for (int i=1; i<=n; i++)
      max = max(max, p[i] - q[i]);
    return max;
  }
  void solve() {
    int n = _Int();
    long[] a = new long[3*n];
    for (int i : until(3*n)) {
      a[i] = sc.nextLong();
    }
    println(solve(n, a));
  }
  public static void main(String[] args) { new Main().solve(); }
}
class Lib {
  void println(Object o) { out.println(o); }
  void ln() { out.println(); }
  void print(Object o) { out.print(o); }
  void printf(String f, Object...o) { out.printf(f, o); }
  Scanner sc = new Scanner(in);
  int _Int() { return sc.nextInt(); }
  long _Long() { return sc.nextLong(); }
  String _Next() { return sc.next(); }
  char _Char() { return sc.next().charAt(0); }
  String _Line() { return sc.nextLine(); }
  boolean _HasInt() { return sc.hasNextInt(); }
  boolean _HasNext() { return sc.hasNext(); }
  boolean _HasLine() { return sc.hasNextLine(); }
  int[] until(int n) { int[] t = new int[n]; for (int i=0; i<n; i++) t[i] = i; return t; }
  int[] until(int fr, int to) { int[] t = new int[to-fr]; for (int i=fr; i<to; i++) t[i-fr] = i; return t; }
  int[] to(int fr, int to) { return until(fr, to+1); } int[] to(int n) { return until(0, n); }
}