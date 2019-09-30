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
        const int NUM = 55556;
        var bo = new bool[NUM];
        var prime = new List<int>();
        for (var i = 2; i < NUM; i++)
            if (!bo[i])
            {
                if(i%5==1)
                prime.Add(i);
                for (var j = 2 * i; j < NUM; j += i)
                    bo[j] = true;
            }
        WriteLine(string.Join(" ", prime.Take(num)));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}