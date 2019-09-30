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
        var nk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var rs = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        Array.Sort(rs);
        var result = 0d;
        for(var i = 0; i < nk[1]; i++)
        {
            result = (result + rs[nk[0] - nk[1] + i]) / 2;
        }
        WriteLine(result);
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}