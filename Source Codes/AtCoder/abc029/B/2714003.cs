using System;
using System.Linq;

class Program
{
    static void Main()
    {
        Console.WriteLine(Enumerable.Repeat(0, 12).Select(_ => Console.ReadLine()).Count(x => x.Contains("r")));
    }
}