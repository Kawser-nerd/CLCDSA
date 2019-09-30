using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[][] ab = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).Reverse().ToArray();
        long incr = 0;
        for (int i = 0; i < ab.Length; i++)
        {
            int a = ab[i][0];
            int b = ab[i][1];
            incr += (b - ((a + incr) % b)) % b;
        }
        Console.WriteLine(incr);
    }
}