using System;
using System.IO;
using System.Text;
using System.Collections.Generic;


class Solver {
  const int M = 9999999;
  const int MOD = 1000000007;
  public long exp(long x, long t) {
    if (t == 0) return 1;
    long ret = exp(x, t >> 1);
    ret = ret * ret % MOD;
    if ((t & 1) == 1) ret = ret * x % MOD;
    return ret;
  }
  public int f(int x) {
    if (x <= 9) return 1;
    if (x <= 99) return 2;
    if (x <= 999) return 3;
    if (x <= 9999) return 4;
    if (x <= 99999) return 5;
    if (x <= 999999) return 6;
    if (x <= 9999999) return 7;
    return 8;
  }
  public void solve() {
    int n = cin.readInt();
    long ans = 0;
    for (int i = 1, r = 1, sum = 0; i <= M; i++) {
      while (sum < n && r <= M) {
        sum += f(r); r++;
      }
      if (sum < n) {
        if ((n - sum) % 8 == 0) ans++;
      } else {
        if (sum == n) ans++;
      }
      sum -= f(i);
    }
    List<int> fac = new List<int>();
    for (int i = 1; i * i <= n; i++) {
      if (n % i != 0) continue;
      fac.Add(i);
      if (n/i != i) fac.Add(n/i);
    }
    foreach(int x in fac) {
      if (x < 8) continue;
      ans += (exp(10, x-1) * 9) - (n / x - 1) + MOD;
      ans %= MOD;
    }
    {
      int r = n / 8;
      ans += r;
      ans %= MOD;
      foreach (int x in fac) {
        if (x < 8) continue;
        if (n/x <= r) {
          ans += MOD - 1;
          ans %= MOD;
        }
      }
    }
    ans = (ans % MOD + MOD) % MOD;
    Console.Out.WriteLine(ans);
  }

  public Istream cin = new Istream(Console.OpenStandardInput());
  static public void swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
}


#region Istream
class Istream {
  public Istream(Stream _ins) { ins = _ins; }

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