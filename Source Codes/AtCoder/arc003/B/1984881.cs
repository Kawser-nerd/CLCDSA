using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.WriteLine(string.Join("\n", Enumerable.Repeat("", int.Parse(Console.ReadLine())).Select(_ => Console.ReadLine()).OrderBy(x => string.Join("", x.Reverse().ToArray())).ToArray()));
    }
}