using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;

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
        int n, m, s;
        sc.Multi(out n, out m, out s);
        --s;
        var edge = new List<int>[n];
        for (int i = 0; i < n; i++)
        {
            edge[i] = new List<int>();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            sc.Multi(out u, out v);
            edge[u - 1].Add(i);
            edge[v - 1].Add(i);
        }
        var uf = new UnionFind(n + m);
        var ans = new List<int>();
        for (int i = n - 1; i >= 0 ; i--)
        {
            foreach (var item in edge[i])
            {
                uf.unite(i, item + n);
            }
            if (uf.same(i, s)) {
                ans.Add(i + 1);
            }
        }
        ans.Reverse();
        Prt(string.Join("\n", ans));
        sw.Flush();
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
class UnionFind
{
    int num;
    int[] par, sz, rank;
    public UnionFind(int n) {
        num = n; par = new int[n]; sz = new int[n]; rank = new int[n];
        for (int i = 0; i < n; ++i) { par[i] = i; sz[i] = 1; rank[i] = 0; }
    }
    int find(int x) => par[x] == x ? x : (par[x] = find(par[x]));
    public bool same(int x, int y) => find(x) == find(y);
    public int unionsize(int x) => sz[find(x)];
    public int unioncount => num;
    public bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        --num;
        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        }
        else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) ++rank[x];
        }
        return true;
    }
    public bool ispar(int x) => x == find(x);
    public int getpar(int x) => find(x);
}