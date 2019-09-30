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
    List<int>[] g;
    int[] tsize, cind, cpos, csize, cdep, cpar, depth;
    int ccnt;

    void Dfs1(int x, int p)
    {
        tsize[x] = 1;
        foreach (int e in g[x])
            if (e != p)
            {
                depth[e] = depth[x] + 1;
                Dfs1(e, x);
                tsize[x] += tsize[e];
            }
    }

    void Dfs2(int x, int p, int cid)
    {
        cind[x] = cid;
        cpos[x] = csize[cid];
        csize[cid]++;
        foreach (int e in g[x])
            if (e != p)
            {
                if (tsize[e] * 2 >= tsize[x])
                    Dfs2(e, x, cid);
                else
                {
                    ccnt++;
                    cdep[ccnt] = cdep[cid] + 1;
                    cpar[ccnt] = x;
                    Dfs2(e, x, ccnt);
                }
            }
    }

    int Lca(int u, int v)
    {
        int pu = cind[u], pv = cind[v];
        while (pu != pv)
        {
            if (cdep[pu] > cdep[pv])
            {
                u = cpar[pu];
                pu = cind[u];
            }
            else
            {
                v = cpar[pv];
                pv = cind[v];
            }
        }
        return cpos[u] < cpos[v] ? u : v;
    }

    int[] load, dpl, dpr;
    bool Fun(int x, int p)
    {
        int l = int.MinValue / 2, r = int.MaxValue / 2;
        foreach (int e in g[x])
            if (e != p)
            {
                Fun(e, x);
                l = Math.Max(l, dpl[e] - 1);
                r = Math.Min(r, dpr[e] + 1);
            }

        if (l > r)
            return true;
        if (load[x] != int.MaxValue)
        {
            if (load[x] < l || load[x] > r)
                return true;
            dpl[x] = dpr[x] = load[x];
        }
        else
        {
            dpl[x] = l;
            dpr[x] = r;
        }

        return false;
    }

    bool Fun2(int x, int p, int pl, int pr)
    {
        if (load[x] != int.MaxValue)
        {
            if (load[x] < pl || load[x] > pr)
                return true;
            pl = pr = load[x];
        }
        else
        {
            pl = Math.Max(pl, dpl[x]);
            pr = Math.Min(pr, dpr[x]);
            if (pl > pr)
                return true;
            load[x] = pl;
        }
        foreach (int e in g[x])
            if (e != p)
                Fun2(e, x, pl - 1, pr + 1);
        
        return false;
    }

    public void Solve()
    {
        int n = ReadInt();

        g = Init<List<int>>(n);
        for (int i = 1; i < n; i++)
        {
            int u = ReadInt() - 1;
            int v = ReadInt() - 1;
            g[u].Add(v);
            g[v].Add(u);
        }

        tsize = new int[n];
        depth = new int[n];
        Dfs1(0, -1);
        
        cind = new int[n];
        cpos = new int[n];
        csize = new int[n];
        cdep = new int[n];
        cpar = new int[n];
        Dfs2(0, -1, 0);

        int root = -1;
        load = Enumerable.Repeat(int.MaxValue, n).ToArray();
        for (int m = ReadInt(); m > 0; m--)
        {
            int u = ReadInt() - 1;
            load[u] = ReadInt();
            if (root != -1)
            {
                int lca = Lca(u, root);
                int d = depth[u] + depth[root] - 2 * depth[lca];
                if ((load[u] + load[root]) % 2 != d % 2)
                {
                    Write("No");
                    return;
                }
            }
            root = u;
        }

        dpl = new int[n];
        dpr = new int[n];
        if (Fun(root, -1))
        {
            Write("No");
            return;
        }

        if (Fun2(root, -1, load[root], load[root]))
            Write("No");
        else
        {
            Write("Yes");
            WriteLines(load);
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