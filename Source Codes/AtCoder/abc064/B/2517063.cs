using System;
using System.Linq;
class Program
{
    static void Main()
    {
        Console.ReadLine();
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Console.WriteLine(inp.Max()-inp.Min());
    }
}