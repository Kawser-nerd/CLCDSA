using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

using static util;
using P = pair<int, int>;

using Binary = System.Func<System.Linq.Expressions.ParameterExpression,
                           System.Linq.Expressions.ParameterExpression,
                           System.Linq.Expressions.BinaryExpression>;
using Unary = System.Func<System.Linq.Expressions.ParameterExpression,
                          System.Linq.Expressions.UnaryExpression>;

class Program {
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    static Scan sc = new Scan();
    const int M = 1000000007;
    const int M2 = 998244353;
    const long LM = 1L << 60;
    const double eps = 1e-11;
    static readonly int[] dd = { 0, 1, 0, -1, 0 };
    const string dstring = "RDLU";
    static void Main(string[] args)
    {
        int n, k;
        sc.Multi(out n, out k);
        var p = sc.IntArr.Select(x => x - 1).ToArray();
        var q = sc.IntArr.Select(x => x - 1).ToArray();
        if (k == 1) {
            DBG(p.Select(x => x + 1));
            return;
        }
        if (k == 2) {
            DBG(q.Select(x => x + 1));
            return;
        }
        var a = new int[6][];
        a[0] = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[0][i] = i;
        }
        a[1] = inv(q);
        a[2] = mul(a[1], p);
        a[3] = mul(a[2], q);
        a[4] = mul(a[3], inv(p));
        a[5] = mul(a[4], q);
        int c = k - 2 - k / 3;
        var b = pow(a[4], c / 4);
        var ib = inv(b);
        b = mul(b, a[c % 4]);
        if (k % 3 == 0) {
            ib = mul(inv(a[c % 4 + 2]), ib);
        }
        else
            ib = mul(inv(a[c % 4 + 1]), ib);

        var ans = mul(b, ib);
        Prt(ans.Select(x => x + 1));

