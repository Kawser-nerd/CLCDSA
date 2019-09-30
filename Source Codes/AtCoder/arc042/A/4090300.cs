using System;
using System.Web;
using System.IO;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using static System.Math;
 

class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] num = Enumerable.Repeat(int.MaxValue, nm[0]).ToArray();
        int currentTop = 1;
        foreach (var item in Enumerable.Repeat(0, nm[1]).Select(_ => int.Parse(Console.ReadLine())).Reverse())
        {
            if(num[item - 1] == int.MaxValue)
            {
                num[item - 1] = currentTop;
                currentTop++;
            }
        }
        Console.WriteLine(string.Join("\n", num.Select((x, y) => new Tuple<int, int>(x, y)).OrderBy(x => x.Item1).ThenBy(x => x.Item2).Select(x => x.Item2 + 1)));
    }
}