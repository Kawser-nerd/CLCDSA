using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var sum = new long[num+1];
        sum[0] = 0;
        var dic = new Dictionary<long, long> { [0] = 1 };
        for(var i = 1; i <= num; i++)
        {
            sum[i] = sum[i - 1] + ar[i-1];
            if (dic.ContainsKey(sum[i])) dic[sum[i]]++;
            else dic[sum[i]] = 1;
        }
        var result = 0L;
        foreach(var d in dic.Values)
        {
            result += Calculation.Combination(d, 2);
        }
        WriteLine(result);
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}

public class Calculation
{
  
    public static long Combination(long num1, long num2)
    {
        if (num1 < num2) return 0;
        var p1 = num1;
        var p2 = num2;
        for (long i = 1; i < num2; i++)
        {
            p1 *= num1 - i;
            p2 *= num2 - i;
        }
        return p1 / p2;
    }
}