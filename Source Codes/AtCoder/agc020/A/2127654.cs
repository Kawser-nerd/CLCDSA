using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        int[] nab = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        bool f = (nab[2] - nab[1]) % 2 == 0;
        Console.WriteLine(f ? "Alice" : "Borys");
    }
}