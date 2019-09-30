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
    void Swap<T>(ref T a, ref T b)
    {
        T t = a;
        a = b;
        b = t;
    }

    class Bit
    {
        private readonly int size;
        private readonly int[] data;

        public Bit(int n)
        {
            size = n;
            data = new int[n];
        }

        public int PrefixSum(int r)
        {
            int ret = 0;
            for (; r >= 0; r = (r & r + 1) - 1)
                ret = Math.Max(ret, data[r]);
            return ret;
        }

        public void Update(int idx, int diff)
        {
            for (; idx < size; idx = (idx | idx + 1))
                data[idx] = Math.Max(data[idx], diff);
        }
    }

    public void Solve()
    {
        int r1 = ReadInt();
        int c1 = ReadInt();
        int r2 = ReadInt();
        int c2 = ReadInt();

        if (r1 > r2)
        {
            Swap(ref r1, ref r2);
            Swap(ref c1, ref c2);
        }

        var a = new List<int[]>();
        for (int n = ReadInt(); n > 0; n--)
        {
            int r = ReadInt();
            int c = ReadInt();
            if (r < r1 || r > r2 || c < Math.Min(c1, c2) || c > Math.Max(c1, c2))
                continue;
            a.Add(new [] { r - r1, Math.Abs(c - c1) });
        }

        if (r1 == r2)
        {
            Write(100.0 * Math.Abs(c1 - c2) + (a.Count > 0 ? 10 * (Math.PI - 2) : 0));
            return;
        }
        if (c1 == c2)
        {
            Write(100.0 * (r2 - r1) + (a.Count > 0 ? 10 * (Math.PI - 2) : 0));
            return;
        }

        double ans = 100.0 * (Math.Abs(r1 - r2) + Math.Abs(c1 - c2));
        if (a.Count == 0)
        {
            Write(ans);
            return;
        }

        a.Sort((a1, a2) => a1[0].CompareTo(a2[0]));
        if (a.Count == r2 - r1 + 1)
        {
            bool f = true;
            for (int i = 1; i < a.Count; i++)
                if (a[i][1] < a[i - 1][1])
                    f = false;
            if (f)
            {
                Write(ans - (20 - 5 * Math.PI) * (r2 - r1) + 10 * (Math.PI - 2));
                return;
            }
        }
        if (a.Count == Math.Abs(c2 - c1) + 1)
        {
            bool f = true;
            for (int i = 1; i < a.Count; i++)
                if (a[i][1] < a[i - 1][1])
                    f = false;
            if (f)
            {
                Write(ans - (20 - 5 * Math.PI) * Math.Abs(c2 - c1) + 10 * (Math.PI - 2));
                return;
            }
        }

        int m = a.Count;
        var list = new List<int>();
        for (int i = 0; i < m; i++)
            list.Add(a[i][1]);
        list.Sort();
        
        var bit = new Bit(m);
        for (int i = 0; i < m; i++)
        {
            int y = list.BinarySearch(a[i][1]);
            int v = bit.PrefixSum(y);
            bit.Update(y, v + 1);
        }

        ans -= (20 - 5 * Math.PI) * bit.PrefixSum(m - 1);
        Write(ans);
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