using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

public class Program
{
    // public static readonly int Mod = 1000000007;

    public static void Main(string[] args)
    {
        int A = Scanner.Int;
        int B = Scanner.Int;
        int poison = Scanner.Int;

        int ans = Math.Min(A, poison);

        poison = Math.Max(0, poison - A);

        ans += B + Math.Min(poison, B);

        poison = Math.Max(0, poison - B);

        Console.WriteLine(ans + Math.Min(1, poison));
        Console.ReadLine();
    }

}

/// <summary>
/// ????
/// </summary>
public class Scanner
{
    private static IEnumerator<string> enumerator = Enumerator();
    private static IEnumerator<string> Enumerator()
    {
        while(true)
        {
            foreach (string s in Console.ReadLine().Split(' '))
            {
                yield return s;
            }
        }
    }

    public static string String
    {
        get
        {
            return enumerator.Next();
        }
    }
    public static int Int
    {
        get
        {
            return String.Int();
        }
    }
    public static long Long
    {
        get
        {
            return String.Long();
        }
    }
    public static double Double
    {
        get
        {
            return String.Double();
        }
    }
}

/// <summary>
/// Linq??
/// </summary>
public static class LinqExtension
{
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

    public static T Next<T>(this IEnumerator<T> self)
    {
        self.MoveNext();
        return self.Current;
    }
}

/// <summary>
/// Int??
/// </summary>
public static class IntExtensiton
{
    /// <summary>
    /// ??
    /// </summary>
    /// <param name="self"></param>
    /// <returns></returns>
    public static long Factorial(this int self)
    {
        if (self == 1) return 1L;
        return self * self.Factorial();
    }

    /// <summary>
    /// ??
    /// </summary>
    /// <param name="self"></param>
    /// <returns></returns>
    public static long Factorial(this int self, int c)
    {
        if (c == 0 || self == 1) return 1L;
        return self * Factorial(self - 1, c - 1);
    }

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

        for (int i = (digit - 1); i >= 0; i--)
        {
            sb.Append(bit.GetBit(i) ? "1" : "0");
        }

        return sb.ToString();
    }

    public static bool IsDivisor(this int self, int target)
    {
        return self % target == 0;
    }

    public static bool NeighboringBit(this int self, int digit = 32)
    {
        if (digit < 2) return false;
        return Enumerable.Range(0, digit - 1).Where(j => self.GetBit(j) && self.GetBit(j + 1)).Any();
    }
}

/// <summary>
/// Long??
/// </summary>
public static class LongExtensition
{
    public static long BitCount(this long bit, int digit = 64)
    {
        long count = 0;
        for (int i = (digit - 1); i >= 0; i--)
        {
            if (bit.GetBit(i)) count++;
        }
        return count;
    }

    public static bool GetBit(this long bit, int digit)
    {
        long mask = (1L << digit);
        return (bit & mask) == mask;
    }

    public static long SetBit(this long bit, int digit)
    {
        return bit | (1L << digit);
    }

    public static string BitToString(this long bit, int digit = 64)
    {
        StringBuilder sb = new StringBuilder();

        for (int i = (digit - 1); i >= 0; i--)
        {
            sb.Append(bit.GetBit(i) ? "1" : "0");
        }

        return sb.ToString();
    }

    public static bool IsDivisor(this long self, int target)
    {
        return self % target == 0;
    }
}

/// <summary>
/// String??
/// </summary>
public static class StringExtensiton
{
    public static void Print(this string str) => Console.WriteLine(str);
    public static int Int(this string str) => int.Parse(str);
    public static long Long(this string str) => long.Parse(str);
    public static double Double(this string str) => double.Parse(str);
}

/// <summary>
/// ????
/// </summary>
public static class F
{
    public static void ChMax<T>(ref T x, T y) where T : IComparable
    {
        if(x.CompareTo(y) < 0)
        {
            x = y;
        }
    }

    public static void ChMin<T>(ref T x, T y) where T : IComparable
    {
        if (x.CompareTo(y) > 0)
        {
            x = y;
        }
    }

    public static void Swap<T>(ref T x, ref T y)
    {
        T tmp = x;

        x = y;
        y = tmp;
    }
}