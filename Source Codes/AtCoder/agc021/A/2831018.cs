using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var N = long.Parse(ReadLine());
        if (N<10)
        {
            WriteLine(N);
            return;
        }
        long max = CalcDigitSum(N);
        long tmp = 10;
        while (tmp <= N)
        {
            var val = CalcDigitSum(N - (N % tmp + 1));//n > m*10^p -1???????m*10^p - 1??
            if (val > max) max = val;
            tmp *= 10;
        }
        WriteLine(max);
    }
    static long CalcDigitSum(long num)
    {
        long res = 0;
        foreach (var item in num.ToString())
        {
            res += long.Parse(item.ToString());
        }
        return res;
    }
}