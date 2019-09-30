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
    public void Solve()
    {
        int n = ReadInt();
        int m = ReadInt();
        var a = ReadIntArray();

        if (a.Sum(aa => (long)aa) < m)
        {
            Write(n);
            return;
        }

        var pdp = new bool[n + 1][];
        pdp[0] = new bool[m];
        pdp[0][0] = true;
        for (int i = 0; i < n; i++)
        {
            pdp[i + 1] = (bool[])pdp[i].Clone();
            for (int j = 0; j + a[i] < m; j++)
                if (pdp[i][j])
                    pdp[i + 1][j + a[i]] = true;
        }

        var sdp = new bool[n + 1][];
        sdp[n] = new bool[m];
        sdp[n][0] = true;
        for (int i = n - 1; i >= 0; i--)
        {
            sdp[i] = (bool[])sdp[i + 1].Clone();
            for (int j = 0; j + a[i] < m; j++)
                if (sdp[i + 1][j])
                    sdp[i][j + a[i]] = true;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < m)
            {
                bool f = true;
                var ldp = pdp[i];
                var rdp = sdp[i + 1];
                int l = m - a[i];
                int r = m - 1;
                int c = 0;
                for (int j = l; j <= r; j++)
                    if (rdp[j])
                        c++;
                for (int j = 0; f && j < m; j++)
                {
                    if (ldp[j] && c > 0)
                        f = false;
                    if (l > 0)
                    {
                        if (rdp[--l])
                            c++;
                    }
                    if (rdp[r--])
                        c--;
                }

                //for (int j = m - a[i]; f && j < m; j++)
                //    for (int k = 0; k <= j && f; k++)
                //        if (ldp[k] && rdp[j - k])
                //            f = false;

                if (f)
                    ans++;
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