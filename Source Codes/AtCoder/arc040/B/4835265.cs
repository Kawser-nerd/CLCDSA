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
        var nr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<char> s = Console.ReadLine().ToList();
        var lastWhitePlace = s.LastIndexOf('.');
        int res = Max(0, lastWhitePlace - nr[1] + 1);
        for (int i = 0; i < nr[0]; i++)
        {
            if (s[i] == '.')
            {
                res++;
                var max = Min(nr[0], i + nr[1]);
                for (int j = i; j < max; j++) s[j] = 'o';
            }
        }
        Console.WriteLine(res);
    }
}