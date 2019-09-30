using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Int32;
using static System.Math;
 
class Program
{
    static void Main(string[] args)
    {
        label:
        WriteLine(hoge() ? "Yes" : "No");
    }

    static bool hoge()
    {
        var org = Parse(ReadLine());
        int f = 0;
        for (int n = org; 0 < n; n /= 10)
        {
            f += n % 10;
        }
        return org % f == 0;
    }
}