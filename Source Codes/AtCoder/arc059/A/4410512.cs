using System;
using System.Linq;

class Program
{
    static int N;
    static int[] a;

    static void Main()
    {
        N = int.Parse(Console.ReadLine());
        a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int x = a.Sum() / N;
        Console.WriteLine(Math.Min(Cost(x), Cost(x + 1)));
    }

    static long Cost(int x)
    {
        return a.Select(s => (long)Math.Pow(s - x, 2.0)).ToArray().Sum();
    }
}