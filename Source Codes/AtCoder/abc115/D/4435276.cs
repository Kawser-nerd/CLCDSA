using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

public class Program
{
    public static void Main(string[] args)
    {
        string[] line = Console.ReadLine().Split(' ');

        int n = line[0].Int();
        long x = line[1].Long();

        long[] a = new long[51]; a[0] = 1;
        foreach (int i in Enumerable.Range(0, 50))
        {
            a[i + 1] = (a[i] * 2) + 3;
        }

        long[] b = new long[51]; b[0] = 1;
        foreach(int i in Enumerable.Range(0, 50))
        {
            b[i + 1] = (b[i] * 2) + 1;
        }


        Func<int, long, long> solve = null;
        solve = (i, j) =>
        {
            //  BBPPPBPBPPPBB

            //  ------|----BB
            if (1 >= j)
            {
                return 0;
            }
            //  ------|-PPPBB
            else if (a[i - 1] > j)
            {
                return solve(i - 1, j - 1);
            }
            //  ------BBPPPBB
            else if (a[i - 1] + 1 >= j)
            {
                return b[i - 1];
            }
            //  --PPPB|BPPPBB
            else if ((a[i - 1] * 2) + 1 >= j)
            {
                return solve(i - 1, j - a[i - 1] - 2) + 1 + b[i - 1];
            }
            //  BBPPPB|BPPPBB
            else
            {
                return b[i - 1] + 1 + b[i - 1];
            }
        };

        Console.WriteLine(solve(n, x));
        Console.ReadLine();
    }
}

/// <summary>
/// Linq??
/// </summary>
public static class LinqExtension
{
    /// <summary>
    /// <para>????</para>
    /// <para>????????????????????????????(??????????)</para>
    /// </summary>
    /// <typeparam name="T">IEnumerable</typeparam>
    /// <param name="solve"></param>
    /// <returns>???????????</returns>
    public static int LeftBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve)
    {
        int ng = -1;
        int ok = self.Count();

        while(Math.Abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;

            if (solve(self.ElementAt(mid)))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        return ok;
    }

    /// <summary>
    /// <para>????</para>
    /// <para>????????????????????????????(??????????)</para>
    /// </summary>
    /// <typeparam name="T">IEnumerable</typeparam>
    /// <param name="solve"></param>
    /// <returns>???????????</returns>
    public static int RightBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve)
    {
        int ng = self.Count();
        int ok = -1;

        while (Math.Abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;

            if (solve(self.ElementAt(mid)))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        return ok;
    }
}

/// <summary>
/// Int??
/// </summary>
public static class IntExtensiton
{
    public static int BitCount(this int bit, int digit = 32)
    {
        int count = 0;
        for (int i = (digit - 1); i >= 0; i--)
        {
            if (bit.GetBit(i)) count++;
        }
        return count;
    }

    public static bool GetBit(this int bit, int digit)
    {
        int mask = (1 << digit);
        return (bit & mask) == mask;
    }

    public static int SetBit(this int bit, int digit)
    {
        return (bit | (1 << digit));
    }

    public static string BitToString(this int bit, int digit = 32)
    {
        StringBuilder sb = new StringBuilder();

        for(int i = (digit - 1); i >= 0; i--)
        {
            sb.Append(bit.GetBit(i) ? "1" : "0");
        }

        return sb.ToString();
    }

    public static IEnumerable<int> Range(this int range)
    {
        return Enumerable.Range(0, range);
    }
}

/// <summary>
/// String??
/// </summary>
public static class StringExtensiton
{
    public static int Int(this string str)
    {
        return int.Parse(str);
    }

    public static long Long(this string str)
    {
        return long.Parse(str);
    }

    public static double Double(this string str)
    {
        return double.Parse(str);
    }
}