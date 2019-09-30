using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

using static util;
using P = pair<int, int>;

using Binary = System.Func<System.Linq.Expressions.ParameterExpression, System.Linq.Expressions.ParameterExpression,
                           System.Linq.Expressions.BinaryExpression>;
using Unary = System.Func<System.Linq.Expressions.ParameterExpression, System.Linq.Expressions.UnaryExpression>;

class Program
{
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    static Scan sc = new Scan();
    const int M = 1000000007;
    // const int M = 998244353;
    const long LM = (long)1e18;
    const double eps = 1e-11;
    static readonly int[] dd = { 0, 1, 0, -1, 0 };
    static void Main(string[] args)
    {
        int n, m, s, t;
        sc.Multi(out n, out m);
        sc.Multi(out s, out t);
        --s;
        --t;
        var edge = new List<pair<long, int>>[n];
        for (int i = 0; i < n; i++)
        {
            edge[i] = new List<pair<long, int>>();
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            long d;
            sc.Multi(out a, out b, out d);
            --a;
            --b;
            edge[a].Add(make_pair(d, b));
            edge[b].Add(make_pair(d, a));
        }
        var sp = new ShortestPath<long>(LM);
        long[] cs, ct;
        var ds = sp.Dijkstra(edge, s, out cs, M);
        var dt = sp.Dijkstra(edge, t, out ct, M);
        long l = ds[t];
        long ans = cs[t] * cs[t] % M;
        if (l % 2 == 0) {
            for (int i = 0; i < n; i++)
            {
                if (ds[i] == l / 2 && dt[i] == l / 2) {
                    ans = ((ans - cs[i] * cs[i] % M * ct[i] % M * ct[i]) % M + M) % M;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            foreach (var item in edge[i])
            {
                int j = item.v2;
                if (ds[i] + dt[i] == l && ds[j] + dt[j] == l && ds[i] + item.v1 == ds[j] && ds[i] * 2 < l && ds[j] * 2 > l) {
                    ans = ((ans - cs[i] * cs[i] % M * ct[j] % M * ct[j]) % M + M) % M;
                }
            }
        }
        Prt(ans);
        sw.Flush();
    }

    static void DBG(string a) => Console.WriteLine(a);
    static void DBG<T>(IEnumerable<T> a) => DBG(string.Join(" ", a));
    static void DBG(params object[] a) => DBG(string.Join(" ", a));
    static void Prt(string a) => sw.WriteLine(a);
    static void Prt<T>(IEnumerable<T> a) => Prt(string.Join(" ", a));
    static void Prt(params object[] a) => Prt(string.Join(" ", a));
}
class pair<T, U> : IComparable<pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T v1;
    public U v2;
    public pair(T v1, U v2) {
        this.v1 = v1;
        this.v2 = v2;
    }
    public int CompareTo(pair<T, U> a) => v1.CompareTo(a.v1) != 0 ? v1.CompareTo(a.v1) : v2.CompareTo(a.v2);
    public override string ToString() => v1 + " " + v2;
}
static class util
{
    public static pair<T, T> make_pair<T>(this IList<T> l) where T : IComparable<T> => make_pair(l[0], l[1]);
    public static pair<T, U> make_pair<T, U>(T v1, U v2) where T : IComparable<T> where U : IComparable<U> => new pair<T, U>(v1, v2);
    public static T sqr<T>(T a) => Operator<T>.Multiply(a, a);
    public static T Max<T>(params T[] a) => a.Max();
    public static T Min<T>(params T[] a) => a.Min();
    public static void swap<T>(ref T a, ref T b) { var t = a; a = b; b = t; }
    public static void swap<T>(this IList<T> a, int i, int j) { var t = a[i]; a[i] = a[j]; a[j] = t; }
    public static T[] copy<T>(this IList<T> a) {
        var ret = new T[a.Count];
        for (int i = 0; i < a.Count; i++) ret[i] = a[i];
        return ret;
    }
}
static class Operator<T>
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

class Scan
{
    public int Int => int.Parse(Str);
    public long Long => long.Parse(Str);
    public double Double => double.Parse(Str);
    public string Str => Console.ReadLine().Trim();
    public pair<T, U> Pair<T, U>() where T : IComparable<T> where U : IComparable<U>
    { T a; U b; Multi(out a, out b); return make_pair(a, b); }
    public int[] IntArr => StrArr.Select(int.Parse).ToArray();
    public long[] LongArr => StrArr.Select(long.Parse).ToArray();
    public double[] DoubleArr => StrArr.Select(double.Parse).ToArray();
    public string[] StrArr => Str.Split(new []{' '}, System.StringSplitOptions.RemoveEmptyEntries);
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
    public void Multi<T, U, V, W, X, Y>(out T a, out U b, out V c, out W d, out X e, out Y f)
    { var ar = StrArr; a = cv<T>(ar[0]); b = cv<U>(ar[1]); c = cv<V>(ar[2]); d = cv<W>(ar[3]); e = cv<X>(ar[4]); f = cv<Y>(ar[5]); }
}
static class mymath
{
    public static long Mod = 1000000007;
    public static bool isprime(long a) {
        if (a < 2) return false;
        for (long i = 2; i * i <= a; i++) if (a % i == 0) return false;
        return true;
    }
    public static bool[] sieve(int n) {
        var p = new bool[n + 1];
        for (int i = 2; i <= n; i++) p[i] = true;
        for (int i = 2; i * i <= n; i++) if (p[i]) for (int j = i * i; j <= n; j += i) p[j] = false;
        return p;
    }
    public static List<int> getprimes(int n) {
        var prs = new List<int>();
        var p = sieve(n);
        for (int i = 2; i <= n; i++) if (p[i]) prs.Add(i);
        return prs;
    }
    public static long[][] E(int n) {
        var ret = new long[n][];
        for (int i = 0; i < n; i++) { ret[i] = new long[n]; ret[i][i] = 1; }
        return ret;
    }
    public static double[][] dE(int n) {
        var ret = new double[n][];
        for (int i = 0; i < n; i++) { ret[i] = new double[n]; ret[i][i] = 1; }
        return ret;
    }
    public static long[][] pow(long[][] A, long n) {
        if (n == 0) return E(A.Length);
        var t = pow(A, n / 2);
        if ((n & 1) == 0) return mul(t, t);
        return mul(mul(t, t), A);
    }
    public static double[][] pow(double[][] A, long n) {
        if (n == 0) return dE(A.Length);
        var t = pow(A, n / 2);
        if ((n & 1) == 0) return mul(t, t);
        return mul(mul(t, t), A);
    }
    public static double dot(double[] x, double[] y) {
        int n = x.Length;
        double ret = 0;
        for (int i = 0; i < n; i++) ret += x[i] * y[i];
        return ret;
    }
    public static double _dot(double[] x, double[] y) {
        int n = x.Length;
        double ret = 0, r = 0;
        for (int i = 0; i < n; i++) {
            double s = ret + (x[i] * y[i] + r);
            r = (x[i] * y[i] + r) - (s - ret);
            ret = s;
        }
        return ret;
    }
    public static long dot(long[] x, long[] y) {
        int n = x.Length;
        long ret = 0;
        for (int i = 0; i < n; i++) ret = (ret + x[i] * y[i]) % Mod;
        return ret;
    }
    public static T[][] trans<T>(T[][] A) {
        int n = A[0].Length, m = A.Length;
        var ret = new T[n][];
        for (int i = 0; i < n; i++) { ret[i] = new T[m]; for (int j = 0; j < m; j++) ret[i][j] = A[j][i]; }
        return ret;
    }
    public static double[] mul(double a, double[] x) {
        int n = x.Length;
        var ret = new double[n];
        for (int i = 0; i < n; i++) ret[i] = a * x[i];
        return ret;
    }
    public static long[] mul(long a, long[] x) {
        int n = x.Length;
        var ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = a * x[i] % Mod;
        return ret;
    }
    public static double[] mul(double[][] A, double[] x) {
        int n = A.Length;
        var ret = new double[n];
        for (int i = 0; i < n; i++) ret[i] = dot(x, A[i]);
        return ret;
    }
    public static long[] mul(long[][] A, long[] x) {
        int n = A.Length;
        var ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = dot(x, A[i]);
        return ret;
    }
    public static double[][] mul(double a, double[][] A) {
        int n = A.Length;
        var ret = new double[n][];
        for (int i = 0; i < n; i++) ret[i] = mul(a, A[i]);
        return ret;
    }
    public static long[][] mul(long a, long[][] A) {
        int n = A.Length;
        var ret = new long[n][];
        for (int i = 0; i < n; i++) ret[i] = mul(a, A[i]);
        return ret;
    }
    public static double[][] mul(double[][] A, double[][] B) {
        int n = A.Length;
        var Bt = trans(B);
        var ret = new double[n][];
        for (int i = 0; i < n; i++) ret[i] = mul(Bt, A[i]);
        return ret;
    }
    public static long[][] mul(long[][] A, long[][] B) {
        int n = A.Length;
        var Bt = trans(B);
        var ret = new long[n][];
        for (int i = 0; i < n; i++) ret[i] = mul(Bt, A[i]);
        return ret;
    }
    public static long[] add(long[] x, long[] y) {
        int n = x.Length;
        var ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = (x[i] + y[i]) % Mod;
        return ret;
    }
    public static long[][] add(long[][] A, long[][] B) {
        int n = A.Length;
        var ret = new long[n][];
        for (int i = 0; i < n; i++) ret[i] = add(A[i], B[i]);
        return ret;
    }
    public static long pow(long a, long b) {
        if (a >= Mod) return pow(a % Mod, b);
        if (a == 0) return 0;
        if (b == 0) return 1;
        var t = pow(a, b / 2);
        if ((b & 1) == 0) return t * t % Mod;
        return t * t % Mod * a % Mod;
    }
    public static long inv(long a) => pow(a, Mod - 2);
    public static long gcd(long a, long b) {
        while (b > 0) { var t = a % b; a = b; b = t; } return a;
    }
    // a x + b y = gcd(a, b)
    public static long extgcd(long a, long b, out long x, out long y) {
        long g = a; x = 1; y = 0;
        if (b > 0) { g = extgcd(b, a % b, out y, out x); y -= a / b * x; }
        return g;
    }
    public static long lcm(long a, long b) => a / gcd(a, b) * b;

