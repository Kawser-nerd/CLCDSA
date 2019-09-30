#region Template code
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Globalization;

static class MyLinq
{
    public static int MaxIdx<T>(this IEnumerable<T> seq) where T : IComparable
    {
        int res = -1;
        T max = default(T);
        int i = 0;
        foreach (T t in seq)
        {
            if (res == -1 || t.CompareTo(max) > 0) { res = i; max = t; }
            i += 1;
        }
        return res;
    }
    public static int MinIdx<T>(this IEnumerable<T> seq) where T : IComparable
    {
        int res = -1;
        T min = default(T);
        int i = 0;
        foreach (T t in seq)
        {
            if (res == -1 || t.CompareTo(min) < 0) { res = i; min = t; }
            i += 1;
        }
        return res;
    }
    public static Tsource MyMax<Tsource, Tkey>(this IEnumerable<Tsource> seq, Func<Tsource, Tkey> func) where Tkey : IComparable
    {
        Tsource res = default(Tsource);
        Tkey maxkey = default(Tkey);
        bool first = true;
        foreach (Tsource t in seq)
        {
            if (first) { maxkey = func(t); res = t; first = false; continue; }
            Tkey k = func(t);
            if (k.CompareTo(maxkey) > 0) { maxkey = k; res = t; }
        }
        return res;
    }
    public static Tsource MyMin<Tsource, Tkey>(this IEnumerable<Tsource> seq, Func<Tsource, Tkey> func) where Tkey : IComparable
    {
        Tsource res = default(Tsource);
        Tkey minkey = default(Tkey);
        bool first = true;
        foreach (Tsource t in seq)
        {
            if (first) { minkey = func(t); res = t; first = false; continue; }
            Tkey k = func(t);
            if (k.CompareTo(minkey) < 0) { minkey = k; res = t; }
        }
        return res;
    }
    public static IEnumerable<U> Zip<S, T, U>(this IEnumerable<S> A, IEnumerable<T> B, Func<S, T, U> func)
    {
        IEnumerator<S> AA = A.GetEnumerator();
        IEnumerator<T> BB = B.GetEnumerator();
        while (AA.MoveNext() && BB.MoveNext())
        {
            yield return func(AA.Current, BB.Current);
        }
    }

}

class Program
{
    static void Main(string[] args)
    {
        System.Threading.Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        Solution sol = new Solution();
        sol.go();
    }
}

partial class Solution
{
    #region I/O
    protected TextReader input = null;
    protected TextWriter output = null;

    string[] line;
    int index;
    protected string ReadLine()
    {
        line = null;
        return input.ReadLine();
    }

    protected int ReadLine_int()
    {
        line = null;
        return Convert.ToInt32(input.ReadLine());
    }

    protected string[] SplitLine()
    {
        index = 0;
        return line = input.ReadLine().Split();
    }

    protected List<int> SplitLine_int()
    {
        index = 0;
        line = input.ReadLine().Split();

        List<int> result = new List<int>();
        foreach (string s in line)
        {
            result.Add(Convert.ToInt32(s));
        }
        return result;
    }

    protected string GetString()
    {
        return line[index++];
    }

    protected int GetInt()
    {
        return Convert.ToInt32(line[index++]);
    }

    protected long GetLong()
    {
        return Convert.ToInt64(line[index++]);
    }

    protected double GetDouble()
    {
        return Convert.ToDouble(line[index++], CultureInfo.InvariantCulture);
    }

    protected void Write(string s)
    {
        output.Write(s);
        Console.Out.Write(s);
    }

    protected void Write(string format, params object[] ss)
    {
        output.Write(format, ss);
        Console.Out.Write(format, ss);
    }

    protected void WriteLine()
    {
        output.WriteLine();
        Console.Out.WriteLine();
    }

    protected void WriteLine(string s)
    {
        output.WriteLine(s);
        Console.Out.WriteLine(s);
    }

    protected void WriteLine(string format, params object[] ss)
    {
        output.WriteLine(format, ss);
        Console.Out.WriteLine(format, ss);

    }

    #endregion

    static string hex(int x)
    {
        return String.Format("{0:x}", x);
    }

    partial void test();
    public void go()
    {
        test();
        Environment.CurrentDirectory = "../..";
        input = File.OpenText(name + ".in");
        output = File.CreateText(name + ".out");
        int N = ReadLine_int();
        for (cas = 1; cas <= N; cas++)
        {
            Solve();
        }

        output.Close();
        input.Close();
        Console.Out.WriteLine("Done...");
        Console.In.ReadLine();
    }
    int cas = -1;

}
#endregion

partial class Solution
{
    static bool isbetter(string A, string B)
    {
        if (B == null) return true;
        if (A == null) return false;
        if (A.Length < B.Length) return true;
        if (A.Length > B.Length) return false;
        return A.CompareTo(B) < 0;
    }
    const string name = "C-small-attempt0";

    void Solve()
    {

        SplitLine_int();
        int W = GetInt();
        int Q = GetInt();
        string[] puzzle = new string[W];
        for (int i = 0; i < W; i++)
        {
            puzzle[i] = ReadLine();
        }
        SplitLine_int();
        string[, ,] DP = new string[500, W, W];
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < W; j++)
            {
                char c = puzzle[i][j];
                if (c == '+' || c == '-') continue;
                DP[c - '0' + 250, i, j] = c.ToString();
            }
        }
        again:
        bool change = false;
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < W; j++)
            {
                char c = puzzle[i][j];
                if (c == '+' || c == '-') continue;
                for (int i1 = i-1; i1 <= i+1; i1++)
                {
                    if (i1 < 0 || i1 >= W) continue;
                    for (int j1 = j - 1; j1 <= j + 1; j1++)
                    {
                        if (!(i1 != i ^ j1 != j)) continue;
                        if (j1 < 0 || j1 >= W) continue;
                        char op = puzzle[i1][j1];
                        for (int i2 = i1 - 1; i2 <= i1 + 1; i2++)
                        {
                            if (i2 < 0 || i2 >= W) continue;
                            for (int j2 = j1 - 1; j2 <= j1 + 1; j2++)
                            {
                                if (j2 < 0 || j2 >= W) continue;
                                if (!(i2 != i1 ^ j2 != j1)) continue;

                                int delta = puzzle[i2][j2] - '0';
                                Debug.Assert(delta >= 0 && delta <= 9);
                                if (op == '-') delta = -delta;
                                for (int SUM = 0; SUM < 500; SUM++)
                                {
                                    if (DP[SUM, i, j]==null) continue;
                                    int SUM2 = SUM + delta;
                                    if (SUM2 < 0 || SUM2 >= 500) continue;
                                    string newstring = DP[SUM, i, j] + op + puzzle[i2][j2];
                                    if (isbetter(newstring, DP[SUM2, i2, j2]))
                                    {
                                        change = true;
                                        DP[SUM2, i2, j2] = newstring;
                                    }
                                }

                            }
                        }


                    }
                    
                }
                                
            }
        }
        if (change) goto again;

        WriteLine("Case #{0}:", cas);
        for (int q = 0; q < Q; q++)
        {
            int query = GetInt();
            string result = null;
            for (int i = 0; i < W; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (isbetter(DP[query+250, i, j], result)) result = DP[query+250, i, j];
                }
            }

            WriteLine("{0}", result);
        }
    }


}

