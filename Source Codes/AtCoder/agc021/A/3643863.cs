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
        var num = ToInt64(ReadLine());
        var dig = num.ToString().Length;
        var max = (dig - 1) * 9 + (ToInt32(num.ToString().Substring(0, 1)) - 1);
        for(var i = 0; i <= 10; i++)
        {
            var s = num.ToString();
            var sum = 0;
            for(var j=0; j < s.Length; j++)
            {
                sum += ToInt32(s.Substring(j, 1));
            }
            max = Max(max, sum);
            num--;
            if (num == 0) break;
        }
        WriteLine(max);
    }
}