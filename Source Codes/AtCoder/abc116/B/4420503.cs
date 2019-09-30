using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var set = new HashSet<int>();
        var i = 1;
        while (set.Add(n))
        {
            n = next(n);
            i++;
        }
        Console.WriteLine(i);
    }

    static int next(int n)
    {
        if (n % 2 == 0) return n / 2;
        else return 3 * n + 1;
    }
}