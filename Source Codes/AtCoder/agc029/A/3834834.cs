using System;
using System.Collections.Generic;
using static System.Console;
using static System.Int32;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        label:
        var s = ReadLine();
        int b = 0;
        long result = 0;
        foreach(char c in s)
        {
            if (c == 'B') ++b;
            else result += b;
        }
        WriteLine(result);
    }
}