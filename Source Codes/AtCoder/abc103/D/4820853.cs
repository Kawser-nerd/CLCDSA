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
        var nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = nm[0];
        int m = nm[1];
        int[][] queries = Enumerable.Repeat(0, m).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).OrderBy(x => x[1]).ToArray();
        int res = 0;
        int resolvedTail = 0;
        for (int i = 0; i < queries.Length; i++)
        {
            if (queries[i][0] < resolvedTail) continue;
            resolvedTail = queries[i][1];
            res++;
        }
        Console.WriteLine(res);
    }
}