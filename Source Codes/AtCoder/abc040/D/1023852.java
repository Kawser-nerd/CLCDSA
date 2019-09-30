import java.io.*;
import java.util.*;

public class Main {
  private static boolean debug = false;
  private static boolean elapsed = false;

  private static PrintWriter _err = new PrintWriter(System.err);

  private int N;
  private int M;
  private int Q;

  private void solve(Scanner sc, PrintWriter out) {
    N = sc.nextInt();
    M = sc.nextInt();
    List<Triple<Integer>> roadList = new ArrayList<>();
    for (int i = 0; i < M; ++i) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      int y = sc.nextInt();
      roadList.add(new Triple<Integer>(y, a, b));
    }

    Q = sc.nextInt();
    List<Triple<Integer>> personList = new ArrayList<>();
    for (int i = 0; i < Q; ++i) {
      int v = sc.nextInt();
      int w = sc.nextInt();
      personList.add(new Triple<Integer>(w, i, v));
    }

    Collections.sort(roadList);
    Collections.reverse(roadList);
    Collections.sort(personList);
    Collections.reverse(personList);

    UnionFind uf = new UnionFind(N);
    int[] count = new int[Q];

    int roadIdx = 0;

    for (int i = 0; i < Q; ++i) {
      int year = personList.get(i).a;
      int p = personList.get(i).b;
      int city = personList.get(i).c;

      while (roadIdx < M && roadList.get(roadIdx).a > year) {
        uf.union(roadList.get(roadIdx).b, roadList.get(roadIdx).c);
        ++roadIdx;
      }
      count[p] = uf.groupSize(city);
    }

    for (int cnt : count) {
      out.println(cnt);
    }
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
  private long ceil2pow(long n) {
    if (n == 0) {
      return 1;
    }
    n--;
    n |= (n >>> 1);
    n |= (n >>> 2);
    n |= (n >>> 4);
    n |= (n >>> 8);
    n |= (n >>> 16);
    n++;
    return n;
  }
  private static class UnionFind {
    private int[] partition;
    private int[] rank;
    private int groupCount;
   
    public UnionFind(int n) {
      partition = new int[n + 1];
      Arrays.fill(partition, -1);
      rank = new int[n + 1];
      Arrays.fill(rank, 0);
      groupCount = n;
    }
   
    public void union(int x, int y) {
      x = find(x);
      y = find(y);
   
      if (x == y) {
        return;
      }
   
      --groupCount;
   
      if (rank[x] < rank[y]) {
        partition[y] += partition[x];
        partition[x] = y;
   
        ++rank[y];
      } else {
        partition[x] += partition[y];
        partition[y] = x;
   
        ++rank[x];
      }
    }
   
    public int find(int x) {
      if(partition[x] < 0) {
        return x;
      } else {
        return (partition[x] = find(partition[x]));
      }
    }
   
    public int groupSize(int x) {
      return -(partition[find(x)]);
    }
   
    public boolean same(int x, int y) {
      return (find(x) == find(y));
    }
   
    public int groupCount() {
      return groupCount;
    }
  }
  private static class Triple<T extends Comparable<T>> implements Comparable<Triple<T>> {
    T a;
    T b;
    T c;
    public Triple(T a, T b, T c) {
      this.a = a;
      this.b = b;
      this.c = c;
    }
    public int compareTo(Triple<T> that) {
      int r = this.a != null ? this.a.compareTo(that.a) : (that.a == null ? 0 : -1);
      if (r != 0) {
        return r;
      }
      r = this.b != null ? this.b.compareTo(that.b) : (that.b == null ? 0 : -1);
      if (r != 0) {
        return r;
      }
      r = this.c != null ? this.c.compareTo(that.c) : (that.c == null ? 0 : -1);
      return r;
    }
    public boolean equals(Object o) {
      if (o instanceof Triple) {
        Triple that = (Triple)o;
        boolean res = (this.a == null && this.a == that.a || this.a != null && this.a.equals(that.a));
        res = res & (this.b == null && this.b == that.b || this.b != null && this.b.equals(that.b));
        res = res & (this.c == null && this.c == that.c || this.c != null && this.c.equals(that.c));
        return res;
      }
      return false;
    }
    public int hashCode() {
      int hashCode = 17;
      hashCode = hashCode * 31 + (a != null ? a.hashCode() : 0);
      hashCode = hashCode * 31 + (b != null ? b.hashCode() : 0);
      hashCode = hashCode * 31 + (c != null ? c.hashCode() : 0);
      return hashCode;
    }
    public String toString() {
      return "[" + a + ", " + b + ", " + c + "]";
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