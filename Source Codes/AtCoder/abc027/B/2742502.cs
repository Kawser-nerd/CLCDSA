using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(ReadLine());
        var a = ReadLine().Split().Select(int.Parse).ToList();
        var count = 0;
        if (a.Sum() % n != 0)
        {
            WriteLine(-1);
            return;
        }
        var one = a.Sum() / n;
        var sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum % (i + 1) != 0 | sum != one * (i + 1)) count++;
        }
        WriteLine(count);
    }
}