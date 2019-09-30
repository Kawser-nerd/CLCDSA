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
    const string name = "B-large";

    void Solve()
    {
        int N = ReadLine_int();

        string[] ss = SplitLine();

        //int[] begincount = new int[26];
        //int[] endcount = new int[26];
        int[] middlecount = new int[26];
        int[] allsamecount = new int[26];
        string[] beginindex = new string[26];
        string[] endindex = new string[26];

        bool impossible = false;
        foreach (string s in ss)
        {
            char begin = s[0];
            char end = s.Last();

            if (s.All(cc => cc == begin))
            {
                allsamecount[begin - 'a'] += 1;
                continue;
            }

            if (beginindex[begin - 'a'] != null) { impossible = true; break; }
            if (endindex[end - 'a'] != null) { impossible = true; break; }

            beginindex[begin - 'a'] = s;
            endindex[end - 'a'] = s;
            {
                string s2 = s;
                while (s2[0] == begin) s2 = s2.Substring(1);
                while (s2!="" && s2.Last() == end) s2 = s2.Substring(0, s2.Length - 1);
                for (int i = 0; i < s2.Length; i++)
                {
                    if (i > 0 && s2[i - 1] == s2[i]) continue;
                    if (middlecount[s2[i] - 'a'] > 0) { impossible = true; break; }
                    middlecount[s2[i] - 'a'] += 1;
                }
            }
        }
        if (impossible)
        {
            WriteLine("Case #{0}: {1}", cas, 0);
            return;
        }
        long result = 1;
        for (int i = 0; i < 26; i++)
        {
            if ((beginindex[i] != null || endindex[i] != null || allsamecount[i]>0) && middlecount[i] > 0) {impossible = true; break;}
        }
        if (impossible)
        {
            WriteLine("Case #{0}: {1}", cas, 0);
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            string s = beginindex[i];
            if (s == null) continue;
            if (s.Last() - 'a' == i) { impossible = true; break; } // cycle
            result *= fact(allsamecount[s.Last() - 'a']); allsamecount[s.Last() - 'a'] = 0;
            result = result % 1000000007;
            result *= fact(allsamecount[s.First() - 'a']); allsamecount[s.First() - 'a'] = 0;
            result = result % 1000000007;
            string other = beginindex[s.Last() - 'a'];
            if (other != null)
            {
                string newstring = s+other;
                beginindex[i] = newstring;
                beginindex[s.Last() - 'a'] = null;
                endindex[s.Last()-'a'] = null;
                endindex[other.Last() - 'a'] = newstring;
                i -= 1; // To repeat loop with the new string
            }
        }
        if (impossible)
        {
            WriteLine("Case #{0}: {1}", cas, 0);
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            result *= fact(allsamecount[i]);
            result = result % 1000000007;
        }
        int groupcount = beginindex.Sum(s => s != null ? 1 : 0) + allsamecount.Sum(x => x>0 ? 1 : 0);
        result *= fact(groupcount);
        result = result % 1000000007;
        WriteLine("Case #{0}: {1}", cas, result);
    }
    long fact(int n)
    {
        if (n <= 0) return 1;
        long res = 1;
        for (int i = n; i >= 1; i--)
        {
            res *= i;
            res = res % 1000000007;

        }
        return res;

    }


}

