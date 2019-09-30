using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n % 400 == 0 || (n % 100 != 0 && n % 4 == 0) ? "YES" : "NO");
    }
}