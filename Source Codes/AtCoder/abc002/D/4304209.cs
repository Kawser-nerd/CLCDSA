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
        var ad = new List<int>[nm[0]];
        for (var i = 0; i < nm[0]; i++)
            ad[i] = new List<int>();
        for(var i = 0; i < nm[1]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            ad[input[0] - 1].Add(input[1] - 1);
            ad[input[1] - 1].Add(input[0] - 1);
        }
        var res = 0;
        for(var i = 1; i < Pow(2, nm[0]); i++)
        {
            var set = new HashSet<int>();
            for(var j = 0; j < nm[0]; j++)
            {
                if (((i >> j) & 1) == 1)
                    set.Add(j);
            }
            var isMatch = true;
            foreach (var item in set)
            {
                foreach (var val in set)
                {
                    if (item == val) continue;
                    if (!ad[item].Contains(val))
                        isMatch = false;
                }
            }
            if (isMatch) res = Max(res, set.Count);
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}