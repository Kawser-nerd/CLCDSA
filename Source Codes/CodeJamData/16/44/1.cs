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
    bool?[,,] mem;
    bool Check(int step, int machine, int people, bool[,] a, int n)
    {
        if (step == n)
            return machine == (1 << n) - 1;
        if (mem[step, machine, people].HasValue)
            return mem[step, machine, people].Value;

        for (int i = 0; i < n; i++)
            if ((people >> i & 1) == 0)
            {
                bool f = true;
                for (int j = 0; j < n; j++)
                    if (a[i, j] && (machine >> j & 1) == 0)
                    {
                        if (!Check(step + 1, machine | 1 << j, people | 1 << i, a, n))
                            return (mem[step, machine, people] = false).Value;
                        else
                            f = false;
                    }
                if (f)
                    return (mem[step, machine, people] = false).Value;
            }
        return (mem[step, machine, people] = true).Value;
    }

    public void Solve()
    {
        int nt = ReadInt();
        for (int tt = 1; tt <= nt; tt++)
        {
            int n = ReadInt();
            var a = ReadLines(n).Select(row => row.Select(ch => ch - '0').ToArray()).ToArray();

            int ans = int.MaxValue;
            for (int mask = 0; mask < 1 << n * n; mask++)
            {
                var b = new bool[n, n];
                int c = 0;
                int p = 0;
                bool f = true;
                for (int i = 0; f && i < n; i++)
                    for (int j = 0; f && j < n; j++, p++)
                    {
                        b[i, j] = (mask >> p & 1) == 1;
                        if (a[i][j] == 1 && !b[i, j])
                            f = false;
                        if (a[i][j] == 0 && b[i, j])
                            c++;
                    }
                if (!f)
                    continue;
                mem = new bool?[n, 1 << n, 1 << n];
                if (Check(0, 0, 0, b, n))
                    ans = Math.Min(ans, c);
            }

            writer.WriteLine("Case #{0}: {1}", tt, ans);
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
        reader = new StreamReader("input.txt");
        writer = new StreamWriter("output.txt");
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
            Console.WriteLine(ex);
#if DEBUG
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