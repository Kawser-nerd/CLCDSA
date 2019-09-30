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
    protected List<double> SplitLine_double()
    {
        index = 0;
        line = input.ReadLine().Split();

        List<double> result = new List<double>();
        foreach (string s in line)
        {
            if (s == "") continue;
            result.Add(Convert.ToDouble(s));
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
    const string name = "C-large";

    int go(int maxheight, int maxwidth, int K)
    {
        if (K==1) return 1;
        int baseA = 1;
        int baseB = 1;
        int H = 2;
        if (maxheight == 1) return K;
        if (maxwidth == 1) return K;
        while (true)
        {
            int C1 = calc(baseA, baseB, H, maxwidth);
            int spend1 = baseA+baseB + (H-2)*2;
            if (C1 >= K) return spend1;

            if (baseA > baseB)
            {
                int C2 = calc(baseA, baseB + 1, H, maxwidth);
                int C3 = 0;
                if (H < maxheight && baseA > 1)
                {
                    C3 = calc(baseA - 1, baseB, H + 1, maxwidth);
                }
                if (C2 < C3) { baseB += 1; continue; }
                else { baseA -= 1; H += 1; continue; }
            }
            else
            {
                int C4 = 0;
                if (baseA<maxwidth)
                {
                    C4 = calc(baseA+1, baseB, H, maxwidth);
                }
                int C5 = 0;
                if (baseB>1 && H<maxheight)
                {
                    C5 = calc(baseA, baseB-1, H+1, maxwidth);
                }
                if (C4 == 0 && C5 == 0) return -1; // impossible
                if (C4 > C5) { baseA += 1; continue; }
                else { baseB -= 1; H += 1; continue; }
            }

        }

    }
    int calc(int baseA, int baseB, int H, int maxwidth)
    {
        int vol = baseA + baseB;
        for (int i = 0; i < H-2; i++)
        {
            if (baseA < baseB) { baseA = Math.Min(baseA+2, maxwidth); vol += baseA; }
            else { baseB = Math.Min(baseB+2, maxwidth); vol += baseB; }
        }
        return vol;
    }
    void Solve()
    {
        //int N = ReadLine_int();
        List<int> line = SplitLine_int();
        int N = line[0];
        int M = line[1];
        int K = line[2];

        if (N == 1 || M == 1)
        {
            WriteLine("Case #{0}: {1}", cas, K);
            return;
        }

        int best = 1000000;
        if (N >= K || M >= K) best = K;

        for (int H = 1; H <= M; H++)
        {
            if (H==1)
            {
                if (N>=K) best = K;
                continue;
            }
            for (int A = 1; A <= N; A++)
            {
                int spend1 = A + A + 2 * (H - 2);
                if (spend1 < best)
                {
                    int vol1 = calc(A, A, H, N);
                    if (vol1 >= K) best = spend1;
                }
                int spend2 = A + A + 1 + 2 * (H - 2);
                if (spend2 < best)
                {
                    int vol2 = calc(A + 1, A, H, N);
                    if (vol2 >= K) best = spend2;
                }
            }
        }

        WriteLine("Case #{0}: {1}", cas, best);
    }


}

