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
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using static System.Math;


class P
{
    static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        bool[] contained = new bool[hw[1]];
        List<char[]> map = new List<char[]>();
        for (int _ = 0; _ < hw[0]; _++)
        {
            char[] line = Console.ReadLine().ToArray();
            if (line.All(x => x != '#')) continue;
            map.Add(line);
            for (int i = 0; i < hw[1]; i++) contained[i] |= line[i] == '#';
        }
        Console.WriteLine(string.Join("\n", map.Select(x => string.Join("", x.Where((_, ind) => contained[ind])))));
    }
}