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
        int[] Count = Enumerable.Repeat(1, nm[0]).ToArray();
        bool[] IsContainRed = new bool[nm[0]];
        IsContainRed[0] = true;
        for (int i = 0; i < nm[1]; i++)
        {
            int[] xy = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int x = xy[0] - 1;
            int y = xy[1] - 1;
            if (IsContainRed[x])
            {
                IsContainRed[y] = true;
                if (Count[x] == 1)
                {
                    IsContainRed[x] = false;
                }
            }
            Count[x]--;
            Count[y]++;
        }
        Console.WriteLine(IsContainRed.Count(x => x));
    }
}