using System;
using System.IO;
using System.Text;

class Solver {
  public Istream cin = new Istream(Console.OpenStandardInput());
  public void solve() {
    int n = cin.readInt();
    int[,] a = new int[2, n];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        a[i, j] = cin.readInt();
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        if (j <= i) cur += a[0, j];
        if (i <= j) cur += a[1, j];
      }
      ans = Math.Max(ans, cur);
    }
    Console.Out.WriteLine(ans);
  }
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