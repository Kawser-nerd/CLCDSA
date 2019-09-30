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
        int[] line = Console.ReadLine().Split(' ').Select(i => int.Parse(i)).ToArray();
        int A = line[0], B = line[1], Q = line[2];

        long[] s = Enumerable.Range(0, A).Select(i => Console.ReadLine().Long()).ToArray();
        long[] t = Enumerable.Range(0, B).Select(i => Console.ReadLine().Long()).ToArray();

        long max = (long)Math.Pow(10, 11);

        foreach (int i in Enumerable.Range(0, Q))
        {
            long ans = long.MaxValue;
            long x = Console.ReadLine().Long();

            int a = s.LeftBinarySearchIndex(v => (v >= x));
            int b = t.LeftBinarySearchIndex(v => (v >= x));

            foreach (long S in Enumerable.Range(a - 1, 2).Select(v => s.Get(v, -max, max)))
            {
                foreach (long T in Enumerable.Range(b - 1, 2).Select(v => t.Get(v, -max, max)))
                {
                    long d1 = Math.Abs(S - x) + Math.Abs(T - S);
                    long d2 = Math.Abs(T - x) + Math.Abs(S - T);

                    ans = new long[]{ d1, d2, ans}.Min();
                }
            }
            Console.WriteLine(ans);
        }

        Console.ReadLine();
    }
}

/// <summary>
/// Linq??
/// </summary>
public static class LinqExtension
{
    public static T LeftBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve, T min, T max)
    {
        int index = self.LeftBinarySearchIndex(solve);

        return self.Get(index, min, max);
    }
    public static T RightBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve, T min, T max)
    {
        int index = self.RightBinarySearchIndex(solve);

        return self.Get(index, min, max);
    }

    /// <summary>
    /// OutOfRange??
    /// </summary>
    /// <typeparam name="T">?T</typeparam>
    /// <param name="self">IEnumerable</param>
    /// <param name="index">?????????</param>
    /// <param name="min">0???????????</param>
    /// <param name="max">??????????</param>
    /// <returns>?T??</returns>
    public static T Get<T>(this IEnumerable<T> self, int index, T min, T max)
    {
        if (index < 0) return min;
        if (index >= self.Count()) return max;

        return self.ElementAt(index);
    }

    /// <summary>
    /// <para>????</para>
    /// <para>????????????????????????????(??????????)</para>
    /// </summary>
    /// <typeparam name="T">IEnumerable</typeparam>
    /// <param name="solve"></param>
    /// <returns>???????????</returns>
    public static int LeftBinarySearchIndex<T>(this IEnumerable<T> self, Func<T, bool> solve)
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
    public static int RightBinarySearchIndex<T>(this IEnumerable<T> self, Func<T, bool> solve)
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

    /// <summary>
    /// ???????
    /// </summary>
    /// <typeparam name="T">?T</typeparam>
    /// <param name="self">???</param>
    /// <param name="func">(index) => T</param>
    /// <returns>??????</returns>
    public static IList<T> Fill<T>(this IList<T> self, Func<int, T> func)
    {
        for (int i = 0; i < self.Count; i++)
        {
            self[i] = func(i);
        }

        return self;
    }

    /// <summary>
    /// ???????
    /// </summary>
    /// <typeparam name="T">?T</typeparam>
    /// <param name="self">???</param>
    /// <param name="value">?T??</param>
    /// <returns>??????</returns>
    public static IList<T> Fill<T>(this IList<T> self, T value)
    {
        for (int i = 0; i < self.Count; i++)
        {
            self[i] = value;
        }

        return self;
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