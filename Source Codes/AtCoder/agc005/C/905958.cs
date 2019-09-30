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
        int n = sc.Int;
        var a = sc.IntArr;
        var c = new int[n];
        foreach (var item in a)
        {
            ++c[item];
        }
        int max = a.Max(), min = a.Min();
        if ((max + 1) / 2 != min || max % 2 == 0 && c[max / 2] != 1 || max % 2 == 1 && c[(max + 1) / 2] != 2)
        {
            DBG("Impossible");
            return;
        }
        for (int i = min + 1; i <= max; i++)
        {
            if (c[i] < 2)
            {
                DBG("Impossible");
                return;
            }
        }
        sw.WriteLine("Possible");
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
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
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
    static int Mod = 1000000007;
    public void setMod(int m) { Mod = m; }
    public bool isprime(long a)
    {
        if (a < 2) return false;
        for (long i = 2; i * i <= a; i++) if (a % i == 0) return false;
        return true;
    }
    public bool[] sieve(int n)
    {
        var isp = new bool[n + 1];
        for (int i = 2; i <= n; i++) isp[i] = true;
        for (int i = 2; i * i <= n; i++) if (isp[i]) for (int j = i * i; j <= n; j += i) isp[j] = false;
        return isp;
    }
    public List<int> getprimes(int n)
    {
        var prs = new List<int>();
        var isp = sieve(n);
        for (int i = 2; i <= n; i++) if (isp[i]) prs.Add(i);
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
    public long[][] powmat(long[][] A, long n)
    {
        if (n == 0) return E(A.Length);
        var t = powmat(A, n / 2);
        if ((n & 1) == 0) return mulmat(t, t);
        return mulmat(mulmat(t, t), A);
    }
    public long[] mulmat(long[][] A, long[] x)
    {
        int n = A.Length, m = x.Length;
        var ans = new long[n];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i] = (ans[i] + x[j] * A[i][j]) % Mod;
        return ans;
    }
    public long[][] mulmat(long[][] A, long[][] B)
    {
        int n = A.Length, m = B[0].Length, l = B.Length;
        var ans = new long[n][];
        for (int i = 0; i < n; i++)
        {
            ans[i] = new long[m];
            for (int j = 0; j < m; j++) for (int k = 0; k < l; k++) ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % Mod;
        }
        return ans;
    }
    public long[] addmat(long[] x, long[] y)
    {
        int n = x.Length;
        var ans = new long[n];
        for (int i = 0; i < n; i++) ans[i] = (x[i] + y[i]) % Mod;
        return ans;
    }
    public long[][] addmat(long[][] A, long[][] B)
    {
        int n = A.Length, m = A[0].Length;
        var ans = new long[n][];
        for (int i = 0; i < n; i++) ans[i] = addmat(A[i], B[i]);
        return ans;
    }
    public long powmod(long a, long b)
    {
        if (a >= Mod) return powmod(a % Mod, b);
        if (a == 0) return 0;
        if (b == 0) return 1;
        var t = powmod(a, b / 2);
        if ((b & 1) == 0) return t * t % Mod;
        return t * t % Mod * a % Mod;
    }
    public long inv(long a) { return powmod(a, Mod - 2); }
    public long gcd(long a, long b)
    {
        while (b > 0) { var t = a % b; a = b; b = t; }
        return a;
    }
    public long lcm(long a, long b) { return a * (b / gcd(a, b)); }
    public long Comb(int n, int r)
    {
        if (n < 0 || r < 0 || r > n) return 0;
        if (n - r < r) r = n - r;
        if (r == 0) return 1;
        if (r == 1) return n;
        var numerator = new int[r];
        var denominator = new int[r];
        for (int k = 0; k < r; k++)
        {
            numerator[k] = n - r + k + 1;
            denominator[k] = k + 1;
        }
        for (int p = 2; p <= r; p++)
        {
            int pivot = denominator[p - 1];
            if (pivot > 1)
            {
                int offset = (n - r) % p;
                for (int k = p - 1; k < r; k += p)
                {
                    numerator[k - offset] /= pivot;
                    denominator[k] /= pivot;
                }
            }
        }
        long result = 1;
        for (int k = 0; k < r; k++) if (numerator[k] > 1) result = result * numerator[k] % Mod;
        return result;
    }
}