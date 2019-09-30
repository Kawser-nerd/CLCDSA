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
        var abcxy = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 0;
        var min = Min(abcxy[3], abcxy[4]);
        if (abcxy[0] + abcxy[1] > 2 * abcxy[2])
        {
            result += abcxy[2] * 2 * min;
            if (min == abcxy[3])
                if (abcxy[1] > 2 * abcxy[2])
                    result += 2 * abcxy[2] * (abcxy[4] - abcxy[3]);
                else result += abcxy[1] * (abcxy[4] - abcxy[3]);
            else
            {
                if (abcxy[0] > 2 * abcxy[2])
                    result += 2 * abcxy[2] * (abcxy[3] - abcxy[4]);
                else result += abcxy[0] * (abcxy[3] - abcxy[4]);
            }
        }
        else result += abcxy[0] * abcxy[3] + abcxy[1] * abcxy[4];
        WriteLine(result);
    }
}