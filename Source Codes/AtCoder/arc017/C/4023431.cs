#pragma warning disable

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;
using System.Collections;

static class MainClass
{
    public static void Main(string[] args)
    {
        var NX = Console.ReadLine().SplittedStringToInt32List();
        var N = NX[0];
        var X = NX[1];
        if (N == 1)
        {
            Console.WriteLine(Console.ReadLine().ToInt32() == X ? 1 : 0);
            return;
        }
        var nibunn = N / 2;
        var firstls = new List<int>();
        var nubunsec = N - (N / 2);
        var firstssum = new List<int>();
        
        var firstsbits = CreateBits(nibunn);
        var secondbits = CreateBits(nubunsec);

        var secsum = new List<int>();
        var secls = new List<int>();
        

        for (int i = 0; i < nibunn; i++)
        {
            var str = Console.ReadLine().ToInt32();
            firstls.Add(str);
        }
        foreach (var item in firstsbits)
        {
            var num = 0;
            var len = item.Count;
            for (int i = 0; i < len; i++)
            {
                if (item[i])
                    num += firstls[i];
            }
            firstssum.Add(num);
        }

        for (int i = 0; i < nubunsec; i++)
        {
            var str = Console.ReadLine().ToInt32();
            secls.Add(str);
        }

        foreach (var item in secondbits)
        {
            var num = 0;
            var len = item.Count;
            for (int i = 0; i < len; i++)
            {
                if (item[i])
                    num += secls[i];
            }
            secsum.Add(num);
        }
        var count = 0;

        secsum.Sort();
        var length = firstssum.Count;
        for (int i = 0; i < length; i++)
        {
            var num1 = firstssum[i];
            var diffw = X - num1;
            if (diffw < 0)
                continue;
            if (diffw == 0)
            {
                count++;
                continue;
            }

            var ind1 = secsum.UpperBound(diffw);
            var ind2 = secsum.LowerBound(diffw);
            if (ind1 >= 0 && ind2 >= 0)
                count += (- ind2 + ind1);


        }
        Console.WriteLine(count);

        Console.ReadLine();
    }


    public static int LowerBound<T>(this List<T> ar, int start, int end, T value, IComparer<T> comparer)
    {
        //var arr = ar.ToArray();
        int low = start;
        int high = end;
        int mid;
        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (comparer.Compare(ar[mid], value) < 0)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    public static int LowerBound<T>(this List<T> arr, T value) where T : IComparable
    {
        return LowerBound(arr, 0, arr.Count(), value, Comparer<T>.Default);
    }

    public static int UpperBound<T>(this List<T> ar, int start, int end, T value, IComparer<T> comparer)
    {
       // var arr = ar.ToArray();
        int low = start;
        int high = end;
        int mid;
        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (comparer.Compare(ar[mid], value) <= 0)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    public static int UpperBound<T>(this List<T> arr, T value)
    {
        return UpperBound(arr, 0, arr.Count(), value, Comparer<T>.Default);
    }


    public static List<List<bool>> CreateBits(int len)
    {
        return CreateBitsPri(new List<List<bool>>(), len, 0);
    }

    private static List<List<bool>> CreateBitsPri(List<List<bool>> bits, int len, int count)
    {
        if (count == 0)
        {
            var lss = new List<bool>();
            lss.Add(true);
            bits.Add(lss);
            var lx = new List<bool>();
            lx.Add(false);
            bits.Add(lx);
            count++;
            return CreateBitsPri(bits, len, count);
        }
        if (len - count == 0)
            return bits;
        count++;
        var ls = new List<List<bool>>();
        foreach (var item in bits)
        {
            var x = item.ToList();
            x.Add(true);
            item.Add(false);
            ls.Add(item);
            ls.Add(x);
        }
        return CreateBitsPri(ls, len, count);
    }

    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<long> SplittedStringToInt64List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => long.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    public const int INF = int.MaxValue / 2;
    public const long LONGINF = long.MaxValue / 2;

    public static int Max(params int[] values)
    {
        var maxes = -1;
        for (int i = 0; i < values.Length; i++)
        {
            maxes = Math.Max(values[i], maxes);
        }
        return maxes;
    }

    public static void PrintArray(int[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j]).Append(" ");
            }
            Console.WriteLine(sb.ToString());
        }
    }
    // public static int[]

    #endregion
}