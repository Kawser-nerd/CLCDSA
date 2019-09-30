using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;
class P
{
    static void Main()
    {
        Console.WriteLine(new TimeSpan(long.Parse(Console.ReadLine()) * 10000000).ToString(@"hh\:mm\:ss"));

    }
}