using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;

using Binary = System.Func<System.Linq.Expressions.ParameterExpression, System.Linq.Expressions.ParameterExpression, System.Linq.Expressions.BinaryExpression>;
using Unary = System.Func<System.Linq.Expressions.ParameterExpression, System.Linq.Expressions.UnaryExpression>;

class Program
{
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    const int M = 1000000007;
    const double eps = 1e-9;
    static int[] dd = { 0, 1, 0, -1, 0 };
    static void Main()
    {
        int n = sc.Int;
        var edge = new List<int>[n];
        var num = new int[n];
        for (int i = 0; i < n; i++)
        {
            edge[i] = new List<int>();
            num[i] = -1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            var a = sc.IntArr;
            edge[a[0] - 1].Add(a[1] - 1);
            edge[a[1] - 1].Add(a[0] - 1);
        }
        int k = sc.Int;
        var lis = new List<int>[2000000];
        for (int i = 0; i < lis.Length; i++)
        {
            lis[i] = new List<int>();
        }
        for (int i = 0; i < k; i++)
        {
            var a = sc.IntArr;
            num[a[0] - 1] = a[1];
            lis[a[1]].Add(a[0] - 1);
        }
        for (int i = 0; i < lis.Length; i++)
        {
            foreach (var item in lis[i])
            {
                foreach (var j in edge[item])
                {
                    if (num[j] == -1)
                    {
                        num[j] = i + 1;
                        lis[i + 1].Add(j);
                    }
                    else
                    {
                        if (num[j] != i + 1 && num[j] != i - 1)
                        {
                            DBG("No");
                            return;
                        }
                    }
                }
            }
        }
        sw.WriteLine("Yes");
        foreach (var item in num)
        {
            sw.WriteLine(item);
        }
        sw.Flush();
    }
    static void swap<T>(ref T a, ref T b) { var t = a; a = b; b = t; }
    static T Max<T>(params T[] a) => a.Max();
    static T Min<T>(params T[] a) => a.Min();
    static void DBG<T>(params T[] a) => Console.WriteLine(string.Join(" ", a));
    static void DBG(params object[] a) => Console.WriteLine(string.Join(" ", a));
    static void Prt<T>(params T[] a) => sw.WriteLine(string.Join(" ", a));
    static void Prt(params object[] a) => sw.WriteLine(string.Join(" ", a));
}
class Score : IComparable
{
    int score, time;
    public int CompareTo(object obj)
    {
        var x = obj as Score;
        return this.score == x.score ? x.time.CompareTo(this.time) : this.score.CompareTo(x.score);
    }
}
static class ex
{
    public static void swap<T>(this IList<T> a, int i, int j) { var t = a[i]; a[i] = a[j]; a[j] = t; }
    public static T[] copy<T>(this IList<T> a)
    {
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
        return ret;
    }
}
public static class Operator<T>
{
    static readonly ParameterExpression x = Expression.Parameter(typeof(T), "x");
    static readonly ParameterExpression y = Expression.Parameter(typeof(T), "y");
    public static readonly Func<T, T, T> Add = Lambda(Expression.Add);
    public static readonly Func<T, T, T> Subtract = Lambda(Expression.Subtract);
    public static readonly Func<T, T, T> Multiply = Lambda(Expression.Multiply);
    public static readonly Func<T, T, T> Divide = Lambda(Expression.Divide);
    public static readonly Func<T, T> Plus = Lambda(Expression.UnaryPlus);
    public static readonly Func<T, T> Negate = Lambda(Expression.Negate);
    public static Func<T, T, T> Lambda(Binary op) => Expression.Lambda<Func<T, T, T>>(op(x, y), x, y).Compile();
    public static Func<T, T> Lambda(Unary op) => Expression.Lambda<Func<T, T>>(op(x), x).Compile();
}

class scanCHK : sc
{
    public static new string Str { get { var s = Console.ReadLine(); return s == s.Trim() ? s : ""; } }
}
class sc
{
    public static int Int => int.Parse(Str);
    public static long Long => long.Parse(Str);
    public static double Double => double.Parse(Str);
    public static string Str => Console.ReadLine().Trim();
    public static int[] IntArr => StrArr.Select(int.Parse).ToArray();
    public static long[] LongArr => StrArr.Select(long.Parse).ToArray();
    public static double[] DoubleArr => StrArr.Select(double.Parse).ToArray();
    public static string[] StrArr => Str.Split();
    static bool eq<T, U>() => typeof(T).Equals(typeof(U));
    static T ct<T, U>(U inp) => (T)Convert.ChangeType(inp, typeof(T));
    static T cv<T>(string inp) => eq<T, int>() ? ct<T, int>(int.Parse(inp))
                         : eq<T, long>() ? ct<T, long>(long.Parse(inp))
                         : eq<T, double>() ? ct<T, double>(double.Parse(inp))
                         : eq<T, char>() ? ct<T, char>(inp[0])
                         : ct<T, string>(inp);
    public static void Multi<T>(out T a) => a = cv<T>(Str);
    public static void Multi<T, U>(out T a, out U b)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); }
    public static void Multi<T, U, V>(out T a, out U b, out V c)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); }
    public static void Multi<T, U, V, W>(out T a, out U b, out V c, out W d)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); }
    public static void Multi<T, U, V, W, X>(out T a, out U b, out V c, out W d, out X e)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]); }
}
struct ModInt
{
    public static long Mod = 1000000007;
    long val;
    public ModInt(long v) { val = (v % Mod + Mod) % Mod; }

