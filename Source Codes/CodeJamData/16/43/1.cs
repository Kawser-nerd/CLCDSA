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
        int nt = ReadInt();
        for (int tt = 1; tt <= nt; tt++)
        {
            int n = ReadInt();
            int m = ReadInt();
            
            int nm = 2 * (n + m);
            var f = new bool[nm, nm];
            for (int i = 0; i < nm; i += 2)
            {
                int u = ReadInt() - 1;
                int v = ReadInt() - 1;
                f[u, v] = f[v, u] = true;
            }

            int ans = -1;
            for (int mask = 0; ans == -1 && mask < 1 << n * m; mask++)
            {
                bool ok = true;
                var a = new int[n + 2, m + 2];
                int p = 0;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++, p++)
                        a[i + 1, j + 1] = (mask >> p & 1) - 2;
                for (int i = 0; i < m; i++)
                    a[0, i + 1] = i;
                for (int i = 0; i < n; i++)
                    a[i + 1, m + 1] = i + m;
                for (int i = 0; i < m; i++)
                    a[n + 1, m - i] = i + n + m;
                for (int i = 0; i < n; i++)
                    a[n - i, 0] = i + n + m + m;

                for (int x = 0; ok && x < nm; x++)
                {
                    int r, c, d;
                    if (x < m)
                    {
                        r = 1;
                        c = x + 1;
                        d = 0;
                    }
                    else if (x < n + m)
                    {
                        r = x - m + 1;
                        c = m;
                        d = 1;
                    }
                    else if (x < n + m + m)
                    {
                        r = n;
                        c = m - (x - n - m);
                        d = 2;
                    }
                    else
                    {
                        r = n - (x - n - m - m);
                        c = 1;
                        d = 3;
                    }

                    while (true)
                    {
                        if (a[r, c] >= 0)
                        {
                            if (!f[x, a[r, c]])
                                ok = false;
                            break;
                        }
                        if (a[r, c] == -2)
                        {
                            if (d == 0)
                            {
                                c--;
                                d = 1;
                            }
                            else if (d == 1)
                            {
                                r++;
                                d = 0;
                            }
                            else if (d == 2)
                            {
                                c++;
                                d = 3;
                            }
                            else
                            {
                                r--;
                                d = 2;
                            }
                        }
                        else
                        {
                            if (d == 0)
                            {
                                c++;
                                d = 3;
                            }
                            else if (d == 1)
                            {
                                r--;
                                d = 2;
                            }
                            else if (d == 2)
                            {
                                c--;
                                d = 1;
                            }
                            else
                            {
                                r++;
                                d = 0;
                            }
                        }
                    }
                }

                if (ok)
                    ans = mask;
            }

            writer.WriteLine("Case #{0}:", tt);
            if (ans == -1)
                Write("IMPOSSIBLE");
            else
            {
                int p = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++, p++)
                        writer.Write("/\\"[(ans >> p & 1)]);
                    Write();
                }
            }
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