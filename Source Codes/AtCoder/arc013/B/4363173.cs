using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;


class Ph
{
    static void Main()
    {
        Console.WriteLine(Enumerable.Repeat(0, int.Parse(Console.ReadLine())).Select(_ => Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x)).Aggregate(Enumerable.Repeat(0, 3), (x, y) => x.Zip(y, (z, w) => Max(z, w))).Aggregate(1, (x, y) => x * y));
    }
}