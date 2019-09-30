using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var nk = Input.ar;
        var row = Input.arL;
        var col = Input.arL;
        Array.Sort(row);
        Array.Sort(col);
        var left = 0L;
        var right = row.Max()*col.Max();
        while (right > left)
        {
            var mid = (right + left) / 2;
            var ct = 0;
            for (var i = 0; i < nk[0]; i++)
                ct += Search.UpperBound(col, mid / row[i]);
            if (ct >= nk[1]) right = mid;
            else left = mid + 1;
        }
        WriteLine(left);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class Search
{
    public static int UpperBound<T>(T[] array,T value)
        where T:IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) == 1) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static int LowerBound<T>(T[] array,T value)
        where T : IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) != -1) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}