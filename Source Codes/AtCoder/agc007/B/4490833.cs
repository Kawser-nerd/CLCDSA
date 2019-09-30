using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select((x, y) => new Tuple<int, int>(int.Parse(x), y)).OrderBy(x => x.Item1).Select(x => x.Item2).ToList();
        Console.WriteLine(string.Join(" ", Enumerable.Range(1, n).Select(x => x * 20000).Zip(a, (x, y) => x + y)));
        Console.WriteLine(string.Join(" ", Enumerable.Range(1, n).Select(x => x * 20000).Reverse()));
    }
}