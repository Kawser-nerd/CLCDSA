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

class P
{
    static void Main()
    {
        char[][] c = Enumerable.Repeat(0, 8).Select(_ => Console.ReadLine().ToArray()).ToArray();
        bool[] hContains = new bool[8];
        bool[] wContains = new bool[8];
        bool[] hpwContains = new bool[15];
        bool[] hmwp7Contains = new bool[15];
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (c[i][j] == 'Q')
                {
                    if (hContains[i]) goto end;
                    hContains[i] = true;
                    if (wContains[j]) goto end;
                    wContains[j] = true;
                    if (hpwContains[i + j]) goto end;
                    hpwContains[i + j] = true;
                    if (hmwp7Contains[i - j + 7]) goto end;
                    hmwp7Contains[i - j + 7] = true;
                }
            }
        }
        if (!IsPossible(c, hContains, wContains, hpwContains, hmwp7Contains)) goto end;
        Console.WriteLine(string.Join("\n", res.Select(x => string.Join("", x))));
        return;
        end:;
        Console.WriteLine("No Answer");
    }
    static char[][] res = null;
    static bool IsPossible(char[][] c, bool[] hContains, bool[] wContains, bool[] hpwContains, bool[] hmwp7Contains)
    {
        if(hContains.All(x => x) && wContains.All(x => x))
        {
            res = c;
            return true;
        }
        int hindex = -1;
        for (int i = 0; i < 8; i++)
        {
            if (!hContains[i])
            {
                hindex = i;
                break;
            }
        }
        if (hindex == -1) return false;
        for (int i = 0; i < 8; i++)
        {
            if (!wContains[i] && !hpwContains[hindex + i] && ! hmwp7Contains[hindex - i + 7])
            {
                var newc = c.Select(x => x.ToArray()).ToArray();
                var newhc = hContains.ToArray();
                var newwc = wContains.ToArray();
                var newhpwc = hpwContains.ToArray();
                var newhmwp7c = hmwp7Contains.ToArray();
                newc[hindex][i] = 'Q';
                newhc[hindex] = true;
                newwc[i] = true;
                newhpwc[hindex + i] = true;
                newhmwp7c[hindex - i + 7] = true;
                if (IsPossible(newc, newhc, newwc, newhpwc, newhmwp7c)) return true;
            }
        }
        return false;
    }
}