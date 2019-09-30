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
        var card = Enumerable.Repeat(0, num).Select(v => Input.num).ToArray();
        var list = new List<int> { card[0] };
        for(var i = 1; i < num; i++)
        {
            if (list[list.Count - 1] < card[i])
                list.Add(card[i]);
            else list[Get(card[i], list)] = card[i];
        }
        WriteLine(num - list.Count);
    }
    private static int Get(int num,List<int> list)
    {
        if (num < list[0]) return 0;
        var right = list.Count;
        var left = 0;
        while (right > left)
        {
            var mid = (right + left) / 2;
            if (list[mid] < num) left = mid + 1;
            else right = mid;
        }
        return left;
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