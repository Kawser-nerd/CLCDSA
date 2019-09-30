using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nml = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] pqr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] pqrs = new int[6][] { new int[] { pqr[0], pqr[1], pqr[2] }, new int[] { pqr[0], pqr[2], pqr[1] }, new int[] { pqr[1], pqr[0], pqr[2] }, new int[] { pqr[1], pqr[2], pqr[0] }, new int[] { pqr[2], pqr[0], pqr[1] }, new int[] { pqr[2], pqr[1], pqr[0] } };

        int max = 0;
        foreach (var PQR in pqrs)
        {
            int[] a = nml.Zip(PQR, (x, y) => x / y).ToArray();
            max = Math.Max(max, a[0] * a[1] * a[2]);
        }
        Console.WriteLine(max);
    }
}