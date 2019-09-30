using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        Array.Sort(ar);
        var tail = 3 * num - 2;
        var result = 0L;
        for(var i = 0; i < num; i++)
        {
            result += ar[tail];
            tail -= 2;
        }
        WriteLine(result);
    }
}