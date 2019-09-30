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
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] As = Enumerable.Repeat(0, nm[0]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        int[][] Cs = Enumerable.Repeat(0, nm[1]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();

        foreach (var a in As)
        {
            int min = int.MaxValue;
            int minInd = -1;
            for (int i = 0; i < Cs.Length; i++)
            {
                var c = Cs[i];
                var abs = Abs(c[0] - a[0]) + Abs(c[1] - a[1]);
                if (min > abs)
                {
                    min = abs;
                    minInd = i;
                }
            }
            Console.WriteLine(minInd + 1);
        }
    }
}