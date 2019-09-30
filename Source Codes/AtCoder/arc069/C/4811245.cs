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
        var a = Console.ReadLine().Split().Select(long.Parse).Concat(Enumerable.Repeat(0L, 1)).ToArray();
        var sortedIndex = a.Select((x, y) => new Tuple<long, int>(x, y)).OrderByDescending(x => x.Item1).Select(x => x.Item2).ToArray();
        long[] res = new long[n];

        int minLastIndex = sortedIndex[0];
        for (int i = 1; i < a.Length; i++)
        {
            if (a[sortedIndex[i - 1]] != a[sortedIndex[i]]) res[minLastIndex] += (a[sortedIndex[i - 1]] - a[sortedIndex[i]]) * i;
            minLastIndex = Min(minLastIndex, sortedIndex[i]);
        }
        Console.WriteLine(string.Join("\n", res));
    }
}