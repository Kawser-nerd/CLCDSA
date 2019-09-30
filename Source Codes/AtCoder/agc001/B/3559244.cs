using System;
using System.IO;
using System.Linq;
using System.Runtime;
using System.Reflection;
using System.Diagnostics;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using static System.Math;


class P
{
    static void Main()
    {
        long[] nx = Console.ReadLine().Split().Select(long.Parse).ToArray();

        Console.WriteLine(nx[0] + Solve(nx[1], nx[0] - nx[1]));
    }
    static long Solve(long up, long side)
    {
        if (up == 0 || side == 0) return 0;
        if (up > side)
        {
            if (up % side == 0) return (side * ((up / side) * 2 - 1));
            return (side * (up / side) * 2) + Solve(up % side, side);
        }
        else
        {
            if (side % up == 0) return (up * ((side / up) * 2 - 1));
            return (up * (side / up) * 2) + Solve(up, side % up);
        }
    }
}