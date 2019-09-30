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
        var nm = Add.ar;
        var res = Enumerable.Repeat(1, nm[0]).ToArray();
        var set = new HashSet<int> { 0 };
        for(var i = 0; i < nm[1]; i++)
        {
            var input = Add.ar;
            res[input[0] - 1]--;
            res[input[1] - 1]++;
            if (set.Contains(input[0] - 1))
                set.Add(input[1] - 1);
            if (res[input[0] - 1] == 0) set.Remove(input[0] - 1);
        }
        WriteLine(set.Count());
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