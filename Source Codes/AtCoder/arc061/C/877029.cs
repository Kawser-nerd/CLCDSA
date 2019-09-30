using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Numerics;

// (?°?°)??e??????????????????????????
public class Solver
{
    class Edge
    {
        public int to, weight;
        public Edge(int to, int weight)
        {
            this.to = to;
            this.weight = weight;
        }
    }

    public void Solve()
    {
        int n = ReadInt();
        
        var g = new List<List<Edge>>();
        var d = Init<Dictionary<int, int>>(n);
        for (int m = ReadInt(); m > 0; m--)
        {
            int u = ReadInt() - 1;
            int v = ReadInt() - 1;
            int c = ReadInt();

            if (!d[u].ContainsKey(c))
            {
                d[u][c] = g.Count;
                g.Add(new List<Edge>());
            }
            if (!d[v].ContainsKey(c))
            {
                d[v][c] = g.Count;
                g.Add(new List<Edge>());
            }

            int xu = d[u][c];
            int xv = d[v][c];
            g[xu].Add(new Edge(xv, 0));
            g[xv].Add(new Edge(xu, 0));
        }

        var q = new LinkedList<Tuple<int, int>>();
        q.AddFirst(Tuple.Create(0, g.Count));
        var dist = Enumerable.Repeat(int.MaxValue, g.Count + n).ToArray();
        dist[g.Count] = 0;
        for (int i = 0; i < n; i++)
        {
            var list = d[i].Values;
            int x = g.Count;
            g.Add(new List<Edge>());
            foreach (int e in list)
            {
                g[e].Add(new Edge(x, 0));
                g[x].Add(new Edge(e, 1));
            }
        }

        while (q.Count > 0)
        {
            var t = q.First.Value;
            q.RemoveFirst();
            if (dist[t.Item2] < t.Item1)
                continue;
            int x = t.Item2;
            foreach (var e in g[x])
            {
                int nd = dist[x] + e.weight;
                if (dist[e.to] > nd)
                {
                    dist[e.to] = nd;
                    if (e.weight == 0)
                        q.AddFirst(Tuple.Create(nd, e.to));
                    else
                        q.AddLast(Tuple.Create(nd, e.to));
                }
            }
        }

        int ans = dist[g.Count - 1];
        Write(ans < int.MaxValue ? ans : -1);
    }

    #region Main

    protected static TextReader reader;
    protected static TextWriter writer;
    static void Main()
    {
#if DEBUG
        reader = new StreamReader("..\\..\\input.txt");
        //reader = new StreamReader(Console.OpenStandardInput());
        writer = Console.Out;
        //writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("input.txt");
        //writer = new StreamWriter("output.txt");
#endif
        try
        {
            new Solver().Solve();
            //var thread = new Thread(new Solver().Solve, 1024 * 1024 * 128);
            //thread.Start();
            //thread.Join();
        }
        catch (Exception ex)
        {
#if DEBUG
            Console.WriteLine(ex);
#else
            throw;
#endif
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read / Write
    private static Queue<string> currentLineTokens = new Queue<string>();
    private static string[] ReadAndSplitLine() { return reader.ReadLine().Split(new[] { ' ', '\t', }, StringSplitOptions.RemoveEmptyEntries); }
    public static string ReadToken() { while (currentLineTokens.Count == 0)currentLineTokens = new Queue<string>(ReadAndSplitLine()); return currentLineTokens.Dequeue(); }
    public static int ReadInt() { return int.Parse(ReadToken()); }
    public static long ReadLong() { return long.Parse(ReadToken()); }
    public static double ReadDouble() { return double.Parse(ReadToken(), CultureInfo.InvariantCulture); }
    public static int[] ReadIntArray() { return ReadAndSplitLine().Select(int.Parse).ToArray(); }
    public static long[] ReadLongArray() { return ReadAndSplitLine().Select(long.Parse).ToArray(); }
    public static double[] ReadDoubleArray() { return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray(); }
    public static int[][] ReadIntMatrix(int numberOfRows) { int[][] matrix = new int[numberOfRows][]; for (int i = 0; i < numberOfRows; i++)matrix[i] = ReadIntArray(); return matrix; }
    public static int[][] ReadAndTransposeIntMatrix(int numberOfRows)
    {
        int[][] matrix = ReadIntMatrix(numberOfRows); int[][] ret = new int[matrix[0].Length][];
        for (int i = 0; i < ret.Length; i++) { ret[i] = new int[numberOfRows]; for (int j = 0; j < numberOfRows; j++)ret[i][j] = matrix[j][i]; } return ret;
    }
    public static string[] ReadLines(int quantity) { string[] lines = new string[quantity]; for (int i = 0; i < quantity; i++)lines[i] = reader.ReadLine().Trim(); return lines; }
    public static void WriteArray<T>(IEnumerable<T> array) { writer.WriteLine(string.Join(" ", array)); }
    public static void Write(params object[] array) { WriteArray(array); }
    public static void WriteLines<T>(IEnumerable<T> array) { foreach (var a in array)writer.WriteLine(a); }
    private class SDictionary<TKey, TValue> : Dictionary<TKey, TValue>
    {
        public new TValue this[TKey key]
        {
            get { return ContainsKey(key) ? base[key] : default(TValue); }
            set { base[key] = value; }
        }
    }
    private static T[] Init<T>(int size) where T : new() { var ret = new T[size]; for (int i = 0; i < size; i++)ret[i] = new T(); return ret; }
    #endregion
}