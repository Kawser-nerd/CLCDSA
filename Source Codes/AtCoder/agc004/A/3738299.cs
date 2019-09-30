using System;
using System.Linq;
class c
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), long.Parse).OrderBy(f => f).ToArray();
        Console.WriteLine(inp.Count(f => f % 2 == 0) > 0 ? 0 : inp[0] * inp[1]);
    }
}