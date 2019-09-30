using System;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);var dp = new int[num];
        dp[0] = 0;dp[1] = Abs(ar[1] - ar[0]);
        for(var i = 2; i < num; i++)
            dp[i] = Min(dp[i - 1] + Abs(ar[i] - ar[i - 1]), dp[i - 2] + Abs(ar[i] - ar[i - 2]));
        WriteLine(dp[num-1]);
    }
}