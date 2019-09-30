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
    const string name = "D-small-attempt0";

    void Solve()
    {
        SplitLine();
        int H = GetInt(), W=GetInt(), R = GetInt();

        int[,] map = new int[H + 10, W + 10];

        for (int i = 0; i < R; i++)
        {
            SplitLine();
            int r = GetInt(), c = GetInt();
            map[r, c] = 1;
        }
        int[,] DP = new int[H + 10, W + 10];
        DP[1, 1] = 1;
        for (int r = 1; r < H; r++)
        {
            for (int c = 1; c < W; c++)
            {
                int count = DP[r, c];
                if (map[r + 1, c + 2] == 0) { DP[r + 1, c + 2] = (DP[r + 1, c + 2] + count) % 10007; }
                if (map[r + 2, c + 1] == 0) { DP[r + 2, c + 1] = (DP[r + 2, c + 1] + count) % 10007; }
            }
            
        }
        WriteLine("Case #{0}: {1}", cas, DP[H,W]);
    }


}

