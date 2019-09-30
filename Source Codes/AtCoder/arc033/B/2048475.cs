using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        string[] a = Console.ReadLine().Split();
        string[] b = Console.ReadLine().Split();
        Console.WriteLine((double)a.Intersect(b).Count() / a.Union(b).Count());
    }
}