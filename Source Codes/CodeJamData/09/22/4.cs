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
    const string name = "B-large";

    public static bool next_permutation(int[] A)
    {
        // My own implementation of Donald E. Knuth, "Algorithm L" (the one that C++ STL uses for next_permutation)
        //  - trebe
        int N = A.Length;
        if (N <= 1) return false;

        int n;
        for (n = N - 2; n >= 0; n--)
        {
            if (A[n] < A[n + 1]) break;
        }
        if (n == -1) return false;

        int m;
        for (m = N - 1; ; m--)
        {
            if (A[m] > A[n]) break;
        }
        int t = A[m]; A[m] = A[n]; A[n] = t;
        int a = n + 1, b = N - 1;
        while (a < b)
        {
            t = A[a]; A[a] = A[b]; A[b] = t;
            a += 1;
            b -= 1;
        }
        return true;

    }


    void Solve()
    {
        string S = ReadLine();
        int[] num = new int[S.Length + 1];
        for (int i = 0; i < S.Length; i++)
        {
            num[i + 1] = (int)(S[i] - '0');
        }
        next_permutation(num);
        string result = "";
        for (int i = 0; i < num.Length; i++)
        {
            if (i == 0 && num[i] == 0) continue;
            result += Convert.ToString(num[i]);
        }
        WriteLine("Case #{0}: {1}", cas, result);
    }


}

