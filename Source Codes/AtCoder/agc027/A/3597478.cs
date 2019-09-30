using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var nx = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var cand = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        Array.Sort(cand);
        for(var i = 0; i < nx[0]; i++)
            if (nx[1] - cand[i] < 0) { WriteLine(i); return; }
            else nx[1] -= cand[i];
        WriteLine(nx[1]==0?nx[0]:nx[0]-1);
    }
}