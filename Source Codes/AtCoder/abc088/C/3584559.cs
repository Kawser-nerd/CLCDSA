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
        var cs = new int[3][];
        for(var i = 0; i < 3; i++)
            cs[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for(var i = 0; i < 100; i++)
        {
            if (i > cs[0][0]) { WriteLine("No");return; }
            var b1 = cs[0][0] - i;
            var a2 = cs[1][0] - cs[0][0] + i;
            var a3 = cs[2][0] - cs[0][0] + i;
            var b2 = cs[0][1] - cs[0][0] + b1;
            var b3 = cs[0][2] - cs[0][0] + b1;
            if(a2+b2==cs[1][1]&&
                a2+b3==cs[1][2]&&
                a3+b2==cs[2][1]&&
                a3 + b3 == cs[2][2]) { WriteLine("Yes");return; }
        }
    }
}