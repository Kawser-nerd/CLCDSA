using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;

class P
{
    static void Main()
    {
        int[] abk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(string.Join("\n", Enumerable.Range(abk[0], abk[2]).Concat(Enumerable.Range(abk[1] - abk[2] + 1, abk[2])).Where(x => abk[0] <= x && x <= abk[1]).Distinct().OrderBy(x => x)));
    }
}