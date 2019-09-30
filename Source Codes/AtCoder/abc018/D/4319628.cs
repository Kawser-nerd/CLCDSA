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
        int[] nmpqr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] choco = Enumerable.Repeat(0, nmpqr[0]).Select(_ => new int[nmpqr[1]]).ToArray();
        for (int i = 0; i < nmpqr[4]; i++)
        {
            int[] xyz = Console.ReadLine().Split().Select(int.Parse).ToArray();
            choco[xyz[0] - 1][xyz[1] - 1] += xyz[2];
        }
        int res = 0;
        for (int i = 0; i < (1 << nmpqr[0]); i++)
        {
            if (PopCount(i) != nmpqr[2]) continue;
            int[] kind = new int[nmpqr[1]];
            for (int j = 0; j < nmpqr[0]; j++)
            {
                if ((i & (1 << j)) == 0) continue;
                for (int k = 0; k < nmpqr[1]; k++)
                {
                    kind[k] += choco[j][k];
                }
            }
            res = Max(res, kind.OrderByDescending(x => x).Take(nmpqr[3]).Sum());
        }
        Console.WriteLine(res);
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static byte PopCount(uint n)
    {
        unchecked
        {
            n = (n & 0x55555555u) + ((n >> 1) & 0x55555555u);
            n = (n & 0x33333333u) + ((n >> 2) & 0x33333333u);
            n = (n & 0x0f0f0f0fu) + ((n >> 4) & 0x0f0f0f0fu);
            n = (n & 0x00ff00ffu) + ((n >> 8) & 0x00ff00ffu);
            return (byte)((n & 0x0000ffffu) + ((n >> 16) & 0x0000ffffu));
        }
    }
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static byte PopCount(int n)
    {
        if (n < 0) return (byte)(PopCount((uint)(-n)) + 1);
        return PopCount((uint)n);
    }
}