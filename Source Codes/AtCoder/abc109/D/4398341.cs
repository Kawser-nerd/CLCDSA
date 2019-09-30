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
        var hw = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar = new int[hw[0]][];
        for (var i = 0; i < hw[0]; i++)
            ar[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse).Select(v=>v%2).ToArray();
        var str = new List<string>();
        var mod = 0;
        for(var i = 0; i < hw[0]; i++)
        {
            for (var j = 0; j < hw[1]; j++)
                if ((ar[i][j] + mod) % 2 == 1)
                {
                    if (i == hw[0] - 1 && j == hw[1] - 1) break;
                    mod = 1;
                    if (j == hw[1] - 1)
                        str.Add($"{i + 1} {j + 1} {i + 2} {j + 1}");
                    else str.Add($"{i + 1} {j + 1} {i + 1} {j + 2}");
                }
                else mod = 0;
            i++;
            if (i == hw[0]) break;
            for (var j = hw[1] - 1; j >= 0; j--)
                if ((ar[i][j] + mod) % 2 == 1)
                {
                    if (i == hw[0] - 1 && j == 0) break;
                    mod = 1;
                    if (j == 0)
                        str.Add($"{i + 1} {j + 1} {i + 2} {j + 1}");
                    else str.Add($"{i + 1} {j + 1} {i + 1} {j}");
                }
                else mod = 0;
        }
        if (str.Count == 0) WriteLine(0);
        else WriteLine($"{str.Count}\n{string.Join("\n", str)}");
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}