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

class Array2
{
    public int defaultvalue = 0;
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
    const string name = "C-small-attempt0";

    void Solve()
    {
        int R = ReadLine_int();
        Array2 arr = new Array2();
        for (int foo = 0; foo < R; foo++)
        {
            SplitLine();
            int X1 = GetInt();
            int Y1 = GetInt();
            int X2 = GetInt();
            int Y2 = GetInt();
            for (int i = Y1; i <= Y2; i++)
            {
                for (int j = X1; j <= X2; j++)
                {
                    arr.set(i, j, 1);
                }
            }
        }
        int result = 0;
        while (true)
        {
            if (arr.arr.All(line => line.All(x => x == 0))) break;
            Array2 arr2 = new Array2();
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    if (arr.get(i,j)==1 && (arr.get(i-1,j)==1||arr.get(i,j-1)==1)) arr2.set(i,j,1);
                    else if (arr.get(i-1,j)==1&&arr.get(i,j-1)==1) arr2.set(i,j,1);
                }
            }
            arr = arr2;
            result += 1;
        }

        WriteLine("Case #{0}: {1}", cas, result);
    }


}

