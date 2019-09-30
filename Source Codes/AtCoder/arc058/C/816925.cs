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

    List<Node> nodes = new List<Node>();
    static int alphaSize = 7;

    public class Node
    {
        public Node[] next = new Node[alphaSize];
        public Node link;
        public int id;
        public bool term;
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.AppendFormat("{0}:{1} back: {2} forward: ", id, term, link != null ? link.id.ToString() : "NULL");
            for (int i = 0; i < alphaSize; i++)
                if (next[i].id != 0)
                    sb.AppendFormat("{0}->{1} ", (char)i, next[i].id);
            return sb.ToString();
        }
    }

    Node Aho(List<List<int>> words)
    {
        var root = new Node();
        nodes.Add(root);
        int cnt = 1;
        for (int i = 0; i < words.Count; i++)
        {
            var cur = root;
            foreach (int ch in words[i])
            {
                int c = ch - 1;
                if (cur.next[c] == null)
                {
                    cur.next[c] = new Node { id = cnt++ };
                    nodes.Add(cur.next[c]);
                }
                cur = cur.next[c];
            }
            cur.term = true;
        }
        var q = new Queue<Node>();
        q.Enqueue(root);
        while (q.Count > 0)
        {
            var cur = q.Dequeue();
            if (cur != root && cur.link.term)
            {
                cur.term = true;
            }
            for (int c = 0; c < alphaSize; ++c)
            {
                if (cur.next[c] == null)
                    cur.next[c] = cur == root ? root : cur.link.next[c];
                else
                {
                    cur.next[c].link = cur == root ? root : cur.link.next[c];
                    q.Enqueue(cur.next[c]);
                }
            }
        }

        return root;
    }

    List<List<int>> o = new List<List<int>>();
    void Fun(int s, int step, int[] a, List<int> b)
    {
        if (step == a.Length)
        {
            o.Add(new List<int>(b));
            return;
        }
        if (s == a[step])
        {
            Fun(0, step + 1, a, b);
            return;
        }
        for (int i = 1; s + i <= a[step]; i++)
        {
            b.Add(i);
            Fun(s + i, step, a, b);
            b.RemoveAt(b.Count - 1);
        }
    }

    public void Solve()
    {
        int n = ReadInt();
        int x = ReadInt();
        int y = ReadInt();
        int z = ReadInt();

        Fun(0, 0, new [] { x, y, z }, new List<int>());
        var root = Aho(o);

        int m = nodes.Count;
        var dp = new long[m + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            var ndp = new long[m + 1];
            for (int j = 0; j < m; j++)
                if (dp[j] > 0)
                    for (int d = 1; d < 11; d++)
                    {
                        int v;
                        if (d > 7)
                            v = 0;
                        else
                            v = nodes[j].next[d - 1].id;
                        if (nodes[v].term)
                            v = m;
                        ndp[v] = (ndp[v] + dp[j]) % MOD;
                    }
            ndp[m] = (ndp[m] + dp[m] * 10) % MOD;
            dp = ndp;
        }

        Write(dp[m]);
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