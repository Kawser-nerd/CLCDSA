#region Template code
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Globalization;

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
        Console.In.ReadLine();
    }
    int cas = -1;
}
#endregion

partial class Solution
{
    const string name = "C-small-attempt0";

    void Solve()
    {
        SplitLine();

        int M = GetInt(), N = GetInt();
        string[] map = new string[M];

        for (int i = 0; i < M; i++)
        {
            map[i] = ReadLine();
        }
        int[] DP = new int[1024];
        int[] DP2 = new int[1024];
        for (int row = 0; row < M; row++)
        {
            for (int mask = 0; mask < 1024; mask++)
            {
                int val = 0;
                if ((mask & (mask << 1)) != 0) goto bad;
                for (int col = 0; col < N; col++)
                {
                    if ((mask & (1 << col)) != 0 && map[row][col] != '.') goto bad;
                    if ((mask & (1 << col)) != 0) val += 1;
                }
                int best = 0;
                for (int mask2 = 0; mask2 < 1024; mask2++)
                {
                    if ((mask & (mask2 << 1)) != 0 || ((mask << 1) & (mask2)) != 0) continue;
                    int b = val + DP[mask2];
                    if (b > best) best = b;
                }
                DP2[mask] = best;

            bad: ;
            }
            DP = DP2;
            DP2 = new int[1024];
        }

        int best2 = 0;
        for (int i = 0; i < 1024; i++)
        {
            if (DP[i] > best2) best2 = DP[i];
        }
        WriteLine("Case #{0}: {1}", cas, best2);
    }


}

