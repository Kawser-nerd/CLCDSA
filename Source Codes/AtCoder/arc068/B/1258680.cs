//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public static void Main()
    {
        var N = int.Parse(Console.ReadLine());

        var A = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

        A = A.OrderBy(x => x).ToArray();

        int pos1 = 0;
        int pos2 = N - 2;

        int totalDiscarded = 0;

        while (pos1 <= pos2)
        {
            while (pos1 <= pos2 && A[pos1] != A[pos1 + 1])
            {
                pos1++;
            }

            while (pos1 <= pos2 && A[pos2] != A[pos2 + 1])
            {
                pos2--;
            }

            if (pos1 <= pos2)
            {
                totalDiscarded += 2;
                pos1++;
                pos2--;
            }
        }

        Console.WriteLine(N - totalDiscarded);
    }
}