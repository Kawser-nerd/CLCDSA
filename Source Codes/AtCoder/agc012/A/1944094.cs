using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(Console.ReadLine().Split().Select(long.Parse).OrderByDescending(x => x).Where((_, index) => index % 2 == 1).Take(n).Sum());
    }
}