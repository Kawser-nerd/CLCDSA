// I run this in Microsoft Visual Studio, so the current directory is in ./bin/Debug relative to the source code.
// The input file is expected to be in "..\.." relative to the running executable.
//  - trebe

// ===== Begin template code =====

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
        sol.main();
    }
}

abstract class SolutionBase
{
    #region I/O
    protected TextReader input = null;
    protected TextWriter output = null;

    protected void Open(string name)
    {
        input = File.OpenText(name + ".in");
        output = File.CreateText(name + ".out");

    }
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

    protected string hex(int x)
    {
        return String.Format("{0:x}", x);
    }

    public abstract void go();
    public void main()
    {
        Environment.CurrentDirectory = Environment.CurrentDirectory + @"\..\..";
        go();

        if (input != null) input.Close();
        if (output != null) output.Close();
        Console.In.ReadLine();
    }
    protected int cas = -1;
    protected void HandleCases(string filename)
    {
        Open(filename);
        int N = ReadLine_int();
        for (cas = 1; cas <= N; cas++)
        {
            //SplitLine();
            HandleCase();
        }
    }
    protected virtual void HandleCase()
    {
        throw new Exception("Not implemented");
    }
}

// ===== End template code =====

class Solution : SolutionBase
{
    public override void go()
    {
        HandleCases("A-large");
    }

    protected override void HandleCase()
    {
        SplitLine();
        int M = GetInt();
        int V = GetInt();
        int[] changeable = new int[M];
        int[] gatekind = new int[M];
        int[] value = new int[M];
        for (int i = 0; i < (M-1)/2; i++)
        {
            SplitLine();
            gatekind[i] = GetInt();
            changeable[i] = GetInt();
        }
        for (int i = (M - 1) / 2; i < M; i++)
        {
            value[i] = ReadLine_int();
        }
        int[] DP = new int[M];
        for (int i = (M - 1) / 2; i < M; i++)
        {
            DP[i] = 1000000;
        }
        for (int i = (M - 1) / 2 - 1; i >= 0; i--)
        {
            if (gatekind[i] == 1) value[i] = (value[2 * i + 1] & value[2 * i + 2]);
            else value[i] = (value[2 * i + 1] | value[2 * i + 2]);

            bool cha = (changeable[i]==1);
            bool andgate = (gatekind[i] == 1);
            int a = value[2 * i + 1];
            int b = value[2 * i + 2];
            int DP1 = DP[2 * i + 1];
            int DP2 = DP[2 * i + 2];
            int DPmin = Math.Min(DP1, DP2);

            int result = 0;
            if (andgate)
            {
                if (a==0 && b==0 && cha) result = DPmin + 1;
                else if (a==0 && b==0 && !cha) result = DP1+DP2;
                else if (a==0 && b==1 && cha) result = 1;
                else if (a==0 && b==1 && !cha) result = DP1;
                else if (a==1 && b==0 && cha) result = 1;
                else if (a==1 && b==0 && !cha) result = DP2;
                else if (a==1 && b==1) result = DPmin;
            }
            else // ORgate
            {
                if (a==1 && b==1 && cha) result = DPmin + 1;
                else if (a==1 && b==1 && !cha) result = DP1+DP2;
                else if (a==1 && b==0 && cha) result = 1;
                else if (a==1 && b==0 && !cha) result = DP1;
                else if (a==0 && b==1 && cha) result = 1;
                else if (a==0 && b==1 && !cha) result = DP2;
                else if (a==0 && b==0) result = DPmin;
            }
            if (result>1000000) result = 1000000;
            DP[i] = result;
        }
        int res = 0;
        if (V == value[0]) res = 0;
        else res = DP[0];

        if (res<1000000)
            WriteLine("Case #{0}: {1}", cas, res);
        else
            WriteLine("Case #{0}: {1}", cas, "IMPOSSIBLE");
    }


}

