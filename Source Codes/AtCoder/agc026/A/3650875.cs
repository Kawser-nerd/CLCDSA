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
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var last = -1;
        var result = 0;
        for (var i = 0; i < num; i++)
        {
            if (last == ar[i])
            {
                result++;
                last = 10000;
            }
            else last = ar[i];
        }
        WriteLine(result);
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}