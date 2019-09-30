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
        //??????????? : ??????????????????????????
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] map = Enumerable.Repeat(0, nm[0]).Select(_ => Console.ReadLine().Select(x => x - '0').ToArray()).ToArray();
        int[][] resmap = Enumerable.Repeat(0, nm[0]).Select(_ => new int[nm[1]]).ToArray();
        for (int i = 0; i < nm[0] - 2; i++)
        {
            for (int j = 1; j < nm[1] - 1; j++)
            {
                int count = map[i][j];
                resmap[i + 1][j] = count;
                map[i][j] -= count;
                map[i + 2][j] -= count;
                map[i + 1][j - 1] -= count;
                map[i + 1][j + 1] -= count;
            }
        }
        Console.WriteLine(string.Join("\n", resmap.Select(x => string.Join("", x))));
    }
}