using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var ab = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();

        Console.WriteLine(F(ab[0] - 1) ^ F(ab[1]));
    }

    static long F(long b)
    {
        return new long[] { b, 1, b + 1, 0 }[(b + 4) % 4];
    }
}