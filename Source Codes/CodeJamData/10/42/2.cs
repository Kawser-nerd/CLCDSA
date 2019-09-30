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
    public static int MaxIdx<T, S>(this IEnumerable<T> seq, Func<T, S> func) where S : IComparable
    {
        return seq.Select(func).MaxIdx();
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
    public static int MinIdx<T, S>(this IEnumerable<T> seq, Func<T, S> func) where S : IComparable
    {
        return seq.Select(func).MinIdx();
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
            if (s == "") continue;
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

    public void go()
    {
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
    const string name = "B-large";

    int P;
    List<int> M;
    List<int> pr = new List<int>();
    int[,] DP;
    bool[,] DP_;
    void Solve()
    {
        P = ReadLine_int();
        M = SplitLine_int();
        for (int i = 0; i < P; i++)
        {
            pr.InsertRange(0, SplitLine_int());
        }
        pr.Insert(0, 0);
        DP = new int[1 << P, P];
        DP_ = new bool[1 << P, P];
        int result = go(1, 0);

        WriteLine("Case #{0}: {1}", cas, result);
    }

    int go(int match, int missed)
    {
        if (DP_[match, missed]) return DP[match, missed];

        if (match >= (1 << (P - 1)))
        {
            int team = (match-(1<<(P-1)))*2;
            int maxmiss = Math.Min(M[team], M[team + 1]);
            int result;
            if (missed > maxmiss) result = 1000000000;
            else if (missed == maxmiss) result = pr[match];
            else result = 0;
            DP[match, missed] = result;
            DP_[match, missed] = true;
            return result;
        }

        int res1 = pr[match] + go(match * 2, missed) + go(match * 2 + 1, missed);
        int res2 = go(match * 2, missed + 1) + go(match * 2 + 1, missed + 1);

        int result2 = Math.Min(res1, res2);
        if (result2 > 1000000000) result2 = 1000000000;
        DP[match, missed] = result2;
        DP_[match, missed] = true;
        return result2;

    }

}

