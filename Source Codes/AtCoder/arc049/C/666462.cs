using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

class Program
{
    const int M = 1000000007;
    const double eps = 1e-9;
    static int[] dd = { 0, 1, 0, -1, 0 };
    static void Main()
    {
        var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        var sc = new Scan();
        int n = sc.Int;
        int a = sc.Int;
        var x = new int[a][];
        var edge = new int[n][];
        var inedge = new int[n];
        for (int i = 0; i < n; i++)
        {
            edge[i] = new int[n];
        }
        for (int i = 0; i < a; i++)
        {
            x[i] = sc.IntArr.Select(t => t - 1).ToArray();
            if (edge[x[i][1]][x[i][0]] == 0)
                ++inedge[x[i][0]];
                
            edge[x[i][1]][x[i][0]] = 1;
        }
        int b = sc.Int;
        var u = new int[b][];
        for (int i = 0; i < b; i++)
            u[i] = sc.IntArr.Select(t => t - 1).ToArray();
        
        var inedt = copy(inedge);
        int ans = 0;
        for (int i = 0; i < (1 << b); i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (((i >> j) & 1) == 0)
                {
                    ++edge[u[j][0]][u[j][1]];
                    if (edge[u[j][0]][u[j][1]] == 1)
                        ++inedge[u[j][1]];
                }
                else
                {
                    inedge[u[j][0]] += 1000;
                }
            }
            var del = new bool[n];
            int delc = 0;
            bool changed = true;
            while (changed)
            {
                changed = false;
                for (int j = 0; j < n; j++)
                {
                    if (inedge[j] == 0 && !del[j])
                    {
                        changed = true;
                        ++delc;
                        del[j] = true;
                        for (int k = 0; k < n; k++)
                            if (edge[j][k] > 0)
                                --inedge[k];
                    }
                }
            }
            ans = Math.Max(ans, delc);
            for (int j = 0; j < b; j++)
            {
                if (((i >> j) & 1) == 0)
                {
                    --edge[u[j][0]][u[j][1]];
                }
            }
            inedge = copy(inedt);
        }
        sw.WriteLine(ans);
        sw.Flush();
    }
    
    static void swap<T>(ref T a, ref T b) { var t = a; a = b; b = t; }

    static T[] copy<T>(T[] a)
    {
        var ret = new T[a.Length];
        for (int i = 0; i < a.Length; i++) ret[i] = a[i];
        return ret;
    }
    static T[][] copy2<T>(T[][] a)
    {
        var ret = new T[a.Length][];
        for (int i = 0; i < a.Length; i++)
        {
            ret[i] = new T[a[0].Length];
            for (int j = 0; j < a[0].Length; j++) ret[i][j] = a[i][j];
        }
        return ret;
    }
}
class Scan
{
    public int Int { get { return int.Parse(Console.ReadLine().Trim()); } }
    public long Long { get { return long.Parse(Console.ReadLine().Trim()); } }
    public string Str { get { return Console.ReadLine().Trim(); } }
    public int[] IntArr { get { return Console.ReadLine().Trim().Split().Select(int.Parse).ToArray(); } }
    public int[] IntArrWithSep(char sep) { return Console.ReadLine().Trim().Split(sep).Select(int.Parse).ToArray(); }
    public long[] LongArr { get { return Console.ReadLine().Trim().Split().Select(long.Parse).ToArray(); } }
    public double[] DoubleArr { get { return Console.ReadLine().Split().Select(double.Parse).ToArray(); } }
    public string[] StrArr { get { return Console.ReadLine().Trim().Split(); } }
    public void Multi(out int a, out int b) { var arr = IntArr; a = arr[0]; b = arr[1]; }
    public void Multi(out int a, out int b, out int c) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; }
    public void Multi(out int a, out int b, out int c, out int d) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; }
    public void Multi(out int a, out string b) { var arr = StrArr; a = int.Parse(arr[0]); b = arr[1]; }
    public void Multi(out string a, out int b) { var arr = StrArr; a = arr[0]; b = int.Parse(arr[1]); }
    public void Multi(out int a, out int b, out string c) { var arr = StrArr; a = int.Parse(arr[0]); b = int.Parse(arr[1]); c = arr[2]; }
    public void Multi(out int a, out char b) { var arr = StrArr; a = int.Parse(arr[0]); b = arr[1][0]; }
    public void Multi(out char a, out int b) { var arr = StrArr; a = arr[0][0]; b = int.Parse(arr[1]); }
    public void Multi(out long a, out long b) { var arr = LongArr; a = arr[0]; b = arr[1]; }
    public void Multi(out long a, out int b) { var arr = LongArr; a = arr[0]; b = (int)arr[1]; }
    public void Multi(out int a, out long b) { var arr = LongArr; a = (int)arr[0]; b = arr[1]; }
    public void Multi(out string a, out string b) { var arr = StrArr; a = arr[0]; b = arr[1]; }
}
class mymath
{
    public bool isprime(long a)
    {
        if (a < 2) return false;
        for (long i = 2; i * i <= a; i++) if (a % i == 0) return false;
        return true;
    }

    public long[][] powmat(long[][] A, int n, int M)
    {
        var E = new long[A.Length][];
        for (int i = 0; i < A.Length; i++)
        {
            E[i] = new long[A.Length];
            E[i][i] = 1;
        }
        if (n == 0) return E;

        var t = powmat(A, n / 2, M);
        if ((n & 1) == 0) return mulmat(t, t, M);
        return mulmat(mulmat(t, t, M), A, M);
    }
    public long[] mulmat(long[][] A, long[] x, int M)
    {
        var ans = new long[A.Length];
        for (int i = 0; i < A.Length; i++) for (int j = 0; j < x.Length; j++) ans[i] = (ans[i] + x[j] * A[i][j]) % M;
        return ans;
    }
    public long[][] mulmat(long[][] A, long[][] B, int M)
    {
        var ans = new long[A.Length][];
        for (int i = 0; i < A.Length; i++)
        {
            ans[i] = new long[B[0].Length];
            for (int j = 0; j < B[0].Length; j++) for (int k = 0; k < B.Length; k++) ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % M;
        }
        return ans;
    }

    public long powmod(long a, long b, long M)
    {
        if (a == 0) return 0;
        if (b == 0) return 1;

        var t = powmod(a, b / 2, M);
        if ((b & 1) == 0) return t * t % M;
        return t * t % M * a % M;
    }

    public long gcd(long a, long b)
    {
        while (b > 0) { var t = a % b; a = b; b = t; }
        return a;
    }
    public long lcm(int a, int b) { return a * (long)b / gcd(a, b); }

    public long Comb(int n, int r)
    {
        const int M = 1000000007;
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
        for (int k = 0; k < r; k++) if (numerator[k] > 1) result = result * numerator[k] % M;

        return result;
    }
}