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
        double lim = 2 * 1e10;
        int lim2 = 110000, lim3 = 2200;
        var isp = new bool[lim2];
        var pr1 = new SortedSet<int>();
        var pr2 = new SortedDictionary<long, int>();
        var dic = new SortedDictionary<long, long>();
        var cnt = new SortedDictionary<long, int>();
        var pr = new List<int>();
        for (int i = 2; i < lim2; i++)
            isp[i] = true; 

        pr2.Add(1, 1);
        for (int i = 2; i < lim2; i++)
        {
            if (isp[i])
            {
                pr.Add(i);
                pr1.Add(i);
                pr2.Add(i * (long)i, i);
                for (long j = i * (long)i; j < lim2; j += i)
                    isp[j] = false;
            }
        }
        int n = sc.Int, ans = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            long a = sc.Long, b = 1, p = 1;
            foreach (var item in pr)
            {
                if (item > lim3 || a < item) break;

                long i3 = item * (long)item * item;
                int i2 = item * item;

                while (a % i3 == 0) a /= i3;
                
                if (a % i2 == 0)
                {
                    a /= i2;
                    b *= i2;
                    p *= item;
                }
                if (a % item == 0)
                {
                    a /= item;
                    b *= item;
                    p *= i2;
                }
                if (p > lim)
                {
                    ++ans;
                    goto A;
                }
            }
            if (a * b == 1)
            {
                one = 1;
                continue;
            }
            if (pr2.ContainsKey(a))
            {
                long nor = a * b, pir = p * pr2[a];
                if (pir > lim)
                {
                    ++ans;
                    continue;
                }
                if (!dic.ContainsKey(nor))
                    dic.Add(nor, pir);
                if (!cnt.ContainsKey(nor))
                    cnt.Add(nor, 1);
                else
                    ++cnt[nor];
            }
            else if (a < lim2 && pr1.Contains((int)a))
            {
                if (p * a > lim || p * a * a > lim)
                {
                    ++ans;
                    continue;
                }
                long nor = a * b, pir = p * a * a;
                if (!dic.ContainsKey(nor))
                    dic.Add(nor, pir);
                if (!cnt.ContainsKey(nor))
                    cnt.Add(nor, 1);
                else
                    ++cnt[nor];
            }
            else
                ++ans;

            A:
            continue;
        }
        int half = 0;
        foreach (var item in cnt)
        {
            var pir = dic[item.Key];
            int c = cnt.ContainsKey(pir) ? cnt[pir] : 0;
            if (item.Value > c)
                ans += item.Value;
            else if (item.Value == c)
                half += c;
        }
        sw.WriteLine(ans + one + half / 2);
        sw.Flush();
    }

    static void swap<T>(ref T a, ref T b) { var t = a; a = b; b = t; }
    static void swap<T>(IList<T> a, int i, int j) { var t = a[i]; a[i] = a[j]; a[j] = t; }
    static T Max<T>(params T[] a) { return a.Max(); }
    static T Min<T>(params T[] a) { return a.Min(); }
    static void DBG<T>(params T[] a) { Console.WriteLine(string.Join(" ", a)); }
    static void DBG(params object[] a) { Console.WriteLine(string.Join(" ", a)); }
    static T[] copy<T>(IList<T> a)
    {
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
        return ret;
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
    public void Multi(out int a, out int b) { var arr = IntArr; a = arr[0]; b = arr[1]; }
    public void Multi(out int a, out int b, out int c) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; }
    public void Multi(out int a, out string b) { var arr = StrArr; a = int.Parse(arr[0]); b = arr[1]; }
    public void Multi(out string a, out int b) { var arr = StrArr; a = arr[0]; b = int.Parse(arr[1]); }
    public void Multi(out int a, out char b) { var arr = StrArr; a = int.Parse(arr[0]); b = arr[1][0]; }
    public void Multi(out char a, out int b) { var arr = StrArr; a = arr[0][0]; b = int.Parse(arr[1]); }
    public void Multi(out long a, out long b) { var arr = LongArr; a = arr[0]; b = arr[1]; }
    public void Multi(out long a, out int b) { var arr = LongArr; a = arr[0]; b = (int)arr[1]; }
    public void Multi(out int a, out long b) { var arr = LongArr; a = (int)arr[0]; b = arr[1]; }
    public void Multi(out string a, out string b) { var arr = StrArr; a = arr[0]; b = arr[1]; }
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
    public long[][] powmat(long[][] A, long n)
    {
        var E = new long[A.Length][];
        for (int i = 0; i < A.Length; i++)
        {
            E[i] = new long[A.Length];
            E[i][i] = 1;
        }
        if (n == 0) return E;
        var t = powmat(A, n / 2);
        if ((n & 1) == 0) return mulmat(t, t);
        return mulmat(mulmat(t, t), A);
    }
    public long[] mulmat(long[][] A, long[] x)
    {
        var ans = new long[A.Length];
        for (int i = 0; i < A.Length; i++) for (int j = 0; j < x.Length; j++) ans[i] = (ans[i] + x[j] * A[i][j]) % Mod;
        return ans;
    }
    public long[][] mulmat(long[][] A, long[][] B)
    {
        var ans = new long[A.Length][];
        for (int i = 0; i < A.Length; i++)
        {
            ans[i] = new long[B[0].Length];
            for (int j = 0; j < B[0].Length; j++) for (int k = 0; k < B.Length; k++) ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % Mod;
        }
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