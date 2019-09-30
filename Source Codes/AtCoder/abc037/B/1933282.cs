using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int a = int.Parse(Console.ReadLine());
        int[] NQ = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = new int[NQ[0]];
        int[][] Q = new int[NQ[1]][].Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        foreach (var q in Q)
        {
            a = a.Select((x, y) => { if (q[0] - 1 <= y && y <= q[1] - 1) return q[2]; return x; }).ToArray();
        }
        foreach (var item in a)
        {
            Console.WriteLine(item);
        }
    }
}