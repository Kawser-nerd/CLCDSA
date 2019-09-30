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
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int res = 0;
        bool lastIsMax = true;
        while (a.Any(x => x > 0))
        {
            lastIsMax = true;
            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] > 0)
                {
                    if (lastIsMax) res++;
                    a[i]--;
                    lastIsMax = false;
                }
                else
                {
                    lastIsMax = true;
                }
            }
        }
        Console.WriteLine(res);
    }
}