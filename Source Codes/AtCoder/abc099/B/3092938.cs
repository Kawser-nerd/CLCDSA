using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;

class Program
{
    static void Main(string[] args)
    {
        label:
        var sp = ReadLine().Split();
        int left = Parse(sp[0]);
        int right = Parse(sp[1]);
        int diff = right - left;
        WriteLine((diff * (diff + 1)) / 2 - right);
        //goto label;
    }
}