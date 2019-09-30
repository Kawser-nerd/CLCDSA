using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Program
{
    const int M = 1000000007;
    const double eps = 1e-9;
    static int[] dd = { 0, 1, 0, -1, 0 };
    static void Main()
    {
        var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        var sc = new Scan();
        // var sc = new ScanCHK();
        int h, w;
        sc.Multi(out h, out w);
        var r = new bool[h][];
        var b = new bool[h][];
        for (int i = 0; i < h; i++)
        {
            r[i] = new bool[w];
            b[i] = new bool[w];
            var a = sc.Str;
            for (int j = 0; j < w; j++)
            {
                if (a[j] == '#')
                {
                    r[i][j] = true;
                    b[i][j] = true;
                    continue;
                }
                if (j == 0 || j < w - 1 && (i & 1) == 0)
                    r[i][j] = true;
                if (j == w - 1 || j > 0 && (i & 1) == 1)
                    b[i][j] = true;
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                sw.Write(r[i][j] ? "#" : ".");

            sw.WriteLine();
        }
        sw.WriteLine();
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                sw.Write(b[i][j] ? "#" : ".");

            sw.WriteLine();
        }
        sw.Flush();
    }

    static void swap<T>(ref T a, ref T b) { var t = a; a = b; b = t; }
    static void swap<T>(IList<T> a, int i, int j) { var t = a[i]; a[i] = a[j]; a[j] = t; }
    static T Max<T>(params T[] a) { return a.Max(); }
    static T Min<T>(params T[] a) { return a.Min(); }
    static string con<T>(IEnumerable<T> a) { return string.Join(" ", a); }
    static void DBG<T>(params T[] a) { Console.WriteLine(string.Join(" ", a)); }
    static void DBG(params object[] a) { Console.WriteLine(string.Join(" ", a)); }
    static T[] copy<T>(IList<T> a)
    {
        int n = a.Count;
        var ret = new T[n];
        for (int i = 0; i < n; i++) ret[i] = a[i];
        return ret;
    }
}
class ScanCHK : Scan
{
    public new string Str
    {
        get
        {
            var s = Console.ReadLine();
            return s == s.Trim() ? s : "";
        }
    }
}
class Scan
{
    public int Int { get { return int.Parse(Str); } }
    public long Long { get { return long.Parse(Str); } }
    public double Double { get { return double.Parse(Str); } }
    public string Str { get { return Console.ReadLine().Trim(); } }
    public int[] IntArr { get { return StrArr.Select(int.Parse).ToArray(); } }
    public int[] IntArrWithSep(char sep) { return Str.Split(sep).Select(int.Parse).ToArray(); }
    public long[] LongArr { get { return StrArr.Select(long.Parse).ToArray(); } }
    public double[] DoubleArr { get { return StrArr.Select(double.Parse).ToArray(); } }
    public string[] StrArr { get { return Str.Split(); } }
    T cv<T>(string inp)
    {
        if (typeof(T).Equals(typeof(int)))    return (T)Convert.ChangeType(int.Parse(inp), typeof(T));
        if (typeof(T).Equals(typeof(long)))   return (T)Convert.ChangeType(long.Parse(inp), typeof(T));
        if (typeof(T).Equals(typeof(double))) return (T)Convert.ChangeType(double.Parse(inp), typeof(T));
        if (typeof(T).Equals(typeof(char)))   return (T)Convert.ChangeType(inp[0], typeof(T));
        return (T)Convert.ChangeType(inp, typeof(T));
    }
    public void Multi<T>(out T a) { a = cv<T>(Str); }
    public void Multi<T, U>(out T a, out U b)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); }
    public void Multi<T, U, V>(out T a, out U b, out V c)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); }
    public void Multi<T, U, V, W>(out T a, out U b, out V c, out W d)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); }
    public void Multi<T, U, V, W, X>(out T a, out U b, out V c, out W d, out X e)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]); }
}
class mymath
{
    int Mod = 1000000007;
    public void setMod(int m) { Mod = m; }
    public bool isprime(long a)
    {
        if (a < 2) return false;
        for (long i = 2; i * i <= a; i++) if (a % i == 0) return false;
        return true;
    }
    public bool[] sieve(int n)
    {
        var p = new bool[n + 1];
        for (int i = 2; i <= n; i++) p[i] = true;
        for (int i = 2; i * i <= n; i++) if (p[i]) for (int j = i * i; j <= n; j += i) p[j] = false;
        return p;
    }
    public List<int> getprimes(int n)
    {
        var prs = new List<int>();
        var p = sieve(n);
        for (int i = 2; i <= n; i++) if (p[i]) prs.Add(i);
        return prs;
    }
    public long[][] E(int n)
    {
        var ret = new long[n][];
        for (int i = 0; i < n; i++)
        {
            ret[i] = new long[n];
            ret[i][i] = 1;
        }
        return ret;
    }
    public long[][] pow(long[][] A, long n)
    {
        if (n == 0) return E(A.Length);
        var t = pow(A, n / 2);
        if ((n & 1) == 0) return mul(t, t);
        return mul(mul(t, t), A);
    }
    public long dot(long[] x, long[] y)
    {
        int n = x.Length;
        long ret = 0;
        for (int i = 0; i < n; i++) ret = (ret + x[i] * y[i]) % Mod;
        return ret;
    }
    public long[][] trans(long[][] A)
    {
        int n = A[0].Length, m = A.Length;
        var ret = new long[n][];
        for (int i = 0; i < n; i++)
        {
            ret[i] = new long[m];
            for (int j = 0; j < m; j++) ret[i][j] = A[j][i];
        }
        return ret;
    }
    public long[] mul(long[][] A, long[] x)
    {
        int n = A.Length;
        var ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = dot(x, A[i]);
        return ret;
    }
    public long[][] mul(long[][] A, long[][] B)
    {
        int n = A.Length;
        var Bt = trans(B);
        var ret = new long[n][];
        for (int i = 0; i < n; i++) ret[i] = mul(Bt, A[i]);
        return ret;
    }
    public long[] add(long[] x, long[] y)
    {
        int n = x.Length;
        var ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = (x[i] + y[i]) % Mod;
        return ret;
    }
    public long[][] add(long[][] A, long[][] B)
    {
        int n = A.Length;
        var ret = new long[n][];
        for (int i = 0; i < n; i++) ret[i] = add(A[i], B[i]);
        return ret;
    }
    public long pow(long a, long b)
    {
        if (a >= Mod) return pow(a % Mod, b);
        if (a == 0) return 0;
        if (b == 0) return 1;
        var t = pow(a, b / 2);
        if ((b & 1) == 0) return t * t % Mod;
        return t * t % Mod * a % Mod;
    }
    public long inv(long a) { return pow(a, Mod - 2); }
    public long gcd(long a, long b)
    {
        while (b > 0) { var t = a % b; a = b; b = t; }
        return a;
    }
    public long lcm(long a, long b) { return a * (b / gcd(a, b)); }
    public long comb(int n, int r)
    {
        if (n < 0 || r < 0 || r > n) return 0;
        if (n - r < r) r = n - r;
        if (r == 0) return 1;
        if (r == 1) return n;
        var numer = new int[r];
        var denom = new int[r];
        for (int k = 0; k < r; k++)
        {
            numer[k] = n - r + k + 1;
            denom[k] = k + 1;
        }
        for (int p = 2; p <= r; p++)
        {
            int piv = denom[p - 1];
            if (piv > 1)
            {
                int ofst = (n - r) % p;
                for (int k = p - 1; k < r; k += p)
                {
                    numer[k - ofst] /= piv;
                    denom[k] /= piv;
                }
            }
        }
        long ret = 1;
        for (int k = 0; k < r; k++) if (numer[k] > 1) ret = ret * numer[k] % Mod;
        return ret;
    }
}