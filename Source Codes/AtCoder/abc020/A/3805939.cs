using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;

class P
{
    static void Main()
    {
        Console.WriteLine(new Random().NextDouble() <= 0.5 ? "ABC" : "chokudai");
    }
}