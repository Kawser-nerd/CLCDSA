using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;
using static System.Math;

class Program
{

    static void Main(string[] args)
    {
        label:
        int count = Parse(ReadLine());
        var result = new int[count];
        for (int i = 0; i < result.Length - 1; ++i)
        {
            var sp = ReadLine().Split();
            int c = Parse(sp[0]);
            int s = Parse(sp[1]);
            int f = Parse(sp[2]);
            result[i] = s + c;
            for (int j = 0; j < i; ++j)
            {
                if (result[j] <= s) result[j] = s + c;
                else
                {
                    result[j] = (result[j] + f - 1) / f * f + c;
                }
            }
        }
        foreach (int n in result)
        {
            WriteLine(n);
        }
    }
}