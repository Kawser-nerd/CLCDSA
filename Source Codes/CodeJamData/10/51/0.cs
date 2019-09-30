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

partial class Solution
{
    bool isprime(int p)
    {
        for (int n = 2; n * n <= p; n++)
        {
            if (p % n == 0) return false;
        }
        return true;
    }


    const string name = "A-small-attempt1";

    int D10;
    List<int> nums;
    bool ambiguous;

    void Solve()
    {
        ambiguous = false;
        SplitLine();
        int D = GetInt();
        D10 = 1; for (int i = 0; i < D; i++) D10 *= 10;
        int K = GetInt();

        nums = SplitLine_int();
        if (nums.Count==1)
        {
            WriteLine("Case #{0}: {1}", cas, "I don't know.");
            return;
        }
        int index = nums.IndexOf(nums.Last());
        if (index<nums.Count-1)
        {
            WriteLine("Case #{0}: {1}", cas, nums[index+1]);
            return;
        }

        int? result = null;
        for (int P = nums.Max()+1; P <= D10; P++)
        {
            if (!isprime(P)) continue;
            for (int A = 0; A < P; A++)
            {
                int B = nums[1] - nums[0] * A;
                while (B < 0) B += ((-B)/P+1)*P;
                B %= P;
                for (int i = 2; i < nums.Count; i++)
                {
                    if (nums[i] != (A * nums[i - 1] + B) % P) goto bad;
                }
                int result2 = (nums.Last() * A + B) % P;
                if (result.HasValue && result != result2) { ambiguous = true; goto done; }
                result = result2;
            bad: ;
            }
        }

        done:
        if (ambiguous || !result.HasValue)
            WriteLine("Case #{0}: {1}", cas, "I don't know.");
        else
            WriteLine("Case #{0}: {1}", cas, result.Value);
    }


}

