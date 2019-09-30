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
        var co = ToInt32(ReadLine());
        var fib = new int[co+2];
        fib[0] = 1;
        fib[1] = 1;
        for (var i = 2; i <= co+1; i++)
            fib[i] = fib[i - 1] + fib[i - 2];
        WriteLine($"{fib[co+1]} {fib[co]}");
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}