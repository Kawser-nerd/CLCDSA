using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;


class P
{
    static void Main()
    {
        int[] ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(ab[1] / ab[0]);
    }
}