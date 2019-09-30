using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using Debug;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var ab = ReadLine().Split(' ');
        var a = (ToInt64(ab[0]) - 1).ToString();
        WriteLine(ct(ab[1]) - ct(a));
    }
    private static long ct(string str)
    {
        var dp = new long[str.Length + 1, 2, 2];
        dp[0, 0, 0] = 1;//??????str.length+1???0??.
        for (var i = 1; i <= str.Length; i++)
            for (var j = 0; j < 2; j++)
                for (var k = 0; k < 2; k++)
                {
                    var val = j == 0 ? str[i - 1] - '0' + 1 : 10;
                    for (var n = 0; n < val; n++)
                        dp[i, ToInt32(j == 1 || n < val - 1), ToInt32(k == 1 || n == 4 || n == 9)] += dp[i - 1, j, k];
                }
        return dp[str.Length, 0, 1] + dp[str.Length, 1, 1];
    }
}