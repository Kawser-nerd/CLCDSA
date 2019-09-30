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
        HandleCases("C-small-attempt1");
    }

    protected override void HandleCase()
    {

        int K = ReadLine_int();
        SplitLine();
        int n = GetInt();
        int[] indexes = new int[n];
        for (int i = 0; i < n; i++)
        {
            indexes[i] = GetInt();
        }

        int[] A = new int[K];
        int[] B = new int[K];
        int count = 0;
        for (int card = K; card >=1; card-=1)
        {
            count += 1;
            int pos = (card - 1) % count;
            B[pos] = card;
            Array.Copy(A, 0, B, pos+1, count-pos-1);
            Array.Copy(A, count-pos-1, B, 0, pos);
            int[] temp = A; A = B; B = temp;
        }
        List<string> result2 = new List<string>();
        foreach (int index in indexes)
        {
            result2.Add(A[index - 1].ToString());
        }

        WriteLine("Case #{0}: {1}", cas, String.Join(" ", result2.ToArray()));
    }


}

