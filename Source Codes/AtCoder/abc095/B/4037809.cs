using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;

class P
{
    static void Main()
    {
        int[] nx = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] m = Enumerable.Repeat(0, nx[0]).Select(_ => int.Parse(Console.ReadLine())).ToArray(); ;
        Console.WriteLine(nx[0] + (nx[1] - m.Sum()) / m.Min());
    }
}