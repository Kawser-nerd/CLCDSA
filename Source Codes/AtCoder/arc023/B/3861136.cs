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
        var rcd = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var gre = new int[rcd[0]][];
        for (var i = 0; i < rcd[0]; i++)
            gre[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var max = 0;
        for(var i = 0; i < Min(rcd[2]+1,rcd[0]); i++)
        {
            var id = Abs(rcd[2] % 2 - i % 2);
            for(var j = 0; j < Min(rcd[2]+1-i, rcd[1]); j++)
            {
                if (id % 2 == 0) max = Max(max, gre[i][j]);
                id++;
            }
        }
        WriteLine(max);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}