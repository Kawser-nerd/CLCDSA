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
        var N = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

        var b = a.OrderBy(x => x).ToArray();

        int pos = 0;
        long lastHeight = 0;

        for (int i = 0; i < N; i++)
        {
            long temp = 0;
            long height = Math.Max(lastHeight, a[i]);

            while (pos < N && b[pos] <= height)
            {
                temp += (b[pos] - lastHeight);
                pos++;
            }

            temp += (N - pos) * (height - lastHeight);

            lastHeight += (height - lastHeight);
            
            Console.WriteLine(temp);
        }
    }
}