using System;
using System.Linq;
using System.Collections.Generic;

class Damondai
{
    static void Main()
    {
        var ab = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        var A = ab[0];
        var B = ab[1];
        var ans = Solve(A - 1) ^ Solve(B);
        Console.WriteLine(ans);
    }
    static long Solve(long num)
    {
        if (num % 2 == 1) return Calc(num);
        else
        {
            if (num <= 0) return 0;
            return num ^ Calc(num - 1);
        }
    }
    static long Calc(long num)
    {
        return (num + 1) / 2 % 2;
    }
}