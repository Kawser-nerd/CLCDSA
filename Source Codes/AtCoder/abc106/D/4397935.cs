using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var nmq = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var lr = new int[nmq[0]+1,nmq[0]+1];
        for (var i = 0; i < nmq[1]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            lr[input[0], input[1]]++;
        }
        var sumo = new int[nmq[0]+1, nmq[0]+1];
        for (var i = 0; i <= nmq[0]; i++)
            for (var j = 1; j <= nmq[0]; j++)
                sumo[i, j] += sumo[i, j - 1] + lr[i, j];
        var res = new int[nmq[2]];
        for(var i = 0; i < nmq[2]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            for (var j = input[0]; j <= input[1]; j++)
                res[i] += sumo[j, input[1]] - sumo[j, input[0] - 1];
        }
        WriteLine(string.Join("\n", res));
        
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}