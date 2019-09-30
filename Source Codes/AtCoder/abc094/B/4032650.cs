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
        int[] nmx = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(Min(a.TakeWhile(x => x <= nmx[2]).Count(), a.SkipWhile(x => x <= nmx[2]).Count()));
    }
}