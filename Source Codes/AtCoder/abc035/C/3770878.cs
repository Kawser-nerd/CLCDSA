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
        var nq = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var imos = new int[nq[0] + 1];
        for(var i = 0; i < nq[1]; i++)
        {
            var lr = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            imos[lr[0]-1]++;
            imos[lr[1]]--;
        }
        for(var i = 1; i < nq[0]; i++)
            imos[i] += imos[i - 1];
        for (var i = 0; i < nq[0]; i++)
            imos[i] %= 2;
        Array.Resize(ref imos, nq[0]);
        WriteLine(string.Join("", imos));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}