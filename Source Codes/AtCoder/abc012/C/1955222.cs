using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = 2025 - int.Parse(Console.ReadLine());
        for (int i = 1; i <= 9; i++)
        {
            if (n % i == 0 && n / i <= 9) Console.WriteLine($"{i} x {n/i}");
        }
    }
}