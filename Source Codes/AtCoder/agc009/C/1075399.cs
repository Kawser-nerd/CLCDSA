using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (?°?°)??e??????????????????????????
public class Solver
{
    const int MOD = 1000000007;

    class SegmentTree
    {
        private int size;
        private long[] data;
        private long[] lazy;

        public SegmentTree(int size)
        {
            this.size = size;
            data = new long[size << 2];
            lazy = new long[size << 2];
        }

        void UpdateNode(int x, int xl, int xr, long d)
        {
            lazy[x] = d;
            data[x] = d * (xr - xl + 1) % MOD;
        }

        void Push(int x, int xl, int xr)
        {
            if (lazy[x] == -1)
                return;
            UpdateNode(x << 1, xl, xr, lazy[x]);
            UpdateNode(x << 1 | 1, xl, xr, lazy[x]);
            lazy[x] = -1;
        }

        private long Query(int x, int xl, int xr, int l, int r)
        {
            if (l == xl && xr == r)
                return data[x];

            Push(x, xl, xr);
            int xm = (xl + xr) / 2;
            if (r <= xm)
                return Query(x << 1, xl, xm, l, r);
            if (l > xm)
                return Query(x << 1 | 1, xm + 1, xr, l, r);
            return (Query(x << 1, xl, xm, l, xm) + Query(x << 1 | 1, xm + 1, xr, xm + 1, r)) % MOD;
        }

        public long Query(int l, int r)
        {
            return Query(1, 0, size - 1, l, r);
        }

        private void Update(int x, int xl, int xr, int l, int r, long v)
        {
            if (l == xl && xr == r)
            {
                UpdateNode(x, xl, xr, v);
                return;
            }

            Push(x, xl, xr);
            int xm = (xl + xr) / 2;
            if (r <= xm)
                Update(x << 1, xl, xm, l, r, v);
            else if (l > xm)
                Update(x << 1 | 1, xm + 1, xr, l, r, v);
            else
            {
                Update(x << 1, xl, xm, l, xm, v);
                Update(x << 1 | 1, xm + 1, xr, xm + 1, r, v);
            }
            data[x] = (data[x << 1] + data[x << 1 | 1]) % MOD;
        }

        public void Update(int l, int r, long add)
        {
            Update(1, 0, size - 1, l, r, add);
        }
    }

    public void Solve()
    {
        int n = ReadInt();
        long d1 = ReadLong();
        long d2 = ReadLong();
        
        var a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = ReadLong();

        var t1 = new SegmentTree(n);
        var t2 = new SegmentTree(n);
        t1.Update(0, 0, 1);
        t2.Update(0, 0, 1);
        for (int i = 1; i < n; i++)
        {
            int l = -1, r = i - 2;
            while (l < r)
            {
                int m = (l + r + 1) / 2;
                if (a[m] > a[i] - d1)
                    r = m - 1;
                else
                    l = m;
            }
            t1.Update(i, i, t2.Query(0, l + 1));
            l = -1;
            r = i - 2;
            while (l < r)
            {
                int m = (l + r + 1) / 2;
                if (a[m] > a[i] - d2)
                    r = m - 1;
                else
                    l = m;
            }
            t2.Update(i, i, t1.Query(0, l + 1));
            if (a[i] < a[i - 1] + d1)
                t1.Update(0, i - 1, 0);
            if (a[i] < a[i - 1] + d2)
                t2.Update(0, i - 1, 0);
        }
        Write((t1.Query(0, n - 1) + t2.Query(0, n - 1)) % MOD);
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