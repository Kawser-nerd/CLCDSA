using System;
using System.Linq;
class c
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        long n = int.Parse(Console.ReadLine());
        inp[0] *= 4;
        inp[1] *= 2;
        var qhs = new long[3] { inp[0], inp[1], inp[2] };
        long best = qhs.Min();
        Console.WriteLine(Math.Min(n / 2 * inp[3] + (n % 2 == 0 ? 0 : best), n * best));
    }
}