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
        HandleCases("B-large");
    }

    protected override void HandleCase()
    {
        SplitLine();
        long A = Convert.ToInt64(GetString());
        long B = Convert.ToInt64(GetString());
        long P = Convert.ToInt64(GetString());
        int n = (int)(B - A + 1);
        int[] cls = new int[n];
        for (int i = 0; i < n; i++)
        {
            cls[i] = -1;
        }
        int result = 0;
        if (P < n)
        {
            for (int p = (int)P; p < n; p++)
            {
                if (!isprime(p)) continue;
                int AA = (int)((p - (A % p)) % p);
                int c = getcls(cls, AA);
                for (int i = AA + p; i < n; i += p)
                {
                    setcls(cls, i, c);
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (cls[i] == -1) result += 1;
            }
        }
        else
        {
            result = n;
        }

        WriteLine("Case #{0}: {1}", cas, result);
    }

    private void setcls(int[] cls, int i, int c)
    {
        Debug.Assert(i != c);
        if (cls[i] == -1) { cls[i] = c; return; }
        int root = getcls(cls, i);
        if (root != c) cls[root] = c;
    }

    private int getcls(int[] cls, int i)
    {
        int result = cls[i];
        if (result == -1) return i;
        result = getcls(cls, result);
        cls[i] = result;
        return result;
    }

    bool isprime(int p)
    {
        for (int n = 2; n * n <= p; n++)
        {
            if (p % n == 0) return false;
        }
        return true;
    }

}

