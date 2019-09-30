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
        var num = ToInt32(ReadLine());
        var ab = new int[num][];
        for (var i = 0; i < num; i++)
            ab[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var imos = new int[1000002];
        for(var i = 0; i < num; i++)
        {
            imos[ab[i][0]]++;
            imos[ab[i][1] + 1]--;
        }
        for(var i = 1; i < 1000001; i++)
        {
            imos[i] += imos[i - 1];
        }
        WriteLine(imos.Max());
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}