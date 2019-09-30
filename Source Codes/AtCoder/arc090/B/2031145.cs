using System;
using System.IO;
using System.Text;


class Solver {
  class UnionFind {
    public UnionFind(int _n) {
      n = _n;
      p = new int[n];
      x = new int[n];
      for (int i = 0; i < n; i++) p[i] = -1;
    }

    public int n;
    public int[] p, x;

    public int root(int v) {
      if (p[v] < 0) return v;
      int np = root(p[v]);
      x[v] += x[p[v]];
      return p[v] = np;
    }
    public bool join(int a, int b, int d) {
      if (root(a) == root(b)) {
        return x[b]-x[a] == d;
      }
      d += x[a]-x[b];
      a = root(a); b = root(b);
      if (p[a] > p[b]) {
        swap(ref a, ref b);
        d = -d;
      }
      p[a] += p[b]; p[b] = a;
      x[b] = d;
      return true;
    }
  }

  public void solve() {
    int n = cin.readInt();
    int m = cin.readInt();
    UnionFind uf = new UnionFind(n);
    for (int i = 0; i < m; i++) {
      int l = cin.readInt();
      int r = cin.readInt();
      int d = cin.readInt();
      --l; --r;
      if (!uf.join(l,r,d)) {
        Console.Out.WriteLine("No");
        return;
      }
    }
    Console.Out.WriteLine("Yes");
  }

  public Istream cin = new Istream(Console.OpenStandardInput());
  static public void swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
}


#region Istream
class Istream {
  public Istream(Stream _ins) { ins = _ins;}

  const int BUF_SZ = 1024;
  private Stream ins;
  private byte[] buf = new byte[BUF_SZ];
  private int len, ptr;

  private byte readByte() {
    if (ptr >= len) {
      ptr = 0;
      len = ins.Read(buf, 0, BUF_SZ);
      if (len == 0) return 0;
    }
    return buf[ptr++];
  }
  public char nextChar() {
    byte b;
    do b = readByte(); while (b < 33 && 126 < b);
    return (char)b;
  }
  public string read() {
    var sb = new StringBuilder();
    for (char c = nextChar(); (33 <= c && c <= 126); c = (char)readByte()) sb.Append(c);
    return sb.ToString();
  }
  public string readLine() {
    var sb = new StringBuilder();
    for (char c = nextChar(); (c != '\n' && c != 0); c = (char)readByte()) sb.Append(c);
    return sb.ToString();
  }
  public long readLong() { return long.Parse(read()); }
  public int readInt() { return int.Parse(read()); }
  public double readDouble() { return double.Parse(read()); }
}
#endregion


#region Main
class ReSha {
  static void Main() {
    new Solver().solve();
  }
}
#endregion