using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;

static class P
{
    static void Main()
    {
        //
        //?????????????
        //?????????????
        //?????????????
        //?????????????
        //?????????????
        //?????????????
        //?????????????
        //?????????????
        //
        var hw = Console.ReadLine().Split().Select(int.Parse).ToList();
        var map = Enumerable.Repeat(0, hw[0]).Select(_ => Console.ReadLine().ToList()).ToList();

        Console.WriteLine(string.Join("\n", Enumerable.Range(0, hw[0]).Select(x => string.Join("", (x % 2 == 0 ? Enumerable.Repeat('#', 1).Concat(map[x].Skip(1)) : Enumerable.Repeat('#', hw[1] - 1).Concat(Enumerable.Repeat('.', 1)))))));
        Console.WriteLine();
        Console.WriteLine(string.Join("\n", Enumerable.Range(0, hw[0]).Select(x => string.Join("", (x % 2 == 1 ? map[x].Take(hw[1] - 1).Concat(Enumerable.Repeat('#', 1)) : Enumerable.Repeat('.', 1).Concat(Enumerable.Repeat('#', hw[1] - 1)))))));
    }
}