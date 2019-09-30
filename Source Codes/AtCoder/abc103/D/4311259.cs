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
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var req = new int[nm[1]][];
        for (var i = 0; i < nm[1]; i++)
            req[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        req = req.OrderBy(ab => ab[1]).ToArray();
        var then = -1;
        var res = 0;
        for(var i = 0; i < nm[1]; i++)
        {
            if (then <= req[i][0])
            {
                then = req[i][1];
                res++;
            }
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}