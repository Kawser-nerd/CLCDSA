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
    public void Solve()
    {
        int n = 32;
        int m = 500;

        var p = new int[] { 3, 2, 3, 2, 7, 2, 3, 2, 3 };
        int np = p.Aggregate((u, v) => u * v);
        var dp = Init<List<long>>(np);
        int start = 0;
        foreach (int pp in p)
            start = start * pp + 1;
        dp[start].Add(1);

        for (int i = 0; i < n - 1; i++)
        {
            var ndp = Init<List<long>>(np);
            for (int j = 0; j < np; j++)
                if (dp[j].Count > 0)
                {
                    var a = new int[9];
                    int x = j;
                    for (int k = 0; k < 9; k++)
                    {
                        a[k] = x % p[k];
                        x /= p[k];
                    }

                    for (int d = 0; d < 2; d++)
                    {
                        if (i == n - 2 && d == 0)
                            continue;
                        x = 0;
                        for (int k = 8; k >= 0; k--)
                        {
                            x = x * p[k] + (a[k] * (k + 2) + d) % p[k];
                        }
                        for (int k = 0; k < dp[j].Count && ndp[x].Count < m; k++)
                            ndp[x].Add(dp[j][k] * 2 + d);
                    }
                }
            dp = ndp;
        }

        Write("Case #1:");
        foreach (long x in dp[0])
        {
            var a = new int[n];
            long y = x;
            for (int i = n - 1; i >= 0; i--)
            {
                a[i] = (int)(y % 2);
                y /= 2;
            }
            writer.Write(string.Concat(a) + " ");
            WriteArray(p);
            //for (int d = 2; d < 11; d++)
            //{
            //    int v = 0;
            //    for (int i = 0; i < n; i++)
            //        v = (v * d + a[i]) % p[d - 2];
            //    if (v != 0)
            //        Write("!");
            //}
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
            //var thread = new Thread(new Solver().Solve, 1024 * 1024 * 128);
            //thread.Start();
            //thread.Join();
            new Solver().Solve();
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