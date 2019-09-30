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
        var q = ToInt32(ReadLine());
        const int NUM = 100001;
        var bo = new bool[NUM];
        for (var i = 2; i < NUM; i++)
            if (!bo[i])
                for (var j = 2 * i; j < NUM; j += i)
                    bo[j] = true;
        var sum = new int[NUM];
        for (var i = 3; i < NUM; i += 2)
            if (!bo[i] && !bo[(i + 1) / 2]) sum[i] = sum[i - 2] + 1;
            else sum[i] = sum[i - 2];
        var s = new int[q];
        for(var i = 0; i < q; i++)
        {
            var lr = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            s[i] = lr[0]!=1?sum[lr[1]] - sum[lr[0]-2]:sum[lr[1]];
        }
        WriteLine(string.Join("\n", s));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}