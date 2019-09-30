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
        string s = input.ReadLine();
        return Convert.ToInt32(s);
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

class Array2
{
    public int defaultvalue = -1;
    public List<List<int>> arr = new List<List<int>>();
    const int rowfactor = 1000;
    public int[] dirs = new int[] { -1, 1, -rowfactor, rowfactor };
    public int[] dirs2 = new int[] { -rowfactor - 1, -rowfactor, -rowfactor + 1, -1, 1, rowfactor - 1, rowfactor, rowfactor + 1 };
    public int get(int i, int j)
    {
        if (i < 0 || i >= arr.Count) return defaultvalue;
        if (j < 0 || j >= arr[i].Count) return defaultvalue;
        return arr[i][j];
    }
    public int get(int P)
    {
        if (P < 0) return defaultvalue;
        return get(P / rowfactor, P % rowfactor);
    }
    public void set(int i, int j, int value)
    {
        if (i < 0 || j < 0) return;
        while (i >= arr.Count) arr.Add(new List<int>());
        while (j >= arr[i].Count) arr[i].Add(defaultvalue);
        arr[i][j] = value;
    }
    public void set(int P, int value)
    {
        set(P / rowfactor, P % rowfactor, value);
    }
    public IEnumerable<int> IterateCells()
    {
        for (int i = 0; i < arr.Count; i++)
        {
            for (int j = 0; j < arr[i].Count; j++)
            {
                yield return rowfactor * i + j;
            }
        }
    }
    public IEnumerable<int> IterateCells(int I, int J)
    {
        for (int i = 0; i < I; i++)
        {
            for (int j = 0; j < J; j++)
            {
                yield return rowfactor * i + j;
            }
        }
    }
}


partial class Solution
{
    const string name = "A-large";

    IEnumerable<int> mkFoo(int result, int x)
    {
        result -= Math.Abs(x);
        if (result == 0) yield return 0;
        else { yield return -result; yield return result; }
    }

    void Solve()
    {
        int k = ReadLine_int();
        List<List<int>> diam = new List<List<int>>();
        for (int i = 0; i < 2*k-1; i++)
        {
            diam.Add(SplitLine_int());
        }
        DP = new Array2();
        for (int result = 0; result < 1000; result++)
        {
            for (int x = -result; x <= result; x++)
            {
                foreach (int y in mkFoo(result,x))
                {
                    if (isOK(result, k, diam, x, y))
                    {
                        WriteLine("Case #{0}: {1}", cas, (k+result)*(k+result)-k*k);
                        return;
                    }
                }
            }
        }

    }

    bool mycompare(List<int> a, List<int> b)
    {
        if (a.Count < b.Count) { List<int> t = a; a = b; b = t; }
        int off = (a.Count - b.Count) / 2;
        for (int i = 0; i < b.Count; i++)
        {
            if (a[i + off] != b[i]) return false;
        }
        return true;
    }
    Array2 DP;
    bool issym(List<int> s, int i, int off)
    {
        int result = DP.get(i,off+100);
        if (result != -1) return result == 1;
        for (int r = 0; r < s.Count; r++)
        {
            int j = s.Count - 1 - r - off;
            if (j < 0 || j >= s.Count) continue;
            if (s[r] != s[j]) { DP.set(i, off + 100, 0); return false; }
        }
        DP.set(i, off + 100, 1);
        return true;
    }

    bool isOK(int result, int k, List<List<int>> diam, int dr, int dc)
    {
        for (int i = 1; i < k+result; i++)
        {
            int r1 = k - 1 - dr - i;
            int r2 = k - 1 - dr + i;
            if (r1 < 0 || r2 >= 2 * k - 1) break;
            if (!mycompare(diam[r1], diam[r2])) return false;
        }
        for (int i = 0; i < diam.Count; i++)
        {
            if (!issym(diam[i], i, dc)) return false;
        }
        return true;
    }

}

