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
        var hw = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var fromto = new int[10][];
        for (var i = 0; i < 10; i++)
            fromto[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var gred = new int[hw[0]][];
        for (var i = 0; i < hw[0]; i++)
            gred[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for (var k = 0; k < 10; k++)
            for (var i = 0; i < 10; i++)
                for (var j = 0; j < 10; j++)
                    fromto[i][j] = Min(fromto[i][j], fromto[i][k] + fromto[k][j]);
        var res = 0L;
        for (var i = 0; i < hw[0]; i++)
            for (var j = 0; j < hw[1]; j++)
                if (gred[i][j] != -1 && gred[i][j] != 1)
                    res += fromto[gred[i][j]][1];
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}