        if (false) {
            var A = new int[2][];
            A[0] = new int[] { 0, 1 };
            A[1] = new int[] { -1, 1 };
            var r = new int[][] { p, q };
            for (int i = 0; i < k - 2; i++)
            {
                r = mul1(A, r);
            }
            // var r = mul1(pow(A, k - 2), p);
            Prt(r[1]);
        }
        sw.Flush();
    }
    // 0: e, 1: x, -1: inv
    static int[] mul(int A, int[] x) {
        var ret = x.copy();
        for (int i = 0; i < ret.Length; i++)
        {
            if (A == 0) {
                ret[i] = i;
            }
            else if (A == 1) {
                ret[i] = x[i];
            }
            else if (A == -1) {
                ret[x[i]] = i;
            }
            else throw new Exception();
        }
        return ret;
    }
    static int[] inv(int[] x) {
        var ret = new int[x.Length];
        for (int i = 0; i < ret.Length; i++)
        {
            ret[x[i]] = i;
        }
        return ret;
    }
    static int[] mul(int[] x, int[] y) {
        var ret = x.copy();
        for (int i = 0; i < ret.Length; i++)
        {
            ret[i] = y[ret[i]];
        }
        return ret;
    }
    static int[][] mul1(int[][] A, int[][] x) {
        var ret = new int[2][];
        for (int i = 0; i < 2; i++)
        {
            ret[i] = mul(mul(A[i][0], x[0]), mul(A[i][1], x[1]));
        }
        return ret;
    }
    static int[][] mul2(int[][] A, int[][] B) {
        var ret = new int[2][];
        for (int i = 0; i < 2; i++)
        {
            ret[i] = new int[2];
            for (int j = 0; j < 2; j++)
            {
                ret[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
            }
        }
        return ret;
    }
    static int[][] pow(int[][] A, long k) {
        if (k == 1) {
            return A;
        }
        var t = pow(A, k / 2);
        t = mul2(t, t);
        if (k % 2 == 1) t = mul2(t, A);
        return t;
    }
    static int[] pow(int[] p, long k) {
        if (k == 0) {
            var ret = new int[p.Length];
            for (int i = 0; i < ret.Length; i++)
            {
                ret[i] = i;
            }
            return ret;
        }
        var t = pow(p, k / 2);
        t = mul(t, t);
        if (k % 2 == 1) t = mul(t, p);
        return t;
    }

    static void DBG(string a) => Console.WriteLine(a);
    static void DBG<T>(IEnumerable<T> a) => DBG(string.Join(" ", a));
    static void DBG(params object[] a) => DBG(string.Join(" ", a));
    static void Prt(string a) => sw.WriteLine(a);
    static void Prt<T>(IEnumerable<T> a) => Prt(string.Join(" ", a));
    static void Prt(params object[] a) => Prt(string.Join(" ", a));
}
class pair<T, U> : IComparable<pair<T, U>> {
    public T v1;
    public U v2;
    public pair() : this(default(T), default(U)) {}
    public pair(T v1, U v2) { this.v1 = v1; this.v2 = v2; }
    public int CompareTo(pair<T, U> a) {
        int c = Comparer<T>.Default.Compare(v1, a.v1);
        return c != 0 ? c : Comparer<U>.Default.Compare(v2, a.v2);
    }
    public override string ToString() => v1 + " " + v2;
    public void Deconstruct(out T a, out U b) { a = v1; b = v2; }
    public static bool operator>(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) > 0;
    public static bool operator<(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) < 0;
    public static bool operator>=(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) >= 0;
    public static bool operator<=(pair<T, U> a, pair<T, U> b) => a.CompareTo(b) <= 0;
}
static class util {
    public static pair<T, U> make_pair<T, U>(T v1, U v2) => new pair<T, U>(v1, v2);
    public static T sq<T>(T a) => Operator<T>.Multiply(a, a);
    public static T Max<T>(params T[] a) => a.Max();
    public static T Min<T>(params T[] a) => a.Min();
    public static bool inside(int i, int j, int h, int w) => i >= 0 && i < h && j >= 0 && j < w;
    public static Dictionary<T, int> compress<T>(this IEnumerable<T> a)
        => a.Distinct().OrderBy(v => v).Select((v, i) => new { v, i }).ToDictionary(p => p.v, p => p.i);
    public static Dictionary<T, int> compress<T>(params IEnumerable<T>[] a) => compress(a.Aggregate(Enumerable.Union));
    public static void swap<T>(ref T a, ref T b) where T : struct { var t = a; a = b; b = t; }
    public static void swap<T>(this IList<T> a, int i, int j) where T : struct { var t = a[i]; a[i] = a[j]; a[j] = t; }
    public static T[] copy<T>(this IList<T> a) {
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
        return ret;
    }
}
static class Operator<T> {
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

class Scan {
    StreamReader sr;
    public Scan() { sr = new StreamReader(Console.OpenStandardInput()); }
    public Scan(string path) { sr = new StreamReader(path); }
    public int Int => int.Parse(Str);
    public long Long => long.Parse(Str);
    public double Double => double.Parse(Str);
    public string Str => sr.ReadLine().Trim();
    public pair<T, U> Pair<T, U>() {
        T a; U b;
        Multi(out a, out b);
        return new pair<T, U>(a, b);
    }
    public P P => Pair<int, int>();
    public int[] IntArr => StrArr.Select(int.Parse).ToArray();
    public long[] LongArr => StrArr.Select(long.Parse).ToArray();
    public double[] DoubleArr => StrArr.Select(double.Parse).ToArray();
    public string[] StrArr => Str.Split(new[]{' '}, StringSplitOptions.RemoveEmptyEntries);
    bool eq<T, U>() => typeof(T).Equals(typeof(U));
    T ct<T, U>(U a) => (T)Convert.ChangeType(a, typeof(T));
    T cv<T>(string s) => eq<T, int>()    ? ct<T, int>(int.Parse(s))
                       : eq<T, long>()   ? ct<T, long>(long.Parse(s))
                       : eq<T, double>() ? ct<T, double>(double.Parse(s))
                       : eq<T, char>()   ? ct<T, char>(s[0])
                                         : ct<T, string>(s);
    public void Multi<T>(out T a) => a = cv<T>(Str);
    public void Multi<T, U>(out T a, out U b)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); }
    public void Multi<T, U, V>(out T a, out U b, out V c)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); }
    public void Multi<T, U, V, W>(out T a, out U b, out V c, out W d)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); }
    public void Multi<T, U, V, W, X>(out T a, out U b, out V c, out W d, out X e)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]); }
}