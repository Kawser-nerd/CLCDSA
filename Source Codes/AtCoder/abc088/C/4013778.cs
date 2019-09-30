using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var c = new int[3][];
        for (int i = 0; i < 3; i++)
        {
            c[i] = Console.ReadLine().Split().Select(t => int.Parse(t)).ToArray();
        }
        var a = new int[3];
        var b = new int[3];

        bool flag = false;
        for (int i = 0; i <= 100; i++)
        {
            a[0] = i;
            b[0] = c[0][0] - a[0];
            b[1] = c[0][1] - a[0];
            b[2] = c[0][2] - a[0];
            a[1] = c[1][0] - b[0];
            a[2] = c[2][0] - b[0];
            if (c[1][1] == a[1] + b[1] && c[1][2] == a[1] + b[2] && c[2][1] == a[2] + b[1] && c[2][2] == a[2] + b[2])
            {
                flag = true;
                break;
            }
        }
        if (flag) Console.WriteLine("Yes");
        else Console.WriteLine("No");
    }
}