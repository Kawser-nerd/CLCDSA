using System;
using System.Linq;
class Program
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Console.WriteLine(inp.Sum() < 10 ? inp.Sum().ToString() : "error");
    }
}