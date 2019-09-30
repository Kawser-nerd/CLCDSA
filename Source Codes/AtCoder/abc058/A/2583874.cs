using System;
using System.Linq;
class Program
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Console.WriteLine(inp[1]*3 == inp.Sum() ? "YES" : "NO");
    }
}