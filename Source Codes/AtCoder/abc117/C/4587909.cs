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
using System.Runtime.CompilerServices;


static class P
{
    static void Main()
    {
        var nm = Console.ReadLine().Split().Select(int.Parse).ToList();
        var a = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToList();
        Console.WriteLine(a.Zip(a.Skip(1), (x, y) => y - x).OrderByDescending(x => x).Skip(nm[0] - 1).Sum());
    }
}