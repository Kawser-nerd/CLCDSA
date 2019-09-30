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
        HandleCases("C-large");
    }

    protected override void HandleCase()
    {
        int N = ReadLine_int();
        int[] x = new int[N];
        int[] y = new int[N];
        int[] z = new int[N];
        int[] p = new int[N];
        
        for (int i = 0; i < N; i++)
        {
            SplitLine();
            x[i] = GetInt();
            y[i] = GetInt();
            z[i] = GetInt();
            p[i] = GetInt();

        }

        double xx = 500000, yy = 500000, zz = 500000;
        double delta = 500000;
        int maxindex = -1; double maxdist = -1;
        while (delta > 1e-13)
        {
            maxindex = -1; 
            maxdist = 0;
            for (int i = 0; i < N; i++)
            {
                double dist = (Math.Abs(xx - x[i]) + Math.Abs(yy - y[i]) + Math.Abs(zz - z[i])) / p[i];
                if (dist > maxdist) { maxdist = dist; maxindex = i; }
            }
            if (x[maxindex] > xx) xx += delta;
            else xx -= delta;

            if (y[maxindex] > yy) yy += delta;
            else yy -= delta;

            if (z[maxindex] > zz) zz += delta;
            else zz -= delta;

            delta *= .7;
        }

        WriteLine("Case #{0}: {1}", cas, maxdist);
    }


}

