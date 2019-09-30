using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;


class P
{
    static void Main()
    {
        int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();

        int min = a.Where(x => x < 3200).Select(x => x / 400).Distinct().Count();
        Console.WriteLine($"{Max(1, min)} {min + a.Count(x => x >= 3200)}");
    }
}