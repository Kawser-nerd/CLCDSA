using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        WriteLine(string.Join(" ", Enumerable.Range(1, 55555).Where(IsPrime).Where(x => x % 5 == 1).Take(int.Parse(ReadLine()))));
    }

    static bool IsPrime(int n)
    {
        if (n < 2) return false;
        var r = (int)Math.Sqrt(n);
        for (int i = 2; i <= r; i++) if (n % i == 0) return false;
        return true;
    }
}