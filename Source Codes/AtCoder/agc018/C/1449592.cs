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

    public void Solve()
    {
        var c = ReadIntArray();
        int n = c.Sum();
        var a = ReadAndTransposeIntMatrix(n);

        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if (c[i] < c[j])
                {
                    Swap(ref c[i], ref c[j]);
                    Swap(ref a[i], ref a[j]);
                }

        var b = new int[n][];
        for (int i = 0; i < n; i++)
            b[i] = new [] { a[0][i], a[1][i], a[2][i] };

        Array.Sort(b, (b1, b2) => (b2[1] - b2[0]).CompareTo(b1[1] - b1[0]));
        long v = 0;
        for (int i = 0; i < c[1]; i++)
            v += b[i][1];

        var f = new bool[n];
        var qr = new Heap<int>((x1, x2) => (b[x1][2] - b[x1][0]).CompareTo(b[x2][2] - b[x2][0]));
        for (int i = c[1]; i < n; i++)
        {
            f[i] = true;
            v += b[i][2];
            qr.Push(i);
        }

        while (qr.Count > c[2])
        {
            int x = qr.Pop();
            f[x] = false;
            v -= b[x][2] - b[x][0];
        }

        long ans = v;
        var ql = new Heap<int>((x1, x2) => (b[x2][2] - b[x2][1]).CompareTo(b[x1][2] - b[x1][1]));
        for (int i = 0; i < c[1]; i++)
            ql.Push(i);
        for (int i = 1; i <= c[2]; i++)
        {
            int j = c[1] + i - 1;
            int x;
            if (f[j])
            {
                v += b[j][1] - b[j][2];
                f[j] = false;
            }
            else
            {
                v += b[j][1] - b[j][0];
                x = qr.Pop();
                while (!f[x])
                {
                    x = qr.Pop();
                }
                v += b[x][0] - b[x][2];
                f[x] = false;
            }

            ql.Push(j);
            x = ql.Pop();
            v += b[x][2] - b[x][1];
            ans = Math.Max(ans, v);
        }

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