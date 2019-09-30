using System;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        Console.ReadLine();
        Console.WriteLine(Console.ReadLine().Split(' ').Select(x => int.Parse(x)).Select(x => (80 - x) > 0 ? (80 - x) : 0).ToList().Sum().ToString());
    }
}