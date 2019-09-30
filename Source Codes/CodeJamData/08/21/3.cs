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

    protected int[] SplitLine_int()
    {
        index = 0;
        line = input.ReadLine().Split();

        List<int> result = new List<int>();
        foreach (string s in line)
        {
            result.Add(Convert.ToInt32(s));
        }
        return result.ToArray();
    }

    protected string GetString()
    {
        return line[index++];
    }

    protected int GetInt()
    {
        return Convert.ToInt32(line[index++]);
    }

    protected double GetDouble()
    {
        return Convert.ToDouble(line[index++], CultureInfo.InvariantCulture);
    }

    protected void Write(string s)
    {
        output.Write(s);
    }

    protected void Write(string format, params object[] ss)
    {
        output.Write(format, ss);
    }

    protected void WriteLine()
    {
        output.WriteLine();
    }

    protected void WriteLine(string s)
    {
        output.WriteLine(s);
    }

    protected void WriteLine(string format, params object[] ss)
    {
        output.WriteLine(format, ss);
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
        // n, A, B, C, D, x0, y0 and M
        SplitLine();
        long n = GetInt();
        long A = GetInt();
        long B = GetInt();
        long C = GetInt();
        long D = GetInt();
        long x0 = GetInt();
        long y0 = GetInt();
        long M = GetInt();
        long[,] count = new long[3, 3];
        long x = x0;
        long y = y0;
        for (int i = 0; i < n; i++)
        {
            count[(int)(x % 3), (int)(y % 3)] += 1;
            x = (A * x + B) % M;
            y = (C * y + D) % M;
        }
        long result = 0;
        for (int x1 = 0; x1 < 3; x1++)
        {
            for (int y1 = 0; y1 < 3; y1++)
            {
                int p1 = 3 * x1 + y1;
                for (int x2 = 0; x2 < 3; x2++)
                {
                    for (int y2 = 0; y2 < 3; y2++)
                    {
                        int p2 = 3 * x2 + y2;
                        int x3 = (300 - x1 - x2) % 3;
                        int y3 = (300 - y1 - y2) % 3;
                        int p3 = 3 * x3 + y3;
                        if (p1 == p2 && p1 == p3)
                        {
                            long co = count[x1, y1];
                            result += co * (co - 1) * (co - 2);
                        }
                        else if (p1 == p2)
                        {
                            long C1 = count[x1, y1];
                            long C2 = count[x3, y3];
                            result += C1 * (C1 - 1) * C2;
                        }
                        else if (p1 == p3 || p2 == p3)
                        {
                            long C1 = count[x1, y1];
                            long C2 = count[x2, y2];
                            result += C1 * (C1 - 1) * C2;
                        }
                        else
                        {
                            result += count[x1, y1] * count[x2, y2] * count[x3, y3];
                        }
                    }
                }
            }
        }

        WriteLine("Case #{0}: {1}", cas, result/6);
    }


}