    static long[] facts;
    public static long[] setfacts(int n) {
        facts = new long[n + 1];
        facts[0] = 1;
        for (int i = 0; i < n; i++) facts[i + 1] = facts[i] * (i + 1) % Mod;
        return facts;
    }
    public static long comb(int n, int r) {
        if (n < 0 || r < 0 || r > n) return 0;
        if (n - r < r) r = n - r;
        if (r == 0) return 1;
        if (r == 1) return n;
        if (facts != null && facts.Length > n) return facts[n] * inv(facts[r]) % Mod * inv(facts[n - r]) % Mod;
        int[] numer = new int[r], denom = new int[r];
        for (int k = 0; k < r; k++) { numer[k] = n - r + k + 1; denom[k] = k + 1; }
        for (int p = 2; p <= r; p++) {
            int piv = denom[p - 1];
            if (piv > 1) {
                int ofst = (n - r) % p;
                for (int k = p - 1; k < r; k += p) { numer[k - ofst] /= piv; denom[k] /= piv; }
            }
        }
        long ret = 1;
        for (int k = 0; k < r; k++) if (numer[k] > 1) ret = ret * numer[k] % Mod;
        return ret;
    }
    public static long[][] getcombs(int n) {
        var ret = new long[n + 1][];
        for (int i = 0; i <= n; i++) {
            ret[i] = new long[i + 1];
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; j++) ret[i][j] = (ret[i - 1][j - 1] + ret[i - 1][j]) % Mod;
        }
        return ret;
    }
    // nC0, nC2, ..., nCn
    public static long[] getcomb(int n) {
        var ret = new long[n + 1];
        ret[0] = 1;
        for (int i = 0; i < n; i++) ret[i + 1] = ret[i] * (n - i) % Mod * inv(i + 1) % Mod;
        return ret;
    }
}

