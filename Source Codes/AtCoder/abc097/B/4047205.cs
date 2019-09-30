using System;
using System.Web;
using System.IO;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var upper = Floor(Sqrt(n));
        int max = 1;
        for (int i = 2; i <= upper; i++)
        {
            int a = i;
            while (true)
            {
                if (a * i > n) break;
                a *= i;
            }
            max = Max(max, a);
        }
        Console.WriteLine(max);
    }
}