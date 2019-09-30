using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine((int)Math.Sqrt(Math.Sqrt(n)));
    }
}