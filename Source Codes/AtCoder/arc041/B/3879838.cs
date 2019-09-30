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
        var gre = new int[nm[0]][];
        var result = new int[nm[0]][];
        for(var i = 0; i < nm[0]; i++)
        {
            var inp = ReadLine();
            gre[i] = new int[nm[1]];
            result[i] = new int[nm[1]];
            for(var j = 0; j < nm[1]; j++)
            {
                gre[i][j] = ToInt32(inp.Substring(j, 1));
            }
        }
        for(var i = 1; i < nm[0] - 1; i++)
        {
            for(var j = 1; j < nm[1] - 1; j++)
            {
                result[i][j] = gre[i - 1][j];
                gre[i - 1][j] -= result[i][j];
                gre[i + 1][j] -= result[i][j];
                gre[i][j - 1] -= result[i][j];
                gre[i][j + 1] -= result[i][j];
            }
        }
        for(var i = 0; i < nm[0]; i++)
        {
            WriteLine(string.Join("", result[i]));
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}