class ShortestPath<T> where T : struct, IComparable<T>
{
    T Inf;
    public ShortestPath(T inf) { Inf = inf; }
    T min(T a, T b) => a.CompareTo(b) > 0 ? b : a;
    T Add(T a, T b) => Operator<T>.Add(a, b);
    public T[][] WarshallFloyd(T[][] g)
    {
        var d = Copy(g);
        int n = d.Length;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) d[j][k] = min(d[j][k], Add(d[j][i], d[i][k]));
        return d;
    }
    T[][] Copy(T[][] g)
    {
        int n = g.Length;
        var ret = new T[n][];
        for (int i = 0; i < n; ++i)
        {
            ret[i] = new T[n];
            for (int j = 0; j < n; ++j)
            {
                if (i != j && g[i][j].Equals(default(T))) ret[i][j] = Inf;
                else ret[i][j] = g[i][j];
            }
        }
        return ret;
    }

    public T[] Dijkstra(List<pair<T, int>>[] edges, int s)
    {
        int n = edges.Length;
        var dist = new T[n];
        var q = new PriorityQueue<pair<T, int>>(){ rev = true };
        for (int i = 0; i < n; ++i) dist[i] = Inf;
        dist[s] = default(T);
        q.Push(make_pair(dist[s], s));
        while (q.Count > 0) {
            var p = q.Pop();
            if (dist[p.v2].CompareTo(p.v1) < 0) continue;
            foreach (var e in edges[p.v2]) {
                T d = Add(p.v1, e.v1);
                if (dist[e.v2].CompareTo(d) > 0) {
                    dist[e.v2] = d;
                    q.Push(make_pair(d, e.v2));
                }
            }
        }
        return dist;
    }
    public T[] Dijkstra(List<pair<T, int>>[] edges, int s, out long[] cnt, long Mod)
    {
        int n = edges.Length;
        var dist = new T[n];
        var q = new PriorityQueue<pair<T, int>>(){ rev = true };
        for (int i = 0; i < n; ++i) dist[i] = Inf;
        dist[s] = default(T);
        q.Push(make_pair(dist[s], s));
        cnt = new long[n];
        cnt[s] = 1;
        while (q.Count > 0) {
            var p = q.Pop();
            if (dist[p.v2].CompareTo(p.v1) < 0) continue;
            foreach (var e in edges[p.v2]) {
                T d = Add(p.v1, e.v1);
                if (dist[e.v2].CompareTo(d) > 0) {
                    dist[e.v2] = d;
                    cnt[e.v2] = cnt[p.v2];
                    q.Push(make_pair(d, e.v2));
                }
                else if (dist[e.v2].CompareTo(d) == 0) {
                    cnt[e.v2] = (cnt[e.v2] + cnt[p.v2]) % Mod;
                }
            }
        }
        return dist;
    }
}

// the greatest element pops
class PriorityQueue<T> where T : IComparable<T> {
    List<T> buf;
    public bool rev = false;
    public PriorityQueue() { buf = new List<T>(); }
    int cmp(int i, int j) => buf[i].CompareTo(buf[j]) * (rev ? -1 : 1);
    void swap(int i, int j) { var t = buf[i]; buf[i] = buf[j]; buf[j] = t; }
    public void Push(T elem) {
        int n = buf.Count;
        buf.Add(elem);
        while (n > 0) {
            int i = (n - 1) >> 1;
            if (cmp(n, i) > 0) swap(i, n);
            n = i;
        }
    }
    public T Pop() {
        T ret = buf[0];
        int n = buf.Count - 1;
        buf[0] = buf[n];
        buf.RemoveAt(n);
        for (int i = 0, j; (j = (i << 1) + 1) < n; i = j) {
            if (j != n - 1 && cmp(j, j + 1) < 0) ++j;
            if (cmp(i, j) < 0) swap(i, j);
        }
        return ret;
    }
    public T Top => buf[0];
    public int Count => buf.Count;
}