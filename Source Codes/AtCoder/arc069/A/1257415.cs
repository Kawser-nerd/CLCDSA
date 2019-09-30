//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;

public class Test
{
    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        long N = line1[0];
        long M = line1[1];
        long total = 0;

        long temp = Math.Min(N, M / 2);

        total += temp;
        N -= temp;
        M -= temp * 2;

        long temp2 = M / 4;

        total += temp2;
        M -= temp2 * 4;

        Console.WriteLine(total);
    }
}