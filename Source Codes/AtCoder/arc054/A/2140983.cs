using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] lxysd = Console.ReadLine().Split().Select(int.Parse).ToArray();
        double d = (lxysd[4] + (lxysd[0] - lxysd[3])) % lxysd[0];
        Console.WriteLine(Math.Min(d / (lxysd[1] + lxysd[2]), (lxysd[2] - lxysd[1] > 0 ? (lxysd[0] - d) / (lxysd[2] - lxysd[1]) : double.MaxValue)));
    }
}