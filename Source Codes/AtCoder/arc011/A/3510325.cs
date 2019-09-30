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
        var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var old = input[0];
        var ne = input[1];
        var num = input[2];
        var result = num;
        var mod = 0;
        while (num+mod >= old)
        {
            mod += num % old;
            var r = num/old* ne + mod / old * ne;
            result += r;
            num = r;
            mod %= old;
        }
        WriteLine(result);
    }
}