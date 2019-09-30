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
        var disks = new int[nm[0]];
        for (var i = 0; i < nm[0]; i++)
            disks[i] = i+1;
        var now = 0;
        for (var i = 0; i < nm[1]; i++)
        {
            var num = ToInt32(ReadLine());
            for(var j = 0; j < nm[0]; j++)
            {
                if (disks[j] == num)
                {
                    disks[j] = now;
                    now = num;
                }
            }
        }
        WriteLine(string.Join("\n", disks));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}