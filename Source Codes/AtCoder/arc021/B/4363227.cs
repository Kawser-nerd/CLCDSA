using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;


class Ph
{
    static void Main()
    {
        var b = Enumerable.Repeat(0, int.Parse(Console.ReadLine())).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        List<int> res = new List<int>();
        res.Add(0);
        for (int i = 0; i < b.Length - 1; i++)
        {
            res.Add(b[i] ^ res.Last());
        }
        if(b.Last() != (res.Last() ^ res.First()))
        {
            Console.WriteLine(-1);
            return;
        }
        Console.WriteLine(string.Join("\n", res));
    }
}