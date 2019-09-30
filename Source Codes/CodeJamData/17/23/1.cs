using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
public class Solver
{
    public class Heap<T>
    {
        private readonly List<T> data;
        private readonly Comparison<T> compare;

        public Heap(Comparison<T> compare)
        {
            this.compare = compare;
            data = new List<T> { default(T) };
        }

        public int Count
        {
            get { return data.Count - 1; }
        }

        public T Peek()
        {
            return data[1];
        }

        public void Push(T item)
        {
            data.Add(item);
            var curPlace = Count;
            while (curPlace > 1 && compare(item, data[curPlace / 2]) < 0)
            {
                data[curPlace] = data[curPlace / 2];
                data[curPlace / 2] = item;
                curPlace /= 2;
            }
        }

        public T Pop()
        {
            var ret = data[1];
            data[1] = data[Count];
            data.RemoveAt(Count);
            var curPlace = 1;
            while (true)
            {
                var max = curPlace;
                if (Count >= curPlace * 2 && compare(data[max], data[2 * curPlace]) > 0)
                    max = 2 * curPlace;
                if (Count >= curPlace * 2 + 1 && compare(data[max], data[2 * curPlace + 1]) > 0)
                    max = 2 * curPlace + 1;
                if (max == curPlace)
                    break;
                var item = data[max];
                data[max] = data[curPlace];
                data[curPlace] = item;
                curPlace = max;
            }

            return ret;
        }
    }

    class Edge
    {
        public int to;
        public double len;
        public Edge(int to, double len)
        {
            this.to = to;
            this.len = len;
        }
    }

    public void Solve()
    {
        int nt = ReadInt();
        for (int tt = 1; tt <= nt; tt++)
        {
            int n = ReadInt();
            int q = ReadInt();
            var horses = ReadIntMatrix(n);
            var g1 = ReadIntMatrix(n);

            var g2 = Init<List<Edge>>(n);
            for (int i = 0; i < n; i++)
            {
                var d = Enumerable.Repeat(long.MaxValue, n).ToArray();
                d[i] = 0;
                var heap = new Heap<Tuple<long, int>>((t1, t2) => t1.Item1.CompareTo(t2.Item1));
                heap.Push(Tuple.Create(0L, i));
                while (heap.Count > 0)
                {
                    var t = heap.Pop();
                    if (d[t.Item2] < t.Item1)
                        continue;
                    for (int j = 0; j < n; j++)
                        if (g1[t.Item2][j] != -1)
                        {
                            long nd = t.Item1 + g1[t.Item2][j];
                            if (nd < d[j])
                            {
                                d[j] = nd;
                                heap.Push(Tuple.Create(nd, j));
                            }
                        }
                }

                for (int j = 0; j < n; j++)
                    if (j != i && d[j] <= horses[i][0])
                        g2[i].Add(new Edge(j, d[j] * 1.0 / horses[i][1]));
            }

            var dist = new double[n][];
            for (int i = 0; i < n; i++)
            {
                dist[i] = Enumerable.Repeat(double.MaxValue, n).ToArray();
                dist[i][i] = 0;
                var heap = new Heap<Tuple<double, int>>((t1, t2) => t1.Item1.CompareTo(t2.Item1));
                heap.Push(Tuple.Create(0.0, i));
                while (heap.Count > 0)
                {
                    var t = heap.Pop();
                    if (dist[i][t.Item2] < t.Item1)
                        continue;
                    foreach (var e in g2[t.Item2])
                    {
                        double nd = t.Item1 + e.len;
                        if (nd < dist[i][e.to])
                        {
                            dist[i][e.to] = nd;
                            heap.Push(Tuple.Create(nd, e.to));
                        }
                    }
                }
            }

            writer.Write("Case #{0}:", tt);
            for (; q > 0; q--)
            {
                int u = ReadInt() - 1;
                int v = ReadInt() - 1;
                writer.Write(" " + dist[u][v]);
            }
            Write();
        }
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
        writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("input.txt");
        //writer = new StreamWriter("output.txt");
#endif
        try
        {
            new Solver().Solve();
            //var thread = new Thread(new Solver().Solve, 1024 * 1024 * 256);
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
