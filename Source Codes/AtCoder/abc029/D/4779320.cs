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
        var num = ReadLine();
        var dp = new long[num.Length + 1, 11, 2];
        dp[0, 0, 0] = 1;
        for(var i=1;i<=num.Length;i++)
            for(var j=0;j<10;j++)
                for(var k = 0; k < 2; k++)
                {
                    var val = k == 0 ? num[i - 1] - '0' + 1 : 10;
                    for (var h = 0; h < val; h++)
                        if (h == 1)
                            dp[i, j + 1, ToInt32(k == 1 || h < val - 1)] += dp[i-1, j, k];
                        else dp[i, j, ToInt32(k == 1 || h < val-1)] += dp[i-1, j, k];
                }
        var sum = 0L;
        for (var i = 0; i < 11; i++)
            sum += (dp[num.Length, i, 0] + dp[num.Length, i, 1]) * i;
        WriteLine(sum);

    }
}