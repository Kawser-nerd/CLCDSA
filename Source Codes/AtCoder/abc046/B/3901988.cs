using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        int n = int.Parse(cin[0]);
        int k = int.Parse(cin[1]);

        Console.WriteLine(k * Math.Pow(k - 1, n - 1));
    }
}