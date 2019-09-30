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
        var set = new HashSet<int>();
        for (var i = 0; i < num; i++)
        {
            while (ar[i] % 2 == 0)
                ar[i] /= 2;
            set.Add(ar[i]);
        }
        WriteLine(set.Count);
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}