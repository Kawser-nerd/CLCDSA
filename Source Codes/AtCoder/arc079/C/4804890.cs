using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using static System.Math;
using Debug = System.Diagnostics.Debug;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;


static class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select(long.Parse).ToArray();

        var max = a.Sum();
        for (long opCount = Max(0, a.Sum(x => x - (n - 1))); opCount <= max; opCount++)
        {
            if(a.Sum(x => (x + opCount) / (n + 1) + ((x + opCount) % (n + 1) == n ? 1 : 0)) == opCount)
            {
                Console.WriteLine(opCount);
                return;
            }
        }
    }
}