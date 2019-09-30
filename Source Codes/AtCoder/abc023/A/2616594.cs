using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        Console.WriteLine(Console.ReadLine().ToArray().Sum(x => x - '0'));
    }
}