    public static implicit operator ModInt(long x) => new ModInt(x);
    public static explicit operator long(ModInt x) => x.val;

    public static ModInt operator+(ModInt x, ModInt y) => x.val + y.val;
    public static ModInt operator-(ModInt x, ModInt y) => x.val - y.val;
    public static ModInt operator*(ModInt x, ModInt y) => x.val * y.val;
    // must : gcd(y, Mod) == 1
    public static ModInt operator/(ModInt x, ModInt y) => x * ~y;
    // powmod(x, y, Mod);
    public static ModInt operator^(ModInt x, long y)
    {
        if (x.val == 0) return x;
        if (y == 0) return 1;
        var t = x ^ (y / 2);
        if ((y & 1) == 0) return t * t;
        return t * t * x;
    }

    public static ModInt operator-(ModInt x) => -(x.val);
    // inv(x) : x * inv(x) == 1
    // must : gcd(x, Mod) == 1
    public static ModInt operator~(ModInt x) => x ^ (Mod - 2);

    public override string ToString() => this.val.ToString();

    // public static bool operator==(ModInt x, ModInt y) => x.val == y.val;
    // public static bool operator!=(ModInt x, ModInt y) => x.val != y.val;
    // public override bool Equals(object obj) => obj != null && this.GetType() == obj.GetType() && this.val == ((ModInt)obj).val;
    // public override int GetHashCode() => (int)this.val;

}
class mymath
{
    public static long Mod = 1000000007;
    public static bool isprime(long a)
    {
        if (a < 2) return false;
        for (long i = 2; i * i <= a; i++) if (a % i == 0) return false;
        return true;
    }
    public static bool[] sieve(int n)
    {
        var p = new bool[n + 1];
        for (int i = 2; i <= n; i++) p[i] = true;
        for (int i = 2; i * i <= n; i++) if (p[i]) for (int j = i * i; j <= n; j += i) p[j] = false;
        return p;
    }
    public static List<int> getprimes(int n)
    {
        var prs = new List<int>();
        var p = sieve(n);
        for (int i = 2; i <= n; i++) if (p[i]) prs.Add(i);
        return prs;
    }
    public static long[][] E(int n)
    {
        var ret = new long[n][];
        for (int i = 0; i < n; i++) { ret[i] = new long[n]; ret[i][i] = 1; }
        return ret;
    }
    public static long[][] pow(long[][] A, long n)
    {
        if (n == 0) return E(A.Length);
        var t = pow(A, n / 2);
        if ((n & 1) == 0) return mul(t, t);
        return mul(mul(t, t), A);
    }
    public static long dot(long[] x, long[] y)
    {
        int n = x.Length;
        long ret = 0;
        for (int i = 0; i < n; i++) ret = (ret + x[i] * y[i]) % Mod;
        return ret;
    }
    public static long[][] trans(long[][] A)
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
    public static long[] mul(long[][] A, long[] x)
    {
        int n = A.Length;
        var ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = dot(x, A[i]);
        return ret;
    }
    public static long[][] mul(long[][] A, long[][] B)
    {
        int n = A.Length;
        var Bt = trans(B);
        var ret = new long[n][];
        for (int i = 0; i < n; i++) ret[i] = mul(Bt, A[i]);
        return ret;
    }
    public static long[] add(long[] x, long[] y)
    {
        int n = x.Length;
        var ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = (x[i] + y[i]) % Mod;
        return ret;
    }
    public static long[][] add(long[][] A, long[][] B)
    {
        int n = A.Length;
        var ret = new long[n][];
        for (int i = 0; i < n; i++) ret[i] = add(A[i], B[i]);
        return ret;
    }
    public static long pow(long a, long b)
    {
        if (a >= Mod) return pow(a % Mod, b);
        if (a == 0) return 0;
        if (b == 0) return 1;
        var t = pow(a, b / 2);
        if ((b & 1) == 0) return t * t % Mod;
        return t * t % Mod * a % Mod;
    }
    public static long inv(long a) => pow(a, Mod - 2);
    public static long gcd(long a, long b)
    {
        while (b > 0) { var t = a % b; a = b; b = t; }
        return a;
    }
    // a x + b y = gcd(a, b)
    public static long extgcd(long a, long b, out long x, out long y)
    {
        long g = a;
        x = 1;
        y = 0;
        if (b != 0)
        {
            g = extgcd(b, a % b, out y, out x);
            y -= a / b * x;
        }
        return g;
    }
    public static long lcm(long a, long b) => a * (b / gcd(a, b));
    public static long comb(int n, int r)
    {
        if (n < 0 || r < 0 || r > n) return 0;
        if (n - r < r) r = n - r;
        if (r == 0) return 1;
        if (r == 1) return n;
        int[] numer = new int[r], denom = new int[r];
        for (int k = 0; k < r; k++) { numer[k] = n - r + k + 1; denom[k] = k + 1; }
        for (int p = 2; p <= r; p++)
        {
            int piv = denom[p - 1];
            if (piv > 1)
            {
                int ofst = (n - r) % p;
                for (int k = p - 1; k < r; k += p) { numer[k - ofst] /= piv; denom[k] /= piv; }
            }
        }
        long ret = 1;
        for (int k = 0; k < r; k++) if (numer[k] > 1) ret = ret * numer[k] % Mod;
        return ret;
    }
}