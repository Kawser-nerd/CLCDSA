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
        var result = 0;
        for(var i = 0; i < num; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            result += input[1] * input[0];
        }
        WriteLine((int)(result*1.05));
    }
}