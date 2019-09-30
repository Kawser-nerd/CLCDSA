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
        var num = Input.num;
        var hw = Input.twodim(num);
        hw = hw.OrderBy(v => v[1]).ThenByDescending(v => v[0]).ToArray();
        var wid = new List<int>{ hw[0][1] }; 
        var hei = new List<int> { hw[0][0] };
        for (var i = 1; i < num; i++)
            if (hei[hei.Count - 1] < hw[i][0] && wid[wid.Count - 1] < hw[i][1])
            {
                wid.Add(hw[i][1]);
                hei.Add(hw[i][0]);
            }
            else
            {
                var index = Search.LowerBound(hei.ToArray(), hw[i][0]);
                hei[index] = hw[i][0];
            }
        WriteLine(hei.Count);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
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