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
        var num = Add.num;
        var ar = new List<long> { int.MinValue };
        ar.AddRange(Add.arL);
        ar.Add(int.MaxValue);
        var arr=ar.OrderBy(v=>v).ToArray();
        var low = Search.LowerBound(arr, (arr[num] + 1) / 2);
        var di = Abs(arr[low] - (arr[num] + 1) / 2) < Abs(arr[low - 1] - (arr[num] + 1) / 2) ? arr[low] : arr[low - 1];
        WriteLine($"{arr[num]} {di}");
    }
}

public class Add
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