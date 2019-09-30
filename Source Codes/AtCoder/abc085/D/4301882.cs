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
        var nh = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ab = new int[nh[0]][];
        for (var i = 0; i < nh[0]; i++)
            ab[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        ab = ab.OrderByDescending(a => a[1]).ToArray();
        var max = ab.Max(b => b[0]);
        var res = 0;
        for(var i = 0; i < nh[0]; i++)
        {
            if (max < ab[i][1] && nh[1] > 0)
            {
                res++;
                nh[1] -= ab[i][1];
            }
            else
                break;
        }
        res += Max(0, (int)Ceiling((double)nh[1] / max));
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}