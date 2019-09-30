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
        var line = Scanner.StringList;
        int N = line[0].Int();
        int M = line[1].Int();

        List<City>[] prefectures = new List<City>[N + 1];

        for (int i = 0; i < prefectures.Length; i++)
        {
            prefectures[i] = new List<City>();
        }

        City[] cities = new City[M];
        foreach(int i in Enumerable.Range(0, M))
        {
            line = Scanner.StringList;
            int prefecture = line[0].Int();
            long year = line[1].Int();

            City city = new City(year, prefecture);
            cities[i] = city;
            prefectures[prefecture].Add(city);
        }

        foreach(List<City> prefecture in prefectures)
        {
            int num = 0;
            foreach(City city in prefecture.OrderBy(i => i.year))
            {
                num++;
                city.year = num;
            }
        }

        foreach(City city in cities)
        {
            Console.WriteLine(city);
        }

        Console.ReadLine();
    }

    public class City
    {
        public long year;
        public int prefecture;

        public City(long year, int prefecture)
        {
            this.year = year;
            this.prefecture = prefecture;
        }

        public override string ToString()
        {
            return prefecture.ToString("000000") + year.ToString("000000");
        }
    }
}

/// <summary>
/// ????
/// </summary>
public class Scanner
{
    public static long Long
    {
        get
        {
            return Console.ReadLine().Long();
        }
    }

    public static int Int
    {
        get
        {
            return Console.ReadLine().Int();
        }
    }

    public static string String
    {
        get
        {
            return Console.ReadLine();
        }
    }

    public static string[] StringList
    {
        get
        {
            return Console.ReadLine().Split();
        }
    }

    public static IEnumerable<int> IntList
    {
        get
        {
            return StringList.Select(int.Parse);
        }
    }

    public static IEnumerable<long> LongList
    {
        get
        {
            return StringList.Select(long.Parse);
        }
    }

    public static IEnumerable<double> DoubleList
    {
        get
        {
            return StringList.Select(double.Parse);
        }
    }
}

/// <summary>
/// Linq??
/// </summary>
public static class LinqExtension
{
    /// <summary>
    /// ????
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="self"></param>
    /// <param name="solve"></param>
    /// <param name="min"></param>
    /// <param name="max"></param>
    /// <returns></returns>
    public static T LeftBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve, T min, T max)
    {
        int index = self.LeftBinarySearchIndex(solve);

        return self.Get(index, min, max);
    }

    /// <summary>
    /// ????
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="self"></param>
    /// <param name="solve"></param>
    /// <param name="min"></param>
    /// <param name="max"></param>
    /// <returns></returns>
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
    /// <summary>
    /// ??
    /// </summary>
    /// <param name="self"></param>
    /// <returns></returns>
    public static long Factorial(this int self)
    {
        return self * self.Factorial();
    }

    /// <summary>
    /// ??
    /// </summary>
    /// <param name="self"></param>
    /// <returns></returns>
    public static long Factorial(this int self, int c)
    {
        if (c == 0 || self == 0) return 1L;
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