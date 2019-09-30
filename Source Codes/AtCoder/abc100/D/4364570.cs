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
        var xyz = new long[nm[0]][];
        for (var i = 0; i < nm[0]; i++)
            xyz[i] = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        var res = long.MinValue;
        for (var i = 0; i < 8; i++)
        {
            var h = Enumerable.Repeat(-1, 3).ToArray();
            for (var j = 0; j < 3; j++)
                if (((i >> j) & 1) == 1)
                    h[j] = 1;
            var al = xyz.OrderByDescending(ar => Enumerable.Range(0,3).Select(v=>h[v]*ar[v]).Sum()).Take(nm[1]).ToArray();
            var sum = 0L;
            for (var j = 0; j < 3; j++)
                sum += Abs(al.Sum(ar => ar[j]));
            res = Max(res,sum);
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}