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
    static class TwoSat
    {
        static List<int>[] g, gr;
        static bool[] used;
        static List<int> order;
        static int[] comp;

        static void Dfs1(int x)
        {
            if (used[x])
                return;
            used[x] = true;
            foreach (int e in g[x])
                Dfs1(e);
            order.Add(x);
        }

        static void Dfs2(int x, int c)
        {
            if (comp[x] != -1)
                return;
            comp[x] = c;
            foreach (int e in gr[x])
                Dfs2(e, c);
        }

        public static bool[] Match(List<int>[] g)
        {
            TwoSat.g = g;
            int n = g.Length / 2;
            gr = Init<List<int>>(2 * n);
            for (int i = 0; i < 2 * n; i++)
                foreach (int e in g[i])
                    gr[e].Add(i);

            used = new bool[2 * n];
            order = new List<int>();
            for (int i = 0; i < 2 * n; i++)
                Dfs1(i);

            comp = Enumerable.Repeat(-1, 2 * n).ToArray();
            for (int i = 0, j = 0; i < 2 * n; i++)
            {
                int x = order[2 * n - i - 1];
                if (comp[x] == -1)
                    Dfs2(x, j++);
            }

            bool[] ret = new bool[n];
            for (int i = 0; i < n; i++)
                if (comp[i] == comp[i + n])
                    return null;
                else
                    ret[i] = comp[i] > comp[i + n];

            return ret;
        }
    }

    int[] dr = { 0, 1, 0, -1 };
    int[] dc = { 1, 0, -1, 0 };
    int[] md1 = { 3, 2, 1, 0 };
    int[] md2 = { 1, 0, 3, 2 };

    int rs, cs;
    string[] a;
    bool[,] f;
    int[,] id;
    List<int> Check(int r, int c, bool v)
    {
        var ret = new List<int>();
        if (v)
        {
            for (int d = 1; d < 4; d += 2)
            {
                int cr = r;
                int cc = c;
                int cd = d;
                while (true)
                {
                    cr += dr[cd];
                    cc += dc[cd];
                    if (cr < 0 || cr == rs || cc < 0 || cc == cs || a[cr][cc] == '#')
                        break;
                    if (a[cr][cc] == '-' || a[cr][cc] == '|')
                        return null;
                    if (a[cr][cc] == '/')
                        cd = md1[cd];
                    else if (a[cr][cc] == '\\')
                        cd = md2[cd];
                    else
                        ret.Add(id[cr, cc]);
                }
            }
        }
        else
        {
            for (int d = 0; d < 4; d += 2)
            {
                int cr = r;
                int cc = c;
                int cd = d;
                while (true)
                {
                    cr += dr[cd];
                    cc += dc[cd];
                    if (cr < 0 || cr == rs || cc < 0 || cc == cs || a[cr][cc] == '#')
                        break;
                    if (a[cr][cc] == '-' || a[cr][cc] == '|')
                        return null;
                    if (a[cr][cc] == '/')
                        cd = md1[cd];
                    else if (a[cr][cc] == '\\')
                        cd = md2[cd];
                    else
                        ret.Add(id[cr, cc]);
                }
            }
        }
        return ret;
    }

    public void Solve()
    {
        int nt = ReadInt();
        for (int tt = 1; tt <= nt; tt++)
        {
            rs = ReadInt();
            cs = ReadInt();
            a = ReadLines(rs);

            id = new int[rs, cs];
            int n = 0, m = 0;
            for (int i = 0; i < rs; i++)
                for (int j = 0; j < cs; j++)
                    if (a[i][j] == '.')
                        id[i, j] = n++;
                    else if (a[i][j] == '-' || a[i][j] == '|')
                        id[i, j] = m++;
            bool ok = true;
            var lists = Init<List<int>>(n);
            var ver = new bool[m];
            for (int i = 0; i < rs; i++)
                for (int j = 0; j < cs; j++)
                    if (a[i][j] == '-' || a[i][j] == '|')
                    {
                        var list1 = Check(i, j, false);
                        var list2 = Check(i, j, true);
                        if (list1 == null && list2 == null)
                            ok = false;

                        if (list1 != null)
                        {
                            foreach (int x in list1)
                                lists[x].Add(id[i, j]);
                        }
                        else
                            ver[id[i, j]] = true; 
                        if (list2 != null)
                            foreach (int x in list2)
                                lists[x].Add(id[i, j] + m);
                    }

            var g = Init<List<int>>(2 * m);
            for (int i = 0; i < n; i++)
                if (lists[i].Count == 0)
                    ok = false;
                else if (lists[i].Count == 1)
                    g[(lists[i][0] + m) % (2 * m)].Add(lists[i][0]);
                else
                {
                    g[(lists[i][0] + m) % (2 * m)].Add(lists[i][1]);
                    g[(lists[i][1] + m) % (2 * m)].Add(lists[i][0]);
                }

            if (!ok)
            {
                writer.WriteLine("Case #{0}: {1}", tt, "IMPOSSIBLE");
                continue;
            }

            var match = TwoSat.Match(g);
            if (match == null)
            {
                writer.WriteLine("Case #{0}: {1}", tt, "IMPOSSIBLE");
                continue;
            }

            writer.WriteLine("Case #{0}: {1}", tt, "POSSIBLE");
            for (int i = 0; i < rs; i++)
            {
                for (int j = 0; j < cs; j++)
                    if (a[i][j] == '-' || a[i][j] == '|')
                        writer.Write(ver[id[i, j]] || !match[id[i, j]] ? '|' : '-');
                    else
                        writer.Write(a[i][j]);
                Write();
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

