using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using static System.Console;
using static System.Convert;
using static System.Math;
using static Extentions;

class IO
{
    int idx;
    string[] input = In.ReadToEnd().Split(new[] { " ", "\n", "\r" },
        StringSplitOptions.RemoveEmptyEntries);

    T Get<T>(Func<string, T> parser) => parser(input[idx++]);

    public string S => Get(s => s);
    public char C => Get(char.Parse);
    public int I => Get(int.Parse);
    public long L => Get(long.Parse);
    public double F => Get(double.Parse);
    public decimal D => Get(decimal.Parse);
    public BigInteger B => Get(BigInteger.Parse);

    T[] Gets<T>(int n, Func<string, T> parser)
        => input.Skip((idx += n) - n).Take(n).Select(parser).ToArray();

    public string[] Ss(int n) => Gets(n, s => s);
    public char[] Cs(int n) => Gets(n, char.Parse);
    public int[] Is(int n) => Gets(n, int.Parse);
    public long[] Ls(int n) => Gets(n, long.Parse);
    public double[] Fs(int n) => Gets(n, double.Parse);
    public decimal[] Ds(int n) => Gets(n, decimal.Parse);
    public BigInteger[] Bs(int n) => Gets(n, BigInteger.Parse);

    public void Write<T>(params T[] xs) => WriteLine(string.Join(" ", xs));
    public void Write(params object[] xs) => WriteLine(string.Join(" ", xs));
}

#region Library

class Monoid<T>
{
    public T Unit { get; private set; }
    Func<T, T, T> append;
    public T Append(T left, T right) => append(left, right);

    public Monoid(T unit, Func<T, T, T> append)
    {
        this.Unit = unit;
        this.append = append;
    }
}

abstract class Graph<T> where T : IEquatable<T>
{
    public abstract T this[int source, int target] { get; set; }

    public int V { get; protected set; }
    public Monoid<T> Monoid { get; protected set; }
    public Monoid<T> Comparer { get; protected set; }

    public event Action GraphChanged;
    protected void OnGraphChanged() => GraphChanged?.Invoke();

    public bool HasEdge(int source, int target)
        => !this[source, target].Equals(this.Comparer.Unit);
}

class AdjacencyMatrix<T> : Graph<T> where T : IEquatable<T>
{
    protected readonly T[,] graph;

    public override T this[int source, int target]
    {
        // O(1)
        get { return graph[source, target]; }

        // O(1)
        set
        {
            var a = this.Comparer.Append(graph[source, target], value);
            if (a.Equals(graph[source, target])) return;
            graph[source, target] = a;
            OnGraphChanged();
        }
    }

    // O(V^2)
    public AdjacencyMatrix(int v, Monoid<T> monoid, Monoid<T> comparer)
    {
        this.V = v;
        this.Monoid = monoid;
        this.Comparer = comparer;
        graph = new T[v, v];
        for (var i = 0; i < v; i++)
            for (var j = 0; j < v; j++)
                graph[i, j] = i == j ? monoid.Unit : comparer.Unit;
    }
}

class WarshallFloyd<T> where T : IEquatable<T>
{
    AdjacencyMatrix<T> graph;
    T[,] d;
    bool calculated = false;

    // O(1)
    public WarshallFloyd(AdjacencyMatrix<T> graph)
    {
        this.graph = graph;
        d = new T[graph.V, graph.V];
        graph.GraphChanged += () => calculated = false;
    }

    // O(V^3)
    public void Calculate()
    {
        if (calculated) return;

        for (var i = 0; i < graph.V; i++)
            for (var j = 0; j < graph.V; j++) d[i, j] = graph[i, j];

        for (var k = 0; k < graph.V; k++)
            for (var i = 0; i < graph.V; i++)
                for (var j = 0; j < graph.V; j++)
                    d[i, j] = graph.Comparer.Append(d[i, j],
                        d[i, k].Equals(graph.Comparer.Unit)
                        || d[k, j].Equals(graph.Comparer.Unit)
                        ? graph.Comparer.Unit
                        : graph.Monoid.Append(d[i, k], d[k, j]));

        calculated = true;
    }

    // O(1)
    public T GetMinCost(int source, int target)
    {
        if (!calculated) throw new InvalidOperationException();
        return d[source, target];
    }
}

class UnionFind
{
    int[] tree;

    // O(N)
    public int CountGroups => tree.Count(x => x < 0);

    // O(N)
    public UnionFind(int length)
    {
        tree = Enumerable.Repeat(-1, length).ToArray();
    }

    // O(?(N))
    public bool Union(int x, int y)
    {
        x = this.Find(x);
        y = this.Find(y);
        if (x == y) return false;
        if (tree[x] > tree[y]) Swap(ref x, ref y);
        tree[x] += tree[y];
        tree[y] = x;
        return true;
    }

    // O(?(N))
    public int Find(int x)
    {
        if (tree[x] < 0) return x;
        return tree[x] = this.Find(tree[x]);
    }

    // O(?(N))
    public bool Same(int x, int y) => this.Find(x) == this.Find(y);

    // O(?(N))
    public int Count(int x) => -tree[this.Find(x)];
}

static class Extentions
{
    public static long Sum(long left, long right) => left + right;

    public static void Swap<T>(ref T x, ref T y)
    {
        var tmp = x;
        x = y;
        y = tmp;
    }
}

#endregion

static class Program
{
    public static void Main()
    {
        var sw = new StreamWriter(OpenStandardOutput()) { NewLine = "\n" };
#if DEBUG
        sw.AutoFlush = true;
#else
        sw.AutoFlush = false;
#endif
        SetOut(sw);
        Solve(new IO());
        Out.Flush();
    }

    static void Solve(IO io)
    {
        var n = io.I;
        var a = new long[n, n];

        var gr = new AdjacencyMatrix<long>(n,
            new Monoid<long>(0, Sum), new Monoid<long>(long.MaxValue, Min));

        for (var i = 0; i < n; i++)
            for (var j = 0; j < n; j++) gr[i, j] = a[i, j] = io.L;

        var wf = new WarshallFloyd<long>(gr);
        wf.Calculate();

        var sum = 0L;

        for (var i = 0; i < n; i++)
            for (var j = 0; j < n; j++) sum += wf.GetMinCost(i, j);

        if (a.Cast<long>().Sum() != sum)
        {
            io.Write(-1);
            return;
        }


        var ans = 0L;

        for (var i = 0; i < n; i++)
        {
            for (var j = 0; j < n; j++)
            {
                var flg = true;

                for (var k = 0; k < n; k++)
                {
                    if (i == j || i == k || j == k) continue;

                    if (a[i, j] >= a[i, k] + a[k, j])
                    {
                        flg = false;
                        break;
                    }
                    //                    Error.WriteLine($"{i} {j} {k} {a[i, j]} {a[i, k]} {a[k, j]} {(a[i, j] < a[i, k] + a[k, j] ? '!' : ' ')}");
                }

                if (flg) ans += a[i, j];
            }
        }

        io.Write(ans >> 1);
    }
}