using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var ti = new int[4][];
        for (var i = 0; i < 4; i++)
            ti[i] =
                Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for (var i = 0; i < 4; i++)
            for (var j = 0; j < 4; j++)
                if ((i != 3 && ti[i][j] == ti[i + 1][j]) ||
                    (j != 3 && ti[i][j] == ti[i][j + 1]))
                {
                    WriteLine("CONTINUE"); return;
                }
        WriteLine("GAMEOVER");
            
    }
}