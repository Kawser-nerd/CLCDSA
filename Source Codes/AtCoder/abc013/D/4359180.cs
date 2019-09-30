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
        var nmd = Console.ReadLine().Split().Select(int.Parse).ToList();
        int[] swap = Enumerable.Range(0, nmd[0]).ToArray();
        if (nmd[1] != 0)
        {
            var a = Console.ReadLine().Split().Select(int.Parse).ToList();
            for (int i = a.Count - 1; i >= 0; i--)
            {
                var tmp = swap[a[i] - 1];
                swap[a[i] - 1] = swap[a[i]];
                swap[a[i]] = tmp;
            }
        } 

        int[] res = Enumerable.Range(1, nmd[0]).ToArray();
        while (nmd[2] > 0)
        {
            if ((nmd[2] & 1) == 1) res = Operate(res, swap);
            swap = Operate(swap, swap);
            nmd[2] >>= 1;
        }
        Console.WriteLine(string.Join("\n", res));
    }

    static int[] Operate(int[] a, int [] op)
    {
        var res = a.ToArray();
        for (int i = 0; i < op.Length; i++)
        {
            res[i] = a[op[i]];
        }
        return res;
    }
}